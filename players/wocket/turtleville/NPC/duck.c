#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
   ::reset(arg);
  if(arg) return 1;

set_name("duck");
set_race("seussian");
set_long("A little duck with its webbed feet and its orange beak.\n"+
         "It looks like most ducks should look like.  It's feathers\n"+
         "puff out slightly from the water.\n");  
set_level(10);
set_hp(150);
set_wc(14);
set_ac(8);
set_chat_chance(10);
load_chat("Duck waddles around.\n");
load_chat("Duck flaps it's wings.\n");
load_chat("Duck quacks.\n");
load_chat("Duck waggles it's tail.\n");
switch(random(5)){
case 0: cute();
        break;
case 1: ugly();
        break;
case 2: brave();
        break;
case 3: scared();
        break;
case 4: average();
        break;
}
}

cute(){
set_short("A brown duck");
}

ugly(){
set_short("An ugly duck");
}

brave(){
set_short("A brave duck");
}

scared(){
set_short("A scared duck");
}

average(){
set_short("A regular duck");
}

