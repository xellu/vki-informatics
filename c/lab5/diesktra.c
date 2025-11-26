#include <stdio.h>

void print(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;
    printf("n=");
    scanf("%d", &n);

    int a[n];        //cisla na prehazovani
    int dir[n];      //smer kazdyho elementu (1 - do prava, -1 - do leva)

    //inicializace
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = -1;
    }

    print(a, n);

    while (1) {
        int mobile = -1;
        int mobileIndex = -1;

        //hledame nejvetsi hybajici se cislo
        for (int i = 0; i < n; i++) {
            int next = i + dir[a[i] - 1];
            if (next >= 0 && next < n && a[i] > a[next]) {
                if (a[i] > mobile) {
                    mobile = a[i];
                    mobileIndex = i;
                }
            }
        }

        if (mobile == -1)
            break; //prohazovani skoncilo

        //prohazujeme mistami hybajici se cislo se svym sousedem 
        int i = mobileIndex;
        int j = i + dir[a[i] - 1];

        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;

        //obnovujeme index hybajiciho se cisla
        mobileIndex = j;

        //po prehozeni menime smer vsech cisel > mobile
        for (int k = 0; k < n; k++) {
            if (a[k] > mobile) {
                dir[a[k] - 1] *= -1;
            }
        }

        print(a, n);
        getchar();
    }

    return 0;
}
