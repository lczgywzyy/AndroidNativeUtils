#include "u_can_i_up_app_MainActivity.h"
#include <string.h>
#include <jni.h>

JNIEXPORT jint JNICALL Java_u_can_i_up_app_MainActivity_testInt(JNIEnv* env, jobject obj){
    return (jint)1;
}
JNIEXPORT jstring JNICALL Java_u_can_i_up_app_MainActivity_testString(JNIEnv* env, jobject obj){
    return env->NewStringUTF("TEST");
}
