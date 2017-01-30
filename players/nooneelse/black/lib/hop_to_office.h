/*
  hop_to_office.h
*/

#include "defs.h"

/* -------- go to office (teleport to the guild office) ---------- */
hop_to_office() {
  string wheree;
  string my_guild_office;
  int sp_cost;
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LIEUTENANT)
    return 0;
  if (MY_ROOM->realm()=="NT" &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT)) {
    tell_object(MY_PLAYER, "You can't do that in this area.\n");
    return 1;
  }
  sp_cost = 55+random(5);
if (MY_PLAYER->query_sp() < sp_cost) {
    write("You do not have enough energy!\n");
  return 1; }
  MY_PLAYER->add_spell_point(- sp_cost);
/*
  if(wheree = call_other("obj/base_tele","teleport")) {
      MY_PLAYER->move_player("with an astonished look#"+wheree); }
  else {
*/
  MY_FANGS->set_old_room(MY_ROOM);
  my_guild_office = GUILD_OFFICE_FLOOR_TOP->find_office(MY_NAME);
  call_other(my_guild_office, "???", 0);
  move_object(MY_PLAYER, my_guild_office);
  write("You fly to your guild office.\n\n");
  command("look", MY_PLAYER);
/*
  }
*/
  write("Ok.\n");
  return 1;
}
