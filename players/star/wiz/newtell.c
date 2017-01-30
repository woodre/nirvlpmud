/*
 *      File:                 /players/star/wiz/newtell.c
 *      Function:             So I can tell Earwax things when he's in edit
 *                            Well..  that and so I talk in pretty colors
 *                            And so I have at least one file in line with
 *                              code standards for me to refer back to
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2007 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               07/25/07
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
inherit "obj/treasure.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("teller");
  set_id("teller");
  set_weight(0);
}

int tell(string arg) {
  string name, tc, who, msg, myname;
  int level;
  object player;


  if ((!arg) || sscanf(arg,"%s %s",who,arg) != 2) {
    write("Usage: tell <player> <message>\n");
    return 1;
  }

  who = lower_case(who);
  player = find_living(who);

  if(!player) {
    object *obs;
    int i;

    i = sizeof(obs = users());

    while(i--)
      if ((string)obs[i]->query_real_name() == who)
        player = obs[i];
  }
  if (!player) {
    write("Nobody logged on with that name.\n");
    return 1;
  }

  level = (int)player->query_level();

  if (!interactive(player)) {
    write("That player is disconnected.\n");
    return 1;
  }

  if (level >= 21 && player->query_tellblock()) {
    write("That person is being anti-social right now.\n");
    return 1;
  }

  if (this_player()->query_invis())
    myname = "Star (invis)";
  else
    myname = "Star";
  player->Replyer("star");
  player->add_tellhistory(myname+" tells you: "+arg);
  msg = HIB + myname + " tells you: " + HIW + arg + NORM + "\n";

  tell_object(player,msg);
  write(HIB + "You tell " + capitalize(who) + NORM + ": "+arg+"\n");
  return 1;
}

void init() {
  ::init();
  add_action("tell", "tell");
}

