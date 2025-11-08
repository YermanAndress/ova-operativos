#include <jni.h>
#include <stdlib.h>
#include "jni_InfoCpu.h"

int strsize(const char* str){
    int size = 0;
    for(; str[size] != '\0'; size++);
    return size;
}

void strcopy(char* destino, const char* src){
    int srcSize = strsize(src);
    int i = 0;
    for(; i < srcSize; i++){
        destino[i] = src[i];
    }
    destino[i] = '\0';''
}

void strcat(char* destino, const char* src){
    int destinoSize =  strsize(destino);
    int srcSize = strsize(src);
    int i = destinoSize;
    for(; i < destinoSize + srcSize - 1; i++){
        destino[i] = src[i-destinoSize];
    }
    destino[i] = '\0';
}

/*
 * Class:     jni_InfoCpu
 * Method:    getInfoCpu
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_jni_InfoCpu_getInfoCpu
  (JNIEnv *env, jobject obj){
    char* cpuStr = (char*) malloc(100000*sizeof(char));// 100 mill caracteres maximo
    if(cpuStr == NULL) return NULL;
    strcopy(cpuStr, "");
    FILE* cpuinfo = fopen("/proc/cpuinfo", "r");
    int size;
    char* line;
    getline(&line, &size, cpuinfo);
    strcopy(cpuStr, line);
    while(!feof(cpuinfo)){
        getline(&line, &size, cpuinfo);
        strcat(cpuStr, line);
    }
    jstring respuesta = (*env)->NewStringUTF(env, cpuStr);
    free(cpuStr);
    fclose(cpuinfo);
    return respuesta;
  }
