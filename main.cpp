#include <bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#include <fstream>
#include <clocale>
#include "conio.h"
#include <ctime>
#define ble_prod
using namespace std;

deque < pair < int , pair < int , string > > > ve;
int pos=0;
clock_t start_time;
clock_t finish_time;
string s,nick="C:/ProgramData/InvokerGame/last.txt",
         record="C:/ProgramData/InvokerGame/Record/record.txt";
bool play=false;

int  v,   mise,
  oldv,oldmise;

string menu[]     = {"Play",  "Education", "Account", "Records", "Exit"};
string menuE[]     = {"Castes",  "Biography", "Back"};
string  bpr="                ", lpr="        ",probel="             ";

void new_new_record(){
    ofstream file(record);
    file << "";
}
void _new_record(){
    ifstream file(nick);
    if (!file.is_open()) new_new_record();
}
void new_last(){
    _new_record();
    ofstream file("C:/ProgramData/InvokerGame/last.txt");
    file << 0 << " " << 0;
}
bool ShowConsoleCursor(bool bShow) {
    CONSOLE_CURSOR_INFO cci;
    HANDLE hStdOut;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hStdOut == INVALID_HANDLE_VALUE)
        return FALSE;
    if(!GetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    cci.bVisible = bShow;
    if(!SetConsoleCursorInfo(hStdOut,&cci))
        return FALSE;
    return TRUE;
}
void save(){
    system("cls");
//    cout << oldv << " " << oldmise << endl;
//    cout << v << " " << mise << endl;
    ofstream file(nick);
    if (oldv==0 && oldmise==0) file << v << " " << mise;
    else
    {
      if (v==oldv)
      {
        if (mise<oldmise) file << v << " " << mise;
        if (oldmise<mise) file << v << " " << oldmise;
      } else
      if (v>oldv) file << v << " " << mise;
      else file << oldv << " " << oldmise;
    }
    file.close();
}

//Education
void Menu1ED(int pos1) {
    system("cls");
    cout << endl;
    for (int i=0; i<3; i++) {
        if (i==pos1)
             cout << "        -> ";
        else cout << "           ";
        cout << menuE[i] << endl;
    }
}
void Biography(){
    system("cls");
    cout << endl;
    cout << "                                A literate wizard knows perhaps two spells; Exceptional - three or four." << endl
    << "        Featuring elements of Quas, Wex, and Exort, Invoker outperforms them all. He summons Forge Spirits, granting them Alacrity to stun them with Cold Snap." << endl
    << "     Anticipating the movement of the enemy, Invoker will use Sun Strike anywhere in the world, then disappear into the Ghost Walk, leaving an impenetrable Ice Wall to " << endl
    << "     prevent pursuers from catching up with him. A strong Tornado lifts opponents into the air while EMP waits for them to drain their mana upon landing. " << endl
    << "        Incoming enemies are pushed back with Deafening Blast, giving Invoker enough time to unleash Chaos Meteor on them." << endl << endl;
    getch();
}
/*void Biography(){
    system("cls");
    cout << endl << endl;
    cout << "   VSEM PRIVER MENYA ZOVYT KOLDYN\n",Sleep(1200);
    cout << "   VSEM POKA)";
    getch();
}*/
void Castes() {

    system("cls");
    cout << endl;
    cout << "  Cold Snap (q q q)" << "    E.M.P.  (w w w)" << "    Sun Strike  (e e e)" << endl;
    cout << "  Ghost Walk(q q w)" << "    Tornado (w w q)" << "    Forge Spirit(e e q)" << endl;
    cout << "  Ice Wall  (q q e)" << "    Alacrity(w w e)" << "    Chaos Meteor(e e w)" << endl << endl;
    cout << "                Deafiling Blast(q w e)";
    getch();
}
void MenuED() {
    system("cls");
    int pos1=0;
    while (true) {
        Menu1ED(pos1);
        char c=getch();
        if ((c=='w' || c==72) && pos1==0) pos1=3;
        if ((c=='s' || c==80) && pos1==2) pos1=-1;
        if ((c=='w' || c==72) && pos1>0) pos1--;
        if ((c=='s' || c==80) && pos1<2) pos1++;
        if (menuE[pos1]=="Castes"    && c==13) Castes();
        if (menuE[pos1]=="Biography" && c==13) Biography();
        if (menuE[pos1]=="Back"      && c==13) break;
    }
}

//Play
void StartPlay(){
    ifstream file(nick);
    file >> oldv >> oldmise;
    system("cls");
}
void RandCust(){
    char q[10]={'A','B','C','D','F','S','V','Z','X','N'};
    srand(time(0));
    random_shuffle(q,q+10);
    if (q[0]=='A') s="Sun Strike",   cout << s; //eee
    if (q[0]=='B') s="Ice Wall",     cout << s; //qqe
    if (q[0]=='C') s="Forge Spirits",cout << s; //eeq
    if (q[0]=='D') s="Alacrity",     cout << s; //wwe
    if (q[0]=='F') s="Chaos Meteor", cout << s; //eew
    if (q[0]=='S') s="Ghost Walk",   cout << s; //qqw
    if (q[0]=='V') s="E.M.P.",          cout << s; //www
    if (q[0]=='Z') s="Tornado",      cout << s; //wwq
    if (q[0]=='X') s="Cold Snap",    cout << s; //qqq
    if (q[0]=='N') s="Deafining Blast",cout << s; //qwe
}
void stop(){
    finish_time = clock();
    system("cls");
    mise=finish_time-start_time;

    ofstream file(nick);
    if (oldv==0 && oldmise==0) file << v << " " << mise;
    else
    {
      if (v==oldv)
      {
        if (mise<oldmise) file << v << " " << mise;
        if (oldmise<mise) file << v << " " << oldmise;
      } else
      if (v>oldv) file << v << " " << mise;
      else file << oldv << " " << oldmise;
    }
    file.close();

    int se=0,mi=0;
    if (mise>1000) se=mise/1000, mise=mise%1000;
    if (se>60) mi=se/60, se=se%60;

    cout << "Time:" << endl
    << setfill('0') << setw(2) << mi << ":"
    << setfill('0') << setw(2) << se << ":"
    << setfill('0') << setw(3) << mise%1000 << endl;

    cout << "Score:" << v << endl;
    Sleep(200); getch();

}
int Play(){
    StartPlay();
    bool t=false;
    bool f=true;
    v=0;
    while (f) {
        play=true;
        system("cls");
        char z,x,c;
        cout << "\n\n\n       " << v << "  ",RandCust(),cout << "\n\n\n        ";
        z=getch(); cout << z;
        if (!t) t=true, start_time = clock();
        if (z!='e' && z!='w' && z!='q') {stop(); return 0;}
        x=getch(); cout << x;
        if (x!='e' && x!='w' && x!='q') {stop(); return 0;}
        c=getch(); cout << c;
        if (c!='e' && c!='w' && c!='q') {stop(); return 0;}
        if (s=="E.M.P."            && (z=='w' && x=='w' && c=='w')) v++; else
        if (s=="Sun Strike"     && (z=='e' && x=='e' && c=='e')) v++; else
        if (s=="Cold Snap"      && (z=='q' && x=='q' && c=='q')) v++; else
        if (s=="Forge Spirits"  && ((z=='e'&& x=='e' && c=='q') || (z=='q' && x=='e' && c=='e') || (z=='e' && x=='q' && c=='e'))) v++; else
        if (s=="Alacrity"       && ((z=='w'&& x=='w' && c=='e') || (z=='e' && x=='w' && c=='w') || (z=='w' && x=='e' && c=='w'))) v++; else
        if (s=="Chaos Meteor"   && ((z=='e'&& x=='e' && c=='w') || (z=='w' && x=='e' && c=='e') || (z=='e' && x=='w' && c=='e'))) v++; else
        if (s=="Ghost Walk"     && ((z=='q'&& x=='q' && c=='w') || (z=='w' && x=='q' && c=='q') || (z=='q' && x=='w' && c=='q'))) v++; else
        if (s=="Tornado"        && ((z=='w'&& x=='w' && c=='q') || (z=='q' && x=='w' && c=='w') || (z=='w' && x=='q' && c=='w'))) v++; else
        if (s=="Ice Wall"       && ((z=='q'&& x=='q' && c=='e') || (z=='e' && x=='q' && c=='q') || (z=='q' && x=='e' && c=='q'))) v++; else
        if (s=="Deafining Blast"&& ((z=='q'&& x=='w' && c=='e') || (z=='q' && x=='e' && c=='w') ||
                                  (z=='e'&& x=='w' && c=='q') || (z=='e' && x=='e' && c=='w') ||
                                  (z=='w'&& x=='e' && c=='q') || (z=='w' && x=='q' && c=='e'))) v++; else f=false;
    }
    system("cls");
    stop();
    return 0;
}

//Record
void new_record(){
    ofstream file(record, ios_base::app);
    file << endl << nick;
}
void readln(string recnick){
    ifstream file(recnick);
    int recv,recmise;
    file >> recv >> recmise;
    recnick.erase(0,27);
    ve.push_back({recv,{recmise,recnick}});
}
void Records(){
    system("cls");
    ve.clear();
    ifstream rec(record);
    bool f=false;
    while (!rec.eof()){
        string recnick; rec >> recnick;
        if (recnick!="") f=true;
        readln(recnick);
    }
  if (f)
  {
    sort(ve.begin(),ve.end()); reverse(ve.begin(),ve.end());
    for (auto u : ve){
        int recmise=u.second.first;
        int recse=0,
            recmi=0;
        if (recmise>1000) recse=recmise/1000;
        if (recse>60) recmi=recse/60, recse=recse%60;
        cout << endl;
        cout << "    " << u.second.second.substr(0,u.second.second.size()-4) << endl;
        cout << "    Score:" << u.first << endl;
        cout << "    Time: "
             << setfill('0') << setw(2) << recmi << ":"
             << setfill('0') << setw(2) << recse << ":"
             << setfill('0') << setw(3) << recmise%1000 << endl << endl;
    }
  } else cout << "No accounts yet";
    Sleep(200); getch();
}

//Account
void _new(){
    ofstream file(nick);
    new_record();
    file << 0 << " " << 0;
}
void lastyes(){
    ifstream file("C:/ProgramData/InvokerGame/last.txt");
    file >> v >> mise;
}
void Yes(){
    nick+=".txt";
    nick="C:/ProgramData/InvokerGame/"+nick;
    ifstream file(nick);
    if (!file.is_open()) _new();
    file >> oldv >> oldmise;
    lastyes();
    save();
    system("cls");
}
void No(){
    nick+=".txt";
    nick="C:/ProgramData/InvokerGame/"+nick;
    ifstream file(nick);
    if (!file.is_open()) _new();
    file >> oldv >> oldmise;
    system("cls");
}
int Account(){
    system("cls");
    bool last=false;
    if (nick=="C:/ProgramData/InvokerGame/last.txt") last=true;
    cout << "Write your nick\n";
    cin >> nick;
    if (nick=="last") cout << "Error\n";
    else if (last && play) Yes();
    else                   No();
    return 0;
}

//Menu
void Menu1E(int pos){
    system("cls");
    cout << endl;
    for (int i=0; i<5; i++) {
        if (i==pos)
             cout << "        -> ";
        else cout << "           ";
        cout << menu[i] << endl;
    }
}
int main(){
    SetConsoleTitle("InvokerGame");
    mkdir("C:/ProgramData/InvokerGame");
    mkdir("C:/ProgramData/InvokerGame/Record");
    new_last();
    ShowConsoleCursor(FALSE);
    while(true) {
        system("color 0B");
        while (true) {
            Menu1E(pos);
            char c=getch();
            if ((c=='w' || c==72) && pos==0) pos=5;
            if ((c=='s' || c==80) && pos==4) pos=-1;
            if ((c=='w' || c==72) && pos>0)  pos--;
            if ((c=='s' || c==80) && pos<4)  pos++;
            if (c=='c') ShellExecute(0,"open","https://www.youtube .com/watch?v=YLt73w6criQ&t=250s",NULL,NULL,SW_SHOWDEFAULT);
            if (c==13) break;
        }
        if (menu[pos]=="Play")      Play();
        if (menu[pos]=="Education") MenuED();
        if (menu[pos]=="Account")   Account();
        if (menu[pos]=="Records")   Records();
        if (menu[pos]=="Exit")      GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT,0);
    }
}
// http://www.youtube.com/watch?v=YLt73w6criQ&t=250s
