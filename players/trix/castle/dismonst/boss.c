inherit "obj/monster";
reset(arg){
   object gold,cigar,suit;
   ::reset(arg);
   if(arg) return;
   set_name("boss");
   set_race("human");
   set_alias("owner");
   set_short("The boss");
   set_long("This is the owner of the EclYpsE, a fat man in a white large suit with white\n"+
            "shirt, necktie and shoes. He smokes a stinky cuban cigar.\n");
   set_level(19);
   set_hp(475);
   set_al(-300);
   set_wc(28);
   set_ac(16);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("The boss looks around you with satisfaction, thinking all this is his.\n");
   load_chat("The boss smokes his cigar.\n");
   load_chat("The explores his nose.\n");
   set_a_chat_chance(20);
   load_a_chat("The boss hits you with his belly.\n");
   load_a_chat("The boss yells: You asshole, get outta my disco!\n");
   gold=clone_object("obj/money");
   gold->set_money(950+random(61));
   move_object(gold,this_object());
   cigar=clone_object("/players/trix/castle/dismonst/cigar");
   move_object(cigar,this_object());
   suit=clone_object("/players/trix/castle/dismonst/suit");
   move_object(suit,this_object());
   call_out("muovi",1);
}
muovi()
{ call_other(this_object(),"random_move");
  call_out("muovi",16);
  return 1;
}
