/*
  return_from_office.h
*/

#include "defs.h"

/* -------- return to original room from office ---------- */
return_from_office() {
  string wheree;
  int sp_cost;
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LIEUTENANT)
    return 0;
  sp_cost = 55+random(5);
  if (MY_PLAYER->query_sp() < sp_cost) {
    write("You do not have enough energy!\n");
  return 1; }
  if (MY_FANGS->query_old_room()) {
    MY_PLAYER->add_spell_point(- sp_cost);
/*
  if(wheree = call_other("obj/base_tele","teleport")) {
      MY_PLAYER->move_player("with an astonished look#"+wheree); }
  else {
*/
    move_object(MY_PLAYER, MY_FANGS->query_old_room());
   write("You fly back from your guild office.\n\n"); 
  }
  else
    write("You try fly back from your guild office, "+
          "but can't find your way.\n\n");
  command("look", MY_PLAYER);
  MY_FANGS->set_old_room(0);
  write("Ok.\n");
  return 1;
}
