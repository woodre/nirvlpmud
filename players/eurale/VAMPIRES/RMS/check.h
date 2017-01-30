/*
  guild_rooms.c - checks everyone for membership
*/

#include "/players/eurale/closed/ansi.h"

check_membership(arg) {
  string str1, str2;
if(arg->query_level() > 99) return;
if(!present("vampire fangs",arg)) {
  if(sscanf(file_name(arg), "%sobj/kid%s", str1, str2) == 2) return 0;
  if(arg->is_pet()) return 0;
  say(HIR+
  "A large, flaming demons swoops in and grabs "+
     capitalize(arg->query_real_name())+"!\n"+
  "It picks "+arg->query_objective()+" up and carries "+
    arg->query_objective()+" off into the darnkess...\n"+NORM);
  tell_object(arg,HIR+
    "A large, flaming demon swoops in, grabs you and carries you off..\n"+
    NORM);
  this_player()->move_player("into the darkness#room/mine/tunnel13.c");
  return 1; }
return;
}

tell_not_me(str, ignore) {
string player;
player = first_inventory(environment(this_player()));
  while(player) {
    if(living(player) && !player->query_npc() &&
      player != this_player() && player->query_real_name() != ignore) {
    tell_object(player,str+"\n");
    }
    player = next_inventory(player);
  }
return 1;
}
