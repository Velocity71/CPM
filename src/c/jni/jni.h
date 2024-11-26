// jni.h

// file included, origionally from jdk-22.jdk/Contents/Home/include
// Holds information for JNIEXPORT and JNICALL
#include "../../../lib/jni.h"

// Ensure this file is only included once
#ifndef _Included_JNI
#define _Included_JNI

// applies when compiling with C++, ensures that this code is treated as C and not C++
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jfloat JNICALL Java_src_java_JNI_getCpuUser
  (JNIEnv *, jobject);


JNIEXPORT jfloat JNICALL Java_src_java_JNI_getCpuSystem
  (JNIEnv *, jobject);


JNIEXPORT jfloat JNICALL Java_src_java_JNI_getCpuIdle
  (JNIEnv *, jobject);


JNIEXPORT jfloat JNICALL Java_src_java_JNI_getCpuNice
  (JNIEnv *, jobject);


JNIEXPORT jlong JNICALL Java_src_java_JNI_getMemResident
  (JNIEnv *, jobject);


JNIEXPORT jlong JNICALL Java_src_java_JNI_getMemVirtual
  (JNIEnv *, jobject);


JNIEXPORT jlong JNICALL Java_src_java_JNI_getDiskTotal
  (JNIEnv *, jobject);


JNIEXPORT jlong JNICALL Java_src_java_JNI_getDiskUsed
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif