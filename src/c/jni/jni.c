// jni.c

// Interface with and give values to Java code

// file included, origionally from jdk-22.jdk/Contents/Home/include
// Holds information for JNIEXPORT and JNICALL
#include "../../../lib/jni.h"

#include "../metrics/cpu_metrics.h"
#include "../metrics/memory_metrics.h"
#include "../metrics/disk_metrics.h"

JNIEXPORT jfloat JNICALL Java_src_java_JNI_getCpuUser(JNIEnv *env, jobject obj) {
    float *ptr = get_cpu_load();
    return (jfloat) *ptr;
}

JNIEXPORT jfloat JNICALL Java_src_java_JNI_getCpuSystem(JNIEnv *env, jobject obj) {
    float *ptr = get_cpu_load(); ptr++;
    return (jfloat) *ptr;
}

JNIEXPORT jfloat JNICALL Java_src_java_JNI_getCpuIdle(JNIEnv *env, jobject obj) {
    float *ptr = get_cpu_load(); ptr+=2;
    return (jfloat) *ptr;
}

JNIEXPORT jfloat JNICALL Java_src_java_JNI_getCpuNice(JNIEnv *env, jobject obj) {
    float *ptr = get_cpu_load(); ptr+=3;
    return (jfloat) *ptr;
}

JNIEXPORT jlong JNICALL Java_src_java_JNI_getMemResident(JNIEnv *env, jobject obj) {
    unsigned long *ptr = get_memory_usage();
    return (jlong) *ptr;
}

JNIEXPORT jlong JNICALL Java_src_java_JNI_getMemVirtual(JNIEnv *env, jobject obj) {
    unsigned long *ptr = get_memory_usage(); ptr++;
    return (jlong) *ptr;
}

JNIEXPORT jlong JNICALL Java_src_java_JNI_getDiskTotal(JNIEnv *env, jobject obj) {
    unsigned long *ptr = get_disk_usage();
    return (jlong) *ptr;
}

JNIEXPORT jlong JNICALL Java_src_java_JNI_getDiskUsed(JNIEnv *env, jobject obj) {
    unsigned long *ptr = get_disk_usage(); ptr++;
    return (jlong) *ptr;
}