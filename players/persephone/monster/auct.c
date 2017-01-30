inherit "obj/monster";
#include "/players/persephone/rooms.h"
object gav;
object gold;
reset(arg) {
 ::reset();
  if (arg) return;
   gav = clone_object("players/persephone/closed/gavt.c");
   move_object(gav, TOB);
   init_command("wield gavel");
   gold = clone_object("obj/money");
   gold->set_money(200);
   move_object(gold, TOB);
   set_name("auctioneer");
   set_alias("trader");
   set_level(17);
   set_al(-100);
   set_short("An Auctioneer");
   set_long("The local auctioneer who once sold houses but now has a far more\n"+
            "insideous occupation being a slave trader. He looks extremely\n" +
            "strong and robust carrying an auctioneers gavel.\n"); 
   set_hp(425);
   set_wc(24);
   set_ac(17);
   set_aggressive(0);
   set_chance(10);
   set_spell_dam(10);
   set_spell_mess1("Brings his Gavel down furiously! Crack!!!\n");
   set_spell_mess2("Strikes you over the head with his Gavel! Thwap!!!\n");
   set_chat_chance(50);
   set_a_chat_chance(50);
   load_chat("Actioneer cries: What am I bid for this strong looking slave\n");
   load_chat("Actioneer shouts: Come on this slave is in the prime of life\n");
   load_chat("Auctioneer cries: is that your final bid\n");
   load_chat("Auctioneer states: A very good purchase sir!\n");
   load_a_chat("Auctioneer sneers: I'll teach you some respect you lowly slave!!\n");
   load_a_chat("The Auctioneer frowns at you exclaiming: Back to the stocks\n");
   load_a_chat("Auctioneer says: See what I mean the last owner did not train him\n");
 }
