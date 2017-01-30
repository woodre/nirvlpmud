	/* Kryten2 */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
    ::reset(arg);
     if(!arg)  {

object ob;

    ob = clone_object("/players/wren/Area/starbug/items/bazookoid.c");
         move_object(ob,this_object());
         command("wield bazookoid",this_object());

set_name("kryten");
set_alias("badass");
set_short("Kryten checking his bazookoid");
set_race("mechanoid");
set_long("Something bad has clearly happened to Kryten. He looks scuffed \n"+
         "and dusty. He growls as you look at him and grips his weapon   \n"+
         "closer. It is as though there is no guilt in him. Better watch \n"+
         "out, the business end of the bazookoid is pointed towards you. \n"+
         "And if he's guilt free, it just might 'accidently go off'.     \n");

set_level(17);
set_ac(14);
set_wc(24);
set_hp(350);
set_al(500);    	         /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/
load_chat("Kryten growls: 'Maybe if I let it get knackered eating you guys it \n"+
          "          will let me live. 'Move it suckers!'\n");
load_chat("Kryten says: 'Shut up you little mincing fairy'.\n");
load_chat("Krtyen says: 'You can't trust him he's got no anger'.\n");
load_chat("Kryten glares at you.\n");

load_a_chat("Kryten says: 'If you bleed on the floor, your're cleaning it up'.\n");
load_a_chat("Kryten says: 'Silicon heaven awaits'.\n");
load_a_chat("Kryten cracks you in the face with the bazookoid.\n");
load_a_chat("Kryten demonstrates his anger with mindless violence skill.\n");

    }
}

