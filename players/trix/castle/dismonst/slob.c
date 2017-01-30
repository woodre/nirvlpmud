inherit "obj/monster";
reset(arg){
   object dress;
   ::reset(arg);
   if(arg) return;
   set_name("woman");
   set_race("human");
   set_alias("slob");
   set_short("A slob woman");
   set_long("This is a slob woman, wearing a kitch pink dress and desperately looking for a\nman.\n");
   set_level(8);
   set_hp(120);
   set_al(50);
   set_wc(12);
   set_ac(7);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("The slob woman looks maliciously at you.\n");
   load_chat("The slob woman winks at you suggestively.\n");
   load_chat("The slob woman looks around in search of something or 'SOMEONE'!\n");
   set_a_chat_chance(20);
   load_a_chat("The slob woman pinches your butt.\n");
   load_a_chat("The slob woman scratches you.\n");
   dress=clone_object("/players/trix/castle/dismonst/pdress");
   move_object(dress,this_object());
   call_out("muovi",1);
}
muovi()
{ call_other(this_object(),"random_move");
  call_out("muovi",16);
  return 1;
}
