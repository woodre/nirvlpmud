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

if(TPXL < 5 || TPGEXP < 670 ||
  TP->query_attrib("cha") < 20 || TP->query_attrib("dex") < 20 ||
  TP->query_attrib("sta") < 20 || TP->query_attrib("mag") < 20 ||
  TP->query_attrib("str") < 20 || TP->query_attrib("wil") < 20 ||
  TP->query_attrib("luc") < 20 || TP->query_attrib("ste") < 20 ||
  TP->query_attrib("pie") < 20 || TP->query_attrib("int") < 20) {
  write("You don't have the attributes to bite anyone.\n");
  return 1; }

if(TPBPTS < 100) {
  write("You lack the blood energy to bite anyone.\n");
  return 1; }

if(target_obj->query_guild_name()) {
  write("This person has pledged elsewhere and cannot be bitten.\n");
    return 1; }

obj = present("vampirebite", target_obj);

if(present("vampire fangs", target_obj)) {
  write("That player is already a vampire!\n");
  return 1; }

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
   write("A player must be level 4 to join this guild.\n");
  return 1; }

  /* No biting in wizards  */
  if(target_obj->query_level() > 20 && (TPRN != "vital" || TPRN != "brittany")) {
  write("Only guild wizards may admit wizards to the Vampire Guild.\n");
  return 1; }

  /*  wizards can't bite  */
if(present("vampire fangs",TP) && TPL > 20 && TPRN != "vital") {
  write("Wizards cannot get involved in player affairs.\n");
  return 1; }

/*  Take away bite ability for abuse - Eurale  */
/*  Beer  5/24/03   */
if(TPRN == "beer") {
  write("You can no longer bite, contact Vital if you have questions.\n");
  return 1; }

/*   Glaxgor 5/25/03   */
if(TPRN == "dw") {
  write("You can no longer bite, contact Vital if you have questions.\n");
  return 1; }


FANGS->tell_my_room(
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
write_file("/players/eurale/VAMPIRES/BITERS", ctime(time())+"  "+
  capitalize(TPRN)+" bit "+capitalize(str)+".\n");

if(obj) {
  obj->add_a_bite(TPRN);
  return 1; }

obj = clone_object(BITE);
move_object(obj, target_obj);
obj->add_a_bite(TPRN);
PFANGS->add_BLOODPTS(-100);
return 1;
}