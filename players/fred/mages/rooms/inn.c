
#include "room.h"
#define FOODS 1
#define Level this_player()->query_level()
#define Name this_player()->query_name()
#define Speak(s)\
 write("Someone says: "+s+"\n")

int cm,mm,rmm;
string last_eater;

#undef EXTRA_RESET
#define EXTRA_RESET\
 cm=FOODS*100;\
 mm=FOODS*100;\
 rmm=FOODS*100;\
  if(arg) return;\
  items=({"menu","The menu looks like this"});

ONE_EXIT("/players/fred/mages/rooms/hall","north",
"The Black Circle Inn",
"You are in the Black Circle Restaurant.  It is a very strange place.\n"+
"Magical Blue lights cast strange shadows on the wall.  An invisible waiter\n"+
"is here to take your order.\n",1)

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
write("1: Small Meal   40 gp\n");
write("2: Large Meal  100 gp\n");
write("3: Grand Feast 200 gp\n");
write("4: Black Ale    10 gp\n");
  write("\n");
  write("Use 'buy <number>' to buy the desired Food. The food should\n"+
        "be consumed on the premises.\n\n");
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
if(s=="1"||s=="<1>") {
  if(!cm) return no_food();
  if(!eat_ok(2)) return 1;
  if(!pays(40)) return 1;

  write("You enjoy a small but nourishing meal.\n");
  say(Name+" enjoys a small but nourishing meal.\n");
  cm=cm-1;
  return tease(10);
 }
 if(s=="2"||s=="<2>") {
  if(!mm) return no_food();
  if(!eat_ok(3)) return 1;
  if(!pays(100)) return 1;
  write("You enjoy a large, nourishing meal.\n");
  say(Name+" enjoys a large, nourishing meal.\n");
  mm=mm-1;
  return tease(25);
 }
 if(s=="3"||s=="<3>") {
  if(!rmm) return no_food();
  if(!eat_ok(4)) return 1;
  if(!pays(200)) return 1;
  write("You enjoy a Grand Feast - very delicious.\n");
  say(Name+" hogs out and chows down a Grand Feast.\n");
  rmm=rmm-1;
  return tease(50);
 }
 if(s=="4"||s=="<4>"||s=="ale"||s=="crimson ale") {
  if(!pays(10)) return 1;
  if(!this_player()->drink_alcohol(2)) {
   Speak("You look a little too drunk for that..let me take it back.");
   this_player()->add_money(10);
   return 1;
  }
  write("You drink a cup of Crimson Ale - That feels good.\n");
  say(Name+" gulps down a cup of Crimson Ale.\n");
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
