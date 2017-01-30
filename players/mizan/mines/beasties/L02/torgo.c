#include "living.h"
/*
 * This is the object wich tries to behave like Leo the archwizard.
 * The purpose is to converse with players and give them portable castles.
 */

object requesting_wizard;
object sponsor;
string next_out;
object next_dest;
object give_him_castle;
int delay;
/* -rw-------   1 nirvana  nirvana      6012 Sep 28  1993 leo.c
LDmud don't like redeclares of stuff in inherits... -Bp july 2006
int level;               Restored from the player save file. */

short() { return "Leo the Archwizard"; }

get() { return 0; }

long() {
    write(short() + ".\n");
}


/* rumplemintz found this bug... i added it at his request. -miz 2007 nov 25 */
query_name() { return name; }

id(str) { return str == name; }

reset(arg) {
    if (arg) {
	sponsor = 0;
	requesting_wizard = 0;
	return;
    }
    msgout = "leaves";
    msgin = "enters";
    name = "leo";
    next_out = 0;
    is_npc = 1;
    level = 40;
    alignment = 1000;
    weapon_class = WEAPON_CLASS_OF_HANDS;
    max_hp = 300;
    hit_point = 300;
    experience = 1000000;
    enable_commands();
    spell_points = 300;
}

catch_tell(str)
{
  object from;
  string a;
  string b;
  string c;
  from = this_player();
  if (!from)
    return;	/* Not from a real player. */
    if (sscanf(str, "%s gives %s to Leo.", a, b) == 2) {
	object ob;
	ob = present(b, this_object());
	if (!ob || !call_other(ob, "id", "orc slayer"))
	    return;
	next_out = "Leo says: Well done. You have fullfilled this quest.\n";
	next_dest = from;
	set_heart_beat(1);
	call_other(from, "set_quest", "orc_slayer");
	destruct(ob);
	return;
    }
  }
/*
  log_file("LEO", str + "\n");
*/
}

/*
 * Always let the heart_beat do the talking, to simulate delay.
 */

heart_beat()
{
  if (attacker_ob)
    fireball(attacker_ob);
  attack();
  already_fight=0;
  if (random(40) == 1)
    say("Leo smiles happily.\n");
  if (delay>0) {
    delay -= 1;
    return;
  }
  if (next_out) {
    tell_object(next_dest, next_out);
    next_out = 0;
  }
  set_heart_beat(0);
}


