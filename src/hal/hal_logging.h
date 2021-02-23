#ifndef HAL_LOGGING_H
#define HAL_LOGGING_H

#include <rtapi.h>
#include <string.h>

// checking & logging shorthands
#define HALERR(fmt, ...)					\
    rtapi_print_msg(RTAPI_MSG_ERR, "HAL error:")
#define HALWARN(fmt, ...)					\
    rtapi_print_msg(RTAPI_MSG_WARN, "HAL WARNING:")
#define HALINFO(fmt, ...)					\
    rtapi_print_msg(RTAPI_MSG_INFO, "HAL info:")

#define HALDBG(fmt, ...)					\
    rtapi_print_msg(RTAPI_MSG_DBG, "HAL:")

#define HAL_ASSERT(x)						\
    do {							\
	if (!(x)) {						\
	    rtapi_print_msg(RTAPI_MSG_ERR, "HAL error: ASSERTION VIOLATED: '%s'", #x);	\
	}							\
    } while(0)


#define CHECK_HALDATA()					\
    do {						\
	if (hal_data == 0) {				\
	    rtapi_print_msg(RTAPI_MSG_ERR, "HAL error: called before init");	\
	    return -EINVAL;				\
	}						\
    } while (0)

#define CHECK_NULL(p)						\
    do {							\
	if (p == NULL) {					\
	    rtapi_print_msg(RTAPI_MSG_ERR,"HAL error: is null");			\
	    return -EINVAL;					\
	}							\
    } while (0)

#define CHECK_LOCK(ll)							\
    do {								\
	if (hal_data->lock & ll) {					\
	    rtapi_print_msg(RTAPI_MSG_ERR,"HAL error: called while HAL is locked (%d)",		\
			    ll);					\
	    return -EPERM;						\
	}								\
    } while(0)


#define CHECK_STR(name)							\
    do {								\
	if ((name) == NULL) {						\
	    rtapi_print_msg(RTAPI_MSG_ERR,"HAL error: argument '" # name  "' is NULL");		\
	    return -EINVAL;						\
	}								\
    } while(0)


#define CHECK_STRLEN(name, len)						\
    do {								\
	CHECK_STR(name);						\
	if (strlen(name) > len) {					\
	    rtapi_print_msg(RTAPI_MSG_ERR,"HAL error: argument '%s' too long (%zu/%d)",		\
			    name, strlen(name), len);			\
	    return -EINVAL;						\
	}								\
    } while(0)

#define NOMEM(fmt, ...)						\
    do {							\
	rtapi_print_msg(RTAPI_MSG_ERR,"HAL error: insufficient memory for: ");			\
	return -ENOMEM;						\
    } while(0)

#endif // HAL_LOGGING_H
