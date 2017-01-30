/*
  defend_me.h
*/

#include "defs.h"

/* ---------- Defend me (defend kids/pets/servants from jerks) --------- */
defend_me(str) {
  string bad_guy;
  object bad_guy_obj, bad_guy_target_obj;
  int bad_guy_sp;
  if (!str) return 0;
  sscanf(str, "against %s", bad_guy);
  if (!bad_guy) {
    write("You must name the evil one.  (defend against <evil one's name>)\n");
    return 1;
  }
  if (MY_LEVEL < 3 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if (!present(bad_guy, MY_ROOM)) {
    write(capitalize(bad_guy)+" isn't here.\n");
    return 1;
  }
  bad_guy_obj = present(bad_guy, MY_ROOM);
  bad_guy_target_obj = bad_guy_obj->query_attack();
/* Fixed by Wizardchild. If 'bad_guy_obj' wasn't fighting anything, and the
   user of the spell didn't have a wolf/servant, then the spell worked before
*/
  if(!bad_guy_target_obj) {
    write("But "+capitalize(bad_guy)+" isn't attacking your wolf/servant/kid!\n");
    return 1;
  }
  if (bad_guy_target_obj==MY_FANGS->query_wolf_obj() ||
      bad_guy_target_obj==MY_FANGS->query_servant_obj() ||
      bad_guy_target_obj->is_kid()) {
    bad_guy_sp = bad_guy_obj->query_spell_point() / 2;
    bad_guy_obj->add_spell_point(- bad_guy_sp);
    call_other("/room/mine/tunnel16", "???", 0);
    move_object(bad_guy_obj, "/room/mine/tunnel16");
    MY_PLAYER->add_spell_point(- 50);
    tell_object(bad_guy_obj, "A swarm of bats swoops in and carries you "+
                             "away to the darkest depths.\n");
    MY_FANGS->tell_my_room(MY_NAME_CAP+" bellows in anger and points at "+
                 capitalize(bad_guy)+
                 " and a swarm of bats swoops in to pick "+
                 bad_guy_obj->query_objective()+" away!\n", bad_guy);
    write("A swarm of bats swoops in and carries "+capitalize(bad_guy)+
          " away to the darkest depths.\n");
    return 1;
  }
  write("But "+capitalize(bad_guy)+" isn't attacking your wolf/servant/kid!!!\n");
  return 1;
}
