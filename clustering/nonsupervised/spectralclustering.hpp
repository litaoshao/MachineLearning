/** 
 \verbatim
 #########################################################################
 # GPL License                                                           #
 #                                                                       #
 # Copyright (c) 2010, Philipp Kraus, <philipp.kraus@flashpixx.de>       #
 # This program is free software: you can redistribute it and/or modify  #
 # it under the terms of the GNU General Public License as published by  #
 # the Free Software Foundation, either version 3 of the License, or     #
 # (at your option) any later version.                                   #
 #                                                                       #
 # This program is distributed in the hope that it will be useful,       #
 # but WITHOUT ANY WARRANTY; without even the implied warranty of        #
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
 # GNU General Public License for more details.                          #
 #                                                                       #
 # You should have received a copy of the GNU General Public License     #
 # along with this program.  If not, see <http://www.gnu.org/licenses/>. #
 #########################################################################
 \endverbatim
 **/

#ifndef MACHINELEARNING_CLUSTERING_NONSUPERVISED_SPECTRALCLUSTERING_HPP
#define MACHINELEARNING_CLUSTERING_NONSUPERVISED_SPECTRALCLUSTERING_HPP


#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "../clustering.hpp"
#include "neuralgas.hpp"
#include "../../exception/exception.h"
#include "../../tools/tools.h"
#include "../../distances/distances.h"

#include <iostream>
#include <boost/numeric/ublas/io.hpp>

namespace machinelearning { namespace clustering { namespace nonsupervised {
    
    namespace ublas = boost::numeric::ublas;
    
    
    
    /** class for (normalized & unnormalized) spectral clustering. This class calculates only the graph laplacian
     * and creates the general eigenvector decomposition. A neuralgas algorithm with euclidian
     * distancesis used for clustering the data
     * @todo set all routines to sparse matrix if arpack can be used with boost
     **/
    template<typename T> class spectralclustering {
        
        
        public :
            
            spectralclustering( const std::size_t&, const std::size_t& );
            void train( const ublas::matrix<T>&, const std::size_t& );
            void train( const ublas::matrix<T>&, const std::size_t&, const T& );
            ublas::matrix<T> getPrototypes( void ) const;
            void setLogging( const bool& );
            std::vector< ublas::matrix<T> > getLoggedPrototypes( void ) const;
            bool getLogging( void ) const;
            std::size_t getPrototypeSize( void ) const;
            std::size_t getPrototypeCount( void ) const;
            std::vector<T> getLoggedQuantizationError( void ) const;
            std::vector<T> use( const ublas::matrix<T>& ) const;
            
            //static std::size_t getEigenGap( const ublas::matrix<T>& ) const;
            //static std::size_t getEigenGap( const ublas::matrix<T>&, const ublas::matrix<T>& ) const;
            

        private :
        
            /** distance object for ng **/
            const distances::euclid<T> m_distance;
            /** neural gas for clustering the graph laplacian **/
            neuralgas<T> m_ng;
        
    };
    

    /** constructor 
     * @param p_prototypes number of prototypes
     * @param p_prototypesize size of each prototype (row / column length of the adjacency matrix)
     **/
    template<typename T> inline spectralclustering<T>::spectralclustering( const std::size_t& p_prototypes, const std::size_t& p_prototypesize ) :
        m_distance( distances::euclid<T>() ),
        m_ng( neuralgas<T>( m_distance, p_prototypes, p_prototypesize) )
    {}
    
    
    /** returns the prototype matrix
     * @return matrix (rows = number of prototypes)
     **/
    template<typename T> inline ublas::matrix<T> spectralclustering<T>::getPrototypes( void ) const
    {
        return m_ng.getPrototypes();
    }
    
    
    
    /** enabled logging for training
     * @param p bool
     **/
    template<typename T> inline void spectralclustering<T>::setLogging( const bool& p )
    {
        m_ng.setLogging(p);
    }
    
    
    
    /** shows the logging status
     * @return bool
     **/
    template<typename T> inline bool spectralclustering<T>::getLogging( void ) const
    {
        return m_ng.getLogging();
    }
    
    
    
    /** returns every prototype step during training
     * @return std::vector with prototype matrix
     **/
    template<typename T> inline std::vector< ublas::matrix<T> > spectralclustering<T>::getLoggedPrototypes( void ) const
    {
        return m_ng.getLoggedPrototypes();
    }
    
    
    /** returns the dimension of prototypes
     * @return dimension of the prototypes
     **/
    template<typename T> inline std::size_t spectralclustering<T>::getPrototypeSize( void ) const 
    {
        return m_ng.getPrototypeSize();
    };
    
    
    /** returns the number of prototypes
     * @return number of the prototypes / classes
     **/
    template<typename T> inline std::size_t spectralclustering<T>::getPrototypeCount( void ) const 
    {
        return m_ng.getPrototypeCount();
    };
    
    
    /** returns the quantisation error 
     * @return error for each iteration
     **/
    template<typename T> inline std::vector<T> spectralclustering<T>::getLoggedQuantizationError( void ) const
    {
        return m_ng.getLoggedQuantizationError();
    }    
    
    
    /** cluster the graph with the <strong>normalized</strong> graph laplacian
     * @todo copy function for matrix musst be optimized
     * @todo try to do it numerical stable
     * @param p_similarity similarity NxN matrix, needs to be symmetric and non-negative
     * @param p_iterations number of iterations
     **/
    template<typename T> inline void spectralclustering<T>::train( const ublas::matrix<T>& p_similarity, const std::size_t& p_iterations )
    {
        if (p_similarity.size1() != p_similarity.size1())
            throw exception::matrixsymmetric();
        if (p_similarity.size2() < m_ng.getPrototypeCount())
            throw exception::samesize("data dimension", "prototype dimension");
        
        // create squared degree and normalized graph laplacian
        const ublas::matrix<T> l_sqrtdegree = tools::matrix::pow( tools::matrix::diag(tools::matrix::sum(p_similarity)), static_cast<T>(-0.5));
        const ublas::matrix<T> l_tmp        = ublas::prod(l_sqrtdegree, p_similarity);
        const ublas::matrix<T> l_laplacian  = tools::matrix::eye<T>(p_similarity.size1()) - ublas::prod(l_tmp, l_sqrtdegree);
        
        // determine eigenvalues and -vector of the graph laplacian
        ublas::vector<T> l_eigenvalue;
        ublas::matrix<T> l_eigenvector;
        tools::lapack::eigen( l_laplacian, l_eigenvalue, l_eigenvector );
         
        // ranking eigenvalues and get the k smallest for the eigenvectors
        const ublas::vector<std::size_t> l_rank = tools::vector::rankIndex<T>(l_eigenvalue);
        
        std::cout << l_eigenvector << std::endl;
        std::cout << std::endl;
        std::cout << l_eigenvalue << std::endl;
        std::cout << l_rank << std::endl;
        
        // extrakt the k eigenvectors
        ublas::matrix<T> l_eigenmatrix(m_ng.getPrototypeCount(), l_laplacian.size1());
        for(std::size_t i=0; i < m_ng.getPrototypeCount(); ++i)
            ublas::row(l_eigenmatrix, i) = ublas::column(l_eigenvector, l_rank(i));
        
        // clustering
        m_ng.train(l_eigenmatrix, p_iterations);
    }
    
        
};};};
#endif
