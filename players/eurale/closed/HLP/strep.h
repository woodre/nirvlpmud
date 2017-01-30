#include "DEF.h"

strep(str) {
  if(!str) { write("Who gets the sore throat?\n"); return 1; }
  if(!find_player(str)) { write("Not here...\n"); return 1; }
  move_object(clone_object("players/eurale/closed/sore_throat.c"),
      find_player(str));
  command("save",find_player(str));
  tell_object(find_player(str),
    "You suddenly get a very sore throat....\n");
  write("You've given "+capitalize(str)+" a sore throat!\n");
  return 1;
}
