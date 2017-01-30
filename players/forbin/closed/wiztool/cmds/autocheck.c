/* autoload check command */

#include "/players/forbin/define.h"

string auto_load;

status main(string arg) {
  if(!arg) {
    notify_fail("Check whose autoloads?\n");
      return 0;
  }
  auto_load = 0;
  if(!restore_object("pfiles/"+arg[0..0]+"/"+arg))
  if(restore_object("players/inactive_saved/"+arg))
  write("-------INACTIVE--------\n");
  if(restore_object("banish/"+arg))
  write("-------BANISHED--------\n");
  if(auto_load)
  write("Auto load string:\n "+auto_load+"\n");
  else write("Nonexistent player.\n");
    return 1;
}
