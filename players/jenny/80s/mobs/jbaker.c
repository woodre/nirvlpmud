inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "jim baker" ||  str == "jim" || str == "baker" || str == "Jim Baker"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("Jim Baker");
    set_race("human");
set_gender("male");
    set_al(-(150+random(100)));
    set_level(12);
    set_hp(170+random(20));
    set_wc(15+random(3));
    set_ac(9);
    set_short(YEL+"Jim Baker"+NORM);
    set_long(
      "Jim Baker is an older gentleman, with grey hair and glasses.  He was\n"+
      "a television Evangelist during the 1980's.  Millions of people watched\n"+
      "him and donated money to his ministry.  Jim was involved in a few\n"+
     "sandals.  He confessed to adultery, for which anyone who has seen his\n"+
     "wife can forgive him, and he also was convicted of fraud.  He spent\n"+
     "his faithful followers money so lavishly, he even had an air conditioned\n"+
     "doghouse built.\n");
  gold=clone_object("obj/money");
  gold->set_money(500+random(200));
  move_object(gold,this_object());

set_chat_chance(10);
    load_chat(YEL+"Jim Baker confesses to his sins."+NORM+"\n");
}
