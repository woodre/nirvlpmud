inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("rosco p. coltrane");
    set_alt_name("rosco p. coltrane");
    set_race("rosco");
    set_alias("coltrane");
set_gender("male");
    set_al(-(200+random(110)));
    set_level(12);
    set_hp(160+random(40));
    set_wc(14+random(4));
MOCO("/players/jenny/dukes/items/hat.c"),this_object());
init_command("wear hat");
    set_ac(7+random(3));
    set_short(BOLD+""+HIB+"Rosco P. Coltrane"+NORM);
    set_long(
      "Rosco is the bungling sheriff of Hazzard County.  He is a tall\n"+
      "man with greying hair.  He is wearing his blue sheriff's uniform.\n"+
     "Rosco wants nothing more than to put those Duke boys in jail.\n"+
      "He has a few things working against him though.  He is one of\n"+
      "the worst drivers in Hazzard County, and if brains were dynamite\n"+
     "old Rosco wouldn't be able to blow his nose.  He is the brother in\n"+
     "law of Boss Hogg.\n");
set_chat_chance(25);
    load_chat(""+CYN+"Rosco says: "+NORM+" I'll cuff'em and stuff'em."+NORM+"\n");
    load_chat(""+CYN+"Rosco says: "+NORM+" I love it.  I love it."+NORM+"\n");
  gold=clone_object("obj/money");
  gold->set_money(400+random(100));
  move_object(gold,this_object());
}
