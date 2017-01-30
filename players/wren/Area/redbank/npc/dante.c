	/*dante*/

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {
/*
object ob,ob2,ob3;
    ob = clone_object("/players/wren/Area/   .c");
         move_object(ob,this_object());
    ob2 = clone_object("/players/wren/Area/   .c");
         move_object(ob2,this_object());
    ob3 = clone_object("/players/wren/Area/    .c");
         move_object(ob3,this_object());
*/
set_name("dante");
set_alt_name("dante_npc");
set_alias("hicks");
set_short("Dante Hicks");
set_race("human");
set_gender("male");
set_long("Dante Hicks is a clerk. He is pretty good at his job   \n"+
         "but its not a hard job to do. He simply has to put up  \n"+
         "with all the braindead morons that wish to buy things. \n"+
	 "He wasn't supposed to work today but the boss ran off  \n"+
         "for a vacation without covering the shift so he had to \n"+
         "come in on his day off and he's not happy about it. If \n"+
         "you can get his attention he may have something to     \n"+
         "sell of some interest provided the annoying customers  \n"+
         "don't get all of it before you. 	                 \n");

set_level(18);
set_ac(16);
set_wc(28);
set_hp(400+random(100));
set_al(400);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(15);		 /*combat chance chance*/

load_chat("Dante asks: 'Which did you like better Jedi or Empire?' \n");
load_chat("Dante says: 'Empire cause its ends on such a down note, Jedi just had a bunch of muppets.' \n");
load_chat("Dante whines: 'I'm not even supposed to be here today.'\n");
load_chat("Dante says: 'You should hear the barrage of stupid questions I get.' \n");

load_a_chat("Dante screams: 'Thirty-seven' and vents his frustration on you. \n");
load_a_chat("Dante says: 'One ball, you only brought one ball. Fuck! Fuck, fuck, fuck!' \n");

set_chance(20);
set_spell_dam(20+random(30));
set_spell_mess1("Dante throws merchandise at his foes. \n");    /*others*/
set_spell_mess2("Dante pelts you with consumer goods. \n");    /*attacker*/
    }
}

