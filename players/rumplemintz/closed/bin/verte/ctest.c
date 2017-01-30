#include <ansi.h>
#include <security.h>
#include "/players/vital/closed/headers/channel.h"

string get_emotional(string channel, string msg);
string get_player_name(string channel);
int valid_channel(string channel);
int cmd_channel(string channel, string msg);

int
main(string str)
{
  string a, b;
  sscanf(str, "%s %s",a,b);
  "/players/vital/daemons/channel"->cmd_channel(a, b);
  return 1;
}

get_help()
{
  string help;
  help = "Mockup of the new channel command for players";
  return help;
}
