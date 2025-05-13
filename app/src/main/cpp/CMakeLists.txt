cmake_minimum_required(VERSION 3.10.2)

project("ffmpegwrapper")

add_library(ffmpegwrapper SHARED
    ffmpegwrapper.cpp
    # 他にも必要なFFmpegの.c/.cppを追加する場合
)

# FFmpegライブラリとリンク（libffmpeg.a等）
# ここに必要なFFmpegのソースまたはlibを指定
# 例: target_link_libraries(ffmpegwrapper libavcodec libavformat ...)

find_library(log-lib log)
target_link_libraries(ffmpegwrapper ${log-lib})