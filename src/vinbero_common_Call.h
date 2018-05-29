#ifndef _VINBERO_COMMON_CALL
#define _VINBERO_COMMON_CALL
#define VINBERO_COMMON_CALL(iName, fName, module, ret, ...) do { \
    struct vinbero_ ## iName ## _Interface interface; \
    VINBERO_ ## iName ## _DLSYM(&interface, &(module)->dlHandle, ret); \
    if(*ret < 0) { \
        VINBERO_COMMON_LOG_ERROR("VINBERO_%s_DLSYM() failed at module %s, with function %s", #iName, (module)->id, "vinbero_"#iName"_"#fName); \
        break; \
    } \
    if(((*ret) = interface.vinbero_ ## iName ## _ ## fName (__VA_ARGS__)) < 0) \
        VINBERO_COMMON_LOG_WARN("vinbero_%s_%s() failed at module %s", #iName, #fName, (module)->id); \
} while(0)
#endif
