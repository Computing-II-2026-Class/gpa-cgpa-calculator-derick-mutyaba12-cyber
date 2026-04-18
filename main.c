/*
Name: MUTYABA DERICK 
Registration Number: 25/U/BIE/01399/PE
*/

#include <stdio.h>

int main(void) {

    int scores[16];

    int sem1_credits[] = {4,3,3,3,3,3,2,3};
    int sem2_credits[] = {4,3,3,3,3,3,3,3};

    double total_weighted = 0;
    int total_credits = 0;

    /* Input scores */
    for(int i=0;i<16;i++){
        if(scanf("%d",&scores[i])!=1){
            printf("Invalid score entered\n");
            return 1;
        }

        if(scores[i]<0 || scores[i]>100){
            printf("Invalid score entered\n");
            return 1;
        }
    }

    /* Semester I */
    double sem1_weighted = 0;
    int sem1_total_credits = 0;

    for(int i=0;i<8;i++){

        double grade;

        if(scores[i] >= 80) grade = 4.0;
        else if(scores[i] >= 70) grade = 3.0;
        else if(scores[i] >= 60) grade = 2.0;
        else if(scores[i] >= 50) grade = 1.0;
        else grade = 0.0;

        sem1_weighted += grade * sem1_credits[i];
        sem1_total_credits += sem1_credits[i];
    }

    double sem1_gpa = sem1_weighted / sem1_total_credits;

    /* Semester II */

    double sem2_weighted = 0;
    int sem2_total_credits = 0;

    for(int i=0;i<8;i++){

        double grade;

        if(scores[8+i] >= 80) grade = 4.0;
        else if(scores[8+i] >= 70) grade = 3.0;
        else if(scores[8+i] >= 60) grade = 2.0;
        else if(scores[8+i] >= 50) grade = 1.0;
        else grade = 0.0;

        sem2_weighted += grade * sem2_credits[i];
        sem2_total_credits += sem2_credits[i];
    }

    double sem2_gpa = sem2_weighted / sem2_total_credits;

    total_weighted = sem1_weighted + sem2_weighted;
    total_credits = sem1_total_credits + sem2_total_credits;

    double cgpa = total_weighted / total_credits;

    printf("Semester I GPA: %.2f\n", sem1_gpa);
    printf("Semester II GPA: %.2f\n", sem2_gpa);
    printf("CGPA: %.2f\n", cgpa);

    if (cgpa >= 4.40)
        printf("Classification: First Class\n");
    else if (cgpa >= 3.60)
        printf("Classification: Second Class Upper\n");
    else if (cgpa >= 2.80)
        printf("Classification: Second Class Lower\n");
    else if (cgpa >= 2.00)
        printf("Classification: Pass\n");
    else
        printf("Classification: Fail\n");

    return 0;
}
