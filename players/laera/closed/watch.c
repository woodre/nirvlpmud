#include "/players/francesco/univ/ansi.h"
inherit "obj/treasure.c";
   int mm1, mm2, hh1, hh2;

string *ciph1;
string *ciph2;
string *ciph3;
string *ciph4;
string *a;
string *p;
string *m;
string *c;
string *s;
string *t;
string *e;
string *a1;
string *a2;
string hh;
int dummy, counter, tu, hhh, alarm;

reset(arg)
{
    if(arg) return;

ciph1 = ({"","","","",""});
ciph2 = ({"","","","",""});
ciph3 = ({"","","","",""});
ciph4 = ({"","","","",""});
a1 = ({"","","","",""});
a2 = ({"",
      "  __  ",
      " |    ",
      "  --  ",
      " |__  "});

a = ({"",
      "  __  ",
      " |  | ",
      "  --  ",
      " |  | "});
p = ({"",
      "  __  ",
      " |  | ",
      "  --  ",
      " |    "});
m = ({"",
      "      ",
      " |\\/| ",
      " |  | ",
      " |  | "});
c = ({"",
      "  __  ",
      " |    ",
      " |    ",
      " |__  "});
e = ({"",
      "  __  ",
      " |    ",
      "  --  ",
      " |__  "});
s = ({"",
      "  __  ",
      " |    ",
      "  --  ",
      "  __| "});
t = ({"",
      "  ___ ",
      "   |  ",
      "   |  ",
      "   |  "});

counter = 0;
dummy = 0;
tu=1;
}

short() { return HIY+"A golden watch"+NORM; }

long(str) {
    write("This is a wonderful golden watch indeed!  And also the chain\n"+
          "is very nice.  You can 'view time' and 'tune watch'.  On the\n"+
          "back, there is something more to view.\n");
	return;
    }

init() {
  ::init();
  add_action("trade","trade");
  add_action("view","view");
  add_action("read","read");
  add_action("tune","tune");
  add_action("alarm","alarm");
}


alarm(str) {
  if(!str) { notify_fail("What do you want to alarm?\n"); return 0; }
  if(str=="watch") {write("The alarm can be set at every minute of the hour.\n"+
                          "Alarm #, to set the desired minute.\n");
                   return 1;}
  if(atoi(str)>= 59 || atoi(str)<0) {
           notify_fail("The alarm can be set in the range 0-59.\n");
           return 0;}
  alarm = atoi(str);
    write(""+alarm+"\n");
  ring();
return 1;
}

ring() {
    hh = extract(ctime(time()),14,15);
    hhh=atoi(hh);
    write(""+hhh+"\n");
    if(hhh==alarm) get_time();  
    call_out("ring",20);
return 1;}

tune(str) {
  if(!str) { notify_fail("What do you want to tune?\n"); return 0; }
  if(str=="watch") {
    write("The watch can be tuned to EST, CST, MST, PST.\n"+
          "Syntax is:  tune est, tune cst, tune mst, tune pst.\n");
    return 1;}
  if(str=="est") {a2=e; tu = 1; write("Ok, the watch is tuned to east standard time.\n");}
  if(str=="cst") {a2=c; tu = 2; write("Ok, the watch is tuned to central standard time.\n");}
  if(str=="mst") {a2=m; tu = 3; write("Ok, the watch is tuned to mountain standard time.\n");}
  if(str=="pst") {a2=p; tu = 4; write("Ok, the watch is tuned to pacific standard time.\n");}
return 1;
}

trade(str){            /* drawback.  to make full price it must be sold to narrator */
  if(!str) { notify_fail("What do you want to trade?\n"); return 0; }
    if(str=="watch"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  'Thank you, thank you, I lost\n"+
            "this wonderful watch ages ago, and now I am very happy\n"+
            "that you brought it back to me.  Please, take these \n"+
            "coins as a sincere mark of thanks.'\n");
      call_other(this_player(),"add_money",(2500));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}    

view(str) {       
   if(!str) { notify_fail("What do you want to view?\n"); return 0; }
   if(str=="the back")  {write("On the back of the watch there are some engravings to read.\n"); return 1;}
   if(str=="time") get_time();
   return 1;}   
/*150*/
get_time() {
   string m1, m2, h2, h1;
    hh = extract(ctime(time()),11,12);
    if(tu == 1) hhh = atoi(hh);
    if(tu == 2) {hhh = atoi(hh) - 1; if(hhh < 0) hhh = hhh + 24;}
    if(tu == 3) {hhh = atoi(hh) - 2; if(hhh < 0) hhh = hhh + 24;}
    if(tu == 4) {hhh = atoi(hh) - 3; if(hhh < 0) hhh = hhh + 24;}

     m1 = extract(ctime(time()),14,14);
     m2 = extract(ctime(time()),15,15);

     if(hhh<10) {hh1=10;a1=a; hh2=hhh;} 
     if(hhh>= 10) {
       if(hhh < 20) {
       hh1=1; hh2=hhh-10;
       if(hh2==1) {hh1=1;hh2=1;a1=a;}
       if(hh2==2) {hh1=1;hh2=2;a1=a;}
       if(hh2==3) {hh1=10;hh2=1;a1=p;}
       if(hh2==4) {hh1=10;hh2=2;a1=p;}
       if(hh2==5) {hh1=10;hh2=3;a1=p;}
       if(hh2==6) {hh1=10;hh2=4;a1=p;}
       if(hh2==7) {hh1=10;hh2=5;a1=p;}
       if(hh2==8) {hh1=10;hh2=6;a1=p;}
       if(hh2==9) {hh1=10;hh2=7;a1=p;}
     }}
     if(hhh >= 20) {
       hh1=2; hh2=hhh-20;
       if(hh2==0) {hh1=10;hh2=8;a1=p;}
       if(hh2==1) {hh1=10;hh2=9;a1=p;}
       if(hh2==2) {hh1=1;hh2=0;a1=p;}
       if(hh2==3) {hh1=1;hh2=1;a1=p;}
       if(hh2==4) {hh1=1;hh2=2;a1=p;}
     }
                   dummy = hh1; counter++; cipher();
                   dummy = hh2; counter++; cipher();
     mm1=atoi(m1); dummy = mm1; counter++; cipher();
     mm2=atoi(m2); dummy = mm2; counter++; cipher();
/* line 65 */
  write("\n  "+ciph1[1]+""+ciph1[2]+BLINK+"  "+NORM+""+ciph1[3]+""+ciph1[4]+"    "+a1[1]+""+m[1]+"    "+a2[1]+""+s[1]+""+t[1]+"\n");
    write("  "+ciph2[1]+""+ciph2[2]+BLINK+" ."+NORM+""+ciph2[3]+""+ciph2[4]+"    "+a1[2]+""+m[2]+"    "+a2[2]+""+s[2]+""+t[2]+"\n");
    write("  "+ciph3[1]+""+ciph3[2]+BLINK+"  "+NORM+""+ciph3[3]+""+ciph3[4]+"    "+a1[3]+""+m[3]+"    "+a2[3]+""+s[3]+""+t[3]+"\n");
    write("  "+ciph4[1]+""+ciph4[2]+BLINK+" ."+NORM+""+ciph4[3]+""+ciph4[4]+"    "+a1[4]+""+m[4]+"    "+a2[4]+""+s[4]+""+t[4]+"\n\n");
    counter=0;
return 1;}   

cipher() {
   switch(dummy) {
     case 1 :  one()   ; break;
     case 2 :  two()   ; break;
     case 3 :  three() ; break;
     case 4 :  four()  ; break;
     case 5 :  five()  ; break;
     case 6 :  six()   ; break;
     case 7 :  seven() ; break;
     case 8 :  eight() ; break;
     case 9 :  nine()  ; break;
     case 0 :  zero()  ; break;
     case 10:  null()   ; break;
   return 1;}
}

one() {
  ciph1[counter] = "     ";
  ciph2[counter] = "   | ";
  ciph3[counter] = "   | ";
  ciph4[counter] = "   | ";
return 1;}

two() {
  ciph1[counter] = "  __  ";
  ciph2[counter] = "    | ";
  ciph3[counter] = "  --  ";
  ciph4[counter] = " |__  ";
return 1;}

three() {
  ciph1[counter] = "  __  ";
  ciph2[counter] = "    | ";
  ciph3[counter] = "  --  ";
  ciph4[counter] = "  __| ";
return 1;}

four() {
  ciph1[counter] = "      ";
  ciph2[counter] = " |  | ";
  ciph3[counter] = "  --  ";
  ciph4[counter] = "    | ";
return 1;}

five() {
  ciph1[counter] = "  __  ";
  ciph2[counter] = " |    ";
  ciph3[counter] = "  --  ";
  ciph4[counter] = "  __| ";
return 1;}

six() {
  ciph1[counter] = "  __  ";
  ciph2[counter] = " |    ";
  ciph3[counter] = "  --  ";
  ciph4[counter] = " |__| ";
return 1;}

seven() {
  ciph1[counter] = "  __  ";
  ciph2[counter] = " |  | ";
  ciph3[counter] = "    | ";
  ciph4[counter] = "    | ";
return 1;}

eight() {
  ciph1[counter] = "  __  ";
  ciph2[counter] = " |  | ";
  ciph3[counter] = "  --  ";
  ciph4[counter] = " |__| ";
return 1;}

nine() {
  ciph1[counter] = "  __  ";
  ciph2[counter] = " |  | ";
  ciph3[counter] = "  --  ";
  ciph4[counter] = "  __| ";
return 1;}

zero() {
  ciph1[counter] = "  __  ";
  ciph2[counter] = " |  | ";
  ciph3[counter] = " |  | ";
  ciph4[counter] = " |__| ";
return 1;}

null(){
  ciph1[counter] = "";
  ciph2[counter] = "";
  ciph3[counter] = "";
  ciph4[counter] = "";
return 1;}

read(str) {       
  if(!str) { notify_fail("What do you want to read?\n"); return 0; }
   if(str=="engravings")  {write("Property of Runi, the narrator.\n"); return 1;}
   notify_fail("What do you want to read?\n"); return 0;
}

id(str) { return str == "watch" || str=="golden watch" ; }

query_weight() { return 1; }

query_value() { return (3500); }

