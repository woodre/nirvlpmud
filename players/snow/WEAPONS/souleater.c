/*
Souleater is a very powerful weapon. It is also very dangerous to the 
wielder and extremely hard to obtain. It drains spell points according
to the wielder's current total... if the wielder is low, the sword drains
both hit points and spell points. If the wielder has very few spell points,
Souleater will take away hit points at an incredible rate.
Souleater is possessed by /players/snow/MONSTERS/ogre_magi.c
and it is not storeable so the player who has this weapon had to go through
hell to get it.
It is approved for game play.
*/

inherit "obj/weapon.c";

#include "/players/snow/closed/cyber/color.h"

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("souleater");
    set_alias("sword");
    set_short(BOLD+"SoulEater"+OFF);
    set_type("sword");
    set_long("This sword seems to suck all light from its surroundings. \n" +
                   "You feel a pull at your very soul as you near it. This \n" +
                   "must be the legendary Souleater. \n");
    set_class(19);
    set_weight(1);
    set_value(10000);
    set_hit_func(this_object());
}

weapon_hit(ob) {
  int spell;
  object me;
  me = wielded_by;
  /* changed to this_player(), bog.  6.6.01 verte */
  if(!me) me = this_player();
  if(!me) return;
  if(!ob) return;
  spell = me->query_sp();
    if(spell > 300) {
  write(
BOLD+"SoulEater"+OFF+" glows a burning black!\n"+
"You feel a massive rush as your soul is partially drained.\n");
  say(me->query_name()+"'s "+BOLD+"SoulEater"+OFF+" glows a burning black!\n");
  me->add_spell_point(-10);
  ob->heal_self(-random(7)-5);
return 5;
  }
    if(spell > 200 && spell < 301) {
  write(
BOLD+"SoulEater"+OFF+" gleams a wicked black hue!\n"+
"Your soul is partially drained!\n");
  say(me->query_name()+"'s "+BOLD+"SoulEater"+OFF+" gleams a wicked black hue!\n");
  me->add_spell_point(-5);
  ob->heal_self(-random(5)-3);
return 5;
  }
    if(spell > 100 && spell < 201) {
  write(
BOLD+"SoulEater"+OFF+" hums in search of life energy!\n"+
"You are drained of some spell energy.\n");
  say(me->query_name()+"'s "+BOLD+"SoulEater"+OFF+" hums in search of life energy!\n");
  me->add_spell_point(-5);
  ob->heal_self(-random(3)-1);
return 5;
  }
    if(spell > 10 && spell < 101) {
  write(
BOLD+"SoulEater"+OFF+" starts to shake violently!\n"+
"Your soul is squeezed for life energy!\n");
  say(me->query_name()+"'s "+BOLD+"SoulEater"+OFF+" starts to shake violently!\n");
  me->heal_self(-3);
return 5;
  }
    if(spell < 11) {
  write(
BOLD+"SoulEater"+OFF+" turns red with your blood!\n"+
"You feel Souleater converting your physical life to its energy food!\n");
  say(me->query_name()+"'s "+BOLD+"SoulEater"+OFF+" turns red with "+me->query_name()+"'s blood!\n");
  me->hit_player(5);
return 5;
  }
    return;
}

quest_ob() { return 1; }
