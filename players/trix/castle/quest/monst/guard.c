inherit "obj/monster";
reset(arg){
   object gold,spear;
   ::reset(arg);
   if(arg) return;
   set_name("guard");
   set_race("human");
   set_alias("trixguard");
   set_short("A guard");
   set_long("A guard soldier, his face has no age, and looking at his clothes you\n"+
            "see he must have been here for ages.\n");
   set_level(19);
   set_hp(475);
   set_al(300);
   set_wc(28);
   set_ac(16 );
   set_aggressive(0);
   set_chat_chance (1);
   load_chat("The Guard looks at you.\n");
   set_a_chat_chance(15);
   load_a_chat("The Guard pushes you against the wall.\n");
   load_a_chat("The Guard says: I'd die rather than neglect my duty.\n");
   gold=clone_object("obj/money");
   gold->set_money(1975+random(26));
   move_object(gold,this_object());
   spear=clone_object("/players/trix/castle/quest/monst/spear");
   move_object(spear,this_object());
}
