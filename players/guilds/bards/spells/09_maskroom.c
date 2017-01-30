#include "/players/guilds/bards/def.h"

status main(string str) {
  object m;
  if(spell(-194, 9, 5) == -1)
  return 0;
  if(environment(TP)->bard_room_hide()) {
    write("The room is already masked in mist.\n");
    return 1;
  }
  this_player()->add_spell_point(-5);
  write("You softly sing the Song of Masking...\n");
  say(tp+" softly sings a song.\n");
  tell_room(environment(TP),
   "The room is suddenly covered in a soft "+HIG+"Mist"+NORM+".\n");
  m = clone_object(OBJ+"hide_room");
  m->start_shadow(environment(this_player()));
  return 1;
}
