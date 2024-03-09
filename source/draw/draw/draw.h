#ifndef F_DRAW_DRAW_H
#define F_DRAW_DRAW_H

#include "binary/binary.h" /* library/binary/binary.h */

typedef struct tagDrawColor
{
  FBYTE Red;
  FBYTE Green;
  FBYTE Blue;
  FBYTE Alpha;
} drawColor;

typedef struct tagDrawRawImage
{
  int        x;
  int        y;
  drawColor* image;
} drawRawImage;

typedef struct tagDrawPoint
{
  int x;
  int y;
} drawPoint, drawSize;

/* 
Init関数
  説明   : RawImageデータの作成
  1      : drawSize イメージのサイズ
  戻り値 : RawImageデータ
Delete関数
  説明   : RawImageデータの削除
  1      : RawImageデータ
  戻り値 : 無し
Fill関数
  説明   : イメージの指定された領域を塗りつぶす
  1      : RawImageデータ
  2      : 指定領域の左上
  3      : 指定領域の幅と高さ(右下から左上の座標を差し引いた大きさ)
  4      : 色
  戻り値 : 無し
AllFill関数
  説明   : イメージ全体を塗りつぶす
  1      : RawImageデータ
  2      : 色
  戻り値 : 無し
Pointing関数
  説明   : 点を描画
  1      : RawImageデータ
  2      : 指定位置
  3      : 色
  戻り値 : 無し
Triangle関数
  説明   : 三角形を描画(塗りつぶし)
  1      : RawImageデータ
  2      : 頂点1
  3      : 頂点2
  4      : 頂点3
  5      : 色
  戻り値 : 無し
Quadrangle関数
  説明   : 四角形を描画(塗りつぶし)
  1      : RawImageデータ
  2      : 頂点1
  3      : 頂点2
  4      : 頂点3
  5      : 頂点4
  6      : 色
  戻り値 : 無し
TriangleSide関数
  説明   : 三角形を描画(幅指定型)
  1      : RawImageデータ
  2      : 頂点1
  3      : 頂点2
  4      : 頂点3
  5      : 幅
  6      : 色
  戻り値 : 無し
QuadrangleSide関数
  説明   : 四角形を描画(幅指定型)
  1      : RawImageデータ
  2      : 頂点1
  3      : 頂点2
  4      : 頂点3
  5      : 頂点4
  6      : 幅
  7      : 色
  戻り値 : 無し
Cut関数
  説明   : 切り取る
  1      : RawImageデータ
  2      : 指定領域の左上
  3      : 指定領域の幅と高さ(右下から左上の座標を差し引いた大きさ)
  戻り値 : RawImageデータ
Scaling関数
  説明   : 拡縮する
  1      : RawImageデータ
  2      : 拡縮後のサイズ
  戻り値 : RawImageデータ
 */

#define drawImageIndex(image_, x_, y_) (y_ * image_->x + x_)

drawRawImage* drawInit          (drawSize size);
void          drawDelte         (drawRawImage* image);
void          drawFill          (drawRawImage* image, drawPoint point , drawSize size, drawColor color);
void          drawAllFill       (drawRawImage* image, drawColor color);
void          drawPointing      (drawRawImage* image, drawPoint point , drawColor color);
void          drawTriangle      (drawRawImage* image, drawPoint point1, drawPoint point2, drawPoint point3, drawColor color);
void          drawQuadrangle    (drawRawImage* image, drawPoint point1, drawPoint point2, drawPoint point3, drawPoint point4, drawColor color);
void          drawTriangleSide  (drawRawImage* image, drawPoint point1, drawPoint point2, drawPoint point3, int width, drawColor color);
void          drawQuadrangleSide(drawRawImage* image, drawPoint point1, drawPoint point2, drawPoint point3, drawPoint point4, int width, drawColor color);
drawRawImage* drawCut           (drawRawImage* image, drawPoint point1, drawPoint point2);
drawRawImage* drawScaling       (drawRawImage* image, drawPoint point1);

#endif
