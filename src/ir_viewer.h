/*
 * ir_viewer.h
 *
 *  Created on: Jan 10, 2017
 *      Author: usrc
 */

#ifndef SRC_IR_VIEWER_H_
#define SRC_IR_VIEWER_H_



#define LOG_LEVEL 10

#define MAX_STREAMS 3
#define MAX_STRLEN 50

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#define LOGE(level, ...) if (level <= LOG_LEVEL + 10) {printf(__VA_ARGS__);printf("\n");}

#define JNIEnv void
#define jobject void *

int jni_ir_viewer_init(JNIEnv *env, jobject thiz);

#endif /* SRC_IR_VIEWER_H_ */
