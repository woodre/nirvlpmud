#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"
inherit "obj/monster.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

set_name("etien");
set_alias("nomad");
set_race("human");
set_gender("male");
set_short("I can't think of a pretitle Etien the great adventurer");
/*set_long(
	"Etien is a human, 6 feet 5 inches tall and 195 lbs.\n" +
	"Etien is wearing a silver gypsy medallion.\n" +
	"Etien has a small "+ YEL + "gold" + OFF + " star tattoo on his inside right ankle.\n" +
    "Etien is carrying:\n" +
	"Etien's quicktyper.\n" +
	"A silver gypsy medallion (worn).\n");*/

set_level(8);
set_hp(100000);
set_al(100);
set_wc(75);
set_ac(40);
set_heal(10,1000);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(3);
load_chat("Etien says: I love to collect things.\n");
load_chat("Etien says: If you have something to barter, talk to me about it.\n");
load_chat("Etien says: I'm searching for items from the forests here but I'm afraid to go inside.\n");
set_a_chat_chance(10);
load_a_chat("Etien exclaims: What are you killing me for?  This room is not pk!\n");
load_a_chat("Etien exclaims: There go my dreams of ever being the richest merchant on Nirvana!\n");
load_a_chat("Etien exclaims: Oh sure, you just love to kill little newbies don't you.  You must be a Ninja!\n");

set_chance(20);
set_spell_dam(100);
set_spell_mess1(
     "Etien casts a magic missile!\n");
set_spell_mess2(
     "Etien hits you with a magic missile!\n");
}

long()
{
	write("Etien is a human, 6 feet 5 inches tall and 195 lbs.\n" +
		  "Etien is wearing a silver gypsy medallion.\n" +
	   	  "Etien has a small "+ YEL + "gold" + OFF + " star tattoo on his inside right ankle.\n" +
    	  "Etien is carrying:\n" +
		  "Etien's quicktyper.\n" +
		  "A silver gypsy medallion (worn).\n");
}

monster_died()
{
   	tell_room(environment(this_object()),
     "Etien died.\n");
   return 0;
}




