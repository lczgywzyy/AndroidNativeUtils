#include "u_can_i_up_app_MainActivity.h"
#include <string.h>
#include <jni.h>

JNIEXPORT jstring JNICALL Java_u_can_i_up_app_MainActivity_sendSMS(JNIEnv* env, jobject thiz){
    jclass smsclazz = env->FindClass("android/telephony/SmsManager");
    if(smsclazz){
        jmethodID get = env->GetStaticMethodID(smsclazz, "getDefault", "()Landroid/telephony/SmsManager;");
        jobject sms = env->NewObject(smsclazz, get); //获得sms对象
        jmethodID send = env->GetMethodID(smsclazz, "sendTextMessage",
            "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V");
        jstring destinationAddress = env->NewStringUTF("15001373068"); //发送短信的地址
        jstring text = env->NewStringUTF("native"); //短信内容
        if (send) {
            env->CallVoidMethod(sms, send, destinationAddress, NULL, text, NULL, NULL);
        }
    }
    return env->NewStringUTF("SEND MESSAGE FINISHED!");
}