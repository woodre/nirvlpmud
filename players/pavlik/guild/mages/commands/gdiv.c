#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("gdiv");
  set_name("Guild Division");
  set_color_name(HIC+"Guild Division"+NORM);
  set_rank(18);
  set_descrip(
	"Once a Mage gains this skill her or she can change the percentage " +
	"of earned experience points that go directly to the guild.  The " +
	"default setting is 50% (1/2 all earned experience goes to the guild) " +
	"however by using the gdiv command this rate can be changed to anything " +
	"from 5% to 100%\n"
  );
}


cmd(str)
{
  int mydiv;

  if(tp->query_guild_rank() < query_rank())
	return 0;

  if(!str)
  {
	notify_fail("Set Guild Dividend to what?\n");
	return 0;
  }

  sscanf(str, "%d", mydiv);

  if(mydiv == 0 && tp->query_guild_rank() > 70) {
        write("Clearing all Guild Div, mighty one.\n");
        guild->set_divd(0);
        return 1;
  }
  if((mydiv < 5) || (mydiv > 100))
  {
	notify_fail("You must set Guild Div to a number between (5) and (100).\n");
	return 0;
  }

  guild->set_divd(mydiv);
  write("Setting Guild Div to "+mydiv+" percent.\n");
  write(mydiv+"% of all earned XP will go to the guild.\n");
  return 1;

}


