/*
  Carried by ~/chaos/mon/efreeti.c
This weapon reduced in power and made storable. 5/00 -snow
*/

inherit "obj/weapon.c";
#include "/players/snow/color.h"
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("battleaxe of flame");
    set_alias("battleaxe");
  set_short(BOLD+RED+"BattleAxe of Flame"+OFF+OFF);
   set_type("axe");
    set_long(
"This is a huge, wickedly curved blade with fire burning up and down its \n"+
"length. The fabled weapon of the Efreet, it is as wicked as they.\n");
    set_class(18);
    set_weight(4);
    set_value(8000);
    set_hit_func(this_object());
}

weapon_hit(ob) {
  object me;
  if(!ob) return;
  if(!environment()) return;
  me = environment();
  if(!living(me)) return;
  if(me->query_attrib("str") > random(60)) {
    write(BOLD+"Your "+RED+"BattleAxe"+OFF+BOLD+" burns through "+ob->query_name()+"!\n"+OFF);
    say(BOLD+me->query_name()+"'s "+RED+"BattleAxe"+OFF+BOLD+" burns through "+ob->query_name()+"!\n"+OFF);
    return 7;
  }
  if(!random(2)) {
    write("Your "+RED+"BattleAxe"+OFF+" burns with a "+RED+"reddish haze"+OFF+"!\n");
    }
  return 0;
}
 
