/*
  attack_damn.h
  
  updated by illarion 8/31/2010
  linked cost to duration
  pruned unneeded code/comments
  see also /players/eurale/VAMPIRES/OBJ/damn.c
*/

#include "/players/eurale/defs.h"

/* -------- scratch an opponent for damage ---------- */
attack_damn(str) {
  int spell_cost;
  int duration;
  object target_obj, disease;

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
  duration = (TPBPTS / 100) - random(3);
  if(duration < 2) duration = 2;
  spell_cost = 10 * duration * 3 / 4;



if(TP->query_sp() < spell_cost) {
  write("You don't have enough spell points for that.\n");
  return 1;
}

if(present("vamp_damn_obj", target_obj)) { 
  write(target_obj->query_name()+" is already damned.\n");
  return 1;
}

  PFANGS->add_BLOODPTS(-4);


disease = clone_object("/players/eurale/VAMPIRES/OBJ/damn.c");
move_object(disease, target_obj);
disease->set_time(duration);


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
  else
    target_obj->attacked_by(TP);

  TP->add_spell_point(-(spell_cost));
  return 1;
}
