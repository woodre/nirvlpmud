/*
  dig_hole.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Dig a hole (to hide stuff in) ---------- */
dig_hole(str) {
  object hole;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you dig anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if(!str || str != "hole") return 0;
  if (MY_GUILD_RANK < 20) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (present("shovel", MY_PLAYER)) {
    write(NORM+CYN+"You don't have a shovel!\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  if (present("guild hole", MY_ROOM)) {
    write(NORM+CYN+"Hmmm.  You stop digging because the ground seems to be soft as\n"+
          "if there's already a hole concealed here."+NORM+"\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 50);
  write(NORM+CYN+"You dig a hole in the ground."+NORM+"\n");
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+" digs a hole in the ground."+NORM);
  hole=clone_object(ALCHEMIST_HOLE);
  move_object(hole, MY_ROOM);
  hole->self_destruct_timer(600);
  return 1;
}
