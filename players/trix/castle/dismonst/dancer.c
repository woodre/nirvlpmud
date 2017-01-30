inherit "obj/monster";
reset(arg){
   object gold,suit;
   ::reset(arg);
   if(arg) return;
   set_name("dancer");
   set_race("human");
   set_alias("girl");
   set_short("A professional dancer");
   set_long("A professional dancer, she's a black gorgeous young woman dressed with a tight\n"+
            "black shining jumpsuit that reveales her curves and leaves her legs naked.\n");
   set_level(17);
   set_hp(425);
   set_al(0);
   set_wc(24);
   set_ac(14);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("The dancer girl dances her ass off.\n");
   load_chat("The dancer girl shakes her body with voluptuous moves.\n");
   load_chat("The dancer girl stops for a moment, grins at you and starts dancing again.\n");
   gold=clone_object("obj/money");
   gold->set_money(900 + random(50));
   move_object(gold,this_object());
   suit=clone_object("/players/trix/castle/dismonst/jumpsuit");
   move_object(suit,this_object());
}
