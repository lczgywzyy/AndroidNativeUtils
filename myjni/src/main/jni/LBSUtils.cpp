#include "u_can_i_up_app_MainActivity.h"
#include <string.h>
#include <jni.h>

JNIEXPORT jstring JNICALL Java_u_can_i_up_app_MainActivity_getLocation(JNIEnv* env, jobject thiz){
    return env->NewStringUTF("LOC!");
}