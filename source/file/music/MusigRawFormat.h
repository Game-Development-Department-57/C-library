#ifndef FUJIWARA_FILE_MUSIGRAWFORMAT_H
#define FUJIWARA_FILE_MUSIGRAWFORMAT_H

#include "data/ftype.h"

typedef struct tagMusicRawHeader
{
  FDWORD SamplingRate;     /* 標本化周波数 */
  FDWORD QuantizationRate; /* 量子化ビット数 */
  FDWORD DataLength;       /* データセクション長さ */
  FDWORD Flags;            /* セクションフラグ */
} MusicRawHeader;          /* MusicRawのヘッダー */

typedef struct tagMusicRawData
{
  FBYTE* Data;             /* データ */
} MusicRawData;            /* MusicRawのデータ */

typedef struct tagMusicRawList
{
  FBYTE* FileName;
  FBYTE* AuthorName;
  FBYTE* Date;
  FBYTE* Comment;
} MusicRawList;

typedef struct tagMusicRaw
{
  MusicRawHeader* Header;  /* ヘッダー */
  MusicRawData*   Data;    /* データ */
  MusicRawList*   List;    /* リスト */
} MusicRaw;                /* 音楽の加工用生データ */

#endif
