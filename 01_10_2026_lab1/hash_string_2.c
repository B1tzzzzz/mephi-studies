#include <stdio.h>
#include <stdlib.h>
#define BASE 61
#define MOD (1e9 + 9)
#define MINCHAR 65
typedef struct {
    char *str;
    size_t lenght;
    size_t capacity;
} string;

void print_int_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void print_char_array(char* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}
int* make_hash(int n, char *str) {
    int *res = (int*)malloc(n * sizeof(int));
    if (res == NULL) {
        fprintf(stderr, "Error allocating memory.");
        return NULL;
    }
    res[0] = str[0] - MINCHAR + 1;
    for (int i = 1; i < n; i++) {
        res[i] = (((1ll * res[i - 1] * BASE) % (long long)MOD) + str[i] - MINCHAR + 1) % (long long)MOD;
    }
    return res;
}

int get_hash(int l, int r, int* hash, int* basePow) {
    if (!l) 
        return hash[r];
    int res = hash[r] - (1ll * hash[l - 1] * basePow[r - l + 1]) % (long long)MOD;
    return (res < 0 ? res + (int)MOD : res);
}

int push_back(string *s, char ch) {
    if (s->lenght + 1 >= s->capacity) {
        s->capacity *= 2;
        char *tmp = (char*)realloc(s->str, s->capacity);
        if (tmp == NULL) {
            fprintf(stderr, "Error allocating memory.");
            //free(s->str);
            return -1;
        }
        s->str = tmp;
    }
    s->str[s->lenght++] = ch;
    return 0;
}

int* calc_base_power(int n) {
    int *res = (int*)malloc(n * sizeof(int));
    if (res == NULL) {
        fprintf(stderr, "Error allocating memory.");
        return NULL;
    }
    res[0] = 1;
    for (int i = 1; i < n; i++) {
        res[i] = (int)((1ll * res[i - 1] * BASE) % (long long)MOD);
    }
    return res;
}
int main() {
    string s1 = {NULL, 0, 16}, s2 = {NULL, 0, 16};
    s1.str = (char*)malloc(s1.capacity);
    if (s1.str == NULL) {
        fprintf(stderr, "Error allocating memory.");
        return 12;
    }

    s2.str = (char*)malloc(s2.capacity);
    if (s2.str == NULL) {
        fprintf(stderr, "Error allocating memory.");
        return 12;
    }

    char current; 
    //printf("Enter the smallest string: ");
    while (scanf("%c", &current) == 1 && current != '\n') {
        if (push_back(&s1, current) == -1) {
            return 12;
        }
    }
    s1.str[s1.lenght] = '\0';

    //printf("Enter the biggest string: ");
    while (scanf("%c", &current) == 1 && current != '\n') {
        if (push_back(&s2, current) == -1) {
            return 12;
        }
    }
    
    s2.str[s2.lenght] = '\0';
    if (1) { //чтобы |s1| < |s2| если пользователь дурачокs1.lenght > s2.lenght
        char *tmpStr = s1.str;
        s1.str = s2.str;
        s2.str = tmpStr;

        int tmpLenght = s1.lenght;
        s1.lenght = s2.lenght;
        s2.lenght = tmpLenght;

        int tmpCapacity = s1.capacity;
        s1.capacity = s2.capacity;
        s2.capacity = tmpCapacity;
        //free(tmpStr);
    }

    //print_char_array(s1.str, s1.lenght);
    //print_char_array(s2.str, s2.lenght);
    const int maxStrSize = s2.lenght, minStrSize = s1.lenght;
    int *basePower = calc_base_power(maxStrSize);
    if (basePower == NULL) {
        fprintf(stderr, "Error allocating memory.");
        return 12;
    }
    
    int* ans = (int*)malloc((maxStrSize - minStrSize + 1) * sizeof(int));
    if (ans == NULL) {
        fprintf(stderr, "Error allocating memory.");
        return 12;
    }
    int lenghtAns = 0;
    int *hash1 = make_hash(s1.lenght, s1.str), *hash2 = make_hash(s2.lenght, s2.str);
    if (hash1 == NULL) {
        fprintf(stderr, "Error allocating memory.");
        return 12;
    }
    if (hash2 == NULL) {
        fprintf(stderr, "Error allocating memory.");
        return 12;
    }
    //print_int_array(hash1, s1.lenght);
    //print_int_array(hash2, s2.lenght);
    for (int i = 0; i < maxStrSize - minStrSize + 1; i++) {
        if (get_hash(0, s1.lenght - 1, hash1, basePower) == get_hash(i, i + s1.lenght - 1, hash2, basePower)) {
            ans[lenghtAns++] = i + 1;
        }
    }

    if (!lenghtAns) {
        //printf("The smallest string is not a substring of the biggest string.");
        printf("0");
    }
    else {
        printf("%d\n", lenghtAns);
        //printf("The smallest string is a substring of the biggest string in positions: ");
        for (int i = 0; i < lenghtAns - 1; i++) {
            printf("%d ", ans[i]); 
        }
        printf("%d", ans[lenghtAns - 1]);
    }
    return 0;
}