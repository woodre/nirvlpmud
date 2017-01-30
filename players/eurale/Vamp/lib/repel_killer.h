/*
  defend_me.h
*/

#include "/players/eurale/defs.h"

  /* protect me/kids/pets/servants from attack */
repel_killer(str) {
  string bad_guy;
  object bad_guy_obj, bad_guy_target_obj;

sscanf(str, "against %s", bad_guy);
if(!bad_guy) {
  write("Who do you want to repel?\n");
  return 1; }

if(TPL < 17 || TPGEXP < 669) {
  write("You lack the skills to cast that spell.\n");
  return 1; }

if(TPSP < 50) {
  write("You don't have enough magic.\n");
  return 1; }

if(!present(bad_guy, ROOM)) {
  write(capitalize(bad_guy)+" isn't here.\n");
  return 1; }

bad_guy_obj = present(bad_guy, ROOM);
bad_guy_target_obj = bad_guy_obj->query_attack();

if(!bad_guy_target_obj) {
  write(capitalize(bad_guy)+" isn't attacking.\n");
  return 1; }

if(bad_guy_target_obj == EFANGS->query_wolf_obj() ||
  bad_guy_target_obj == EFANGS->query_servant_obj() ||
  bad_guy_target_obj->is_kid()) {
    call_other("/room/mine/tunnel16", "???", 0);
    move_object(bad_guy_obj, "/room/mine/tunnel16");
    TP->add_spell_point(- 50);

    tell_object(bad_guy_obj,
      "A "+BOLD+"swam of bats"+NORM+" swoops in and carries you away!\n");

    EFANGS->tell_my_room(
      capitalize(TPRN)+" bellows in anger and points at "+
      capitalize(bad_guy)+".....\n"+
      "A "+BOLD+"swam of bats"+NORM+" swoops in and carries "+
      bad_guy_obj->query_objective()+" away!\n");

    write("A "+BOLD+"swam of bats"+NORM+" swoops in and carries "+
          capitalize(bad_guy)+" away....\n");
  return 1; }

write(capitalize(bad_guy)+" is NOT attacking you or your loved ones.\n");
return 1;
}
