#include <iostream>
#include <string>
#include <map>
using namespace std;
class Medicine
{
protected:
string name;
double price;
string impact;
public:
Medicine(const string& name, double price, const string& impact)
: name(name), price(price), impact(impact) { }
virtual void displayInformation() const {
cout << "Medicine Name: " << name << endl;
cout << "Price: " << price << " $" << endl;
cout << "Impact: " << impact << endl;
}
};
class PainReliever : public Medicine
{
public:
PainReliever(const string& name, double price, const string& impact)
: Medicine(name, price, impact) { }
void displayInformation() const override {
cout << "--- Pain Reliever ---" << endl;
Medicine::displayInformation();
cout << "Medicine Type: Pain Reliever" << endl;
}
class Antibiotic : public Medicine
{
public:
Antibiotic(const string& name, double price, const string& impact)
: Medicine(name, price, impact) { }
void displayInformation() const override {
cout << "--- Antibiotic ---" << endl;
Medicine::displayInformation();
cout << "Medicine Type: Antibiotic" << endl;
}
};
class Antacid : public Medicine
{
public:
Antacid(const string& name, double price, const string& impact)
: Medicine(name, price, impact) { }
void displayInformation() const override {
cout << "--- Antacid ---" << endl;
Medicine::displayInformation();
cout << "Medicine Type: Antacid" << endl;
}
};
int main()
{
map<string, Medicine*> medicineCatalog;
medicineCatalog["Aspirin"] = new PainReliever("Aspirin", 10.5, "Relieves
general pain");
medicineCatalog["Amoxicillin"] = new Antibiotic("Amoxicillin", 20.75,
"Treats bacterial infections");
medicineCatalog["Tums"] = new Antacid("Tums", 5.25, "Relieves acidity");
cout << "Available Medicines:- " << endl;
for (const auto& pair : medicineCatalog) {
cout << pair.first << endl;
}
string selectedMedicine;
cout << "Enter the name of the medicine you want to view: ";
cin >> selectedMedicine;
if (medicineCatalog.find(selectedMedicine) != medicineCatalog.end())
{
medicineCatalog[selectedMedicine]->displayInformation();
}
else
{
cout << "Invalid medicine name." << endl;
}
medicineCatalog.clear();
return 0;
}