#include <iostream>

using namespace std;

#define TABLE_SIZE 128

struct LinkedHashEntry {
	const char* key;
	int val;
	LinkedHashEntry* next;
	LinkedHashEntry(const char* key, int val) : key(key), val(val), next(nullptr) {}
};

struct Hashtable {
	LinkedHashEntry* entries[TABLE_SIZE];
	int size;

	Hashtable() : size(0) {
		for (int i = 0; i < TABLE_SIZE; i++)
			entries[i] = nullptr;
	}
};

int hash1(const char* key) {
	int h = 5381;
	while (*key) {
		h = (h << 5) + h + *key;
		key++;
	}
	return h;
}

int lookup(Hashtable* table, const char* key) {
	int h = hash1(key) % TABLE_SIZE;
	if (table->entries[h] == nullptr)
		throw "key not found";

	LinkedHashEntry* p = table->entries[h];
	while (p && p->key != key)
		p = p->next;
	if (!p)
		throw "key not found";
	return p->val;

}

void put(Hashtable* table, const char* key, int val){
	int h = hash1(key) % TABLE_SIZE;
	LinkedHashEntry* t = new LinkedHashEntry(key, val);
	if (!table->entries[h])
		table->entries[h] = t;
	else{
		LinkedHashEntry* p = table->entries[h];
		t->next = p;
		t = p;
	}
}

void remove (Hashtable* table, char* key) {
	int h = hash1(key) % TABLE_SIZE;

	if (table->entries[h]) {
		LinkedHashEntry *prep = nullptr;
		LinkedHashEntry *p = table->entries[h];
		while (p->next && p->key != key) {
			prep = p;
			p = p->next;
		}
		if (p->key == key) {
			//head
			if (!prep) {
				LinkedHashEntry *nEntry = p->next;
				delete p;
				table->entries[h] = nEntry;
			}
			else {
				LinkedHashEntry *next = p->next;
				delete p;
				prep->next = next;
			}
		}
	}
}

int main(){
	Hashtable* h = new Hashtable();
	put(h,"qwe", 2);

	cout << lookup(h,"qwe")<< endl;

	return 0;
}