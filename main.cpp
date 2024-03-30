#include <iostream>
//#include "for_table.cpp"


#include "cmath"


struct neipier_table {
    int tenth;
    int first;
};

struct for_cross {
    int num;
    int cross;
};


neipier_table table[10][10];
void for_table() {
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            printf("%s %d %d\n", "i, j", i, j);
            int tenththing = floor((i * j) / 10);
            int firstthing = (i * j) - (10 * tenththing);
            printf("%s %d %d\n", "set table", tenththing, firstthing);
            neipier_table result = {tenththing, firstthing};
            printf("%s\n", "check input table result");
            table[i][j] = result;
            printf("%s\n", "check input result");
        }
    }
    printf("%s\n", "check for_table end");

}





int make_whole_table(int a, int b) {
    int count_a = 0;
    int count_b = 0;
    int length_a_lists = (int) floor(log10(a)) + 1;
    int length_b_lists = (int) floor(log10(b)) + 1;
    int a_lists[(int) floor(log10(a))];
    int a_save_lists[(int) floor(log10(a))];
    printf("%s %d\n", "length of a_list", length_a_lists);
    int b_lists_[(int) floor(log10(b))];
    printf("%s %d\n", "length of b_list", length_b_lists);
    neipier_table whole_table[(int) floor(log10(b)) + 1][(int) floor(log10(b)) + 1];
    printf("%s %d %d\n","check whole_table", (int) floor(log10(a)) + 1, (int) floor(log10(b)) + 1);

    while (a != 0) {
        a_lists[count_a] = a%10;
        a_save_lists[count_a] = a%10;
        printf("%s %d %d\n", "check a_list", a%10, count_a);
        count_a++;
        a /= 10;
    }
    printf("%s\n", "check set a_lists a");

//    for (int i =0;i<count_a;i++) {
//        a_lists[i] = a_save_lists[i];
//        printf("%s %d\n", "check is ok", a_lists[i]);
//    }

    while (b != 0) {

//        for (int i =0;i<count_a;i++) {
//            a_lists[i] = a_lists[i];
//            printf("%s %d\n", "check is ok", a_lists[i]);
//        }

        printf("%s %d\n", "check in b loop a_list b4", a_lists[count_b]);
        b_lists_[count_b] = b%10;
        printf("%s %d\n", "b_list", b_lists_[count_b]);

        printf("%s %d\n", "check in b loop a_list", a_lists[count_b]);
        printf("%s %d %d\n", "check b_list", b%10, count_b);
        count_b++;
        b /= 10;
    }

    for (int i =0;i<count_a;i++) {
        a_lists[i] = a_lists[i];
        printf("%s %d\n", "check is ok", a_lists[i]);
    }


    printf("%s\n", "check set b_lists b");
    for (int i = 0;i<length_a_lists;i++) {
        for (int j = 0;j<length_b_lists;j++) {



//            printf("%s %d %d\n", "i, j", i, j);
//            printf("%s %d\n", "?", length_a_lists - 1 - i);
//            printf("%s %d\n", "??", a_lists[0]);
            printf("%s %d\n", "check a_lists input", a_lists[length_a_lists - 1 - i]);
            printf("%s %d\n", "check b_lists input", b_lists_[length_b_lists - 1 - j]);
            whole_table[i][j] = table[a_lists[length_a_lists - 1 - i]][b_lists_[length_b_lists - 1 - j]];
            printf("%s %d %d\n", "set whole_table", table[a_lists[length_a_lists - 1 - i]][b_lists_[length_b_lists - 1 - j]].tenth, table[a_lists[length_a_lists - 1 - i]][b_lists_[length_b_lists - 1 - j]].first);
        }
    }
    printf("%s\n", "set whole_table");
    int all_crosses = length_a_lists + length_b_lists;
    int crosses_list[all_crosses];
    for (int i =0;i<all_crosses;i++) {
        crosses_list[i] = 0;
    }
    printf("%s\n", "set crosses_list all null");
    for (int i = 0;i<length_a_lists;i++) {
        for (int j = 0;j<length_b_lists;j++) {
            printf("%s %d %d\n", "tenth, first", whole_table[i][j].tenth, whole_table[i][i].first);
            crosses_list[i + j] += whole_table[i][j].tenth;
            crosses_list[i + j+1] += whole_table[i][j].first;
        }
    }
    printf("%s\n", "set crosses list summation");
    int num = 0;
    for (int i = 0;i<all_crosses;i++) {
        num += pow(10, all_crosses-1-i) * crosses_list[i];
        printf("%s %d\n", "check before num" ,(int) pow(10, all_crosses-1-i) * crosses_list[i]);
    }
    printf("%s\n", "set print to normalize");

    return num;

}





int main() {
    int a;
    int b;
    for_table();
    printf("%s\n", "1st");
    scanf("%d", &a);
    printf("%s\n", "2nd");
    scanf("%d", &b);
    int result = make_whole_table(a, b);
    printf("%s %d %d\n", "a, b", a, b);
    printf("%s %d %s %d\n", "neipier_result : ",result, "the_result : ", a * b);
    return 0;
}
