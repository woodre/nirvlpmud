/*
  scratch_enemy.h
*/

#include "/players/eurale/defs.h"

/* -------- scratch an opponent for damage ---------- */
attack_damn(str) {
  int success_chance, random_nbr, spell_damage, spell_cost;
  int b_points;
  object target_obj, disease;
  string spell_name, caster_msg, target_msg, room_msg;

if(TP->query_ghost()) {
  write("How can you attack anything? You are a ghost.\n");
  return 1; }

if(!str && !TP->query_attack())
{
  write("Use: damn [<who>]\n");
  return 1;
}

if(!str)
  target_obj = TP->query_attack();

if(!target_obj)
  target_obj = present(str, ROOM);

if(!target_obj && !present(str, ROOM))
{
  write("You don't see "+str+" here.\n");
  return 1;
}


if(TPL < 17 || TPGEXP < 669 || TP->query_attrib("int") < 25) {
  write("You lack the skills necessary for that spell.\n");
  return 1; }

if(TPBPTS < 4) {
  write("You lack the blood energy to damn.\n");
  return 1; }

if(target_obj->is_player())
{
  if(!TP->query_pl_k() && !TP->query_fight_area()) 
  {
    write("You can't cast that here!\n");
    return 1;
  }

  if(!target_obj->query_pl_k() && !TP->query_fight_area())
  {
    write("You can't cast that!\n");
    return 1;
  }
}

PFANGS->add_BLOODPTS(-4);
  /* new code to switch over to spell_object */
spell_name = "damn";
spell_damage = 0;
spell_cost = 30;

/*
caster_msg =
  "     You concentrate your "+BOLD+"MENTAL POWER"+NORM+" and "+HIR+
  "DAMN THE SOUL"+NORM+" of "+capitalize(str)+"!\n";

target_msg =
  capitalize(TPRN)+" "+BOLD+"GLARES"+NORM+" at you until your "+HIR+
  "SOUL FEELS DAMNED"+NORM+"!\n";

room_msg =
  capitalize(TPRN)+" concentrates "+TP->query_possessive()+BOLD+
  " MENTAL POWERS"+NORM+" and "+capitalize(str)+" "+HIY+
  "HOWLS IN PAIN"+NORM+"!\n";
*/

if(TP->query_sp() < spell_cost) {
  write("You don't have enough spell points for that.\n");
  return 1;
}

if(present("vamp_damn_obj", target_obj)) return 1;

disease = clone_object("/players/eurale/VAMPIRES/OBJ/damn.c");
move_object(disease, target_obj);
disease->set_time( (TPBPTS / 100) - random(3) );


tell_object(TP,
  "     You concentrate your "+BOLD+"MENTAL POWER"+NORM+" and "+HIR+
  "DAMN THE SOUL"+NORM+" of "+capitalize(target_obj->query_name())+"!\n");

tell_object(target_obj,
  capitalize(TPRN)+" "+BOLD+"GLARES"+NORM+" at you until your "+HIR+
  "SOUL FEELS DAMNED"+NORM+"!\n");

tell_room(environment(TP),
  capitalize(TPRN)+" concentrates "+TP->query_possessive()+BOLD+
  " MENTAL POWERS"+NORM+" and "+capitalize(target_obj->query_name())+" "+HIY+
  "HOWLS IN PAIN"+NORM+"!\n", ({ TP, target_obj }));

if(!TP->query_attack())
  TP->attack_object(target_obj);

TP->add_spell_point(-(spell_cost));

/*
  TP->spell_object(target_obj, spell_name, spell_damage, spell_cost,
                      caster_msg, target_msg, room_msg);

  TP->set_spell_dtype("other|mental");
*/

  return 1;
}
