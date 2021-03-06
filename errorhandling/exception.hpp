/** 
 @cond
 ############################################################################
 # LGPL License                                                             #
 #                                                                          #
 # This file is part of the Machine Learning Framework.                     #
 # Copyright (c) 2010-2012, Philipp Kraus, <philipp.kraus@flashpixx.de>     #
 # This program is free software: you can redistribute it and/or modify     #
 # it under the terms of the GNU Lesser General Public License as           #
 # published by the Free Software Foundation, either version 3 of the       #
 # License, or (at your option) any later version.                          #
 #                                                                          #
 # This program is distributed in the hope that it will be useful,          #
 # but WITHOUT ANY WARRANTY; without even the implied warranty of           #
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
 # GNU Lesser General Public License for more details.                      #
 #                                                                          #
 # You should have received a copy of the GNU Lesser General Public License #
 # along with this program. If not, see <http://www.gnu.org/licenses/>.     #
 ############################################################################
 @endcond
 **/

#ifndef __MACHINELEARNING_ERRORHANDLING_EXCEPTION_HPP
#define __MACHINELEARNING_ERRORHANDLING_EXCEPTION_HPP

#include <string>
#include <stdexcept>


namespace machinelearning { 
    
    /** namespace for all exceptions of the framework
     * @todo adding more exceptions for a better error handling
     **/
    namespace exception {
    
        
        /** exception class for throwing on runtime errors **/
        class runtime : public std::runtime_error
        { 
            public : 

                explicit runtime( const std::string& );            
                template <typename T> explicit runtime( const std::string&, const T* );
                template <typename T> explicit runtime( const std::string&, const T& );
        };
 
        
    }
}


#include "exception.implementation.hpp"

#endif
