#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

#define SPELL_DELAY 30

reset(arg) {
  if(arg) return;
  set_verb("meditate");
  set_name("Meditate");
  set_color_name(HIC+"Meditate"+NORM);
  set_rank(26);
  set_descrip(
	"A well-trained mind can place itself into a state of Meditation. " +
	"This relaxed yet focused state of mind allows a Mage to recover " +
	"spell points at an accelerated rate - however the Mage will not " +
	"recover any health points during this time.\n"
  );
}


cmd()
{
  if(tp->query_guild_rank() < query_rank())
	return 0;

  if(guild->query_guild_var("meditate"))
  {
	int n;
	n = time();
	write("You stop meditating.\n");
	guild->unset_guild_var("meditate");

	if(guild->query_next_prot() < n + SPELL_DELAY)
		guild->set_next_prot(n + SPELL_DELAY);
	if(guild->query_next_dmg() < n + SPELL_DELAY)
		guild->set_next_dmg(n + SPELL_DELAY);
	if(guild->query_next_heal() < n + SPELL_DELAY)
		guild->set_next_heal(n + SPELL_DELAY);
	if(guild->query_next_alter() < n + SPELL_DELAY)
		guild->set_next_alter(n + SPELL_DELAY);

	return 1;
  }

  if(tp->query_attack())
  {
	notify_fail("Not while you are fighting!\n");
	return 0;
  }

  if(tp->query_hp() < 10)
  {
	notify_fail("Your body is too damaged to meditate right now.\n");
	return 0;
  }

  write(
   "You bow your head in "+CYN+"meditation"+NORM+".\n" +
   "You feel the "+MAG+"magic"+NORM+" in everything around you infuse your body.\n");
  say(
   ME+" bows "+PO+" head in meditation.\n");

  guild->set_guild_var("meditate", tp->query_hp());
  return 1;

}

