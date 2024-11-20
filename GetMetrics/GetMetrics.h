// GetMetrics.h

// Expect file not found, has to be included in compilation
// Holds information for JNIEXPORT and JNICALL
#include <jni.h>

// Ensure this file is only included once
#ifndef _Included_GetMetrics
#define _Included_GetMetrics

// applies when compiling with C++, ensures that this code is treated as C and not C++
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jfloat JNICALL Java_GetMetrics_getCpuUser
  (JNIEnv *, jobject);


JNIEXPORT jfloat JNICALL Java_GetMetrics_getCpuSystem
  (JNIEnv *, jobject);


JNIEXPORT jfloat JNICALL Java_GetMetrics_getCpuIdle
  (JNIEnv *, jobject);


JNIEXPORT jfloat JNICALL Java_GetMetrics_getCpuNice
  (JNIEnv *, jobject);


JNIEXPORT jlong JNICALL Java_GetMetrics_getMemResident
  (JNIEnv *, jobject);


JNIEXPORT jlong JNICALL Java_GetMetrics_getMemVirtual
  (JNIEnv *, jobject);


JNIEXPORT jlong JNICALL Java_GetMetrics_getDiskTotal
  (JNIEnv *, jobject);


JNIEXPORT jlong JNICALL Java_GetMetrics_getDiskUsed
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
