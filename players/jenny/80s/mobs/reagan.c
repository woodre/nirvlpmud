inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "Ronald Reagan" ||  str == "ronald reagan" || str == "ronald" || str == "reagan" || str == "president"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Ronald Reagan");
    set_race("human");
set_gender("male");
    set_al(25+random(10));
    set_level(15);
    set_hp(220+random(20));
    set_wc(18+random(2));
    set_ac(13);
    set_short(BOLD+HIR+"Ronald Reagan"+NORM);
    set_long(
      "Ronald Reagan is a very tall elderly gentlemen.  He has short\n"+
      "wavy dark hair, and is wearing a three piece suit.  He was\n"+
     "President of the United States from 1980-1988, although you\n"+
      "may also remember him as an actor in old western films.  This\n"+
      "conservative Republican was a charismatic President whom\n"+
     "the country loved.  He is also responsible for racking up a\n"+
     "huge national debt, in part by spending a mind boggling\n"+
      "amount of money on national defense.\n");
set_chat_chance(12);
    load_chat(HIR+"President Reagan says: "+NORM+" I don't remember anything about Iran-Contra.\n");
MOCO("/players/jenny/80s/items/beans.c"),this_object());
}
