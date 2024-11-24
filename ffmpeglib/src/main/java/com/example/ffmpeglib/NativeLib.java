package com.example.ffmpeglib;

public class NativeLib {

    // Used to load the 'ffmpeglib' library on application startup.
    static {
        System.loadLibrary("avcodec");
        System.loadLibrary("ffmpeglib");
    }

    /**
     * A native method that is implemented by the 'ffmpeglib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}