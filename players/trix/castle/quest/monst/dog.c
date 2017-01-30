inherit "obj/monster";
reset(arg){
   object skin;
   ::reset(arg);
   if(arg) return;
   set_name("dog");
   set_race("dog");
   set_alias("dog");
   set_short("A hydrophobic dog");
   set_long("A hydrophobic stray dog, it's skeletal but you understand it's got the \n"+
            "enormous strenght and anger that hydrophobia causes in its victims.\n");
   set_level(6);
   set_hp(90);
   set_al(200);
   set_wc(10);
   set_ac(5);
   set_aggressive(1);
   set_chat_chance (10);
   load_chat("The dog growls at you.\n");
   skin=clone_object("/players/trix/castle/quest/monst/dogskin");
   move_object(skin,this_object());
}
