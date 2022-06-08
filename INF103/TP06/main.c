#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include <inttypes.h>
#include "patient.h"

uint64_t ssn;

int main(int argc, const char *argv[]){
    srand(time(NULL));
    struct patientInfo *queue = NULL;
    int i=0, prio=0;
    unsigned long ssn=0;

    for (i = 0; i < 10; i++) {
        ssn = rand();
        ssn = (ssn << 32) | rand();
        ssn = (ssn % (999999999 - 100000000)) + 100000000;
        prio = rand() % 6;

        queue = enqueue(queue,prio,ssn);
        print_queue(queue);

        sleep(1);

        if ((rand() % 2) && (rand() % 2)) {
            struct patientInfo* out = dequeue(&queue);
            printf("****[%12s (priority: %d)] is now out of the queue!\n",
                   priority_strings[out->prio], out->prio);
        }
    }
    printf("\n========================== dequeueFever ==========================\n");
    struct patientInfo* fever = dequeueFever(&queue);
    printf("\n=== fevers");
    print_queue(fever);
    printf("=== queue");
    print_queue(queue);
    
    printf("\n========================== deadPatient ==========================\n");
    struct patientInfo* tmp = queue;
    i = rand() % queueLength(queue);
    int j = i+1;
    for(; i>0; --i, tmp=tmp->next);
    ssn=tmp->ssn;

    struct patientInfo patient = deadPatient(&queue, ssn);
    printf("\n=== patient died unexpectedly\n");
    printf("%2d: [%12s (priority: %d)] Social security number: %d\n", j, priority_strings[patient.prio], patient.prio, patient.ssn);
    printf("\n=== queue");
    print_queue(queue);

    queueFree(&queue);
    queueFree(&fever);
    return 0;
}
