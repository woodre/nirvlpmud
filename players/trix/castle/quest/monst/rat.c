inherit "obj/monster";
reset(arg){
   object skin;
   ::reset(arg);
   if(arg) return;
   set_name("rat");
   set_race("rat");
   set_alias("rat");
   set_short("A mutant sewer rat");
   set_long("A mutant sewer rat, product of the chronic pollution Trixtown's sewer is \n"+
            "affected by. It looks more like a big dog rather than a mouse.\n");
   set_level(4);
   set_hp(60);
   set_al(200);
   set_wc(8);
   set_ac(4);
   set_aggressive(1);
   set_chat_chance (10);
   load_chat("The rats sniffs you.\n");
   skin=clone_object("/players/trix/castle/quest/monst/skin");
   move_object(skin,this_object());
}
