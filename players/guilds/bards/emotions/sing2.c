#include "/players/guilds/bards/def.h"

status main(){
  write("You chant part of an old Irish battle song.\n");
  say(tp + " chants part of an old Irish battle song.\n");
  tell_room(ENV,"  You feel your blood stir and pulse quicken!\n");
  return 1;
}
