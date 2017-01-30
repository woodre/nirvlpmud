inherit "obj/monster";
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("guts");
   set_race("other");
   set_alias("guts");
   set_short("Worm guts");
   set_long("These guts have a mind of their own! Can you free yourself?\n");
   set_level(20);
   set_hp(450);
   set_al(0);
   set_wc(1);
   set_ac(14);
   set_aggressive(1);
   set_dead_ob(this_object());
   set_chance(100);
   set_spell_dam(30);
   set_spell_mess1("The guts begin to digest you!");
   set_spell_mess2("The worms acid splash everywhere!");
}
monster_died(){
   object room,opening;
   room=environment(this_object());
   opening=clone_object("/players/ladyfinger/obj/opening");
   move_object(opening,environment(this_object()));
   tell_room(room,"You have managed to cut an opening in the stomach wall!\n");
   return 0;
}
