#include "/players/pestilence/define.h"
#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";
int OPEN;

reset(arg) {
  if(arg) return;

long_desc =
"    This is the west room of the guild complex.  There is a\n"+
"large row of lockers on the west wall, possible to keep weapons and\n"+
"armors in.  The walls are solid rock.\n";
set_light(1);

items = ({
"rocks","Large rocks that surround everything",
"lockers","A lockers system where u can buy, withdraw, deposit or list weapons",

});

dest_dir = ({
  "/players/pestilence/closed/destroyer/room/hall.c","east",
});
} 

short() {
    return ""+YEL+"Locker Room"+NORM+"";
}

realm() { return "NT"; }

init(){
   ::init();
   add_action("withdraw","withdraw");
   add_action("list", "list");
   add_action("deposit","deposit");
   add_action("buylocker","buy");
   add_action("clear","clear"); 
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }

deposit(str){
   "/players/catwoman/tl.c"->deposit_item(str);
   return 1;
}
buylocker(str){
   "/players/catwoman/tl.c"->buy_locker(str);
   return 1;
}
list(){
   "/players/catwoman/tl.c"->list();
   return 1;
}

withdraw(str){
   "/players/catwoman/tl.c"->withdraw_item(str);
   return 1;
}
clear(str){
   "/players/catwoman/tl.c"->clear(str);
   return 1;
}
