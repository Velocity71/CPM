#include <stdio.h> // used for error printing
#include <stdlib.h> // used for the exit() function
#include <mach/mach.h> // Mach-specific APIs, used to get parameters like resident and virtual RAM

// Returns a pointer pointing to the array holding the memory usage statistics
unsigned long *get_memory_usage() {

    task_basic_info_data_t memory_usage; // struct for memory usage statistics, populated later by task_info()
    mach_msg_type_number_t memory_usage_count = TASK_BASIC_INFO_COUNT; // specifies number of elements in the memory_usage struct

    // Retrieves memory usage information, return_status indicates errors, information populates to the memory_usage struct
    kern_return_t return_status = task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&memory_usage, &memory_usage_count);

    // Checks if host_statistics() was executed successfully
    if (return_status != KERN_SUCCESS) {
        fprintf(stderr, "Failed to get memory usage info: %s\n", mach_error_string(return_status)); // if error, converts into readable message and prints to stderr
        exit(1); // exit get_memory_usage() early
    }

    // Save memory usage statistics to an array and return pointer for array
    unsigned long *bytes = (unsigned long *)malloc(2);
    bytes[0] = memory_usage.resident_size;
    bytes[1] = memory_usage.virtual_size;
    unsigned long *ptr = bytes;
    return ptr;
}