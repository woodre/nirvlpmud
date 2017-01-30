inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "bill cosby" ||  str == "bill" || str == "cosby" || str == "Bill Cosby"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Bill Cosby");
    set_race("human");
set_gender("male");
    set_al(100+random(10));
    set_level(15);
    set_hp(220+random(10));
    set_wc(19+random(2));
    set_ac(12);
    set_short(BOLD+HIR+"Bill Cosby"+NORM);
    set_long(
      "Bill Cosby is a tall, older looking black man.  He is wearing\n"+
      "a very colorful sweater.  In the 80's, this comedian was the star\n"+
     "of the extremely popular Cosby Show.  He would also make\n"+
      "commercials hawking almost any product.\n");
set_chat_chance(18);
    load_chat(HIR+"Bill Cosby says: "+NORM+" I like the new coke even better\n"+
"than the old coke.\n");
MOCO("/players/jenny/80s/items/coke.c"),this_object());
}
