#include "security.h"
#include "living.h"
/*
 * This is the object wich tries to behave like Leo the archwizard.
 * The purpose is to converse with players and give them portable castles.
 */

string next_out;
object next_dest;
object give_him_castle;
int delay;
int level;		/* Restored from the player save file. */


get() { return 0; }


id(str) { return str == name; }

reset(arg) {
    if (arg) {
	return;
    }
    msgout = "leaves";
    msgin = "enters";
    name = "listen";
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
      tell_object(find_player("hagbard"), str);
}
