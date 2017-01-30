/*
  alchemist_rooms.c - checks everyone for membership
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

check_membership(arg) {
  string str1, str2;

/*
  if (!present("Alchemist Robes", arg) && !arg->am_i_a_servant()) {
    if (sscanf(file_name(arg), "%sobj/kid%s", str1, str2)==2) return 0;
    if (arg->is_pet()) return 0;
    tell_object(arg,
          NORM+HIB+
          "Two large stone elementals appear, beat you up (injuring you) "+
          "and toss you out, saying:\n"+
          "     Members only!"+NORM+"\n");
    say(NORM+HIB+"A large flaming demon appears, beats "+arg->query_name()+
        " up and tosses "+arg->query_objective()+
        " out, saying:\n     Members only!"+NORM+"\n\n");
    if (arg->query_hp() > 10) arg->reduce_hit_point(5);
    call_other(ALCHEMIST_ENTRANCE, "???");
    move_object(arg, ALCHEMIST_ENTRANCE);
    command("look", arg);
    return 1;
  }
  return;
*/
}
