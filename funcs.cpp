#include <iostream>
#include <fstream>
#include "Z.h"
#include <math.h>

using namespace std;

ostream& operator<<(ostream& os, const nm::jets& Jets){
    os << Jets.model <<" "<< Jets.pilot << " " << Jets.range << " " << Jets.speed<< " "<<Jets.status<< " " <<Jets.time<<" "<< Jets.x<<" "<< Jets.y<<" "<< Jets.timeEnd;
    return os;
}

istream& operator>>(istream& is, nm::jets& Jets){
    is >> Jets.model >> Jets.pilot >> Jets.range >> Jets.speed>>Jets.status>>Jets.time>>Jets.x>>Jets.y>>Jets.timeEnd;
    return is;
}

void nm::display(string a){
    string line;
    ifstream f;
    f.open(a); // окрываем файл
    if(!f.is_open()){
        cout << "Файл не найден. Создается новый файл: " << a << "\n";
        ofstream f(a);
        cout<< "Файл пуст"<<endl;
        f.close();
    return;}
    bool flag = true;
    int b=0;
    if(a=="jets.txt"){
        cout << "Модель самолета\t| Имя пилота\t| Маршрут\t| Скорость самолета\t| Статус\t| Время в пути\t| Текущие оординаты\t| Оставшееся время" << endl;}
        else {
        cout << "Название маршрута\t| Координаты начала\t| Координаты конца" << endl;}
        while (getline(f, line)) {
            cout << b<<". "<<line << endl;
            flag = false;
            b++;
        }
        if(flag) cout << "Файл пуст" << endl;
    f.close();



}

void nm::searchJET(){
    cout << "Enter model of jet" << endl;
    string Model;
    cin >> Model;
    jets editable;
    ifstream f;
    f.open("jets.txt");
    if(!f.is_open())
        return;
    while(f >> editable){
        if(editable.model == Model){
            cout << editable.model << " " << editable.pilot<< " " << editable.range << " " << editable.speed << " "<<editable.status<< " " <<editable.time <<" " <<editable.x<<" " <<editable.y <<" " <<editable.timeEnd<< endl;
        }
    }
    f.close();
}

void nm::addJET(){
    jets editable;
    cout << "Введите название самолета, имя пилота, скорость самолета" << endl;
    cin >> editable.model >> editable.pilot >> editable.speed;
    fstream f;
    editable.range = "no";
    editable.status = 0;
    editable.time = 0;
    editable.x=0;
    editable.y=0;
    editable.timeEnd=0;
    f.open("jets.txt", ios::app | ios::ate);
    if(!f.is_open()){
        cout << "Не удалось открыть файл." << endl;
        return;}
    f << editable.model << " " << editable.pilot << " " << editable.range << " " << editable.speed << " "<< editable.status << " " << editable.time <<" "<<editable.x<<" "<< editable.y<<" "<<editable.timeEnd<< endl;
    f.close();
}

void nm::delJET(){
    string line;
    int i = 0;
    ifstream fread;
    fread.open("jets.txt");
    if(!fread.is_open())
        return;
    while(getline(fread, line)){
        i++;
    }
    jets arr[i];
    fread.close();
    fread.open("jets.txt");
    if(!fread.is_open())
        return;
    jets editable2;
    for(int n = 0; n < i; n++){
        fread >> editable2;
        arr[n] = editable2;
    }
    fread.close();
    jets editable;
    cout << "Enter model, pilot, range, speed ";
    cin >> editable;
    ofstream fwrite;
    fwrite.open("jets.txt");
    if(!fwrite.is_open())
        return;
    for(int n = 0; n < i; n++){
        if((arr[n].model != editable.model) || (arr[n].pilot != editable.pilot) || (arr[n].range != editable.range) || (arr[n].speed != editable.speed)|| (arr[n].status != editable.status)|| (arr[n].time != editable.time)|| (arr[n].x!= editable.x)|| (arr[n].y != editable.y)|| (arr[n].timeEnd != editable.timeEnd)){
            fwrite << arr[n].model << " " << arr[n].pilot << " " << arr[n].range << " " << arr[n].speed << " " << arr[n].status<< " " << arr[n].time<<" "<<arr[n].x<<" "<<arr[n].y<<" "<<arr[n].timeEnd<< endl;
        }
    }
    fwrite.close();
}

ostream& operator<<(ostream& os, const nm::routes& Routes){
    os << Routes.name << " " << Routes.startX << Routes.startY << " " << Routes.endX << Routes.endY;
    return os;
}

istream& operator>>(istream& is, nm::routes& Routes){
    is >> Routes.name >> Routes.startX >> Routes.startY >> Routes.endX >> Routes.endY;
    return is;
}

void nm::searchROU(){
    cout << "Enter name of route" << endl;
    string name;
    cin >> name;
    routes editable;
    ifstream f;
    f.open("routes.txt");
    if(!f.is_open())
        return;
    while(f >> editable){
        if(editable.name == name){
            cout << editable.name << " " << editable.startX << " " << editable.startY << " " << editable.endX << " " << editable.endY << endl;
        }
    }
    f.close();
}

void nm::addROU(){
    cout << "Название маршрута, координаты начала (x, y), координаты конца (x, y)" << endl;
    routes editable;
    cin >> editable;
    fstream f;
    f.open("routes.txt", ios::app | ios::ate);
    if(!f.is_open())
        return;
    f << editable.name << " " << editable.startX << " " << editable.startY << " " << editable.endX << " " << editable.endY << endl;
    f.close();
}

void nm::delROU(){
    string line;
    int i = 0;
    ifstream fread;
    fread.open("routes.txt");
    if(!fread.is_open())
        return;
    while(getline(fread, line)){
        i++;
    }
    routes arr[i];
    fread.close();
    fread.open("routes.txt");
    if(!fread.is_open())
        return;
    routes editable2;
    for(int n = 0; n < i; n++){
        fread >> editable2;
        arr[n] = editable2;
    }
    fread.close();
    routes editable;
    cout << "Enter name, start(x,y), end(x,y)" << endl;
    cin >> editable;
    ofstream fwrite;
    fwrite.open("routes.txt");
    if(!fwrite.is_open())
        return;
    for(int n = 0; n < i; n++){
        if((arr[n].name != editable.name) || (arr[n].startX != editable.startX) || (arr[n].startY != editable.startY) || (arr[n].endX != editable.endX) || (arr[n].endY != editable.endY)){
            fwrite << arr[n].name << " " << arr[n].startX << " " << arr[n].startY << " " << arr[n].endX << " " << arr[n].endY << endl;
        }
    }
    fwrite.close();
}

/*     Херня с которой начинала эту часть, хз мож чет глянуть надо будет

void nm::peremeshenie(){
    string line;
    int i = 0;
    ifstream fread;
    fread.open("routes.txt");
    if(!fread.is_open())
        return;
    while(getline(fread, line)){
        i++;
    }
    routes arr[i];
    fread.close();
    fread.open("routes.txt");
    if(!fread.is_open())
        return;
    routes editable2;
    for(int n = 0; n < i; n++){
        fread >> editable2;
        arr[n] = editable2;
    }
    fread.close();


    int n2;
    cout << "введите номер" << endl;
    cin >> n2;
    cout<<"Введите количество прошедших часов"<<endl;
    int a;
    cin >> a;


    ofstream fwrite;
    fwrite.open("routes.txt");
    int c;
    float c1;
    c=sqrt(pow(arr[n2].startX-arr[n2].endX,2)+pow(arr[n2].startY-arr[n2].endY,2));

    
    int n1;
    cout << "введите номер самолета" << endl;
    cin >> n1;


    string line1;
    i = 0;
    ifstream fread1;
    fread1.open("jets.txt");
    if(!fread1.is_open())
        return;
    while(getline(fread1, line1)){
        i++;
    }
    jets arr1[i];
    fread1.close();
    fread1.open("jets.txt");
    if(!fread1.is_open())
        return;
    jets editable3;
    for(int n = 0; n < i; n++){
        fread1 >> editable3;
        arr1[n] = editable3;
    }
    fread1.close();

    c1=a*arr1[n1].speed;

    int _x, _y, _l;
    _x = arr[n2].endX-arr[n2].startX;
    _y = arr[n2].endY-arr[n2].startY;
    _l = sqrt(pow(_x,2)+pow(_y,2));
    _x =_x*c1/_l;
    _y=_y*c1/_l;
    c1=c1*100/c;
    float _t=c/arr1[n1].speed;

    cout<<"На данный момент самолет находится на координате "<< _x<< "  " <<_y<< "И преодолел " << c1<<" % пути на месте будет через "<<_t <<" ч"<<endl;
    }

    */ 

void nm::vylet(){
    string line1;
    int _i = 0;
    ifstream fread1;
    fread1.open("routes.txt");
    if(!fread1.is_open()){
    cout<<"Не удалось открыть файл"<<endl;
        return;}
    while(getline(fread1, line1)){
        _i++;
    }
    routes arr1[_i];
    fread1.close();
    fread1.open("routes.txt");
    if(!fread1.is_open()){
    cout<<"Не удалось открыть файл"<<endl;
        return;}
    routes editable12;
    for(int n = 0; n < _i; n++){
        fread1 >> editable12;
        arr1[n] = editable12;
    }

    fread1.close();
    cout<< "Введите индекс желаемого маршрута для вылета"<<endl;
    int _a;
    cin >>_a;
    

    string line;
    int i = 0;
    ifstream fread;
    fread.open("jets.txt");
    if(!fread.is_open()){
    cout<<"Не удалось открыть файл"<<endl;
        return;}
    while(getline(fread, line)){
        i++;
    }
    jets arr[i];
    fread.close();
    fread.open("jets.txt");
    if(!fread.is_open()){
    cout<<"Не удалось открыть файл"<<endl;
        return;}
    jets editable2;
    for(int n = 0; n < i; n++){
        fread >> editable2;
        arr[n] = editable2;
    }
    fread.close();

    cout<<"Введите индекс свободного самолета, отправляемого в путь"<<endl;
    int index;
    cin >> index;
    if(index>=i){
        cout<<"Данного самолета не существует"<<endl;
        return;
    }
    if(arr[index].status) 
    cout<< "Данный самолет уже находится в рейсе" <<endl;
    else {
        arr[index].status=1;
        arr[index].range=arr1[_a].name;
        arr[index].x=arr1[_a].startX;
        arr[index].y=arr1[_a].startY;
        int c=sqrt(pow(arr1[_a].startX-arr1[_a].endX,2)+pow(arr1[_a].startY-arr1[_a].endY,2));
        arr[index].timeEnd= c/arr[index].speed;
    }
    ofstream fwrite;
    fwrite.open("jets.txt");
    if(!fwrite.is_open()){
    cout<<"Не удалось открыть файл"<<endl;
        return;}
    for(int n = 0; n < i; n++){
            fwrite << arr[n].model << " " << arr[n].pilot << " " << arr[n].range << " " << arr[n].speed << " " << arr[n].status<< " " << arr[n].time<<" "<< arr[n].x<<" "<<arr[n].y<<" "<<arr[n].timeEnd<< endl;
        }
    fwrite.close();
}


void nm::time(){
    string line1;
    int i1 = 0;
    ifstream fread1;
    fread1.open("routes.txt");
    if(!fread1.is_open())
        return;
    while(getline(fread1, line1)){
        i1++;
    }
    routes arr1[i1];
    fread1.close();
    fread1.open("routes.txt");
    if(!fread1.is_open())
        return;
    routes editable2;
    for(int n = 0; n < i1; n++){
        fread1 >> editable2;
        arr1[n] = editable2;
    }
    fread1.close();

    string line;
    int i = 0;
    ifstream fread;
    fread.open("jets.txt");
    if(!fread.is_open())
        return;
    while(getline(fread, line)){
        i++;
    }
    jets arr[i];
    fread.close();
    fread.open("jets.txt");
    if(!fread.is_open())
        return;
    jets editable3;
    for(int n = 0; n < i; n++){
        fread >> editable3;
        arr[n] = editable3;
    }
    fread.close();


    cout<<"Введите время, проведенное в пути"<<endl;
    int t;
    cin>>t;

    ofstream fwrite;
    fwrite.open("jets.txt");
    if(!fwrite.is_open()){
        cout<<"Не удалось открыть файл"<<endl;
            return;}
        for(int n = 0; n < i; n++){
            if(arr[n].status!=0){
            for(int n1 = 0; n1 < i1; n1++){
                if(arr[n].range==arr1[n1].name){
            


        int c, c1, _x, _y, _l;
        _x = arr1[n1].endX-arr1[n1].startX;
        _y = arr1[n1].endY-arr1[n1].startY;
        c=sqrt(pow(_x,2)+pow(_y,2));//длина всего пути
        c1=t*arr[n].speed; //пройден путь за время
        _l = sqrt(pow(_x,2)+pow(_y,2));//длина направляющего вектора
        int _t=c/arr[n].speed;//требуемое время
        arr[n].time= arr[n].time+t;
        arr[n].timeEnd=_t-t;
        arr[n].x=_x*c1/_l;
        arr[n].y=_y*c1/_l;
        if(arr[n].time<=0){
            cout<<"Самолет "<< arr[n].model <<" прибыл в пункт назначения"<<endl;
            arr[n].time=0;
            arr[n].status=0;
            arr[n].timeEnd=0;
            arr[n].x=0;
            arr[n].y=0;
            arr[n].range="No";
        }
            }}
            fwrite << arr[n].model << arr[n].pilot << " " << arr[n].range << " " << arr[n].speed << " " << arr[n].status<< " " << arr[n].time<<" "<< arr[n].x<<" "<<arr[n].y<<" "<<arr[n].timeEnd<< endl;
            
        }


    
        fwrite.close();
}
}