inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if(!arg) {

   set_name("fool");
   set_short("A dumb fool");
   set_race("human");
   set_long("A typical fool I'm sure you encounter in everday life.  It\n"+
     "can be a boss, the person who cut you off in traffic, or someone\n"+
     "on this mud!  Do the right thing and kill this fool!\n");

   set_level(7);
   set_ac(6);
   set_wc(11);
   set_hp(105);
   set_al(-105);
   set_aggressive(0);
   set_chat_chance(10);
   set_a_chat_chance(10);
   load_chat("The fool is irritating you with its presence!\n");
   load_chat("Fool says:  Ha ha, you can't hit me!\n");
   load_a_chat("Fool slaps you!\n");
   load_a_chat("Fool says:  You'll have to do better than that to win!\n");
   }
}
