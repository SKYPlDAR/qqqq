#include <fstream>
#include "Z.h"
#include <math.h>
                            //exit(EXIT_SUCCESS);
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
    int i = arr_s("jets.txt");
    jets arr[i];
    array(i,"jets.txt", arr);

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
    int i = arr_s("routes.txt");
    routes arr[i];
    array(i,"routes.txt", arr);
    
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

int nm::arr_s(string f_name){
        string line;
    int i = 0;
    ifstream fread;
    fread.open(f_name);
    if(!fread.is_open())
        return;
    while(getline(fread, line)){
        i++;
    }
    fread.close();
    return i;
}

void nm::array(int i, string f_name, routes*arr){
    ifstream fread;
    fread.open(f_name);
    if(!fread.is_open())
        return;
    routes editable;
    for(int n = 0; n < i; n++){
        fread >> editable;
        arr[n] = editable;
    }
    fread.close();
    routes editable;
    cout << "Enter name, start(x,y), end(x,y)" << endl;
    cin >> editable;
}

void nm::array(int i, string f_name, jets*arr){
    ifstream fread;
    fread.open(f_name);
    if(!fread.is_open())
        return;
    jets editable;
    for(int n = 0; n < i; n++){
        fread >> editable;
        arr[n] = editable;
    }
    fread.close();
    jets editable;
    cout << "Enter name, start(x,y), end(x,y)" << endl;
    cin >> editable;
}

void nm::vylet(){
    int j = arr_s("routes.txt");
    routes arr1[j];
    array(j,"routes.txt", arr1);

    int i = arr_s("jets.txt");
    jets arr[i];
    array(i,"jets.txt", arr);

    cout<< "Введите индекс желаемого маршрута для вылета"<<endl;
    int a;
    cin >>a;

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
        arr[index].range=arr1[a].name;
        arr[index].x=arr1[a].startX;
        arr[index].y=arr1[a].startY;
        int c=sqrt(pow(arr1[a].startX-arr1[a].endX,2)+pow(arr1[a].startY-arr1[a].endY,2));
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
    int j = arr_s("routes.txt");
    routes arr1[j];
    array(j,"routes.txt", arr1);

    int i = arr_s("jets.txt");
    jets arr[i];
    array(i,"jets.txt", arr);


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
            for(int m = 0; m < j; m++){
                if(arr[n].range==arr1[m].name){
            
        int c, c1, _x, _y, _l;
        _x = arr1[m].endX-arr1[m].startX;
        _y = arr1[m].endY-arr1[m].startY;
        c=sqrt(pow(_x,2)+pow(_y,2));//длина всего пути/направляющ вектора
        c1=t*arr[n].speed; //пройден путь за время
        int _t=c/arr[n].speed;//требуемое время
        arr[n].time= arr[n].time+t;
        arr[n].timeEnd=_t-t;
        arr[n].x=_x*c1/c;
        arr[n].y=_y*c1/c;
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