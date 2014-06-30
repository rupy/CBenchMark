//
//  bench.c
//  CppBenchMark
//
//

#include <stdio.h>
#include <time.h>

#define BENCHMARK_SIZE 1000000000
#define BENCHMARK_TIMES 10

long benchmarkAdd();
long benchmarkSub();
long benchmarkMul();
long benchmarkDiv();
long benchmarkFloatAdd();
long benchmarkFloatSub();
long benchmarkFloatMul();
long benchmarkFloatDiv();

int main(int argc, const char * argv[])
{
    // 加算
    double time_average = 0;
    int i;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_average += (double) benchmarkAdd() / BENCHMARK_TIMES;
    }
    printf("整数加算：%f(ms)\n", time_average);
    
    // 減算
    time_average = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_average += (double) benchmarkSub() / BENCHMARK_TIMES;
    }
    printf("整数減算：%f(ms)\n", time_average);
    
    // 乗算
    time_average = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_average += (double) benchmarkMul() / BENCHMARK_TIMES;
    }
    printf("整数乗算：%f(ms)\n", time_average);
    
    // 除算
    time_average = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_average += (double) benchmarkDiv() / BENCHMARK_TIMES;
    }
    printf("整数除算：%f(ms)\n", time_average);
    
    // 浮動小数点加算
    time_average = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_average += (double) benchmarkFloatAdd() / BENCHMARK_TIMES;
    }
    printf("浮動小数点加算：%f(ms)\n", time_average);
    
    // 浮動小数点減算
    time_average = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_average += (double) benchmarkFloatSub() / BENCHMARK_TIMES;
    }
    printf("浮動小数点減算：%f(ms)\n", time_average);
    
    // 浮動小数点乗算
    time_average = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_average += (double) benchmarkFloatMul() / BENCHMARK_TIMES;
    }
    printf("浮動小数点乗算：%f(ms)\n", time_average);
    
    // 浮動小数点除算
    time_average = 0;
    for(i = 0; i < BENCHMARK_TIMES; ++i){
        time_average += (double) benchmarkFloatDiv() / BENCHMARK_TIMES;
    }
    printf("浮動小数点除算：%f(ms)\n", time_average);



}




/**
 * 加算のベンチマーク
 * @return 計測時間(ms)
 */
long benchmarkAdd(){
    long start_time, end_time;
    long a = 0;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a += i;
        a = 0;
    }
    end_time = clock();
    return (end_time - start_time);
}

/**
 * 減算のベンチマーク
 * @return 計測時間(ms)
 */
long benchmarkSub(){
    long start_time, end_time;
    long a = 0;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a -= i;
        a = 0;
    }
    end_time = clock();
    return (end_time - start_time);
}

/**
 * 乗算のベンチマーク
 * @return 計測時間(ms)
 */
long benchmarkMul(){
    long start_time, end_time;
    long a = 1;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a *= i;
        a = 0;
    }
    end_time = clock();
    return (end_time - start_time);
}

/**
 * 除算のベンチマーク
 * @return 計測時間(ms)
 */
long benchmarkDiv(){
    long start_time, end_time;
    long a = 1;
    long i;
    
    start_time = clock();
    for(i = 1; i < BENCHMARK_SIZE + 1; ++i){ // 0除算を避ける
        a /= i;
        a = 0;
    }
    end_time = clock();
    return (end_time - start_time);
}

/**
 * 加算のベンチマーク
 * @return 計測時間(ms)
 */
long benchmarkFloatAdd(){
    long start_time, end_time;
    float a = 0;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a += i;
        a = 0.0f;
    }
    end_time = clock();
    return (end_time - start_time);
}

/**
 * 減算のベンチマーク
 * @return 計測時間(ms)
 */
long benchmarkFloatSub(){
    long start_time, end_time;
    float a = 0;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a -= i;
        a = 0.0f;
    }
    end_time = clock();
    return (end_time - start_time);
}

/**
 * 乗算のベンチマーク
 * @return 計測時間(ms)
 */
long benchmarkFloatMul(){
    long start_time, end_time;
    float a = 1;
    long i;
    
    start_time = clock();
    for(i = 0; i < BENCHMARK_SIZE; ++i){
        a *= i;
        a = 0.0f;
    }
    end_time = clock();
    return (end_time - start_time);
}

/**
 * 除算のベンチマーク
 * @return 計測時間(ms)
 */
long benchmarkFloatDiv(){
    long start_time, end_time;
    float a = 1;
    long i;
    
    start_time = clock();
    for(i = 1; i < BENCHMARK_SIZE + 1; ++i){ // 0除算を避ける
        a /= i;
        a = 0.0f;
    }
    end_time = clock();
    return (end_time - start_time);
}
