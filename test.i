# 64 "././include/linux/compiler_types.h"
#define __kernel

#define __user BTF_TYPE_TAG(user)

#define __iomem
#define __percpu __percpu_qual BTF_TYPE_TAG(percpu)
#define __rcu BTF_TYPE_TAG(rcu)

#define __chk_user_ptr(x) (void)0
#define __chk_io_ptr(x) (void)0

#define __force
#define __nocast
#define __safe
#define __private
#define ACCESS_PRIVATE(p, member) ((p)->member)
#define __builtin_warning(x, y...) (1)

# 1 "./include/linux/compiler_attributes.h" 1

#define __LINUX_COMPILER_ATTRIBUTES_H
# 26 "./include/linux/compiler_attributes.h"
#define __alias(symbol) __attribute__((__alias__(#symbol)))

#define __aligned(x) __attribute__((__aligned__(x)))
#define __aligned_largest __attribute__((__aligned__))
# 44 "./include/linux/compiler_attributes.h"
#define __alloc_size__(x, ...) __attribute__((__alloc_size__(x, ##__VA_ARGS__)))
# 55 "./include/linux/compiler_attributes.h"
#define __always_inline inline __attribute__((__always_inline__))
# 70 "./include/linux/compiler_attributes.h"
#define __assume_aligned(a, ...) \
	__attribute__((__assume_aligned__(a, ##__VA_ARGS__)))

#define __cleanup(func) __attribute__((__cleanup__(func)))

#define __attribute_const__ __attribute__((__const__))
# 92 "./include/linux/compiler_attributes.h"
#define __copy(symbol) __attribute__((__copy__(symbol)))
# 106 "./include/linux/compiler_attributes.h"
#define __diagnose_as(builtin...)
# 119 "./include/linux/compiler_attributes.h"
#define __deprecated

#define __designated_init __attribute__((__designated_init__))
# 138 "./include/linux/compiler_attributes.h"
#define __compiletime_error(msg) __attribute__((__error__(msg)))
# 149 "./include/linux/compiler_attributes.h"
#define __visible __attribute__((__externally_visible__))
