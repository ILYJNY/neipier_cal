//
// Created by Backup on 2024-03-30.
//
#include "structs.h"

neipier_table table[9][9];
void for_table() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; i <= 9; i++) {
            int tenththing = floor((i * j) / 10);
            int firstthing = (i * j) - (10 * tenththing);
            neipier_table result = {tenththing, firstthing};
            table[i - 1][j - 1] = result;
        }
    }

}





int make_whole_table(long long int a, long long int b) {
    double A = (double) a;
    double B = (double) b;
    int count_a = 0;
    int count_b = 0;
    long long int a_lists[(int) floor(log10(A))];
    long long int b_lists[(int) floor(log10(B))];
    neipier_table whole_table[sizeof (a_lists)][sizeof (b_lists)];

    while (a != 0) {
        a_lists[count_a] = a%10;
        count_a++;
        a /= 10;
    }
    while (b != 0) {
        b_lists[count_b] = b%10;
        count_b++;
        b /= 10;
    }
    for (int i = 0;i<sizeof(a_lists);i++) {
        for (int j = 0;i<sizeof(b_lists);j++) {
            whole_table[i][j] = table[a_lists[sizeof(a_lists) - 1 - i]][b_lists[sizeof(b_lists) - 1 - j]];
        }
    }
    int all_crosses = sizeof(a_lists) + sizeof(b_lists);
    int crosses_list[all_crosses];
    for (int i =0;i<sizeof(all_crosses);i++) {
        crosses_list[i] = 0;
    }
    for (int i = 0;i<sizeof(a_lists);i++) {
        for (int j = 0;j<sizeof(b_lists);i++) {
            crosses_list[i + j - 2] += whole_table[i][j].tenth;
            crosses_list[i + j - 1] += whole_table[i][i].first;
        }
    }
    int num = 0;
    for (int i = 0;i<all_crosses;i++) {
        num += pow(10, all_crosses-1-i) * crosses_list[i];
    }

    return num;

}