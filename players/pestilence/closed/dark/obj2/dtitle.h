#include "/players/pestilence/closed/std/colorize.h"

int cmd_ctitle(string str) {
  object targ;
  string name, title;
if(this_player()->query_guild_rank() < 9){ write("You can't set your title until guild rank 9.\n"); return 1; }
  if(!str || sscanf(str,"%s",title)!=1) {
    notify_fail("Usage: dtitle <title>\n");
    return 0;
  }
  title=colorize(title);
  this_player()->set_title(title);
  write("You have set your title to '"+title+"'.\n");
  return 1;
}
