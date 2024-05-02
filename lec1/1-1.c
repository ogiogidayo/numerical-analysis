#include <stdio.h>

int main(void) {
    double student_num = 210;
    double n = -36.1157 + student_num * 0.0067;
    int flag, binary = 0;
    int base = 1;
    if (n < 0)
        flag = 1;   // 符号チェック
    int part_int = (int)n;
    double part_double = n - (int)n;
    if (flag == 1) {
        part_int = -part_int;
        part_double = -part_double;
    }
    printf("%d.%f\n", part_int, part_double);

    while(part_int > 0){
        binary = binary + ( part_int % 2 ) * base;
        part_int = part_int / 2;
        base = base * 10;
    }
    printf("%d\n", binary);
    char part_double_binary[33]; // 32 digits + null terminator
    for (int i = 0; i < 23; ++i) {
        part_double *= 2;
        if (part_double >= 1) {
            part_double_binary[i] = '1';
            part_double -= 1;
        } else {
            part_double_binary[i] = '0';
        }
    }
    part_double_binary[32] = '\0';
    printf("%s\n", part_double_binary);

}