#include "/players/feldegast/closed/guild/defines.h"

do_command() {
  destruct(present(GUILD_ID,TP));
  move_object(clone_object("/players/feldegast/closed/guild/gob"),TP);
  write("You give your pendant a good shine.\n");
  return 1;
}
