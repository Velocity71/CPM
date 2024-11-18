#include <stdio.h>

#include "CPUMetrics.h"
#include "MemMetrics.h"

int main() {
    float *clptr = get_cpu_load();
    printf("---CPU LOAD---\n");
    printf("User: %f%%\n", *clptr); clptr++;
    printf("System: %f%%\n", *clptr); clptr++;
    printf("Idle: %f%%\n", *clptr); clptr++;
    printf("Nice: %f%%\n", *clptr);

    unsigned long *muptr = get_memory_usage();
    printf("---MEMORY USAGE---\n");
    printf("Resident (Physical RAM) size: %lu bytes\n", *muptr); muptr++;
    printf("Virtual (Virtual RAM) size: %lu bytes\n", *muptr);
}