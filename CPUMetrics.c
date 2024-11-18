#include <stdio.h> // used for error printing
#include <stdlib.h> // used for the exit() function
#include <mach/mach.h> // Mach-specific APIs, used to get parameters like CPU load

// Returns a pointer pointing to the array holding the cpu load percentages
float *get_cpu_load() {

    host_cpu_load_info_data_t cpu_load; // struct for CPU load information, populated later by host_statistics()
    mach_msg_type_number_t cpu_load_count = HOST_CPU_LOAD_INFO_COUNT; // specifies number of elements in the cpu_load struct

    // Retrieves CPU load information, return_status indicates errors, information populates to the cpu_load struct
    kern_return_t return_status = host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpu_load, &cpu_load_count);

    // Checks if host_statistics() was executed successfully
    if (return_status != KERN_SUCCESS) {
        fprintf(stderr, "Failed to get CPU load  info: %s\n", mach_error_string(return_status)); // if error, converts into readable message and prints to stderr
        exit(1); // exit get_cpu_load() early
    }

    // Calculate CPU load as a percentage for user, system, idle, and nice
    uint64_t total_ticks = 0; // sum of ticks across all CPU states
    for (int i = 0; i < CPU_STATE_MAX; i++) {
        total_ticks += cpu_load.cpu_ticks[i]; // add number of ticks for each state
    }

    // Save CPU load statistics to an array and return pointer for array
    float *percentages = (float *)malloc(4);
    percentages[0] = (float)cpu_load.cpu_ticks[CPU_STATE_USER] / total_ticks * 100;
    percentages[1] = (float)cpu_load.cpu_ticks[CPU_STATE_SYSTEM] / total_ticks * 100;
    percentages[2] = (float)cpu_load.cpu_ticks[CPU_STATE_IDLE] / total_ticks * 100;
    percentages[3] = (float)cpu_load.cpu_ticks[CPU_STATE_NICE] / total_ticks * 100;
    float *ptr = percentages;
    return ptr;
}