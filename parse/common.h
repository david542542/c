// common.h

#ifndef __COMMON_H__
#define __COMMON_H_

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

bool is_empty_expr(char* buffer);
char* trim_expr_end(char* buffer, int buffer_index);


#endif
