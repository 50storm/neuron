#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define INPUTNO 2
#define MAXINPUTNO 100

double f(double u);
void initw(double w[INPUTNO+1]);
double forward( double w[INPUTNO + 1],
                double e[INPUTNO]
              );
int getdata(double e[][INPUTNO]);

int main()
{
    double w[INPUTNO + 1]; //重みとしきいち
    double e[MAXINPUTNO][INPUTNO];//データセット
    double o; // 出力

    int i,j;
    int n_of_e;

    initw(w);

    n_of_e = getdata(e);

    printf("データの個数:%d\n", n_of_e );

    //計算本体
    for(i=0; i<n_of_e; ++i){
      printf("%d ", i);
      for(j=0; j<INPUTNO; ++j){
        printf("%lf ", e[i][j] );
      }
      o=forward(w, e[i]);
      printf("%lf\n", o);
    }

    return 0;
}

//学習データ読み込み
int getdata( double e[][INPUTNO] ){
  int n_of_e = 0; //学習データセットの個数
  int j = 0;

  while (scanf("%lf", &e[n_of_e][j]) != EOF) {
    ++j;
    if( j>= INPUTNO){
      j=0;
      ++n_of_e;

    }
  }

  return n_of_e;
}


//forward関数
double forward(double w[INPUTNO+1], double e[INPUTNO])
{
  int i;
  double u,o;

  u = 0;
  for(i = 0; i<INPUTNO ; ++i){
    u+=e[i]*w[i];
  }
  u-=w[i];  //しきい値の処理

  //出力計算
  o = f(u);

  return o;

}

//重みの初期化
void initw(double w[INPUTNO + 1]){
  w[0] = 1;
  w[1] = 1;
  w[2] = 1.5;
}


//伝搬関数
double f(double u){
  //ステップ関数
  if( u>=0 ) return 1.0;
  else return 0.0;

  //シグモイド関数
  // return 1.0/(1.0+exp(-u))

}
