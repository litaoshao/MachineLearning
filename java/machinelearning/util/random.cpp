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

#include <stdexcept>

#include "random.h"
#include "../../java.h"


namespace java  = machinelearning::java;
namespace tools = machinelearning::tools;

/* $LastChangedDate$ */

/** field id that stores the ID of the pointer **/
static jfieldID fidx_machinelearning_util_random    = NULL;



/** destructor call for the random object 
 * @param p_env JNI environment
 * @param p_object JNI object
 **/
JNIEXPORT void JNICALL Java_machinelearning_util_Random_dispose(JNIEnv* p_env, jobject p_object)
{
    java::jni::disposeObjectPointer< tools::random >(p_env, p_object, fidx_machinelearning_util_random);
}


/** constructor call
 * @param p_env JNI environment
 * @param p_object JNI object
 * @return object pointer
 **/
JNIEXPORT jlong JNICALL Java_machinelearning_util_Random_cppCtor(JNIEnv* p_env, jobject p_object)
{
    return java::jni::createObjectPointer(p_env, p_object, fidx_machinelearning_util_random, new tools::random());
}


/** creates a random float value
 * @param p_env JNI environment
 * @param p_object JNI object
 * @param p_distribution distribution object
 * @return float random value
 **/
JNIEXPORT jobject JNICALL Java_machinelearning_util_Random_getFloat(JNIEnv* p_env, jobject p_object, jobject p_distribution)
{
    tools::random* l_ptr = java::jni::getObjectPointer< tools::random >(p_env, p_object, fidx_machinelearning_util_random);
    if (!l_ptr)
        return p_env->NewGlobalRef(NULL);
    
    // create random value
    float l_val = 0;
    switch (java::jni::getEnumOrdinalValue(p_env, p_distribution)) {
            
        case 0 :
            try {
                l_val = l_ptr->get<float>( tools::random::uniform );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 1 :
            try {
                l_val = l_ptr->get<float>( tools::random::bernoulli );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 2 :
            try {
                l_val = l_ptr->get<float>( tools::random::cauchy );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 3 :
            try {
                l_val = l_ptr->get<float>( tools::random::gamma );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 4 :
            try {
                l_val = l_ptr->get<float>( tools::random::poisson );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 5 :
            try {
                l_val = l_ptr->get<float>( tools::random::exponential );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 6 :
            try {
                l_val = l_ptr->get<float>( tools::random::normal );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 7 :
            try {
                l_val = l_ptr->get<float>( tools::random::student );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 8 :
            try {
                l_val = l_ptr->get<float>( tools::random::weibull );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 9 :
            try {
                l_val = l_ptr->get<float>( tools::random::rayleigh );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 10 :
            try {
                l_val = l_ptr->get<float>( tools::random::chisquared );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 11 :
            try {
                l_val = l_ptr->get<float>( tools::random::pareto );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 12 :
            try {
                l_val = l_ptr->get<float>( tools::random::triangular );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 13 :
            try {
                l_val = l_ptr->get<float>( tools::random::beta );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        default:
            p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), _("option value is unkown") );
            return p_env->NewGlobalRef(NULL);
    }
    
    // create java object
    jclass l_elementclass   = NULL;
    jmethodID l_elementctor = NULL;
    java::jni::getCtor(p_env, "java/lang/Float", "(F)V", l_elementclass, l_elementctor);
    
    return p_env->NewObject( l_elementclass, l_elementctor, l_val );
}


/** creates a random double value
 * @param p_env JNI environment
 * @param p_object JNI object
 * @param p_distribution distribution object
 * @return double random value
 **/
JNIEXPORT jobject JNICALL Java_machinelearning_util_Random_getDouble(JNIEnv* p_env, jobject p_object, jobject p_distribution)
{
    tools::random* l_ptr = java::jni::getObjectPointer< tools::random >(p_env, p_object, fidx_machinelearning_util_random);
    if (!l_ptr)
        return p_env->NewGlobalRef(NULL);
        
    // create random value
    double l_val = 0;
    switch (java::jni::getEnumOrdinalValue(p_env, p_distribution)) {
            
        case 0 :
            try {
                l_val = l_ptr->get<double>( tools::random::uniform );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 1 :
            try {
                l_val = l_ptr->get<double>( tools::random::bernoulli );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 2 :
            try {
                l_val = l_ptr->get<double>( tools::random::cauchy );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 3 :
            try {
                l_val = l_ptr->get<double>( tools::random::gamma );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 4 :
            try {
                l_val = l_ptr->get<double>( tools::random::poisson );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 5 :
            try {
                l_val = l_ptr->get<double>( tools::random::exponential );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 6 :
            try {
                l_val = l_ptr->get<double>( tools::random::normal );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 7 :
            try {
                l_val = l_ptr->get<double>( tools::random::student );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 8 :
            try {
                l_val = l_ptr->get<double>( tools::random::weibull );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 9 :
            try {
                l_val = l_ptr->get<double>( tools::random::rayleigh );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 10 :
            try {
                l_val = l_ptr->get<double>( tools::random::chisquared );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 11 :
            try {
                l_val = l_ptr->get<double>( tools::random::pareto );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 12 :
            try {
                l_val = l_ptr->get<double>( tools::random::triangular );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 13 :
            try {
                l_val = l_ptr->get<double>( tools::random::beta );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        default:
            p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), _("option value is unkown") );
            return p_env->NewGlobalRef(NULL);
    }
    
    // create java object
    jclass l_elementclass   = NULL;
    jmethodID l_elementctor = NULL;
    java::jni::getCtor(p_env, "java/lang/Double", "(D)V", l_elementclass, l_elementctor);
    
    return p_env->NewObject( l_elementclass, l_elementctor, l_val );
}


/** generates a random value
 * @param p_env JNI environment
 * @param p_object JNI object
 * @param p_distribution distribution object
 * @param p_first first value for the distribution
 * @return random value
 **/
JNIEXPORT jobject JNICALL Java_machinelearning_util_Random_get__Lmachinelearning_util_Random_Distribution_2Ljava_lang_Float_2(JNIEnv* p_env, jobject p_object, jobject p_distribution, jobject p_first)
{
    tools::random* l_ptr = java::jni::getObjectPointer< tools::random >(p_env, p_object, fidx_machinelearning_util_random);
    if (!l_ptr)
        return p_env->NewGlobalRef(NULL);
    
    const jmethodID l_valueof = java::jni::getMethodID(p_env, "java/lang/Float", "floatValue", "()F");
    
    // create random value
    float l_val = 0;
    switch (java::jni::getEnumOrdinalValue(p_env, p_distribution)) {
            
        case 0 :
            try {
                l_val = l_ptr->get<float>( tools::random::uniform, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 1 :
            try {
                l_val = l_ptr->get<float>( tools::random::bernoulli, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 2 :
            try {
                l_val = l_ptr->get<float>( tools::random::cauchy, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 3 :
            try {
                l_val = l_ptr->get<float>( tools::random::gamma, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 4 :
            try {
                l_val = l_ptr->get<float>( tools::random::poisson, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 5 :
            try {
                l_val = l_ptr->get<float>( tools::random::exponential, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 6 :
            try {
                l_val = l_ptr->get<float>( tools::random::normal, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 7 :
            try {
                l_val = l_ptr->get<float>( tools::random::student, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 8 :
            try {
                l_val = l_ptr->get<float>( tools::random::weibull, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 9 :
            try {
                l_val = l_ptr->get<float>( tools::random::rayleigh, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 10 :
            try {
                l_val = l_ptr->get<float>( tools::random::chisquared, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 11 :
            try {
                l_val = l_ptr->get<float>( tools::random::pareto, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 12 :
            try {
                l_val = l_ptr->get<float>( tools::random::triangular, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 13 :
            try {
                l_val = l_ptr->get<float>( tools::random::beta, p_env->CallFloatMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        default:
            p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), _("option value is unkown") );
            return p_env->NewGlobalRef(NULL);
    }
    
    // create java object
    jclass l_elementclass   = NULL;
    jmethodID l_elementctor = NULL;
    java::jni::getCtor(p_env, "java/lang/Float", "(F)V", l_elementclass, l_elementctor);
    
    return p_env->NewObject( l_elementclass, l_elementctor, l_val );   
}


/** generates a random value
 * @param p_env JNI environment
 * @param p_object JNI object
 * @param p_distribution distribution object
 * @param p_first first value for the distribution
 * @param p_second second value for the distribution
 * @return random value
 **/
JNIEXPORT jobject JNICALL Java_machinelearning_util_Random_get__Lmachinelearning_util_Random_Distribution_2Ljava_lang_Float_2Ljava_lang_Float_2(JNIEnv* p_env, jobject p_object, jobject p_distribution, jobject p_first, jobject p_second)
{
    tools::random* l_ptr = java::jni::getObjectPointer< tools::random >(p_env, p_object, fidx_machinelearning_util_random);
    if (!l_ptr)
        return p_env->NewGlobalRef(NULL);
    
    const jmethodID l_valueof = java::jni::getMethodID(p_env, "java/lang/Float", "floatValue", "()F");
    
    // create random value
    float l_val = 0;
    switch (java::jni::getEnumOrdinalValue(p_env, p_distribution)) {
            
        case 0 :
            try {
                l_val = l_ptr->get<float>( tools::random::uniform, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 1 :
            try {
                l_val = l_ptr->get<float>( tools::random::bernoulli, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 2 :
            try {
                l_val = l_ptr->get<float>( tools::random::cauchy, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 3 :
            try {
                l_val = l_ptr->get<float>( tools::random::gamma, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 4 :
            try {
                l_val = l_ptr->get<float>( tools::random::poisson, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 5 :
            try {
                l_val = l_ptr->get<float>( tools::random::exponential, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 6 :
            try {
                l_val = l_ptr->get<float>( tools::random::normal, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 7 :
            try {
                l_val = l_ptr->get<float>( tools::random::student, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 8 :
            try {
                l_val = l_ptr->get<float>( tools::random::weibull, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 9 :
            try {
                l_val = l_ptr->get<float>( tools::random::rayleigh, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 10 :
            try {
                l_val = l_ptr->get<float>( tools::random::chisquared, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 11 :
            try {
                l_val = l_ptr->get<float>( tools::random::pareto, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 12 :
            try {
                l_val = l_ptr->get<float>( tools::random::triangular, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 13 :
            try {
                l_val = l_ptr->get<float>( tools::random::beta, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        default:
            p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), _("option value is unkown") );
            return p_env->NewGlobalRef(NULL);
    }
    
    // create java object
    jclass l_elementclass   = NULL;
    jmethodID l_elementctor = NULL;
    java::jni::getCtor(p_env, "java/lang/Float", "(F)V", l_elementclass, l_elementctor);
    
    return p_env->NewObject( l_elementclass, l_elementctor, l_val );   
}


/** generates a random value
 * @param p_env JNI environment
 * @param p_object JNI object
 * @param p_distribution distribution object
 * @param p_first first value for the distribution
 * @param p_second second value for the distribution
 * @param p_third third value for the distribution
 * @return random value
 **/
JNIEXPORT jobject JNICALL Java_machinelearning_util_Random_get__Lmachinelearning_util_Random_Distribution_2Ljava_lang_Float_2Ljava_lang_Float_2Ljava_lang_Float_2(JNIEnv* p_env, jobject p_object, jobject p_distribution, jobject p_first, jobject p_second, jobject p_third)
{
    tools::random* l_ptr = java::jni::getObjectPointer< tools::random >(p_env, p_object, fidx_machinelearning_util_random);
    if (!l_ptr)
        return p_env->NewGlobalRef(NULL);
    
    const jmethodID l_valueof = java::jni::getMethodID(p_env, "java/lang/Float", "floatValue", "()F");
    
    // create random value
    float l_val = 0;
    switch (java::jni::getEnumOrdinalValue(p_env, p_distribution)) {
            
        case 0 :
            try {
                l_val = l_ptr->get<float>( tools::random::uniform, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 1 :
            try {
                l_val = l_ptr->get<float>( tools::random::bernoulli, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 2 :
            try {
                l_val = l_ptr->get<float>( tools::random::cauchy, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 3 :
            try {
                l_val = l_ptr->get<float>( tools::random::gamma, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 4 :
            try {
                l_val = l_ptr->get<float>( tools::random::poisson, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 5 :
            try {
                l_val = l_ptr->get<float>( tools::random::exponential, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 6 :
            try {
                l_val = l_ptr->get<float>( tools::random::normal, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 7 :
            try {
                l_val = l_ptr->get<float>( tools::random::student, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 8 :
            try {
                l_val = l_ptr->get<float>( tools::random::weibull, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 9 :
            try {
                l_val = l_ptr->get<float>( tools::random::rayleigh, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 10 :
            try {
                l_val = l_ptr->get<float>( tools::random::chisquared, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 11 :
            try {
                l_val = l_ptr->get<float>( tools::random::pareto, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 12 :
            try {
                l_val = l_ptr->get<float>( tools::random::triangular, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 13 :
            try {
                l_val = l_ptr->get<float>( tools::random::beta, p_env->CallFloatMethod( p_first, l_valueof ), p_env->CallFloatMethod( p_second, l_valueof ), p_env->CallFloatMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        default:
            p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), _("option value is unkown") );
            return p_env->NewGlobalRef(NULL);
    }
    
    // create java object
    jclass l_elementclass   = NULL;
    jmethodID l_elementctor = NULL;
    java::jni::getCtor(p_env, "java/lang/Float", "(F)V", l_elementclass, l_elementctor);
    
    return p_env->NewObject( l_elementclass, l_elementctor, l_val );   
}


/** generates a random value
 * @param p_env JNI environment
 * @param p_object JNI object
 * @param p_distribution distribution object
 * @param p_first first value for the distribution
 * @return random value
 **/
JNIEXPORT jobject JNICALL Java_machinelearning_util_Random_get__Lmachinelearning_util_Random_Distribution_2Ljava_lang_Double_2(JNIEnv* p_env, jobject p_object, jobject p_distribution, jobject p_first)
{
    tools::random* l_ptr = java::jni::getObjectPointer< tools::random >(p_env, p_object, fidx_machinelearning_util_random);
    if (!l_ptr)
        return p_env->NewGlobalRef(NULL);
    
    const jmethodID l_valueof = java::jni::getMethodID(p_env, "java/lang/Double", "doubleValue", "()D");
    
    // create random value
    double l_val = 0;
    switch (java::jni::getEnumOrdinalValue(p_env, p_distribution)) {
            
        case 0 :
            try {
                l_val = l_ptr->get<double>( tools::random::uniform, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 1 :
            try {
                l_val = l_ptr->get<double>( tools::random::bernoulli, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 2 :
            try {
                l_val = l_ptr->get<double>( tools::random::cauchy, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 3 :
            try {
                l_val = l_ptr->get<double>( tools::random::gamma, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 4 :
            try {
                l_val = l_ptr->get<double>( tools::random::poisson, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 5 :
            try {
                l_val = l_ptr->get<double>( tools::random::exponential, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 6 :
            try {
                l_val = l_ptr->get<double>( tools::random::normal, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 7 :
            try {
                l_val = l_ptr->get<double>( tools::random::student, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 8 :
            try {
                l_val = l_ptr->get<double>( tools::random::weibull, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 9 :
            try {
                l_val = l_ptr->get<double>( tools::random::rayleigh, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 10 :
            try {
                l_val = l_ptr->get<double>( tools::random::chisquared, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 11 :
            try {
                l_val = l_ptr->get<double>( tools::random::pareto, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 12 :
            try {
                l_val = l_ptr->get<double>( tools::random::triangular, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 13 :
            try {
                l_val = l_ptr->get<double>( tools::random::beta, p_env->CallDoubleMethod( p_first, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        default:
            p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), _("option value is unkown") );
            return p_env->NewGlobalRef(NULL);
    }
    
    // create java object
    jclass l_elementclass   = NULL;
    jmethodID l_elementctor = NULL;
    java::jni::getCtor(p_env, "java/lang/Double", "(D)V", l_elementclass, l_elementctor);
    
    return p_env->NewObject( l_elementclass, l_elementctor, l_val );  
}


/** generates a random value
 * @param p_env JNI environment
 * @param p_object JNI object
 * @param p_distribution distribution object
 * @param p_first first value for the distribution
 * @param p_second second value for the distribution
 * @return random value
 **/
JNIEXPORT jobject JNICALL Java_machinelearning_util_Random_get__Lmachinelearning_util_Random_Distribution_2Ljava_lang_Double_2Ljava_lang_Double_2(JNIEnv* p_env, jobject p_object, jobject p_distribution, jobject p_first, jobject p_second)
{
    tools::random* l_ptr = java::jni::getObjectPointer< tools::random >(p_env, p_object, fidx_machinelearning_util_random);
    if (!l_ptr)
        return p_env->NewGlobalRef(NULL);
    
    const jmethodID l_valueof = java::jni::getMethodID(p_env, "java/lang/Double", "doubleValue", "()D");
    
    // create random value
    double l_val = 0;
    switch (java::jni::getEnumOrdinalValue(p_env, p_distribution)) {
            
        case 0 :
            try {
                l_val = l_ptr->get<double>( tools::random::uniform, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 1 :
            try {
                l_val = l_ptr->get<double>( tools::random::bernoulli, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 2 :
            try {
                l_val = l_ptr->get<double>( tools::random::cauchy, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 3 :
            try {
                l_val = l_ptr->get<double>( tools::random::gamma, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 4 :
            try {
                l_val = l_ptr->get<double>( tools::random::poisson, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 5 :
            try {
                l_val = l_ptr->get<double>( tools::random::exponential, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 6 :
            try {
                l_val = l_ptr->get<double>( tools::random::normal, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 7 :
            try {
                l_val = l_ptr->get<double>( tools::random::student, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 8 :
            try {
                l_val = l_ptr->get<double>( tools::random::weibull, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 9 :
            try {
                l_val = l_ptr->get<double>( tools::random::rayleigh, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 10 :
            try {
                l_val = l_ptr->get<double>( tools::random::chisquared, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 11 :
            try {
                l_val = l_ptr->get<double>( tools::random::pareto, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 12 :
            try {
                l_val = l_ptr->get<double>( tools::random::triangular, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 13 :
            try {
                l_val = l_ptr->get<double>( tools::random::beta, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        default:
            p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), _("option value is unkown") );
            return p_env->NewGlobalRef(NULL);
    }
    
    // create java object
    jclass l_elementclass   = NULL;
    jmethodID l_elementctor = NULL;
    java::jni::getCtor(p_env, "java/lang/Double", "(D)V", l_elementclass, l_elementctor);
    
    return p_env->NewObject( l_elementclass, l_elementctor, l_val );  
}


/** generates a random value
 * @param p_env JNI environment
 * @param p_object JNI object
 * @param p_distribution distribution object
 * @param p_first first value for the distribution
 * @param p_second second value for the distribution
 * @param p_third third value for the distribution
 * @return random value
 **/
JNIEXPORT jobject JNICALL Java_machinelearning_util_Random_get__Lmachinelearning_util_Random_Distribution_2Ljava_lang_Double_2Ljava_lang_Double_2Ljava_lang_Double_2(JNIEnv* p_env, jobject p_object, jobject p_distribution, jobject p_first, jobject p_second, jobject p_third)
{
    tools::random* l_ptr = java::jni::getObjectPointer< tools::random >(p_env, p_object, fidx_machinelearning_util_random);
    if (!l_ptr)
        return p_env->NewGlobalRef(NULL);
    
    const jmethodID l_valueof = java::jni::getMethodID(p_env, "java/lang/Double", "doubleValue", "()D");
    
    // create random value
    double l_val = 0;
    switch (java::jni::getEnumOrdinalValue(p_env, p_distribution)) {
            
        case 0 :
            try {
                l_val = l_ptr->get<double>( tools::random::uniform, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 1 :
            try {
                l_val = l_ptr->get<double>( tools::random::bernoulli, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 2 :
            try {
                l_val = l_ptr->get<double>( tools::random::cauchy, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 3 :
            try {
                l_val = l_ptr->get<double>( tools::random::gamma, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 4 :
            try {
                l_val = l_ptr->get<double>( tools::random::poisson, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 5 :
            try {
                l_val = l_ptr->get<double>( tools::random::exponential, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 6 :
            try {
                l_val = l_ptr->get<double>( tools::random::normal, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 7 :
            try {
                l_val = l_ptr->get<double>( tools::random::student, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 8 :
            try {
                l_val = l_ptr->get<double>( tools::random::weibull, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 9 :
            try {
                l_val = l_ptr->get<double>( tools::random::rayleigh, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 10 :
            try {
                l_val = l_ptr->get<double>( tools::random::chisquared, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 11 :
            try {
                l_val = l_ptr->get<double>( tools::random::pareto, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 12 :
            try {
                l_val = l_ptr->get<double>( tools::random::triangular, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        case 13 :
            try {
                l_val = l_ptr->get<double>( tools::random::beta, p_env->CallDoubleMethod( p_first, l_valueof ), p_env->CallDoubleMethod( p_second, l_valueof ), p_env->CallDoubleMethod( p_third, l_valueof ) );
            } catch (const std::exception& e) {
                p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), e.what() );
            }
            break;
            
        default:
            p_env->ThrowNew( p_env->FindClass("machinelearning/exception/Runtime"), _("option value is unkown") );
            return p_env->NewGlobalRef(NULL);
    }
    
    // create java object
    jclass l_elementclass   = NULL;
    jmethodID l_elementctor = NULL;
    java::jni::getCtor(p_env, "java/lang/Double", "(D)V", l_elementclass, l_elementctor);
    
    return p_env->NewObject( l_elementclass, l_elementctor, l_val );  
}