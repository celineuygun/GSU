#ifndef PATIENT_H_
#define PATIENT_H_

/* Aciliyetine gore hastalik seviyeleri */
enum Priority {
    PRIO_HEART_ATTACK,
    PRIO_FRACTURE,
    PRIO_FEVER,
    PRIO_NAUSEA,
    PRIO_SORE_THROAT,
    PRIO_ALLERGIES,
};

struct patientInfo {
    /* Aciliyet bilgisi */
    enum Priority prio;
    /* Sosyal guvenlik numarasi */
    int ssn;
    struct patientInfo *next;
};

extern const char *priority_strings[];

struct patientInfo* enqueue(struct patientInfo *head, enum Priority prio, int ssn);
struct patientInfo* dequeue(struct patientInfo **head);
void print_queue(struct patientInfo *head);
int is_empty(struct patientInfo *head);
struct patientInfo* dequeueFever(struct patientInfo **head);
struct patientInfo deadPatient(struct patientInfo **head, int ssn);
int queueLength(struct patientInfo *head);
void queueFree(struct patientInfo **head);

#endif /* PATIENT_H_ */
