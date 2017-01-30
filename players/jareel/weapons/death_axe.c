inherit "obj/weapon.c";
#include "/players/jareel/ansi.h"
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("death axe");
    set_alias("death");
    set_short(BOLD+BLU+"Death "+BOLD+BLK+"Axe"+NORM);
    set_type("axe");
    set_long("This axe seems to absorb all light from its surroundings. \n" +
                   "You feel evil tug soul as you look upon it. This \n" +
                   "is a very powerfull force of evil. \n");
    set_light(0);
    set_class(200);
    set_weight(2);
    set_value(10000);
    set_hit_func(this_object());
  set_save_flag(0);
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
    if(spell > 250) {
  write(
BOLD+BLU+"The Death"+NORM+BOLD+BLK+" Axe"+NORM+" burns with a black gleem!\n"+
"You feel a sharp pain run up your arm, and you feel empowererd.\n");
  say(me->query_name()+"'s "+BOLD+BLU+"Death"+BOLD+BLK+" Axe burns black!"+NORM+"\n");
  say(me->query_name()+"'s "+BOLD+BLU+"Death"+NORM+BOLD+BLK+" Axe burns black!"+NORM+"\n");
  me->add_spell_point(random(10));
me->heal_self(-random(5));
  ob->heal_self(-random(7)-5);
return 8;
  }
    if(spell > 150 && spell < 251) {
  write(
BOLD+BLU+"The Death"+NORM+BOLD+BLK+" Axe"+NORM+" unleashes darkness!\n"+
"            "+BOLD+BLK+"Darkness floods the room"+NORM+"!\n");
  say(me->query_name()+"'s "+BOLD+BLU+"Death "+NORM+BOLD+BLK+"Axe "+NORM+" unleashes darkness!\n");
  me->add_spell_point(random(5));
me->heal_self(-random(5)-3);
  ob->heal_self(-random(5)-3);
return 5;
  }
    if(spell > 50 && spell < 151) {
  write(
BOLD+BLU+"The Death "+NORM+BOLD+BLK+"Axe "+NORM+"tears at your soul!\n"+
"                   You feel drained and weak.\n");
 say(me->query_name()+"'s "+BOLD+BLU+"Death"+NORM+BOLD+BLK+" Axe"+NORM+" tears at "+me->query_name()+"'s soul!\n");
  me->add_spell_point(random(3));
me->heal_self(-3);
  ob->heal_self(-3);
return 3;
  }
    if(spell > 1 && spell < 101) {
  write(
BOLD+BLU+"The Death"+NORM+BOLD+BLK+" Axe"+NORM+" starts to shake violently!\n"+
"Your body is sucked of life!\n");
  say(me->query_name()+"'s "+BOLD+BLU+"Death"+NORM+BOLD+BLK+" Axe"+NORM+" starts to shake violently!\n");
me->add_spell_point(random(2));  
me->heal_self(-2);
ob->heal_self(-3);
return 1;
  }
    if(spell < 1) {
  write(
BOLD+BLU+"The Death"+NORM+BOLD+BLK+" Axe "+NORM+" glows vibrant with blood!\n"+
"You feel the axe rip at the life force around you!\n");
  say(me->query_name()+"'s "+BOLD+BLU+"Death"+NORM+BOLD+BLK+" Axe"+NORM+" rips souls apart!\n");
  say(me->query_name()+"'s "+BOLD+BLU+"Death"+NORM+BOLD+BLK+" Axe"+NORM+" rips souls apart!\n");
me->heal_self(-20);
ob->heal_self(-20);
return 15;
  }
    return;
}

