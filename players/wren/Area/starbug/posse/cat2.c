	/* Cat2 */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob;

    ob = clone_object("/players/wren/Area/starbug/items/bazookoid.c");
         move_object(ob,this_object());
         command("wield bazookoid",this_object());

set_name("cat");
set_alias("the cat");
set_short("The Cat");
set_race("cat");

set_long("The Cat looks horrible. He's wearing mismatched earth tones \n"+
         "and his hair is diseveled. He looks like he should be sleeping \n"+
         "in a gutter somewhere. This is hard to believe. It appears his \n"+
         "vanity is gone, nothing else could explain why he isn't looking \n"+
         "his best. He is slouched on a crate cradling a bottle in a brown \n"+
         "bag and his bazookoid. In his present state he doesn't look \n"+
         "very threatening. \n");

set_level(17);
set_ac(14);
set_wc(24);
set_hp(350);
set_al(500);   			 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/

load_chat("Cat says: 'Don't mind me I'm nobody'.\n");
load_chat("Cat takes a big draw on his bottle.\n");
load_chat("Cat says: 'I'll do whatever you guys decide to do'. \n");

load_a_chat("Cat says: 'You'll probably be doing the world a favor by killing me.'\n");
load_a_chat("Cat hits you with his bottle.\n");
load_a_chat("Cat vomits on your shoes. \n");
load_a_chat("You are disgusted by a smell akin to yak urine from the cat's torn coat.\n");

    }
}
