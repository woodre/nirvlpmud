#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 650
#define MONEY_COST 1800
#define RANK 40
#define SKILL_NAME "summon"

/***************************************************/
/* This summons the guild pet.  This command can   */
/* only be used within specific parts of the guild */
/* hall.  The guild pet info is located at:        */
/* /players/vertebraker/guilds/meijin/obj/guild_pet             */
/***************************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Summon \n");
  write("     Syntax : xsummon\n");
  write("     Cost   : "+COST+" ep + "+MONEY_COST+" coins\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Summons your Meijin Dragon.  The Meijin Dragon\n");
  write("         as a fiercely loyal companion.  "+MONEY_COST+" gold coins\n");
  write("         are required to summon the dragon.  Dragons can\n");
  write("         only be summoned from certain places.\n");
/* **** */
  write("\n");
  write("         ** This command is currently not avaliable.\n");
  write("         ** The Guild Pet is still under review.\n");
  write("\n");
/* **** */
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main() {
  object obj;
  int num;

  write("Sorry, this command is not avaliable at the moment.\n");
  write("Please read the help file.\n");
  return 1;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(obj = find_living((string)TP->query_real_name()+"'s meijin_pet")) {
	write(PRE+"You summon "+capitalize((string)obj->query_name())+" to your side.\n");
	obj->summon_pet();
	return 1;
  }

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(TP->query_money() < MONEY_COST) {
	write("You do not have the required amount of coins.\n");
	return 1;
  }
  if(!environment(TP)->query_xsummon()) {
	write("You cannot summon from here.\n");
	return 1;
  }
  write("\n");
  write(PRE+"You stand atop the Citadel and raise your hands to the sky.\n");
  write(PRE+"A "+HIM+"Dragoncry"+NORM+" echoes around you in response.\n");
  say(ME+" stands atop the battlements and raises "+POS+" hands to the sky.\n");
  say("A dragon sweeps down from the skies and lands gently before "+ME+"!\n");
  obj = clone_object("players/pavlik/guild/obj/guild_pet");
  obj->set_owner(TP->query_real_name());
  obj->configure_dragon();
  move_object(obj, environment(TP));
  write(capitalize((string)obj->query_name())+" sweeps down from the sky and lands gently before you.\n");
  write("\n");
  GOB->add_endurance(-COST);
  TP->add_money(-MONEY_COST);
  return 1;
}

