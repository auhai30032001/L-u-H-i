#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include"dohoa.h"


using namespace std;

class Book
{
    protected:
    string IDBook; //Ma sach
    string NameBook;//Ten sach
    string CategoryBook;//The loai
    double Publishingyear;//Nam Xuat Ban
    bool Category;//Loai sach
    public :
    Book();
    ~Book();
    virtual void Input();
    virtual void Output();
    virtual double Bill() = 0; // Thanh toan
    void SetS(bool s);
    int GetS();
    string GetID(); // lay ma sach
    float GetYear();// Lay nam xuat ban
    string GetName();//Lay ten sach
    
};

class ScienceBook: public Book//Class sach Khoa Hoc
{
    private:
    double fee;//Phi Dich sach khoa hoc
    public:
    ScienceBook();
    ~ScienceBook();
    void Input();
    void Output();
    double Bill();//Thanh tien

};

class EducatinalBook : public Book//Class sach Giao Duc
{
    private:
    double Fee;//Phi dich sach giao duc
    public:
    EducatinalBook();
    ~EducatinalBook();
    void Input();
    void Output();
    double Bill();//Thanh tien

};

class Store 
{
    private:
    vector<Book*> DSS;
    public:
    void InputS();
    void OutputS();
    double TotalMoney();//Tong tien sach 
    void SearchByID();//Tim sach theo ma sach
    void SearchByName();//Tim sach theo ten sach
    void SearchMax();//Tim sach co gia cao nhat
    void Search();//Tim sach theo yeu cau
    void SortByName();//Sap xep sach theo ten(A->Z)
    void SortByPublishingyear();//Sap xep sach theo Nam xuat ban
    void Remove();//Xoa mot sach
    void Edit();// Sua thong tin sach theo ten
};

Book::Book()
{
    NameBook = "";
    IDBook = "";
    CategoryBook = "";
    Publishingyear = 0;
}

ScienceBook::ScienceBook()
{
    fee = 0;
}

EducatinalBook::EducatinalBook()
{
    Fee = 0;
}

//Ham nhap
void Book::Input()
{
    ToMau(36,6,"                                                                                                ",145);
    ToMau(36,8," ",145);
    ToMau(36,9," ",145);
    ToMau(36,10," ",145);
    ToMau(36,7," ",145);
    //Gach Bang
    ToMau(58,7," ",145);
    ToMau(72,7," ",145);
    ToMau(92,7," ",145);
    ToMau(110,7," ",145);
    ToMau(131,7," ",145);

    ToMau(58,9," ",145);
    ToMau(72,9," ",145);
    ToMau(92,9," ",145);
    ToMau(110,9," ",145);
    ToMau(131,9," ",145);
    ToMau(36,8,"                                                                                                ",145);
    ToMau(37,10,"                                                                                               ",145);
	ToMau(40,7,"Book Title",6);
	cin.ignore(1);
    gotoxy(40,9);
    getline(cin,NameBook);
    ToMau(62,7,"ID Book",6);
    cin.ignore(0);
    gotoxy(63,9);
    getline(cin,IDBook);
    ToMau(74,7,"Category Book",6);
    cin.ignore(0);
    gotoxy(76,9);
    getline(cin,CategoryBook);
    ToMau(94,7,"PublishingYear",6);
    gotoxy(96,9);
    cin>>Publishingyear;
}

//Ham xuat
void Book::Output()
{

    cout<<endl;
    cout<<"\t\t\t\t\t-------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t"<<setw(9)<<left<<"|   Book Title"<<"          "<<"|"<<setw(13)<<right<<"ID Book  "<<"    "<<"|"<<setw(18)<<right<<"         Category       "<<"|"<<setw(15)<<left<<"   PublishingYear"<<right<<"     |"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t"<<"|"<<setw(23)<<left<<NameBook<<"|"<<setw(17)<<left<<IDBook<<"|"<<setw(24)<<left<<CategoryBook<<"|"<<setw(22)<<left<<Publishingyear<<"|"<<endl;
    cout<<"\t\t\t\t\t-------------------------------------------------------------------------------------------"<<endl;
    
}

//Kiem tra loai sach
void Book::SetS(bool s)
{
    Category = s;
}

//Lay loai sach
int Book::GetS()
{
    return this -> Category;
}

//Lay ma sach
string Book::GetID()
{
    return this ->IDBook;
}

//Lay nam xuat ban
float Book::GetYear()
{
    return this ->Publishingyear;
}

//Lay ten sach
string Book::GetName()
{
    return this ->NameBook;
}


void ScienceBook ::Input()
{
    Book::Input();
    ToMau(112,7,"Fee Science Book",6);
    gotoxy(114,9);
    cin>>fee;
}

void ScienceBook ::Output()
{
    Book::Output();
    cout<<"\t\t\t\t\t--- Fee Science Book --- " << fee*12 << " ( $ )" << "<=>" <<(fee*12)*20000<<" (Dng)" <<"\t" ;
    //gotoxy(42,7); textcolor(5); cout<<"Fee Science Book  "<<fee<<"[$]"<<"\t";
}


//Tinh gia tien sach khoa hoc
double ScienceBook::Bill()
{
    return (fee*12); 
}


void EducatinalBook::Input()
{
    Book::Input();
    ToMau(112,7,"Fee Educatinal Book",6);
    gotoxy(114,9);
    cin>>Fee;
}

void EducatinalBook::Output()
{
    Book::Output();
    cout<<"\t\t\t\t\t--- Fee Educatinal Book --- " << Fee*14 << " ( $ )" << "<=>" <<(Fee*14)*20000<<" (Dng)" <<"\t" ;
}

//Tinh gia tien sach giao duc
double EducatinalBook::Bill()
{
    return (Fee*14);
}

void Store::InputS()
{
    int  Choose,i = 1;
    while(i)
    {  
    	system("cls");
        ToMau(1,1," ",40);
        ToMau(2,1,"               MENU              ",228);
        ToMau(2,2,"                                 ",242);
        ToMau(2,3," 1.Input Inform Science Book.    ",242);
        ToMau(2,4,"                                 ",242);
        ToMau(2,5," 2.Input Inform Educational Book.",242);
        ToMau(2,6,"                                 ",242);
        ToMau(2,7," 3.Search by Name.               ",242);
        ToMau(2,8,"                                 ",242);
        ToMau(2,9," 4.Search by ID.                 ",242);
        ToMau(2,10,"                                 ",242);
        ToMau(2,11," 5.Search Max.                   ",242);
        ToMau(2,12,"                                 ",242);
        ToMau(2,13," 6.Search From..To.              ",242);
        ToMau(2,14,"                                 ",242);
        ToMau(2,15," 7.Sort by Name(A->Z).           ",242);
        ToMau(2,16,"                                 ",242);
        ToMau(2,17," 8.Sort by PublishingYear(Dec).  ",242);
        ToMau(2,18,"                                 ",242);
        ToMau(2,19," 9.Remove.                       ",242);
        ToMau(2,20,"                                 ",242);
        ToMau(2,21," 10.Edit.                        ",242);
        ToMau(2,22,"                                 ",242);
        ToMau(2,23," 11.OutList.                     ",242);
        ToMau(2,24,"                                 ",242);
        ToMau(2,25," 0.Exit.                         ",242);
        ToMau(2,26,"  INPUT YOUR CHOOSE!             ",244);
        ToMau(1,2," ",40);
        ToMau(1,3," ",40);
        ToMau(1,4," ",40);
        ToMau(1,5," ",40);
        ToMau(1,6," ",40);
        ToMau(1,7," ",40);
        ToMau(1,8," ",40);
        ToMau(1,9," ",40);
        ToMau(1,10," ",40);
        ToMau(1,11," ",40);
        ToMau(1,12," ",40);
        ToMau(1,13," ",40);
        ToMau(1,14," ",40);
        ToMau(1,15," ",40);
        ToMau(1,16," ",40);
        ToMau(1,17," ",40);
        ToMau(1,18," ",40);
        ToMau(1,19," ",40);
        ToMau(1,20," ",40);
        ToMau(1,21," ",40);
        ToMau(1,22," ",40);
        ToMau(1,23," ",40);
        ToMau(1,24," ",40);
        ToMau(1,25," ",40);
        ToMau(1,26," ",40);
        ToMau(35,1," ",40);
        ToMau(35,2," ",40);
        ToMau(35,3," ",40);
        ToMau(35,4," ",40);
        ToMau(35,5," ",40);
        ToMau(35,6," ",40);
        ToMau(35,7," ",40);
        ToMau(35,8," ",40);
        ToMau(35,9," ",40);
        ToMau(35,10," ",40);
        ToMau(35,11," ",40);
        ToMau(35,12," ",40);
        ToMau(35,13," ",40);
        ToMau(35,14," ",40);
        ToMau(35,15," ",40);
        ToMau(35,16," ",40);
        ToMau(35,17," ",40);
        ToMau(35,18," ",40);
        ToMau(35,19," ",40);
        ToMau(35,20," ",40);
        ToMau(35,21," ",40);
        ToMau(35,22," ",40);
        ToMau(35,23," ",40);
        ToMau(35,24," ",40);
        ToMau(35,25," ",40);
        ToMau(35,26," ",40);
        Book *s; 
        gotoxy(25,26);
		cin>>Choose;
        switch(Choose)
        {
            case 1:
            s = new ScienceBook;
            ToMau(70,3,"-INFORMATION SCIENCE BOOK-",244);
            s->Input();
            DSS.push_back(s);
            s->SetS(true);
            break;
            
            case 2:
            s = new EducatinalBook;
            ToMau(70,3,"-INFORMATINON EDUCATINAL BOOK-",244);
            s->Input();
            DSS.push_back(s);
            s->SetS(false);
            break;

            case 3:
            SearchByName();
            system("pause");
            break;

            case 4:
            SearchByID();
            system("pause");
            break;

            case 5:
            SearchMax();
            system("pause");
            break;

            case 6:
            Search();
            system("pause");
            break;

            case 7:
            SortByName();
            system("pause");
            break;

            case 8:
            SortByPublishingyear();
            system("pause");
            break;

            case 9:
            Remove();
            system("pause");
            break;

            case 10:
            Edit();
            system("pause");
            break;

            case 11:
            system("cls");
            OutputS();
            TotalMoney();
            system("pause");
            break;

            case 0:
            i = 0; 
            break;

            default:
            cout<<"Input Invalue!.Choose again!"<<endl;
        }
    }
}        

//Ham xuat thong tin tung loai sach
void Store::OutputS()
{
    for(int i = 0; i < DSS.size(); i++)
    {
        if(DSS[i]->GetS() == true)
        {
            cout<<"\n\t\t\t\t\t\t\t\t---INFORMATIONAL SCIENCE BOOK---"<<endl;
            DSS[i]->Output();
        }
        else 
        {
            cout<<"\n\n\t\t\t\t\t\t\t\t---INFORMATION EDUCATINAL BOOK---"<<endl;
            DSS[i]->Output();
        }
    }
}


//Ham tim sach co gia tien cao nhat
void Store::SearchMax()
{
    Book  *s;
    double max = DSS[0]->Bill();
    for(int i = 0; i < DSS.size(); i++)
    {
        if(DSS[i]->Bill() >= max)
        {
            max = DSS[i]->Bill();
            s = DSS[i];
        }
    }
    gotoxy(70,2);
    cout<<"Most Expensive!";
    gotoxy(37,4);
    s ->Output();
}

//Ham tinh tong tien
double Store::TotalMoney()
{
    double sum = 0;
    for(int i = 0; i < DSS.size(); i++)
    {
        sum = sum + DSS[i]->Bill();
    }
    cout<<"\n\n\t\t\t\t\t[Total Money] "<< sum<<".($)"<<"<=>"<<sum*20000 <<".(Dng)"<< endl;
}

//Ham tim sach theo ten
void Store::SearchByName()
{
    string name;
    ToMau(80,2,"Input Name Book  ",240);
    cin.ignore();
    gotoxy(105,2);
    getline(cin,name);
    int tim = 0;
    for(int i = 0; i < DSS.size(); i++)
    {
        if(DSS[i]->GetName().compare(name) == 0)
        {
            DSS[i]->Output();
            tim = 1;
        }
    }
    if(tim == 0)
    {
        ToMau(60,10,"Not Found!",240);
    }
}


//Ham tim sach theo Ma Sach
void Store::SearchByID()
{
    string id;
    ToMau(80,2,"Input ID  ",240 );
    cin.ignore(1);
    gotoxy(105,2);
    getline(cin,id);
    int Temp = 0;
    for(int i = 0 ; i < DSS.size(); i++)
    {
        if(DSS[i] ->GetID().compare(id) == 0)
        {
            DSS[i] ->Output();
            Temp = 1;
        }
    }
    if(Temp == 0)
    {
        ToMau(60,10,"Not Found!",240);
    }
}

//Ham tim sach theo yeu cau
void Store::Search()
{
    float a , b;
    ToMau(80,2,"Input A B ",240);
    gotoxy(105,2);
    cin>>a;
    gotoxy(110,2);
    cin>>b;
    for(int i = 0 ; i < DSS.size(); i++)
    {
        if(DSS[i]->GetYear() >= a && DSS[i] ->GetYear() <= b)
        {
            DSS[i] ->Output();
        }
    }
}

//Ham doi vi tri
void swap(Store  *x, Store *y)
{
    Store z = *x;
    *x = *y;
    *y = z;
}

//Ham sap xep theo ten(sap xep noi bot)
void Store::SortByName()
{
    for(int i = 0; i < DSS.size(); i++)
    {
        for(int j = i + 1; j < DSS.size(); j++)
        {
            if(DSS[i]->GetName().compare(DSS[j]->GetName()) > 0)
            {
                swap(DSS[i],DSS[j]);
            }
        }
    }
    gotoxy(37,2);
    OutputS();
}


//Ham sap xep theo Nam xuat ban(sap xep chon)
void Store::SortByPublishingyear()
{ 
    for(int i= 0; i< DSS.size(); i++)
    {
        int min  = i;
        for(int j = 0 ; j< DSS.size(); j++)
        {
            if(DSS[j]->GetYear() < DSS[min]->GetYear())
            {
                min = j;
            }
            if(i != min)
            {
                swap(DSS[min],DSS[i]);
            }
        }
    }
    gotoxy(37,2);
    OutputS();
}


//Ham Xoa sach
void Store::Remove()
{
    string name;
    ToMau(80,2,"Input Name Remove   ",240);
    cin.ignore(1);
    gotoxy(105,2);
    getline(cin,name);
    int tim = 0;
    for(int i = 0 ; i< DSS.size(); i++)
    {
        if(name.compare(DSS[i]->GetName()) == 0)
        {
            DSS.erase(DSS.begin() + i);
            tim = 1;
        }
    }
    gotoxy(37,4);
    OutputS();
    if(tim == 0)
    {
        ToMau(60,10,"Not Found!",240);
    }
}


void Store::Edit()
{
    Book *s;
    string name;
    ToMau(80,2,"Input Book Title Edit!",240);
    cin.ignore(1);
    gotoxy(105,2);
    getline(cin,name);
    int tim = 0;
    for(int i = 0 ; i < DSS.size() ; i++)
    {
        if(name.compare(DSS[i]->GetName()) == 0)
        {
            DSS[i]->Input();
            tim = 1;
            break;
        }
    }
    if(tim == 0)
    {
        ToMau(60,10,"Not Found!",240);
    }
}


//Ham hien thi thong tin nhom
void Inform()
{
	ToMau(33,5,"--CHAO MUNG CO VA CAC BAN DEN VOI HE THONG QUAN LI SACH CUA CHUNG EM-- ",242);
	ToMau(50,6,"---- DO AN BAI TAP LON CUA NHOM  ----",241);
    ToMau(34,7,"...................Cac Thanh Vien Cua Nhom Gom..................",243);
    ToMau(51,9,"- Nguyen Huu Dai  -6051071023 - ",242);
    ToMau(51,10,"                               ",242);
    ToMau(51,11,"- Pham Hoang Hai  -6051071035 - ",244);
    ToMau(51,12,"                               ",244);
    ToMau(51,13,"- Tran Cong Dai   -6051071024 - ",245);
    ToMau(51,14,"                               ",245);
    ToMau(51,15,"- Nguyen Tien Dat -6051071026 - ",246);
    ToMau(51,16,"                               ",246);
    ToMau(51,17,"- Le Au Hai       -6051071034 - ",253);
    ToMau(51,18,"                               ",253);
    ToMau(30,24,"-----------------------------CLICK ENTER TO CONTINUE!----------------------------",253);
    getchar();
}

Book::~Book(){}
ScienceBook::~ScienceBook(){}             // Cac ham huy
EducatinalBook::~EducatinalBook(){}

//Ham main
int main()
{
	resizeConsole(1500,666);
    Store *a = new Store;
    Inform();
    a->InputS();
    delete a;
    return 0;

}































