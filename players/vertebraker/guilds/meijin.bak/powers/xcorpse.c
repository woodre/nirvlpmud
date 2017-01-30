#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xcorpse"

/*****/
/* heal endurance points from a corpse.  the amount recovered is equal */
/* to the corpse's heal_value * 7.                                     */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xcorpse \n");
  write("     Syntax : xcorpse \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Gloat over a vansquished foe.  This ritual \n");
  write("         imbibes you with endurance.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

int main() {
  object obj;

  obj = present("corpse", environment(this_player()));

  if(!obj) {
	write("There is no corpse here.\n");
	return 1;
  }

  switch (random(3)) {
    case 0:
	write("You stand over the vanquished foe and raise your arms in triumph!\n");
	say(ME+" stands over a vanquished foe and raises "+POS+" arms in triumph!\n");
	break;
    case 1:
	write("You kneel next to the corpse and bow your head solemnly.\n");
	say(ME+" kneels next to a corpse and bows "+POS+" head solemnly.\n");
	break;
    case 2:
	write("You grin and wipe your bloody weapon on "+
	capitalize((string)obj->query_name())+"'s corpse.\n");
	say(ME+" grins and wipes "+POS+" bloody weapon on "+
	capitalize((string)obj->query_name())+"'s corpse.\n");
	break;
  }
  write("The corpse disappears in a flash of white energy.\n");
  say("The corpse disappears in a flash of white energy.\n");
  GOB->add_endurance((int)obj->heal_value() * 7);
  destruct(obj);
  return 1;
}

