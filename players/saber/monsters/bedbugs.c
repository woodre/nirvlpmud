inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
    set_name("bugs");
   set_short();
   set_long("A large bug.  It appears to be sleeping.\n");
     set_level(2);
     set_ac(3);
     set_wc(6);
     set_hp(30);
     set_al(-10);
     set_frog(1);
     set_aggressive(0);
     set_chat_chance(1);
    load_chat("You think you hear something snoring.\n");
   }
}
