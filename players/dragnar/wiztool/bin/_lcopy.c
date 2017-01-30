/** Copy a living thing such as a mob or player **/
#include <ansi.h>
int
cmd_lcopy(string str) {
  object target, mob;
  target = find_living(str);
  if( !target ) {
    write("Unable to find "+str+".\n");
    return 1;
  }
  mob = clone_object("/players/dragnar/SevenSpires/mons/clone.c");
  move_object( mob, environment( this_player() ));
  mob->set_target( target ); 
  write("Copy complete.\n");
  return 1;
}
