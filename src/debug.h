/* code was written by openai */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>

/* Debug macros */
#define DEBUG 1  // Set to 0 to disable debug output
				 
#define print_var(x) printf("%s = %d\n", #x, x)

#define debug(M, ...) \
    do { \
        if (DEBUG) { \
            fprintf(stderr, "[DEBUG] %s:%d: " M "\n", \
                    __FILE__, __LINE__, ##__VA_ARGS__); \
        } \
    } while(0)

#define log_err(M, ...) \
    fprintf(stderr, "[ERROR] (%s:%d) " M "\n", \
            __FILE__, __LINE__, ##__VA_ARGS__)

#define log_warn(M, ...) \
    fprintf(stderr, "[WARN] (%s:%d) " M "\n", \
            __FILE__, __LINE__, ##__VA_ARGS__)

#define log_info(M, ...) \
    fprintf(stderr, "[INFO] (%s:%d) " M "\n", \
            __FILE__, __LINE__, ##__VA_ARGS__)

/* Assertions */
#define assertf(A, M, ...) \
    do { \
        if (!(A)) { \
            log_err(M, ##__VA_ARGS__); \
            exit(1); \
        } \
    } while(0)

#endif /* DEBUG_H_ */

