/*
  summon.h
*/

#include "/players/eurale/defs.h"

object obj;

/* --------------- Summon a player to the vamp's location --------------- */
summon(str) {
  object target_obj, summons_obj;
  string str1;

if(TPL < 17 || TPGEXP < 669 || TP->query_attrib("int") < 18) {
  write("You don't have the skill for that ability yet.\n");
  return 1; }

if(!str) {
  write("Use: summon <who>\n");
  return 1; }

if(TPSP < 50) {
  write("You don't possess enough magic for that.\n");
  return 1; }

str1 = file_name(ROOM);
if(str1 == COFFIN_ROOM) {
  write("You cannot summon people into your coffin.\n");
  return 1; }

if(ROOM->realm()=="NT") {
  write("You are in an area that prevents that.\n");
  return 1; }

target_obj = find_player(str);
if(!target_obj || target_obj->query_invis()) {
  write("Can't find "+capitalize(str)+".\n");
  return 1; }

if(present("summons", target_obj)) {
  write(capitalize(str)+" already has a summons.\n");
  return 1; }

summons_obj = clone_object(SUMMONS);
summons_obj->set_summons_owner(TPRN);
move_object(summons_obj, target_obj);
tell_object(target_obj,
   HIR+"You have been summoned by "+capitalize(TPRN)+"."+NORM+"\n"+
    "You can:\n"+
    "  use it by typing 'accept summons'\n"+
    "  get rid of it by typing 'drop summons'\n"+
    "  check out "+capitalize(TPRN)+"'s location before deciding with "+
    "'check summons'\n");
TP->add_spell_point(-50);
write(HIR+capitalize(str)+" has been summoned!"+NORM+"\n");
return 1;
}
