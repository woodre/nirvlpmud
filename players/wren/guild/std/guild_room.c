#include "../def.h"

inherit ROOM;

status  open;

void reset(status x)
{
 if(x) return;
 set_light(1);
}

string query_guild_room()
{
 return GUILDNAME;
}

void init()
{
 if(!open && TP && TP->is_player() &&
    ((string)TP->query_guild_name() != GUILDNAME) &&
     ((int)TP->query_level() < APPRENTICE))
 {
  TL(TP, "\n\
 Suddenly, a dozen half-ogre bodyguards swarm upon\n\
you, lift you high above their heads and hurl you\n\
back to the Village Green.\n\n");
  command("follow stop", TP);
  TR(TO, "\nA dozen or so ogres burst into the room, grab "+(string)TP->QN+"\n\
by "+possessive(TP)+" neck, and hurl "+objective(TP)+" far away...\n\n",
 ({TP}));
  TR("/room/vill_green",
 (string)TP->QN+" is hurled into the green by a dozen or so ogres.\n",
  ({TP}));
  MO(TP, "/room/vill_green");
  TL(TP, "\nYou land with a * THUD *!\n\n");
  return;
 }
 ::init();
}
