	/* Cat */

#include <ansi.h>
inherit "/obj/monster";

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2,ob3,ob4;
    ob = clone_object("/players/wren/Area/starbug/items/mirror.c");
         move_object(ob,this_object());
    ob2 = clone_object("/players/wren/Area/starbug/items/sequinjacket.c");
         move_object(ob2,this_object());
         command("wear jacket",this_object());
    ob3 = clone_object("/players/wren/Area/starbug/items/comb.c");
         move_object(ob3,this_object());
    ob4 = clone_object("/players/wren/Area/starbug/items/fish.c");
         move_object(ob4,this_object());

set_name("cat");
set_alias("the cat");
set_short("The Cat, stylin");
set_race("cat");
set_long("The Cat. He evolved from the generations of cats that were born from \n"+
         "Lister's cat, Frankenstein(female). His parents were the cripple and \n"+
         "the idiot. He's vain and self-assured and sure that he's dead sexy to \n"+
         "women. He's wearing one of his favorite jackets. Though you'd never \n"+
         "get him to pick just one from his vast collection.\n");
set_level(17);
set_ac(14);
set_wc(24);
set_hp(350);
set_al(500);    		 /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/
load_chat("Cat says: 'OOOoooowwww, How'my lookin'. I'm lookin good. No better \n"+
          "than good. I'm looking smooth, with a capital 'SMO'. \n");
load_chat("Cat says: 'Hey, goal post head, what are you talking about?\n");
load_chat("Cat says: 'This is mine, and this is mine, that is mine...I don't want this bit though.' \n");
load_chat("Cat struts about the room practicing his showing off for the ladies.' \n");
load_chat("Cat combs his hair carefully and then again.'\n");
load_chat("Cat says: 'Now how'my looking...'\n");
load_a_chat("Cat says: 'Hey what are you doing monkey?\n");
load_a_chat("Cat says: 'Its been a good day, I've claimed a lot of stuff, had ten naps, \n"+
            "           and maybe if I'm lucky I'll get to have sex with something.\n");
load_a_chat("Cat spins and kicks you. \n");
load_a_chat("You are dazzled by the Cat's sparkling jacket and dance moves.\n");
    }
}
