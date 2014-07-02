//
//  bench.c
//
//

#include <stdio.h>
#include <time.h>

#define BENCHMARK_SIZE 100000000 // １億
#define BENCHMARK_TIMES 100

double benchmarkAdd();
double benchmarkSub();
double benchmarkMul();
double benchmarkDiv();
double benchmarkFloatAdd();
double benchmarkFloatSub();
double benchmarkFloatMul();
double benchmarkFloatDiv();
double benchmarkCallFunc();
int emptyFunc();

int main(int argc, const char * argv[])
{
    // 加算
    double time_sum = 0;
    int i;

    // CPUの準備
    for(i = 0; i < 1000000; ++i);

    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_sum += benchmarkAdd();
    }
    printf("整数加算：%f(s)\n", time_sum / BENCHMARK_TIMES);
    
    // 減算
    time_sum = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_sum += benchmarkSub();
    }
    printf("整数減算：%f(s)\n", time_sum / BENCHMARK_TIMES);
    
    // 乗算
    time_sum = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_sum += benchmarkMul();
    }
    printf("整数乗算：%f(s)\n", time_sum / BENCHMARK_TIMES);
    
    // 除算
    time_sum = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_sum += benchmarkDiv();
    }
    printf("整数除算：%f(s)\n", time_sum / BENCHMARK_TIMES);
    
    // 浮動小数点加算
    time_sum = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_sum += benchmarkFloatAdd();
    }
    printf("実数加算：%f(s)\n", time_sum / BENCHMARK_TIMES);
    
    // 浮動小数点減算
    time_sum = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_sum += benchmarkFloatSub();
    }
    printf("実数減算：%f(s)\n", time_sum / BENCHMARK_TIMES);
    
    // 浮動小数点乗算
    time_sum = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_sum += benchmarkFloatMul();
    }
    printf("実数乗算：%f(s)\n", time_sum / BENCHMARK_TIMES);
    
    // 浮動小数点除算
    time_sum = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_sum += benchmarkFloatDiv();
    }
    printf("実数除算：%f(s)\n", time_sum / BENCHMARK_TIMES);

    // 関数呼び出し
    time_sum = 0;
    for(int i = 0; i < BENCHMARK_TIMES; ++i){
        time_sum += benchmarkCallFunc();
    }
    printf("関数呼出：%f(s)\n", time_sum / BENCHMARK_TIMES);

}




/**
 * 加算のベンチマーク
 * @return 計測時間(ms)
 */
double benchmarkAdd(){
    clock_t start_time, end_time;
    volatile long a = 0;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a += i;
        a = 0;
    }
    end_time = clock();
    return (double)(end_time - start_time)/CLOCKS_PER_SEC;
}

/**
 * 減算のベンチマーク
 * @return 計測時間(ms)
 */
double benchmarkSub(){
    clock_t start_time, end_time;
    volatile long a = 0;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a -= i;
        a = 0;
    }
    end_time = clock();
    return (double)(end_time - start_time)/CLOCKS_PER_SEC;
}

/**
 * 乗算のベンチマーク
 * @return 計測時間(ms)
 */
double benchmarkMul(){
    clock_t start_time, end_time;
    volatile long a = 1;
    long i, j;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a *= i;
        a = 0;
    }
    end_time = clock();
    return (double)(end_time - start_time)/CLOCKS_PER_SEC;
}

/**
 * 除算のベンチマーク
 * @return 計測時間(ms)
 */
double benchmarkDiv(){
    clock_t start_time, end_time;
    volatile long a = 1;
    long i;
    
    start_time = clock();
    for(i = 1; i < BENCHMARK_SIZE + 1; ++i){
        a /= i;
        a = 0;
    }
    end_time = clock();
    return (double)(end_time - start_time)/CLOCKS_PER_SEC;
}

/**
 * 加算のベンチマーク
 * @return 計測時間(ms)
 */
double benchmarkFloatAdd(){
    clock_t start_time, end_time;
    volatile float a = 0;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a += i;
        a = 0;
    }
    end_time = clock();
    return (double)(end_time - start_time)/CLOCKS_PER_SEC;
}

/**
 * 減算のベンチマーク
 * @return 計測時間(ms)
 */
double benchmarkFloatSub(){
    clock_t start_time, end_time;
    volatile float a = 0;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a -= i;
        a = 0;
    }
    end_time = clock();
    return (double)(end_time - start_time)/CLOCKS_PER_SEC;
}

/**
 * 乗算のベンチマーク
 * @return 計測時間(ms)
 */
double benchmarkFloatMul(){
    clock_t start_time, end_time;
    volatile float a = 1;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a *= i;
        a = 0;
    }
    end_time = clock();
    return (double)(end_time - start_time)/CLOCKS_PER_SEC;
}

/**
 * 除算のベンチマーク
 * @return 計測時間(ms)
 */
double benchmarkFloatDiv(){
    clock_t start_time, end_time;
    volatile float a = 1;
    long i;
    
    start_time = clock();
    for(i = 1; i < BENCHMARK_SIZE + 1; ++i){
        a /= i;
        a = 0;
    }
    end_time = clock();
    return (double)(end_time - start_time)/CLOCKS_PER_SEC;
}

/**
 * 関数呼び出しのベンチマーク
 * @return 計測時間(ms)
 */
double benchmarkCallFunc(){
    clock_t start_time, end_time;
    volatile int a = 1;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a = emptyFunc();

    }
    end_time = clock();
    return (double)(end_time - start_time)/CLOCKS_PER_SEC;
}

/**
 * 空の関数
 * @return 1
 */
int emptyFunc(){
   return 10 ;
}
