#include <stdio.h>

#include "CPUMetrics.h"

#include <sys/types.h>
#include <sys/sysctl.h>

int main() {
    float *ptr = get_cpu_load();
    printf("User: %f%%\n", *ptr);
}