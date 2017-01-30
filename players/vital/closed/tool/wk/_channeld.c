#include <ansi.h>
#include <security.h>
#include "/players/vital/closed/headers/channel.h"

main(string str)
{
  string command, channel, player;
  if(!str)
  {
    notify_fail(get_help() + "\n");
    return 0;
  }
  sscanf(str, "%s %s %s", command, channel, player);
  if(!find_living(player))
  {
    notify_fail("No such player " + player + "logged on!\n" + get_help() + "\n");
    return 0;
  }
  if(command == "add")
  {
    CHANNELD->add_channel(channel, find_player(player));
    return 1;
  }
  if(command == "remove")
  {
    CHANNELD->remove_channel(channel, find_player(player));
    return 1;
  }
}

get_help()
{
  string help;
  help = "Syntax: add/remove <channel> <player>";
  return help;
}