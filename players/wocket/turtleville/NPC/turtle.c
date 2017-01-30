#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset();
  if(arg) return 1;

set_name("turtle");
set_race("seussian");
set_long("A small gentle turtle.  Its green eyes stare at you underneath\n"+
         "its very protective shell.  Little stubby feet stick out in all\n"+
         "directions while a tail wiggles in the background.  It is oddly\n"+
         "large and strong for being a turtle.  The marsh must have some\n"+
         "strange effects.\n");
set_level(14);
set_hp(300);
set_wc(14);
set_ac(15);
set_dead_ob(this_object());
set_chat_chance(10);
load_chat("Turtle waddles around.\n");
load_chat("Turtle flips onto it's back.\n");
load_chat("Turtle sticks it's tongue out.\n");
load_chat("Turtle wiggles it's tail.\n");
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
set_short(HIG+"A cute turtle"+NORM);
}

ugly(){
set_short(HIG+"An ugly turtle"+NORM);
}

brave(){
set_short(HIG+"A brave turtle"+NORM);
}

scared(){
set_short(HIG+"A scared turtle"+NORM);
}

average(){
set_short(HIG+"A regular turtle"+NORM);
}

monster_died(){
    move_object(clone_object("/players/wocket/turtleville/OBJ/shell.c"),environment(this_object()));
return 0;
}
