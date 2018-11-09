#include<iostream>
using namespace std;
class c
{
public:
struct s{
int item;s*next; s*prev;
};
int kol;
s*head; s*last;
c(){
head = last = NULL;
kol = 0;
cout << "создан пустой список.\n\n";
};
void init(){
int a; cin >> a;
s*pv = new s; pv->item = a;
pv->next = NULL;
pv->prev = NULL;
head = last = pv;
kol++;
}
void addlast(int a){
s*pv = new s; s*pvv = new s;
pv->item = a;
pv->next = NULL;
last->next = pv;
pv->prev = last;
pvv = last;
last = pv;
last->prev = pvv;
kol++;
}

void addp(){
int v, z;
if (last == NULL || head == NULL){
cout << "сначала добавьте первый элемент :";
init();
}
else{
cout << "вставка после   - 1\n";
cout << "вставка перед   - 2\n";
cout << "вставка в конец - 3\n";
cin >> v;
switch (v){
case 1:addafterp(); break;
case 2:addbeforep(); break;
case 3:cout << "значение : "; cin >> z; addlast(z); break;
}
}
};
void addafterp(){
int p, z, v;
cout << "позиция : "; cin >> p;
cout << "значение: "; cin >> z;
s*pv = new s;
pv->item = z;
if (p<0 || p>kol-1){
cout << "вы ввели не сущ. позицию\n";
}
else{
if (p == kol-1){
addlast(z);
}
else{
s*pred = new s;
s*current = new s; current = head;
for (int i = 0; i <p;i++){
pred = current;
current = current->next;
}
pv->next = current->next;
current->next->prev = pv;
pv->prev = current;
current->next = pv;
kol++;
}
}
}
void addbeforep(){
int p, z, v;
cout << "позиция : "; cin >> p;
cout << "значение: "; cin >> z;
s*pv = new s;
pv->item = z;
if (p<0 || p>kol-1){
cout << "вы ввели не сущ. позицию\n";
}
else{
if (p == 0){
pv->next = head;
head->prev = pv;
head = pv;
head->prev = NULL;
kol++;
}
else{
s*current = new s; current = head;
for (int i = 0; i < p-1; i++){

current = current->next;
}
pv->next = current->next;
current->next->prev = pv;
pv->prev = current;
current->next = pv;
kol++;
}
}
}

void addz(){
int v, z;
if (last == NULL || head == NULL){
cout << "сначала добавьте первый элемент :";
init();
}
else{
cout << "вставка после   - 1\n";
cout << "вставка перед   - 2\n";
cout << "вставка в конец - 3\n";
cin >> v;
switch (v){
case 1:addafterz(); break;
case 2:addbeforez(); break;
case 3:cout << "значение : "; cin >> z; addlast(z); break;
}
}
}
void addafterz(){
int zz, z, v;	bool f = false;
cout << "значение: "; cin >> zz;
cout << "значение(добавляемое): "; cin >> z;
s*pv = new s;
pv->item = z;
if (zz == last->item){
addlast(z);
}
else{
s*pred = new s;
s*current = new s; current = head;
for (int i = 0; i < kol; i++){
if (current->item == zz){
pv->next = current->next;
current->next->prev = pv;
pv->prev = current;
current->next = pv;
kol++;
f = true;
}
current = current->next;
}
}
if (f == false){
cout << "элемент не найден.\n";
}
}
void addbeforez(){
int zz, z, v; bool f = false;
cout << "значение : "; cin >> zz;
cout << "значение(добавляемое): : "; cin >> z;
s*pv = new s;
pv->item = z;
if (zz == head->item){
pv->next = head;
head->prev = pv;
head = pv;
kol++;
f = true;
}
else{
s*pred = new s;
s*current = new s; current = head;
for (int i = 0; i < kol; i++){
if (current->next->item == zz){
pv->next = current->next;
current->next->prev = pv;
pv->prev = current;
current->next = pv;
kol++;
f = true;
break;
}
current = current->next;
}
}
if (f == false){
cout << "элемент не найден.\n";
}
}


void delp(){
int v, z;
if (head == NULL){
cout << "список пуст.\n";
}
else{
cout << "удаление после   - 1\n";
cout << "удаление перед   - 2\n";

cin >> v;
switch (v){
case 1:delafterp(); break;
case 2:delbeforep(); break;
}
}
}
void delafterp(){
int p;
cout << "позиция : "; cin >> p;
s*pv = new s;
if (p<0 || p>kol-1){
cout << "вы ввели не сущ. позицию\n";
}
else{
if (p == kol-1){
pv = last;
last = last->prev ;
last->next = NULL;
cout << "элемент " << pv->item << " удален.\n";
delete pv;
kol--;
}
else{
if (p == 0){
p++;
}
s*pred = new s;
s*current = new s; current = head;
for (int i = 0; i < p; i++){
current = current->next;
}
pv = current;
current->prev->next = current->next;
current->next->prev = current->prev;
cout << "элемент " << pv->item << " удален.\n";
delete pv;
kol--;
}
}
}
void delbeforep(){
int p;
cout << "позиция : "; cin >> p;
s*pv = new s;
if (p<1 || p>kol){
cout << "вы ввели не сущ. позицию\n";
}
else{
if (p == kol){
pv = last->prev;
last->prev->prev->next = last;
last->prev = last->prev->prev;
last->next = NULL;
cout << "элемент " << pv->item << " удален.\n";
delete pv;
kol--;
}
else{
if (p == 1){
pv = head->next;
cout << "элемент " << head->item << " удален.\n";
delete head;
head = pv;
head->prev = NULL;
kol--;
}
else{
s*pred = new s;
s*current = new s; current = head;
for (int i = 0; i < p - 1; i++){
current = current->next;
}
pv = current;
current->prev->next = current->next;
current->next->prev = current->prev;
cout << "элемент " << pv->item << " удален.\n";
delete pv;
kol--;
}
}
}
}

void delz(){
int v, z;
if (head == NULL){
cout << "список пуст.\n";
}
else{
cout << "удаление после   - 1\n";
cout << "удаление перед   - 2\n";

cin >> v;
switch (v){
case 1:delafterz(); break;
case 2:delbeforez(); break;
}
}
}
void delafterz(){
int p;
cout << "значение : "; cin >> p; bool f = false;
s*pv = new s;
if (p == last->item){
cout << "enter error.\n";
}
else{
if (p == last->prev->item){
pv = last;
last = last->prev;
last->next = NULL;
cout << "элемент " << pv->item << " удален.\n";
delete pv;
kol--;
f = true;
}
else{
s*pred = new s;
s*current = new s; current = head;
while (current != NULL)
{
if (current->item == p){
current = current->next; break;
}
current = current->next;
}
pv = current;
current->prev->next = current->next;
current->next->prev = current->prev;
cout << "элемент " << pv->item << " удален.\n";
delete pv;
kol--;
f = true;

if (f == false){
cout << "элемент не найден.\n";
}
}
}
}
void delbeforez(){
int p;
cout << "значение : "; cin >> p; bool f = false;
s*pv = new s;
if (p == head->item){
cout << "enter error.\n";
}
else{
if (p == head->next->item){
pv = head->next;
cout << "элемент " << head->item << " удален.\n";
delete head;
head = pv;
head->prev = NULL;
kol--;
f = true;
}
else{
if (p == last->item){
pv = last->prev;
last->prev->prev->next = last;
last->prev = last->prev->prev;
last->next = NULL;
cout << "элемент " << pv->item << " удален.\n";
delete pv;
kol--;
}
else{
s*pred = new s;
s*current = new s; current = head;
while (current != NULL)
{
if (current->item == p){
current = current->prev;  break;
}
current = current->next;
}
pv = current;
current->prev->next = current->next;
current->next->prev = current->prev;
cout << "элемент " << pv->item << " удален.\n";
delete pv;
kol--;
f = true;
if (f == false){
cout << "элемент не найден.\n";
}
}
}
}
}

void show(){
s*pv = new s; pv = head;
if (head == NULL){
cout << "список пуст.\n\n";
}
else{
while (pv != NULL)
{
cout << pv->item << endl;
pv = pv->next;
}
}
}
void show1(){
s*pv = new s; pv = last;
if (last == NULL){
cout << "список пуст.\n\n";
}
else{
while (pv!= NULL)
{
cout << pv->item << endl;
pv = pv->prev;
}
}
}

void searchp(){
int v;
if (head == NULL){
cout << "список пуст.\n";
}
else{
cout << "поиск после   - 1\n";
cout << "поиск перед   - 2\n";

cin >> v;
switch (v){
case 1:searchafterp(); break;
case 2:searchbeforep(); break;
}
}
}
void searchafterp(){
int p;
cout << "позиция : "; cin >> p;
s*pv = new s;
if (p<0 || p>kol - 1){
cout << "вы ввели не сущ. позицию\n";
}
else{
if (p == kol - 1){
cout << "элемент :" << last->item << "\n";
}
else{
if (p == 0){
p++;
}
s*pred = new s;
s*current = new s; current = head;
for (int i = 0; i < p; i++){
current = current->next;
}
cout << "элемент :" << current->item << " \n";
}
}
}
void searchbeforep(){
int p;
cout << "позиция : "; cin >> p;
s*pv = new s;
if (p<1 || p>kol){
cout << "вы ввели не сущ. позицию\n";
}
else{
if (p == kol){
cout << "элемент :" << last->prev->item << "\n";
}
else{
if (p == 1){
cout << "элемент :" << head->item << " \n";
}
else{
s*pred = new s;
s*current = new s; current = head;
for (int i = 0; i < p; i++){
current = current->next;
}
cout << "элемент :" << current->prev->item << " \n";
}
}
}
}

void searchz(){
int v;
if (head == NULL){
cout << "список пуст.\n";
}
else{
cout << "поиск после   - 1\n";
cout << "поиск перед   - 2\n";

cin >> v;
switch (v){
case 1:searchafterz(); break;
case 2:searchbeforez(); break;
}
}
}
void searchafterz(){
int p, pp=0;
cout << "значение : "; cin >> p; bool f = false;
s*pv = new s;
if (p == last->item){
cout << "enter error.\n";
}
else{
if (p == last->prev->item){
cout << "значение : " << last->item << "\n позиция :" << kol << endl;
f = true;
}
else{
s*pred = new s;
s*current = new s; current = head;
while (current != NULL)
{
if (current->item == p){
current = current->next; break;
}
pp++;
current = current->next;
}
cout << "значение " << current->item << "\n позиция :"<<pp+1<<endl;
f = true;
if (f == false){
cout << "элемент не найден.\n";
}
}
}
}
void searchbeforez(){
int p,pp=0;
cout << "значение : "; cin >> p; bool f = false;
s*pv = new s;
if (p == head->item){
cout << "enter error.\n";
}
else{
if (p == head->next->item){
cout << "значение " << head->item << "\nпозиция :"<<0<<endl;
f = true;
}
else{
if (p == last->item){
cout << "значение " << last->prev->item << "\nпозиция :"<<kol-2<<endl;
}
else{
s*pred = new s;
s*current = new s; current = head;
while (current != NULL)
{
if (current->item == p){
current = current->prev;  break;
}
current = current->next;
pp++;
}
pv = current;
cout << "значение :" << pv->item << "\nпозиция :"<<pp-2<<endl;
f = true;
if (f == false){
cout << "элемент не найден.\n";
}
}
}
}
}

void sort(){
if (head == NULL){
cout << "список пуст.\n";
}
else{
int y;
s *pv = new s;
s *current = new s;
s *pvs = new s;
for (int i = 0; i < kol - 1; i++) {
pv = head;
current = pv->next;
for (int j = 0; j < kol - i - 1; j++) {
if ((pv->item)>(current->item)){
if (pv == head){
(current->next)->prev = current->prev;
(current->prev)->next = current->next;
current->next = pv;
current->prev = NULL;
(current->next->prev) = current;
head = current;
pvs = current;
current = pv;
pv = pvs;
head = pv;
}
else if (pv->next == last){
(pv->next)->prev = pv->prev;
(pv->prev)->next = pv->next;
pv->next = NULL;
pv->prev = current;
current->next = pv;
last = pv;
pvs = pv;
pv = current;
current = pvs;
}
else {
(pv->next)->prev = pv->prev;
(pv->prev)->next = pv->next;
pv->next = current->next;
pv->prev = current;
(current->next)->prev = pv;
(current->next) = pv;
pvs = pv;
pv = current;
current = pvs;
}
}
pv = pv->next;
current = current->next;
}
}
}
cout << "список отсортирован.\n";
}

~c(){
if (head == NULL){
cout << "список пуст.\n\n";
}
else{
s*temp = new s;
while (head != NULL){
temp = head->next;
delete head;
head = temp;
}
cout << "очистка завершена\n\n";
}
}
};
int main(){
setlocale(LC_ALL, "");
int v; c ob;
while (true)
{
cout << "добавление по позиции  -1\n";
cout << "добавление по значению -2\n\n";
cout << "удаление по позиции    -3\n";
cout << "удаление по значению   -4\n\n";
cout << "вывод с начала         -5\n";
cout << "вывод с конца          -6\n\n";
cout << "поиск по позиции       -7\n";
cout << "поиск по значении      -8\n\n";
cout << "сортировка             -9\n";
cout << "очистка списка         -10\n";
cout << "выход                  -11\n\n";

cout << "выбор функции :"; cin >> v;
cin.clear();
cout << "введите цифру.\n";
cin.ignore(10, '\n');
system("CLS");

switch (v){
case 1:ob.addp(); break;
case 2:ob.addz(); break;
case 3:ob.delp(); break;
case 4:ob.delz(); break;
case 5:ob.show(); break;
case 6:ob.show1(); break;
case 7:ob.searchp(); break;
case 8:ob.searchz(); break;
case 9:ob.sort(); break;
case 10:ob.~c(); break;
case 11:return 0;	}}
system("pause");
return 0;}
 

