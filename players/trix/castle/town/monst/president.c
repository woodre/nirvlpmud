/* Changed from lev.20 to 10, hp500 to 200, wc30 to 15, ac17 to 10,
   aggressive 0 to 1, and coins 4950 to 1500  -Snow */
inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("president");
   set_race("human");
   set_alias("president");
   set_short("Bank President");
   set_long("An old and greedy man, looking around with semi-closed eyes.  His\n"+
            "pockets seem full of money.\n");
   set_level(12);
   set_hp(180);
  set_wc(16);
  set_ac(9);
  add_money(1500);
   set_aggressive(1);
    set_whimpy();
   set_chat_chance (5);
   load_chat("Bank President looks at you suspiciously.\n");
   set_a_chat_chance(15);
   load_a_chat("Bank president says: Go away, damned thief!!!\n");
   load_a_chat("Bank president shouts: Guards!!! Guards!!!\n");
}
