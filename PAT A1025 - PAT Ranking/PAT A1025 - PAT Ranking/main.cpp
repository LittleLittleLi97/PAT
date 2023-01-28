//
//  main.cpp
//  PAT A1025 - PAT Ranking
//
//  Created by 97 on 2019/7/17.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct testee {
    char registration_number[13];
    int score;
    int location_number;
}person[30000];

bool cmp(testee a, testee b){
    if (a.score != b.score) return a.score > b.score;
    else return strcmp(a.registration_number, b.registration_number) < 0;
}

int main(){
    int locations;
    scanf("%d", &locations);
    int i = 0;
    int real_location = 1;
    while (locations) {
        int number;
        scanf("%d", &number);
        while (number) {
            scanf("%s %d", person[i].registration_number, &person[i].score);
            person[i].location_number = real_location;
            i++;
            number--;
        }
        locations--;
        real_location++;
    }
    sort(person, person + i, cmp);
    int real_rank = 1;
    int current_rank = 1;
    int local_real_rank[100] = {0};
    int local_current_rank[100] = {0};
    for (int a = 0; a < 100; a++) {
        local_real_rank[a] = 1;
        local_current_rank[a] = 1;
    }
    int local_sg_score[100] = {0};
    printf("%d\n", i);
    for (int j = 0; j < i; j++) {
        printf("%s %d %d %d\n", person[j].registration_number, current_rank, person[j].location_number, local_current_rank[person[j].location_number]);
        real_rank++;
        local_real_rank[person[j].location_number]++;
        local_sg_score[person[j].location_number] = person[j].score;
        if (person[j+1].score != person[j].score) {
            current_rank = real_rank;
        }
        if (person[j+1].score != local_sg_score[person[j+1].location_number]) {
            local_current_rank[person[j+1].location_number] = local_real_rank[person[j+1].location_number];
        }
    }
}
