#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_

#define N 20

/*
 * Kisi tipini ifade eder.
 * name: adi
 * surname: soyadi
 * tel_number: telefon numarasi
 * id: id numarasi
 */
typedef struct mContact{
	char name[N];
	char surname[N];
	char tel_number[N];
	int id;  
} Contact;

/*
 * Kisi listesini ifade eder.
 * contact_list: kisileri tasiyan
 *      dizidir.
 * max_number: dizideki maksimum
 *      eleman sayisidir.
 * current_number: dizideki guncel
 *      eleman sayisidir.
 */
typedef struct mContactList{
	Contact* contact_list;
	int current_number;
	int max_number;
} ContactList;

void menu();
ContactList create_contact_list(int number);
void add_new_contact(ContactList* c,Contact new_cnt);
void print_contact_list(ContactList c);
void find_contact(ContactList *c, char* name, char* surname);
void delete_contact_list(ContactList *c);
void change_info(ContactList *c, int kisi, int bilgi);
void delete_contact(ContactList *c, char* name, char* surname);
void write_file(ContactList *c, char* fileName);
 
#endif /* CONTACTLIST_H_ */
