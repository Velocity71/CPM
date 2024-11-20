#include <jni.h>

#include "Metrics/headers/CPUMetrics.h"
#include "Metrics/headers/MemMetrics.h"
#include "Metrics/headers/DiskMetrics.h"

JNIEXPORT jfloat JNICALL Java_GetMetrics_getCpuUser(JNIEnv *env, jobject obj) {
    float *ptr = get_cpu_load();
    return (jfloat) *ptr;
}

JNIEXPORT jfloat JNICALL Java_GetMetrics_getCpuSystem(JNIEnv *env, jobject obj) {
    float *ptr = get_cpu_load(); ptr++;
    return (jfloat) *ptr;
}

JNIEXPORT jfloat JNICALL Java_GetMetrics_getCpuIdle(JNIEnv *env, jobject obj) {
    float *ptr = get_cpu_load(); ptr+=2;
    return (jfloat) *ptr;
}

JNIEXPORT jfloat JNICALL Java_GetMetrics_getCpuNice(JNIEnv *env, jobject obj) {
    float *ptr = get_cpu_load(); ptr+=3;
    return (jfloat) *ptr;
}

JNIEXPORT jlong JNICALL Java_GetMetrics_getMemResident(JNIEnv *env, jobject obj) {
    unsigned long *ptr = get_memory_usage();
    return (jlong) *ptr;
}

JNIEXPORT jlong JNICALL Java_GetMetrics_getMemVirtual(JNIEnv *env, jobject obj) {
    unsigned long *ptr = get_memory_usage(); ptr++;
    return (jlong) *ptr;
}

JNIEXPORT jlong JNICALL Java_GetMetrics_getDiskTotal(JNIEnv *env, jobject obj) {
    unsigned long *ptr = get_disk_usage();
    return (jlong) *ptr;
}

JNIEXPORT jlong JNICALL Java_GetMetrics_getDiskUsed(JNIEnv *env, jobject obj) {
    unsigned long *ptr = get_disk_usage(); ptr++;
    return (jlong) *ptr;
}