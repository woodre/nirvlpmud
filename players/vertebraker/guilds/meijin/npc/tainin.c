inherit "/obj/monster";
#include "/players/vertebraker/guilds/meijin/defs.h"

object seated;

reset(arg) {
  ::reset(arg);
  if (!arg) {
  set_name("Tainin");
  set_alias("tainin");
  set_alt_name("versed");
  set_short("Tainin the Versed");
  set_long("Tainin the Versed.\n");
  set_level(50);
  set_ac(100);
  set_wc(500);
  set_hp(10000);
  set_al(0);
  set_aggressive(0);
  }
}

query_meijin_master() { return 1; }

init() {
  ::init();
  add_action("tell","tell");
}

tell(str) {
  string tmp;
  if(sscanf(str, "tainin %s", tmp) == 1) {
	write("You say to Tainin: "+tmp+"\n");
	tell_object(this_object(), ME+" tells you: "+tmp+"\n");
	return 1;
  }
}

short() {
  if(this_object()->query_attack()) return "Tainin (angered)";
  else return "Tainin the Versed sits here";
}

long() {
  if(this_object()->query_attack()) {
	write("Tainin the Angered is a fierce warrior.  His moves are\n");
        write("incredible quick and sure.  Tainin's hands and feet move\n");
        write("with blinding speed as he cuts down his enemy.\n");
  }
  else {
	write("Tainin regards you openly with bright green eyes.  His eyes\n");
	write("have seen sights from all around the globe.  Tainin uses his\n");
	write("vast experience and knowledge to help others "+CYN+"kaeru"+NORM+", or refine,\n");
	write("their own experiences.  With his help, a willing student can gain\n");
	write("valuable practice.\n");
  }
  return;
}

catch_tell(str) {
  string tmp, tmp2, tmp3;
  int amt;

  if(!present(this_player(), environment(this_object()))) return;

  if(sscanf(str, "%s bows to you.", tmp) == 1) {
	write("Tainin smiles openly and returns your bow.\n");
	return 1;
  }
  if(sscanf(str, "%s waves at you.", tmp) == 1) {
	write("Tainin returns your gesture with a quick wave of his hand.\n");
	return 1;
  }
  if(sscanf(str, "%s thanks you.", tmp) == 1) {
	write("Tainin says to you:  You are welcome!\n");
	return 1;
  }
  if(sscanf(str, "%s winks at you suggestively.", tmp) == 1) {
	write("Tainin fondles you.\n");
	return 1;
  }
  if(sscanf(str, "%s fondles you.", tmp) == 1) {
	write("Tainin giggles like a little girl.\n");
	return 1;
  }

  if(this_player() != environment(this_object())->query_seated()) return;

  if(sscanf(str, "%s sits %s", tmp, tmp2) == 2) {
	write("Tainin regards you with silent eyes.\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %sinfo%s", tmp, tmp2, tmp3) == 3) {
	int cost;
	if(this_player()->query_guild_name() != "meijin") {
		write("Tainin says to you:  There is nothing I can tell you.\n");
		return 1;
	}
	cost = (this_player()->query_guild_rank() / 10) * 2500;
	if(cost < 2500) cost = 2500;
	write(
	"Tainin says to you:  I can help you gain practices which you can\n"+
	"use to improve your skills and abilities.  It will cost you\n"+
	cost+" guild XP to gain a practice from me.\n");
	write("\n");
/*
	write(
	"Tainin says to you:  I can also help you change regular experience into\n"+
	"guild experience.  The exchange ratio is 3:1.  To exchange experience,\n"+
	"tell me 'exchange <amt>'.\n");
	return 1;
 */
  }
  if(sscanf(str, "%s tells you: %skaeru%s", tmp, tmp2, tmp3) == 3) {
	if(this_player()->query_guild_name() != "meijin") {
		write("Tainin says to you:  You cannot even begin to comprehend our ways.\n");
		return 1;
	}
	gain_practice();
	return 1;
  }
/*
  if(sscanf(str, "%s tells you: exchange %d", tmp, amt) == 2) {
	exchange_exp(amt);
	return 1;
  }
 */
}

/*
 * This function will not be avaliable for awhile so that I can determine
 * the normal rate that I player can earn experience and advance through
 * the guild.
 */
exchange_exp(amt) {
  int minexp;
  int level, extra_level;

  if(amt <= 0) {
	write("Tainin says to you:  Don't be so stupid.\n");
	return 1;
  }
  if(amt > 1000000) {
	write("Tainin says to you: You can only exchange 1,000,000 experience points at a time.\n");
	return 1;
  }
  if(amt < 10) {
	write("Tainin says to you: You must exchange at least 10 experience points.\n");
	return 1;
  }

  level = TP->query_level();
  extra_level = TP->query_extra_level();

  if(extra_level) {
        minexp = call_other("room/exlv_guild", "get_next_exp",  extra_level - 1);
  }
  else {
        minexp = call_other("room/adv_guild", "get_next_exp", level - 1);
  }

  if((TP->query_exp() - amt) < minexp) {
	write("Tainin says to you:  You cannot exchange that much experience.\n");
	return 1;
  }
  write("Tainin uses his wisdom and knowledge to exchange your experience.\n");
  write("You gain "+amt/3+" guild experience points.\n");
  TP->add_guild_exp(amt/3);
  TP->add_exp(-amt);
  return 1;
}

gain_practice() {
  int amt, max;
  int cost, gexp;

  amt = present("pavlik_guild_obj", this_player())->query_bought_practices();
  max = (this_player()->query_guild_rank() / 10) * 2;

  if(amt > max) {
	write("Tainin says to you:  Sorry, I cannot help you now.  You must become\n");
	write("more proficient in the ways of Meijin before you can kaeru again.\n");
	return 1;
  }

  cost = (this_player()->query_guild_rank() / 10) * 2500;
  if(cost < 2500) cost = 2500;
  gexp = DAEMON->query_rank_cost(this_player()->query_guild_rank());

  if((this_player()->query_guild_exp() - cost) < gexp) {
	write("Tainin says to you:  Sorry, You have not aquired enough experience to\n");
	write("do this.  Perhaps you can come back later.\n");
	return 1;
  }

  write("Tainin says to you:  You are wise to have learned so much.  You have much\n");
  write("potential.  More practice will perfect your skills.\n");
  write("You have gained "+HIW+"1 practice"+NORM+".\n");
  present("pavlik_guild_obj", this_player())->add_practices(1);
  present("pavlik_guild_obj", this_player())->add_bought_practices(1);
  this_player()->add_guild_exp(-cost);

  return 1;
}

