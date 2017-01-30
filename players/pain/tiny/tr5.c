/* Shamelessly stolen from Eurale */
#include "/players/eurale/closed/ansi.h"
#include "room.h"
/* this constant should be 1 for virgin Mud's */
/* #define FOODS = 5  */
#define Level this_player()->query_level()
#define Name this_player()->query_name()
#define Speak(s)\
 write("Waiter says: "+s+"\n")

int cm,mm,rmm;
string last_eater;

#undef EXTRA_RESET
#define EXTRA_RESET\
  cm = 30;\
  mm = 25;\
 rmm = 20;\
  if(arg) return;\
  items=({"menu","The menu looks like this"});

ONE_EXIT("players/pain/tiny/tr3.c","east",
"The "+RED+"Grill"+NORM,
"You are in the "+RED+"Grill"+NORM+" of the Wizard's Club. \nHere you can buy food to still your\n"+
"hunger, but only a limited selection is available and only in\n"+
"limited quantities.  There is a menu posted on the wall.\n",
1)

init() {
 add_action("buy","buy");
 add_action("buy","order");
 ::init();
}

long(s) {
 ::long(s);
 show_menu();
}

show_menu() {
 write("\n");
 if(!(cm||mm||rmm)) 
  Speak("We have completely sold out...come back later.");
 else {
  write("1: Club Sandwich            ");write(cm);write(" at 210 gp\n");
  write("2: Club Burger              ");write(mm);write(" at 300 gp\n");
  write("3: Club Steak               ");write(rmm);write(" at 350 gp\n");
  write("4: A Mug of Beer            ");write(" ");write("    10 gp\n");
  write("\n");
  write("Use 'buy <number>' to buy the desired Food. The food will\n"+
        "be consumed at once. Good appetite.\n\n");
 }
 return;
}

no_food() {
 Speak("Sorry - we have sold out of that.");
 if(cm||mm||rmm)
  Speak("Why don't you try something else ?");
 else
  Speak("Why don't you come back later ?");
 return 1;
}

pays(n) {
 if(this_player()->query_money()<n) {
  Speak("You cannot afford that.");
  return 0;
 }
 this_player()->add_money(-n);
 return 1;
}

tease(n) {
 if(Name==last_eater)
  Speak("My - Are we hungry today.");
 last_eater=Name;
 this_player()->heal_self(n);
 return 1;
}

buy(s) {
 if(!s) {
  Speak("What do you want to buy ?");
  return 1;
 }

/* baked potato, price 210, heals 15 times 14 per pt  */
if(s=="1"||s=="<1>") {
  if(!cm) return no_food();
  if(!pays(210)) return 1;
  write("You are served a Club Sandwich - very nourishing\n");
  say(Name+" orders a Club Sandwich\n");
  call_other(this_player(),"eat_food",10);
  cm=cm-1;
  return tease(15);
 }

/* Leak soup, price 300, heals 25 times 12 per pt  */
 if(s=="2"||s=="<2>") {
  if(!mm) return no_food();
  if(!pays(300)) return 1;
  write("You are served a Club Burger - very good\n");
  say(Name+" orders a Club Burger\n");
  call_other(this_player(),"eat_food",12);
  mm=mm-1;
  return tease(25);
 }

/*  Beef stew, price 350, heals 35 times 10 per pt  */
 if(s=="3"||s=="<3>") {
  if(!rmm) return no_food();
  if(!pays(350)) return 1;
  write("You are served a HUGE steak - very delicious\n");
  say(Name+" orders a HUGE steak\n");
  call_other(this_player(),"eat_food",14);
  rmm=rmm-1;
  return tease(35);
 }
 if(s=="4"||s=="<4>"||s=="mug"||s=="beer") {
  if(!pays(50)) return 1;
  if(!this_player()->drink_alcohol(2)) {
   Speak("You look a little too drunk for that..let me take it back.");
   this_player()->add_money(50);
   return 1;
  }
  write("You drink a mug of first class beer - That feels good.\n");
  say(Name+" drinks a beer.\n");
  return 1;
 }
 Speak("We have no such number on the menu, try 1, 2 or 3.");
 return 1;
}

eat_ok(arg) {
    if (!call_other(this_player(), "eat_food", arg))
      {
         Speak("You look like your full.\n");
         return 0;
       }
     return 1;
}
