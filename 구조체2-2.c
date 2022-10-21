#include <stdio.h>  //stdio 라이브러리
#include <string.h> //string 라이브러리
#include <stdlib.h> //stdlib 라이브러리

// 1차 인증시험 대비 문제 풀이입니다. 

typedef struct student{
    char name[21];
    int kor, eng, mat;
    double avg;
}student;

void read_data(student *pst, int N);
void sort_score(student *pst, int N);
student *select_out(student *pst1, student *pst2, int N);

int main()
{
    student std1[49], std2[49], *Output, *p;
    int n;
    scanf("%d", &n);
    getchar();

    read_data(std1, n);
    read_data(std2, n);

    sort_score(std1, n);
    sort_score(std2, n);

    Output = select_out(std1, std2, n);

    for(p=Output; p<Output+n; p++){
        printf("%s %d %d %d %.1lf\n", p->name, p->kor, p->eng, p->mat, p->avg);
    }
    


    return 0;
}
void read_data(student *pst, int N){
    student *p;
    for(p=pst; p<pst+N; p++){
        scanf("%s", p->name);
        scanf("%d %d %d", &p->kor, &p->eng, &p->mat);
        getchar();
        p->avg = (p->kor + p->eng + p->mat) / 3.0;
    }
}
void sort_score(student *pst, int N){
    student *p, tmp;
    int i;

    for(i=0; i<N-1; i++){
        for(p=pst; p<pst+N-1; p++){
            if(p->avg < (p+1)->avg){
                tmp = *p;
                *p = *(p+1);
                *(p+1) = tmp;
            }
            else if(p->avg == (p+1)->avg){
                if(p->kor < (p+1)-> kor){
                    tmp = *p;
                    *p = *(p+1);
                    *(p+1) = tmp;
                }
                else if(p->kor == (p+1)->kor){
                    if(p->eng < (p+1)->eng){
                        tmp = *p;
                        *p = *(p+1);
                        *(p+1) = tmp;
                    }
                }
            }
        }
    }
}
student *select_out(student *pst1, student *pst2, int N){
    if((pst1+(N/2))->avg > (pst2+(N/2))->avg){
        return pst1;
    }
    else    return pst2;
}
// 1차 인증시험 대비 문제풀이입니다.