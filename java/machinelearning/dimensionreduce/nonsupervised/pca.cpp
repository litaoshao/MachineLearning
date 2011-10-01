/** 
 @cond
 ############################################################################
 # LGPL License                                                             #
 #                                                                          #
 # This file is part of the Machine Learning Framework.                     #
 # Copyright (c) 2010, Philipp Kraus, <philipp.kraus@flashpixx.de>          #
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


#include "pca.h"
#include "../../function.hpp"
#include <machinelearning.h>

namespace ml  = machinelearning;
namespace dim = machinelearning::dimensionreduce::nonsupervised;

/** field id that stores the ID that stores the pointer **/
jFieldID machinelearning_dimensionreduce_nonsupervised_pca_fieldidx = NULL;


/** constructor call
 * @param p_env JNI environmental
 * @param p_object JNI object
 * @param p_idx field index object
 * @param p_dimension dimension value
**/
JNIEXPORT jlong JNICALL Java_machinelearning_dimensionreduce_nonsupervised_pca_cpp_1ctor(JNIEnv* p_env, jobject p_object, jint p_dimension)
{
    jlong l_ptr = 0;
    
    try {
        ml::java::createObjectPointer(p_env, p_object, machinelearning_dimensionreduce_nonsupervised_pca_fieldidx, new pca);
    } catch (...) {
        
    }
    
    return l_ptr;
}


/** dispose call for an java object
 * @param p_env JNI environmental
 * @param p_object JNI object
 **/
JNIEXPORT void JNICALL Java_machinelearning_dimensionreduce_nonsupervised_pca_dispose(JNIEnv* p_env, jobject p_object)
{
    ml::java::disposeObjectPointer(p_env, p_object, machinelearning_dimensionreduce_nonsupervised_pca_fieldidx);
}


JNIEXPORT jobjectArray JNICALL Java_machinelearning_dimensionreduce_nonsupervised_pca_map(JNIEnv* p_env, jobject p_object, jobjectArray j_data)
{
  
}


JNIEXPORT jint JNICALL Java_machinelearning_dimensionreduce_nonsupervised_pca_getDimension(JNIEnv* p_env, jobject p_object)
{
}


JNIEXPORT jobjectArray JNICALL Java_machinelearning_dimensionreduce_nonsupervised_pca_getProject(JNIEnv* p_env, jobject p_object)
{
}
