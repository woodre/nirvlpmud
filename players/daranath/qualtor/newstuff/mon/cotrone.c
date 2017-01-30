#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object(ROOT+"junk/simple_chain.c"),this_object());
move_object(clone_object(ROOT+"junk/surcoat1.c"),this_object());
move_object(clone_object(ROOT+"weps/crusader.c"),this_object());

set_name("Cotrone SilverBlade");
set_alias("cotrone");
set_short("Cotrone, Former Paladin of Nirvana");
set_alt_name("shopkeeper");
set_race("human");
set_gender("male");
set_long("Cotrone SilverBlade has long since retired from adventuring life within\n"+
         "Nirvana. A long scar runs down the side of his face and underneath a\n"+
         "coat of simple chainmail, probably a trophy of the event that caused\n"+
         "him to retire. Cotrone still wear a large coat of arms with Qual'tors\n"+
         "sigil over his chainmail, probably a relic of a time long past.\n"+
/*
         "Cotrone can give you <"+HIW+"info"+NORM+"> about the Dungeon Quest.\n"+
*/
         "For 100 coins, You can <"+HIW+"ask"+NORM+"> him for advice about his wares.\n");
set_level(12);

init_command("wear chainmail");
init_command("wear coat");
init_command("wield blade");

set_ac(9);
set_wc(15 + random(4));
set_hp(180 + random(20));
set_al(1000);
set_aggressive(0);
set_chat_chance(3);
set_a_chat_chance(25);
load_chat("Cotrone nods torwards you as your browse through his store.\n");
load_chat("Cotrone stares at you as you shop, making you uncomfortable.\n");
load_chat("Cotrone seems to be waiting for you to do something.\n");
load_a_chat("Cotrone slashes at you with his blade.\n");

   }
}
