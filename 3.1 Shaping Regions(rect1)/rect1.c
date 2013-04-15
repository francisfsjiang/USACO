/*
ID:The One
TASK:rect1
LANG:C
*/
#include  <stdio.h>
#include  <stdlib.h>
#include  <assert.h>
 
FILE *pfin, *pfout;
int a, b, n;
typedef struct _rect{
    int x1, y1, x2, y2, color;
}rect;
rect r[2500];
int count[2500] = {0};
#define STACK_LEN 10000
rect stack[2][STACK_LEN];
int top[2] = {-1, -1};
rect *p[2] = {stack[0], stack[1]};
rect r1, r2;
 
void divide(const rect *a, const rect *b, int index){
    /* 利用矩阵b将矩阵a切分 */
    /* 矩形不相交 */
    if (a->x1 > b->x2 || a->x2 < b->x1 || a->y1 > b->y2 || a->y2 < b->y1) {
        assert(top[index] < STACK_LEN);
        p[index][++(top[index])] = *a;
        return;
    }
    if (b->x1 > a->x1) {
        /* 1st */
        assert(top[index] < STACK_LEN);
        p[index][++(top[index])] = (rect) {a->x1, (b->y1<a->y1)?a->y1:b->y1, b->x1, a->y2, a->color};
    }
    if (b->y1 > a->y1) {
        /* 2nd */
        assert(top[index] < STACK_LEN);
        p[index][++(top[index])] = (rect) {a->x1, a->y1, (b->x2>a->x2)?a->x2:b->x2, b->y1, a->color};
    }
    if (b->x2 < a->x2) {
        /* 3rd */
        assert(top[index] < STACK_LEN);
        p[index][++(top[index])] = (rect) {b->x2, a->y1, a->x2, (b->y2>a->y2)?a->y2:b->y2, a->color};
    }
    if (b->y2 < a->y2) {
        /* 4th */
        assert(top[index] < STACK_LEN);
        p[index][++(top[index])] = (rect) {(b->x1<a->x1)?a->x1:b->x1, b->y2, a->x2, a->y2, a->color};
    }
}
 
int main() {
    pfin = freopen("rect1.in", "r", stdin);
    pfout = freopen("rect1.out", "w", stdout);
    assert(pfin && pfout);
 
    scanf("%d %d %d\n", &a, &b, &n);
    int i, j;
    i = -1;
    j = i & 0x1;
    p[j][++(top[j])] = (rect) { 0, 0, a, b, 1};
    for (i=0; i<n; i++) {
        scanf("%d %d %d %d %d\n", &r1.x1, &r1.y1, &r1.x2, &r1.y2, &r1.color);
        assert(r1.x1 >= 0 && r1.x2 <= a && r1.y1 >= 0 && r1.y2 <= b);
        /* 利用j轮换两个栈，轮流导入导出 */
        j = i & 0x1;
        while (top[1-j] != -1) {
            r2 = p[1-j][(top[1-j])--];
            divide(&r2, &r1, j);     /* 利用r1将r2切分，将分出来的矩形放到p[j]中 */
        }
        assert(top[j] < STACK_LEN);
        p[j][++(top[j])] = r1;
    }
    while (top[j] != -1) {
        r1 = p[j][(top[j])--];
        count[r1.color] += (r1.x2 - r1.x1) * (r1.y2 - r1.y1);
    }
    for (i=0; i<2500; i++) {
        if (count[i]) {
            printf("%d %d\n", i, count[i]);
        }
    }
 
    fclose(pfin);
    fclose(pfout);
    return 0;
}
