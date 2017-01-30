inherit "/obj/monster";
#include "/players/jareel/define.h"
    int number;
string mobname;
reset(arg)
{
    number = random(5);
   ::reset(arg);
        if (arg) return;
        set_race("broo");
        set_al(-1000);
set_ac(14);
set_wc(24);
set_hp(350);
set_level(17);
add_money(1800+random(300));
    
        if(number == 0) {mobname = "A "+BOLD+RED+"Broo"+NORM;}
        if(number == 1) {mobname = "A "+BOLD+GRN+"Broo"+NORM;}
        if(number == 2) {mobname = "A "+BOLD+YEL+"Broo"+NORM;}
        if(number == 3) {mobname = "A "+BOLD+MAG+"Broo"+NORM;}
        if(number == 4) {mobname = "A "+BOLD+BLK+"Broo"+NORM;}
                     
set_name(mobname);
set_short(mobname);
    set_long(
"This creature embodies the essence of chaos, with a human body and \n"+
"the head of a goat.  Putrid green bile pusses from several open sores. \n"+
"Your stomach starts to turn as you gaze upon this vile creature. \n");
set_spell_mess1("The broo lowers his head and charges his foe.\n");
set_spell_mess2("The broo lowers his head and charges at you.\n"+
                               "                T H U D !\n"+
                               "The broo runs into you hard.\n");
set_chance(5);
set_spell_dam(30);
}
