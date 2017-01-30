inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("kobold");
   set_alias("kobold");
   set_short("A small humanoid");
   set_long("Upon closer observation you recognize this thing as being a kobold.\n"+
            "These cruel creatures work for the Shadow Master.\n");
   set_level(2);
   set_hp(30);
   set_ac(3);
   set_wc(6);
   set_al(-30);
   set_chat_chance(2);
   load_chat("Kobold looks at you with hate in its eyes.\n");
   gold=clone_object("obj/money");
   gold->set_money(60);
   move_object(gold,this_object());
}
