#include "/players/linus/def.h"
inherit "/obj/monster.c";
id(str) { return str=="roo"; }
object arm;
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("roo");
 set_short("Roo");
 set_long("Roo is a joey, a young kangaroo.  When he isn't riding along with\n"+
 "Kanga in her pouch, he enjoys playing with his toys and his good\n"+
 "friend Tigger.  He wears a small blue t-shirt and is looking forward\n"+
 "to going to Christopher Robin's house for a picnic.\n");
 arm=CO("/players/linus/Newbie/obj/blue_shirt.c");
 MO(arm,TO);
 init_command("wear shirt");
 set_aggressive(0);
 set_al(1000);
 set_race("kangaroo");
 set_level(20);
 set_ac(15);
 set_wc(19);
 set_hp(400);
 set_chat_chance(10);
 load_chat("Roo says: I can do anything!\n");
 set_a_chat_chance(10);
 load_a_chat("Roo says: Help! Mother! Help!\n");
}
