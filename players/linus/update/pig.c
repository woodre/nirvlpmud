#include "/players/linus/def.h"
inherit "/obj/monster.c";
 id(str) { return str=="piglet" || str=="pig"; }
object arm;
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_short("Piglet");
 set_name("Piglet");
 set_long(
 "Piglet is a nervous little pig.  He lives with Winnie the Pooh in the\n"+
 "hundred acre wood.  Piglet has long floppy ears, which wiggle a little\n"+
 "bit due to his nervousness.  Piglet is waiting with Pooh for the\n"+
 "others to arrive so they can go to a picnic at Christopher Robin's\n"+
 "house.\n");
 arm=CO("/players/linus/Newbie/obj/striped_shirt.c");
 MO(arm,TO);
 init_command("wear shirt");
 set_aggressive(0);
 set_race("piglet");
 set_level(18);
 set_ac(15);
 set_wc(18);
 set_hp(450+random(100));
 set_al(1000);
 set_chat_chance(10);
 load_chat("Piglet's ears twitch...\n");
 load_chat("Piglet says: Oh dear! Oh dear! Oh dearie, dearie, dearie, dear!\n");
 load_chat("Piglet fidgets nervously...\n");
 set_a_chat_chance(10);
 load_a_chat("Piglet says: Why are you doing this to me?\n");
 load_a_chat("Piglet starts to cry.\n");
 load_a_chat("Piglet says: Someone help me!\n");
}
