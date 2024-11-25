#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ffmpeglib_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    __android_log_write(ANDROID_LOG_INFO, "ffmpeg", "hello world");
    return env->NewStringUTF(hello.c_str());
}