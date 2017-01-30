inherit "/obj/monster";
#include "/players/vertebraker/guilds/meijin/defs.h"
#define MAX_PET_LEVEL 20
#define MAX_PET_STAMINA 50
#define MAX_PET_MAGIC 50
#define MAX_PET_ATTACK 60
#define MAX_PET_DEFENSE 60

reset(arg) {
  ::reset(arg);
  if (!arg) {
  set_name("Kitaeru");
  set_alias("kitaeru");
  set_alt_name("master");
  set_short("Master Kitaeru");
  set_long("Master Kitaeru.\n");
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
  add_action("train","train");
  add_action("cost","cost");
  add_action("sit","sit");
  add_action("stand","stand");
}

short() {
  if(this_object()->query_attack()) return "Kitaeru the Dragonmaster";
  else return "Kitaeru stands here watching the skies";
}

long() {
  if(this_object()->query_attack()) {
	write("Kitaeru the Angered is a fierce warrior.  Her moves are\n");
        write("incredible quick and sure.  Kitaeru's hands and feet move\n");
        write("with blinding speed as she cuts down his enemy.\n");
  }
  else {
	write("Kitaeru stands here scanning the skies with watchful eyes.\n");
	write("It is said that she can smell a dragon's scent on the wind.\n");
	write("Kitaeru has spent her life studying dragons.  She uses her\n");
	write("vast knowledge to "+CYN+"train"+NORM+" Meijin dragons.\n");
	write("She can also tell you how much it will "+CYN+"cost"+NORM+" to have\n");
	write("your dragon trained.\n");
  }
  return;
}

sit() {
  write("You sit down and enjoy the fresh air.\n");
  say(capitalize(this_player()->query_name())+" sits down.\n");
  return 1;
}

stand() {
  write("You stand up.\n");
  say(capitalize(this_player()->query_name())+" stands up.\n");
  return 1;
}

catch_tell(str) {
  string tmp, tmp2, tmp3;

  if(!present(this_player(), environment(this_object()))) return 1;

  if(sscanf(str, "%s tells you: %sinfo%s", tmp, tmp2, tmp3) == 3) {
	write("Kitaeru says to you:  I am Kitaeru, the Dragon Master.  I can\n");
	write(CYN+"train"+NORM+" your dragon.  I can also tell you how much it will "+CYN+"cost\n"+NORM);
	write("to have your dragon trained.\n");
	return 1;
  }
  if(sscanf(str, "%s tells you%s", tmp, tmp2) == 2) {
	write("Kitaeru says:  Just type 'train' or 'cost'.\n");
	return 1;
  }
}


get_cost(obj, str) {
  int amt;

  switch (str) {
	case "attack" :
		amt = obj->query_attack_stat() * 750; break;
	case "defense" :
		amt = obj->query_defense() * 750; break;
	case "stamina" :
		amt = obj->query_stamina() * 1100; break;
	case "magic" :
		amt = obj->query_magic() * 1100; break;
	case "level" :
		amt = obj->query_level() * 5500; break;
  }
  return amt;
}

cost(str) {
  int amt, mon;
  object obj;

  if(!str) {
	write("Kitaeru says:  What do you want to have trained?\n");
	return 1;
  }
  if(!(obj = find_living(TP->query_real_name()+"'s meijin_pet"))) {
	write("Your dragon must be present.\n");
	return 1;
  }
  amt = get_cost(obj, str);
  if(!amt) return 0;
  if(str == "attack" || str == "defense") mon = 1600;
  if(str == "stamina" || str == "magic") mon = 3100;
  if(str == "level") mon = 8500;

  write("Kitaeru says:  It will cost you "+amt+" xp and "+mon+" gold coins.\n");
  return 1;
}

train(str) {
  int amt, mon;
  object obj;

  if(!str) {
	write("Kitaeru says:  What do you want to have trained?\n");
	return 1;
  }
  if(!(obj = find_living(TP->query_real_name()+"'s meijin_pet"))) {
	write("Your dragon must be present.\n");
	return 1;
  }
  amt = get_cost(obj, str);
  if(str == "attack" || str == "defense") mon = 1600;
  if(str == "stamina" || str == "magic") mon = 3100;
  if(str == "level") mon = 8500;
  if(!mon) return 0;

  if(mon > TP->query_money()) {
	write("Kitaeru says:  Sorry, you cannot afford to do this.\n");
	return 1;
  }
  if(amt > (TP->query_guild_exp() - DAEMON->query_rank_cost(TP->query_guild_rank()))) {
	write("Kitaeru says:  You do not have the experience to do this.\n");
	return 1;
  }
  if((str == "attack" && obj->query_attack_stat() >= MAX_PET_ATTACK) ||
     (str == "defense" && obj->query_defense() >= MAX_PET_DEFENSE) ||
     (str == "stamina" && obj->query_stamina() >= MAX_PET_STAMINA) ||
     (str == "magic" && obj->query_magic() >= MAX_PET_MAGIC) ||
     (str == "level" && obj->query_level() >= MAX_PET_LEVEL)) {
	write("Kitaeru says:  Your pet cannot increase its "+str+" any further.\n");
	return 1;
  }
  write("Kitaeru trains your Dragon.\n");
  write(capitalize(obj->query_name())+"'s "+str+" increases!\n");
  say("Kitaeru trains "+capitalize(TP->query_name())+"'s dragon.\n");
  if(str == "level") obj->raise_pet_level();
  else if(str == "attack") obj->raise_attack();
  else if(str == "defense") obj->raise_defense();
  else if(str == "stamina") obj->raise_stamina();
  else if(str == "magic") obj->raise_magic();
  this_player()->add_guild_exp(-amt);
  this_player()->add_money(-mon);
  return 1;
}

