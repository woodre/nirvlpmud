/* 08/19/06 Earwax: Daemonized this */
/* Don't document this, it's not a command for players to use normally */

int cmd_church(string arg) {
  if(this_player()->query_level() > 21)
    if(!environment(this_object())) {
    move_object(this_player(), "room/vill_green");
    return 1;
  }
}
