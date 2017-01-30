	/*Beast Keeper*/

inherit "/obj/monster2.c";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2,ob3;
    ob = clone_object("/players/wren/Area/evilcircus/items/vwhip.c");
         move_object(ob,this_object());
         command("wield whip",this_object());

    ob2 = clone_object("/players/wren/Area/evilcircus/items/chair.c");
         move_object(ob2,this_object());
         command("offwield chair",this_object());

    ob3 = clone_object("/players/wren/Area/evilcircus/items/pouch.c");
         move_object(ob3,this_object());
/*
set_id("keeper_npc"); */
set_name("keeper");
set_alt_name("beastkeeper");
set_alias("golhan");
set_short("Beastkeeper");
set_race("human");
set_gender("male");
set_long("Golhan the Beastkeeper looks about as rough and violent as the \n"+
         "creatures he controls. Scars criss-cross his face and his massive \n"+
         "limbs.One eye is concealed behind a red leather eyepatch. Very dense \n"+
         "roughly scraped hide armor provides him with some protection  \n"+
	 "from his charges. The beasts seem to fear little but they do eye \n"+
         "Golhan's movements very cautiously and obey his directions.	  \n");

set_level(20);
set_ac(18);
set_wc(34);
set_hp(500+random(200));
set_al(-500);    		 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(5);		 /*combat chance chance*/

load_chat("Golhan snaps his whip off to the side startling the audience. \n");
load_chat("The Beastkeeper pats one of his animals and he strolls across the ring. \n");
load_chat("The animals perform under the careful eye of the trainer much to the delight of the croud.\n");

load_a_chat("Golhan growls: 'Down curr, you're no tougher than me beasties, just need tamed.' \n");
load_a_chat("Beastkeeper zings the whip past your ear while tapping you with the stun wand.\n");


set_chance(7);
set_spell_dam(25+random(30));
set_spell_mess1("The Beastkeeper's whip suddenly leaps with a strange energy at his foe.\n");    /*others*/
set_spell_mess2("Golhan's whip crackles and discharges a dark energy as it flicks your flesh.\n");    /*attacker*/

  set_dead_ob(this_object());
    }
}

monster_died()
{
 object ob, oc;
 tell_room(environment(),
  "The beasts ROAR in anger!\n");

 ob = first_inventory(environment());

 while(ob)
 {
  oc = next_inventory(ob);

  if(ob->is_aggro_dood())
   ob->do_aggro((object)this_object()->query_attack());

  ob = oc;
 }
}
