package com.github.naofum.gogakudroid;

public class FFmpegCompatWrapper {
    static {
        System.loadLibrary("ffmpegwrapper"); // libffmpegwrapper.so をロード
    }

    public static native int runFFmpegCommand(String command);
}