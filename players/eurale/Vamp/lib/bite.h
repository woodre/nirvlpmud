/*
  bite_player.h
*/

#include "/players/eurale/defs.h"

/* -------- Bite a player (recuitment) ---------- */
bite_player(str) {
  object obj, target_obj;
  int is_a_traitor;
  string msg;

if(!str) {
  write("You must specify who you want to bite.\n");
  write("Use: bite <who>\n");
  return 1; }

target_obj = present(str, ROOM);
if(!target_obj) {
  write(capitalize(str)+" is not here!\n");
  return 1; }

if(TPL < 17 || TPGEXP < 669) {
  write("You can't use that abilitiy yet.\n");
  return 1; }

if(EFANGS->check_guild(str) != "{     ~:~    }") {
  if(EFANGS->check_guild(str) != " ") {
    write(capitalize(str)+" is already in the "+
          EFANGS->check_guild(str)+" guild!\n");
    return 1; }
}

obj = present("vampirebite", target_obj);

if(present("vampire fangs", target_obj)) {
  write("That player is already a vampire!\n");
  return 1; }

if(target_obj->query_guild_exp() == 1) target_obj->add_guild_exp(-1);

if(target_obj->query_guild_exp()) {
  write("You can't recruit a member of another guild.\n"+
        "Have them leave their old guild first.\n");
  return 1; }

if(target_obj->query_npc()) {
  write("You can only bite players!\n");
  return 1; }

call_other(TRAITOR, "???");
is_a_traitor = TRAITOR->query_traitor(target_obj->query_real_name());
if(is_a_traitor) {
  write(capitalize(target_obj->query_real_name())+
        " is a traitor to the guild!  You cannot bite traitors!\n");
  return 1; }

if(target_obj->query_level() < 4) {
   write("A player must be level 3 to join a guild.\n");
  return 1; }

  /* no biting in wizards unless its by a guild master or assistant */
if(target_obj->query_level() > 20 || TPGEXP < 672) {
  write("Only the Guild Master or a Guild Assistant can bite wizards.\n");
  return 1; }

  /*  wizards can't bite  */
if(present("vampire fangs",TP) && TPL > 20 && TPGEXP < 671) {
  write("Wizards cannot get involved in player affairs.\n");
  return 1; }

EFANGS->tell_my_room(
    capitalize(TPRN)+
      " pierces "+capitalize(target_obj->query_name())+"'s neck with "+
      TP->query_possessive()+" fangs and drinks deeply.");

write("As you open your jaws wide to be able to clamp down on "+
      capitalize(str)+"'s\n"+
      "neck, your lips slide back to expose your sharp fangs.\n"+
      "You feel an almost electric shock as the first drop of "+
      target_obj->query_possessive()+"\n"+
      "blood touches your tongue.\n");

  /*  log the biter  */
write_file("/players/eurale/Vamp/BITERS", ctime(time())+"  "+
  capitalize(TPRN)+" bit "+capitalize(str)+".\n");

if(obj) {
  obj->add_a_bite(TPRN);
  return 1; }

obj = clone_object(BITE);
move_object(obj, target_obj);
obj->add_a_bite(TPRN);
return 1;
}
