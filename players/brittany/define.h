/*  General-Purpose Include */

#include "/players/brittany/ansi"

/* inherit */
#define ROOM "room/room";
#define WEAPON "obj/weapon";
#define TREASURE "obj/treasure";
#define MONSTER "obj/monster";
#define ARMOUR "obj/armour";

#define TP this_player()
#define TO this_object()
#define ENV environment
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define CAP capitalize
#define LOWER lower_case
#define POS TP->query_possessive()
#define MOCO move_object(clone_object
