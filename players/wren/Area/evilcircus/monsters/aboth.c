	/*Aboth the Avenger*/

inherit "/obj/monster";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {
/*
object ob,ob2,ob3;

    ob = clone_object("/players/wren/Area/   .c");
         move_object(ob,this_object());

    ob2 = clone_object("/players/wren/Area/   .c");
         move_object(ob2,this_object());

    ob3 = clone_object("/players/wren/Area/evilcircus/items/pouch.c");
         move_object(ob3,this_object());
*/
set_name("aboth");
set_alt_name("avenger");
set_alias("ab");
set_short("Aboth the Avenger");
set_race("human");
set_gender("male");

set_long("Cloaked in blood spattered white robes stands Aboth the Avenger. \n"+
	 "A golden aura of righteousness glows around this holy warrior. \n"+
         "Despite being covered in the grime of combat he somehow seems \n"+
         "free of its stain. It is evident that something sinister \n"+
         "must be wandering about the circus for he isn't a performer.	  \n");

set_level(25);
set_ac(22+random(4));
set_wc(42+random(4));
set_hp(950+random(250));
set_al(900);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_heal(60,8);
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(10);		 /*combat chance chance*/
set_armor_params("other|fire", 10, 20, "fire_defense");


load_chat("Aboth whispers a mantra like prayer against evil. \n");
load_chat("Aboth wipes sweat and blood from his face.	\n");
load_chat("The Avenger looks carefully around the tent. \n");
load_chat("Aboth says: 'Something is fowl within this enclosure'. \n");

load_a_chat("Aboth chants words of strength.\n");
load_a_chat("Aboth say: 'I must prevail.' \n");
load_a_chat("Healing magics wash across Aboth.\n");
load_a_chat("Aboth parries your attack and returns a strike of his own.\n");
load_a_chat("The Avenger looks concerned that you should attack him so.\n");

set_chance(20);
set_spell_dam(30+random(30));
set_spell_mess1("The room flashes brightly as Aboth's sword cleavers his opponent. \n");    /*others*/
set_spell_mess2(""+HIW+"Light rains down as Aboth cleaves you"+NORM+" \n");    /*attacker*/

    }
}

int 
fire_defense() {

   if(!random(5)) {
         tell_room(environment(),
              BLU+"Icey"+NORM+" gusts swirl around Aboth fending off the heat. \n");
              return 3001; 
            }
}

