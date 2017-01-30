inherit "obj/weapon.c";
#include "/players/jareel/ansi.h"

reset(arg) {
  ::reset(arg);
  if (arg) return;
  
  set_name("hell scourge");
  set_alias("scourge");

set_short(BOLD+RED+"Hell Scourge"+NORM);

set_type("exotic");

set_long(BOLD+RED+"This unique weapon is a five-thronged whip made from the bone, entrails,\n" +
"and sinew of gods and heroes slain before time began.  Lighter than a feather\n" +
"the weapon embraces the grasp of a powerful warrior, hungering for the kill\n"+NORM);
  set_class(20);
  set_weight(1);
  set_value(10000);
  set_hit_func(this_object());
  set_save_flag(1);
}

weapon_hit(ob) {
    int spell;
         object me;
    me = wielded_by;
    if(!me) me = environment();
    if(!me) return;
    if(!living(me)) return;
    if(!ob) return;

spell = me->query_sp();

if(spell > 500) {
   write(BOLD+RED+"The Hell Scourge feels satiated\n"+NORM);
say(BOLD+RED+me->query_name()+"'s Hell Scourge rips into its foe.\n"+NORM);
  me->add_spell_point(random(10));
  me->heal_self(random(5));
  ob->heal_self(-random(9)-5);
  me->add_alignment(-2);
  return 3;
}

if(spell > 390 && spell < 420) {
write(BOLD+RED+"The Hell Scourge feeds upon your soul, lashing out violently!!!\n"+NORM);
say(BOLD+RED+me->query_name()+"'s Hell Scourge lashes out violently!!!\n"+NORM);
      me->heal_self(-random(5));
      ob->heal_self(-random(5)-3);
      me->add_alignment(-2);
return 3;
}

if(spell > 220 && spell < 300) {
   write(BOLD+RED+"The Hell Scourge rips at your soul!!!\n"+NORM);
   say(BOLD+RED+me->query_name()+"'s Hell Scourge slashes at "+ob->query_name()+"\n"+NORM);
         me->heal_self(-5);
         ob->heal_self(-5);
         me->add_alignment(-2);
return 3;
}

if(spell > 1 && spell < 49) {
   write("The Hell Scourge rips energy from your soul!!!\n");
         me->heal_self(-10);
         me->add_alignment(-2);
return 1;
}
}
