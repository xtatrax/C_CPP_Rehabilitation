// 元ソース : https://w.atwiki.jp/yosilove/pages/16.html

#include <al/al.h>
#include <al/alc.h>
//#include <OpenAL/al.h>
//#include <OpenAL/alc.h>
//#include <al.h>
//#include <alc.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>//sleep関数用

int main(){
    ALCdevice *device;
    ALCcontext *context;
    const static int dataSize=22050;
    ALshort data[dataSize];
    ALuint buffer, source;
    int i;

    //デバイスを開く
    device = alcOpenDevice(NULL);
    //コンテキストを生成
    context = alcCreateContext(device, NULL);
    //使用するコンテキストの指定
    alcMakeContextCurrent(context);
    //バッファの生成
    alGenBuffers(1, &buffer);

    //信号を生成する
    for (i = 0; i < dataSize; ++i) {
        data[i] = sin(i * 3.14159 * 2 * 440 / dataSize) * 32767;
    }
    unsigned char dt50p[] = {0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00};
    ALsizei size = sizeof(dt50p);
    //信号をバッファに入れる
    alBufferData(buffer, AL_FORMAT_MONO16, data, sizeof(data), dataSize);
    //alBufferData(buffer, AL_FORMAT_MONO8, dt50p, size, size*440);
    //ソースを生成
    alGenSources(1, &source);
    //バッファからソースを作る
    alSourcei(source, AL_BUFFER, buffer);
    //ソースを再生する
    alSourcePlay(source);
    sleep(1);

    //お片づけ
    alSourceStop(source);
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);
    return 0;
}