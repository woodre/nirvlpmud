inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "dancer" ||  str == "a break-dancer" || str == "break dancer" || str == "break-dancer"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("break-dancer");
    set_race("human");
set_gender("male");
    set_al(30+random(15));
    set_level(6); 
    set_hp(85+random(10));
    set_wc(10+random(2));
    set_ac(5);
    set_short("A break-dancer");
    set_long(
      "This is a thin young man who is wearing red leather pants,\n"+
      "decorated with 20 zippers, and a white t-shirt.  He is break-\n"+
     "dancing on the sidewalk, while listening to music from his\n"+
      "boombox.  Break dancing involves dancing on the ground,\n"+
      "spinning on your back, head, etc.  It is one of the most\n"+
      "ridiculous things to come out of the 80's.\n");
  gold=clone_object("obj/money");
  gold->set_money(220+random(60));
  move_object(gold,this_object());
}
