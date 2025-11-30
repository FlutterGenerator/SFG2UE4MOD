#ifndef __SUBSTRATEHOOK_H__
#define __SUBSTRATEHOOK_H__

#include <stdlib.h>

#ifndef _extern  // Проверяем, определён ли уже макрос
#define _extern extern "C" __attribute__((__visibility__("hidden")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

void MSHookFunction(void *symbol, void *replace, void **result);

#ifdef __cplusplus
}
#endif

#endif
