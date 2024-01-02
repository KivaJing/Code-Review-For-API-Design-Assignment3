#include "save.h"

Save::Save()//:read("save.dat", std::ios::out | std::ios::binary),write("save.dat", std::ios::out | std::ios::binary)
{
	/*read.open("save.dat", std::ios::out | std::ios::binary);
	write.open("save.dat", std::ios::out | std::ios::binary);*/
}

Save::~Save()
{
    /*read.close();
    write.close();*/
}

void Save::save()
{
    Student wstu[3];
    wstu[0].roll_no = 1;
    wstu[0].name = "Ram";
    wstu[1].roll_no = 2;
    wstu[1].name = "Shyam";
    wstu[2].roll_no = 3;
    wstu[2].name = "Madhu";
    ofstream write("save.dat", std::ios::out | std::ios::binary);
    for (int i = 0; i < 3; i++)
      write.write((char*)&wstu[i], sizeof(Student));
    write.close();
    write.clear();
    if (!write.good()) {
        cout << "Error occurred at writing time!" << endl;
        return ;
    }
    
  ifstream  read("save.dat", std::ios::in | std::ios::binary);
    if (!read) {
        cout << "Cannot open file!" << endl;
        return ;
    }
    Student rstu[3];
    for (int i = 0; i < 3; i++)
       read.read((char*)&rstu[i], sizeof(Student));
    read.close();
    read.clear();
    if (!read.good()) {
        cout << "Error occurred at reading time!" << endl;
        return ;
    }
    cout << "Student's Details:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Roll No: " << wstu[i].roll_no << endl;
        cout << "Name: " << wstu[i].name << endl;
        cout << endl;
    }
  
}

void Save::final_page(PrimitiveBatch& batch)
{
}
