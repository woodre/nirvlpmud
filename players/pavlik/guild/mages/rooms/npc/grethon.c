inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Grethon");
 set_alias("grethon");
 set_short("Grethon (crazed)");
 set_long(
 "Grethon is probably the most horrid thing you have ever seen in your\n"+
 "life!  The wretched wizard has became disfigured in the miscasting\n"+
 "of a powerful spell.  Grethon hops around his laboratory on his one\n"+
 "remaining leg, searching for a spell that might recapture his former\n"+
 "appearance.  He has been known to pay great rewards for those that\n"+
 "help him.\n");
 set_level(30);
 set_ac(80);
 set_wc(80);
 set_hp(10000);
 set_al(10000);
 set_aggressive(0);
   }
}

