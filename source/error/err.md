# errライブラリについて
## 目次
[割り当て規則](#割り当て規則)
[関数群](#関数群)
[定数群](#定数群)

## 割り当て規則
err型(int型)の32bitを次のように利用する。  
|   範囲   |  幅   |     用途     |   別名   |
|---------:|------:|:-------------|:---------|
|    31bit | 1bit  | 正負のフラグ | Sign     |
| 30-24bit | 7bit  | 予約領域     | Reserved |
| 23-12bit | 12bit | クラス       | Record-A |
| 11-0bit  | 12bit | 詳細         | Record-B |
  
基本的にエラーの割り当ては、負の値であるため正の値が割り当てられるのは特殊な場合である。  
0x00000000は必ずSUCCESSである。  
  
関数群と定数群の実体はマクロである。  

## 関数群
|       function      |     説明     |
|:-------------------:|:------------:|
| errGetSign(err)     |   Sign取得   |
| errGetReserved(err) | Reserved取得 |
| errGetRecordA(err)  | Record-A取得 |
| errGetRecordB(err)  | Record-B取得 |
| errSetSign(err)     |   Sign代入   |
| errSetReserved(err) | Reserved代入 |
| errSetRecordA(err)  | Record-A代入 |
| errSetRecordB(err)  | Record-B代入 |

## 定数群
|      define      |         説明         |
|:----------------:|:--------------------:|
| errMaskSign      |      Signのマスク    |
| errMaskReserved  |   Reservedのマスク   |
| errMaskRecordA   |   Record-Aのマスク   |
| errMaskRecordB   |   Record-Bのマスク   |
| errShiftSign     |   Signのオフセット   |
| errShiftReserved | Reservedのオフセット |
| errShiftRecordA  | Record-Aのオフセット |
| errShiftRecordB  | Record-Bのオフセット |
