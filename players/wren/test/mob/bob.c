	/* Monster using V file - Bob.c*/

#include <ansi.h>
inherit "/obj/monster2";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {
/*
object ob,ob2,ob3;

    ob = clone_object("/players/wren/Area/   .c");
         move_object(ob,this_object());
         command("wield obj",this_object());

    ob2 = clone_object("/players/wren/Area/   .c");
         move_object(ob2,this_object());
         command("offwield obj",this_object); 

    ob3 = clone_object("/players/wren/Area/    .c");
         move_object(ob3,this_object());
*/
set_name("bob");
set_alt_name("boss");
set_alias("ass");
set_short("Bob the Target Boss");
set_race("manager");
set_gender("male");

set_long("This is Bob, he's the store manager at Target. We don't  \n"+
	 "care for his style. He's and ass. Kill him please.	  \n");

set_level(15);

set_ac(12);
set_wc(20);
set_hp(250);

set_al(-100);    		 /*alignment*/
set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(2);		 /*combat chance chance*/

                                 /*seconds between wander,flag if !0 wander from fight, directions not to use*/
set_wander(5, 0, ({"up","east","south"}) );
                                 /*health %, chance to succeed per try,perferred direction of flight or 0, message of fleeing */
set_wimpy(20, 20, "south", "Bob screams about lousy overnight and flees. \n");	  
                                 /*flag aggy 1 on or 0 off, relative health of target,chance per hb of attacking */
set_aggressive(1, 100, 100); 
             
                                 /*path for helper, seconds between summons, number in room, total callable number */
set_assist("/players/wren/test/darth2", 20, 2, 2); 

load_chat("Bob stands stumped.	\n");
load_chat("Bob says, 'Hiya'.\n");

load_a_chat("Bob says,' You overnighters are whiners.	\n");
load_a_chat("Bob says,' I know how the stockrooms work.	\n");

set_chance(10);
set_spell_dam(10);

set_spell_mess1("Bob fires his PDT wildly at you. \n");    /*others*/ 
set_spell_mess2("Bob slices you with a red card. \n");    /*attacker*/ 


    }
}
/*
get_spell_mess1() {
     return
     "Bob <Verbs> " +(string)attacker_obj->query_name();
                  }

get_spell_mess2() {
     return
     "Bob harshly <Verbs> " +(string)attacker_obj->query_name();
                  }
*/

