#include "../defs.h"

main() {
  object ob;

  previous_object()->save_stats();
  destruct(previous_object());
  ob = clone_object( GUILD_FILE );
  move_object( ob, this_player() );
  return 1;
}
