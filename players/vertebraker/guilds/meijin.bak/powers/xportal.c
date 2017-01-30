#include "/players/pavlik/guild/defs.h"
#define SKILL_NAME "xportal"
#define COST 350

/* Ok, Bp 1617 Jul 21 21:28 xportal.c   */
void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xportal \n");
  write("     Syntax : xportal \n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         The portal command will return you instantly to\n");
  write("         the Citadel.  Portal may not be avaliable in\n");
  write("         some areas.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

int main() {
  object obj;
  string whoops;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(TP->query_attack()) {
	write("You cannot portal when you are fighting.\n");
	return 1;
  }
  if((string)environment(TP)->realm() == "NT") {
	write("You cannot portal here.\n");
	return 1;
  }
  write(PRE+"Your "+HIY+"golden armband"+NORM+" pulses with energy.\n");
  write(PRE+"A magical portal opens before you and you step through.\n");
  say("A magical portal opens before "+ME+".  "+ME+" steps in and disappears.\n");

  if(whoops = (string)call_other("obj/base_tele", "teleport")) {
	write(PRE+" ... Something is amiss ... \n");
	move_object(TP, whoops);
  }
  else {
	move_object(TP, "players/pavlik/guild/room/start");
  }
  say(ME+" steps through the magic portal.\n");
  write(environment(TP)->short()+"\n");
  GOB->add_endurance(-COST);
  return 1;
}

