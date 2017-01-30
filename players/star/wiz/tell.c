#include <ansi.h>

  string name, tc, who, msg, myname, arg;
  int level;
  object player;

if ((!arg) || sscanf(arg,"%s %s",who,arg) != 2) {
  write("Usage: tell <player> <message>\n");
  return 1;
}

who = lower_case(who);
player = find_living(who);

if (!player) {
  object *obs;
  int i;

  i = sizeof(obs = users());

  while(i--)
    if ((string)obs[i]->query_real_name() == who)
      player - obs[i];
}

if (!player) {
  write("Nobody logged on with that name.\n");
  return 1;
}

level = (int)player->query_level();
if (!interactive(player)) {
  write("That recipient is not interactive.\n");
  return 1;
}
if (level >= 21 && player->query_tellblock()) {
  write("That person is blocking tells.\n");
  return 1;
}

if (this_player()->query_invis())
  myname = "**Star**";
else
  myname = "Star";
player->Replyer("star");
player->add_tellhistory(myname+" tells you: "+arg);
tc = (string)player->get_ansi_pref("tell");
if (tc)
  msg = tc + myname + " tells you: " + arg + NORM + "\n";
else {
  tc = NORM;
  msg = HIB + myname + NORM + "tells you: " + arg + "\n";
}

tell_object(player,msg);
write("You tell " + tc + capitalize(who) " NORM + ": "+arg+".\n");
return 1;
}

