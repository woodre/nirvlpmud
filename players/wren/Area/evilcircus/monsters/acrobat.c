	/*blade acrobats - sharp 'witted' performers*/

inherit "/obj/monster";
#include "/players/wren/ansi.h"

reset(arg)  {
     ::reset(arg);
     if(!arg)  {
/*
object ob,ob2,ob3;

    ob = clone_object("/players/wren/Area/evilcircus/items/pouch.c");
         move_object(ob,this_object());

    ob2 = clone_object("/players/wren/Area/evilcircus/items/daggers.c");
         move_object(ob2,this_object());

    ob3 = clone_object("/players/wren/Area/    .c");
         move_object(ob3,this_object());
*/
set_name("juggler");
set_alt_name("blades");
set_alias("acrobat");
set_short("An acrobat juggling blades");
set_race("ghast");
set_gender("female");

set_long("Lithe athletic females twirl sharp objects dexterously around \n"+
	 "themselves. Their faces are hidden behind colorful wispy veils\n"+
         "much like the rest of their body. Little can be told about them.\n"+
         "Something seems cold and inhuman though in thier manners.	  \n");
set_level(18);
set_ac(14);
set_res(10);
set_armor_params("phsical",10,10,"spec");
set_wc(24+random(6));
set_hp(320+random(200));
set_heal(20,40);
set_al(-500);  			 /*alignment*/
set_aggressive(1);		 /*0 not, 1 is*/
set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(1);		 /*combat chance chance*/

load_chat("An acrobat cartwheels across the ring. \n");
load_chat("A pair of acrobats juggle daggers between them with lightning speed.	\n");

load_a_chat("Ghast slices her dagger across your arm and slinks beyond reach.\n");
load_a_chat("Acrobat drop kicks you and rolls away.		\n");

set_chance(20);
set_spell_dam(10+random(20));
set_spell_mess1("Acrobat throws a series of daggers into their foe.\n");    /*others*/
set_spell_mess2("You are peppered with nasty sharp daggers thrown by acrobats. \n");    /*attacker*/

    }
}

spec() {
   if(!random(50)) {
   write("Blade acrobats twirl dexterously out of harms way.  \n");
   return 1112;
       }
    }
