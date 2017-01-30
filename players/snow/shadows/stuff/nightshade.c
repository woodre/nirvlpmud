/*
Weapon of evil found on /pl/s/shadows/mon/death_knight.c
non-storable
*/
 
#include "/players/snow/closed/color.h"
 
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("nightshade");
    set_alias("broadsword");
    set_short(BOLD+"NightShade"+OFF+", the Broadsword of Death");
   set_type("sword");
    set_long(
"This broadsword belonged to Balathuil, the Death Knight. Its blade\n"+
"is as keen as any weapon you have ever seen. Dark shadows seem to wrap\n"+
"around it.\n");
    set_class(20);
    set_weight(5);
    set_value(10000);
    set_hit_func(this_object());
}

weapon_hit(ob) {
  object me;
  int heart, dam;
  if(!ob) return;
  if(!environment()) return;
  me = environment();
  if(!living(me)) return;
  heart = me->query_alignment();
  dam = -heart / 100;
  if(dam > 10) dam = 10;
  if(heart < 0 && ob->query_level() > random(40)) {
    write("Nightshade burns black with evil!\n");
    if(heart < ob->query_alignment()) {
     write(BOLD+"  Your soul pulses with evil pleasure!\n"+OFF);
      if(ob->is_player()) {
        ob->add_hit_point(-dam);
        return 4;            }
      if(dam > ob->query_hp()) dam = (ob->query_hp() - 1);
    ob->heal_self(-dam);
    }
return 4;
   }
       return;
}

quest_ob() { return 1; }
