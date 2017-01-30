#include "/players/linus/def.h"
inherit "/obj/monster.c";
id(str) { return str=="pooh" || str=="winnie" || str=="bear" || str=="pooh bear" || str=="winnie the pooh"; }
object arm;
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Winnie the Pooh");
 set_short("Winnie the Pooh");
 set_long(
 "Winnie the Pooh is a small, yellow bear.  He wears a red t-shirt, which\n"+
 "is stained with honey.  Pooh loves honey, and would do almost anything\n"+
 "for some.  He is sitting on the log outside of his house, waiting for\n"+
 "the rest of his friends to arrive.  They have been invited to a picnic\n"+
 "at Christopher Robin's house today.\n");
  arm=CO("/players/linus/Newbie/obj/pooh_shirt.c");
  MO(arm,TO);
  init_command("wear shirt");
 set_level(20);
 set_ac(17);
 set_wc(25);
 set_hp(600+random(51));
 add_money(4000+random(51));
 set_chat_chance(10);
 load_chat("Pooh says: Do you have any honey?\n");
 load_chat("Pooh says: I love honey!\n");
 load_chat("Pooh says: Oh bother!\n");
 load_chat("Pooh licks some honey off of his paw...\n");
 set_a_chat_chance(10);
 load_a_chat("Pooh says: Why do you attack me?\n");
 load_a_chat("Your hands get all sticky from the honey...\n");
 set_chance(10);
 set_spell_dam(random(25));
 set_spell_mess1("Pooh bear grabs a honey pot and\n"+
 HIR+"                   S M A S H E S\n"+NORM+
 "                               it over his attackers head!\n");
 set_spell_mess2("Pooh bear grabs a honey pot and\n"+
 HIR+"                   S M A S H E S\n"+NORM+
 "                               it over your head!\n");
}
