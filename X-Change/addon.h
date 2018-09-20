/* Created by "go tool cgo" - DO NOT EDIT. */

/* package service.robot.com */


#line 1 "cgo-builtin-prolog"

#include <stddef.h> /* for ptrdiff_t below */

#ifndef GO_CGO_EXPORT_PROLOGUE_H
#define GO_CGO_EXPORT_PROLOGUE_H

typedef struct { const char *p; ptrdiff_t n; } _GoString_;

#endif

/* Start of preamble from import "C" comments.  */


#line 10 "D:\\code\\Go_Path\\src\\service.robot.com\\export_action.go"

// CGO
#include <stdlib.h>

#line 1 "cgo-generated-wrapper"

#line 10 "D:\\code\\Go_Path\\src\\service.robot.com\\main.go"

// CGO
#include <stdlib.h>

// 声明一个指向参数为-const char*类型, 返回值为-void类型的函数指针类型
typedef void(*callback_async_event) (const char*);

// code 异步回调函数 code_callback_async_event_func
// params:
// 		callback_async_event: 函数指针
// 		msg:
static inline void code_callback_async_event_func(callback_async_event f, const char* msg)
{
	return f(msg);
}

// action 异步回调函数 action_callback_async_event_func
// params:
// 		callback_async_event:
//		msg:
static inline void action_callback_async_event_func(callback_async_event f, const char* msg) {
	return f(msg);
}

#line 1 "cgo-generated-wrapper"


/* End of preamble from import "C" comments.  */


/* Start of boilerplate cgo prologue.  */
#line 1 "cgo-gcc-export-header-prolog"

#ifndef GO_CGO_PROLOGUE_H
#define GO_CGO_PROLOGUE_H

typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
//typedef __SIZE_TYPE__ GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;
//typedef float _Complex GoComplex64;
//typedef double _Complex GoComplex128;

/*
  static assertion to make sure the file is being used on architecture
  at least with matching size of GoInt.
*/
typedef char _check_for_64_bit_pointer_matching_GoInt[sizeof(void*)==64/8 ? 1:-1];

typedef _GoString_ GoString;
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;

#endif

/* End of boilerplate cgo prologue.  */

#ifdef __cplusplus
extern "C" {
#endif


//
// action_event UI层 Action 事件函数，导出为 C 接口,完成两个功能：
//      执行命令接收：From UI，本地 JS 接口调用
//      执行命令路由：To Controller， Websocket 通信，函数执行结果通过
//                  异步回调函数 callback_async_event 返回
// params:
//      cmd:     命令标志符
//      cSerial: 设备序列号
//      cData:   要处理的数据
//      ret:     函数执行结果：0-success, 1-failed
// return:
//      *C.Char: 字符串类型的结果, 必须是由 DataAction 结构序列化而得到

extern char* action_event(char* p0, char* p1, char* p2, int* p3);

// TODO: Will Deprecated

extern char* debug_code(char* p0, int p1, int* p2);

extern char* make_json_result(char* p0, char* p1);

//
// register_action_callback_async_event 导出 C 接口，用于注册异步函数回调事件

extern void register_action_callback_async_event(callback_async_event p0);

#ifdef __cplusplus
}
#endif
