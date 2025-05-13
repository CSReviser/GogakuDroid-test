#include <jni.h>
#include <string>
#include <vector>
#include <sstream>

// ffmpeg_main 関数があることを想定
extern "C" int ffmpeg_main(int argc, char **argv);

extern "C"
JNIEXPORT jint JNICALL
Java_com_github_naofum_gogakudroid_FFmpegCompatWrapper_runFFmpegCommand(
        JNIEnv *env, jclass clazz, jstring command) {

    const char *cmdStr = env->GetStringUTFChars(command, 0);
    std::string cmd(cmdStr);
    env->ReleaseStringUTFChars(command, cmdStr);

    // スペースで分割（簡易的）
    std::istringstream iss(cmd);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) tokens.push_back(token);

    std::vector<char*> argv;
    for (auto &s : tokens) argv.push_back(&s[0]);
    int argc = argv.size();

    return ffmpeg_main(argc, argv.data());
}