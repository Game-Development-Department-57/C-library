#ifndef FSTRING_H
#define FSTRING_H

/* 
date:2023-12-15
name:fstring.h
make:Fujiwara
path:string.fstring
 */

typedef struct tagFString
{
  int   size;       // 使用済み領域
  int   reserved;   // 予約済み領域
  char* string;     // 実体へのポインタ bufferを使う場合はbufferのポインタ
  char  buffer[16]; // 長さ16未満の領域
} FString;

inline int FStringReservedSize(int size);
inline char* FStringAlloc(int size);
FString* FStringInit(int size);
void FStringDelete(FString* string);
FString* FStringSet(char* str);
int FStringReset(FString* string, char* str);
int FStringResize(FString* string, int target_size);
int FStringAutoResize(FString* string);
int FStringFill(FString* string, char charactor);

#include <stdlib.h>
inline int FStringReservedSize(int size)
{
  return 16 * (size / 16 + 1);
}

inline char* FStringAlloc(int size)
{
  return (char*) malloc(sizeof(char) * FStringReservedSize(size));
}

/*
FStringReservedSize 予約領域のサイズ計算
FStringAlloc        予約領域の確保
FStringInit         FStringの生成
FStringDelete       FStringの削除
FStringSet          新規のFStringに文字列を設定
FStringReset        既存のFStringに文字列を設定
FStringResize       FStringの予約領域のサイズ変更
FStringAutoResize   FStringの予約領域の自動変更
FStringFill         文字列を特定の文字で埋める
*/

#endif