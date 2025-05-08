#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"
#include <immintrin.h>

uint32_t a[16][1024][1024];

uint32_t b[1024][1024];

uint32_t c[16][1024][1024];

uint64_t rdtsc(void)
{
    uint32_t lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

void checksum() {
    uint64_t sum = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 1024; j++) {
            for (int k = 0; k < 1024; k++) {
                sum += c[i][j][k];
            }
        }
    }
    printf("K = %llu\n", sum);
}

void transpose() {
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < i; j++) {
            uint32_t temp = b[i][j];
            b[i][j] = b[j][i];
            b[j][i] = temp;
        }
    }
}

void clear() {
    memset(c, 0, sizeof(c));
}

void mul1() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 1024; j++) {
            for (int k = 0; k < 1024; k++) {
                for (int l = 0; l < 1024; l++) {
                    c[i][j][k] += a[i][j][l] * b[l][k];
                }
            }
        }
    }
    // checksum();
}

void mul2() {
    transpose();
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 1024; j++) {
            for (int k = 0; k < 1024; k++) {
                for (int l = 0; l < 1024; l++) {
                    c[i][j][k] += a[i][j][l] * b[k][l];
                }
            }
        }
    }
    // checksum();
    // transpose();
}

void mul3() {
    transpose();
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 1024; j++) {
            for (int k = 0; k < 1024; k++) {
                __m256i sum = _mm256_setzero_si256(); //计算和
                for (int l = 0; l < 1024; l += 8) {
                    //加载数据
                    __m256i a256 = _mm256_loadu_si256((__m256i*)&a[i][j][l]);
                    __m256i b256 = _mm256_loadu_si256((__m256i*)&b[k][l]);
                    sum = _mm256_add_epi32(sum, _mm256_mullo_epi32(a256, b256)); //向量乘法实现
                }
                uint32_t sum_arr[8];
                _mm256_storeu_si256((__m256i*)sum_arr, sum); //向量的元素分别取出
                for (int l = 0; l < 8; l++) {
                    c[i][j][k] += sum_arr[l];
                }
            }
        }
    }
    // checksum();
}

void test() {
    uint64_t start = rdtsc();
    mul1();
    uint64_t end = rdtsc();
    checksum();
    printf("mul1: %llu\n", end - start);

    clear();
    start = rdtsc();
    mul2();
    end = rdtsc();
    checksum();
    printf("mul2: %llu\n", end - start);
    transpose(); //重置矩阵

    clear();
    start = rdtsc();
    mul3();
    end = rdtsc();
    checksum();
    printf("mul3: %llu\n", end - start);
}

int main() {
    char fname[50];
    //获得矩阵A
    for (int i = 1; i <= 16; i++) {
        sprintf(fname, "E:/Desktop/vector/mat/A%d.txt", i);
        FILE *fp = fopen(fname, "r");
        for (int j = 0; j < 1024; j++) {
            for (int k = 0; k < 1024; k++) {
                fscanf(fp, "%lu", &a[i-1][j][k]);
                // printf("%llu ", a[i-1][j][k]);
            }
        }
        fclose(fp);
    }
    //获得矩阵B
    FILE *fp = fopen("E:/Desktop/vector/mat/B.txt", "r");
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            fscanf(fp, "%lu", &b[i][j]);
            // printf("%llu ", b[i][j]);
        }
    }
    fclose(fp);
    
    test();
}