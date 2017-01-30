/* Changed from lev.20 to 16, hp500 to 420, wc30 to 20, ac17 to 10, 
   coins from 4950 to 1200, and added spell stuff. -Snow */
inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("keeper");
   set_race("human");
   set_alias("drugstore keeper");
   set_short("The drugstore keeper");
   set_long("A fat man wearing a greasy suit.  There's something greedy and dirty\nin his eyes.\n");
   set_level(16);
   set_hp(420);
   set_al(300);
   set_wc(20);
   set_ac(10);
   set_aggressive(0);
   set_chance(30);
   set_spell_mess2("The keeper hammers you with a meaty fist!\n");
   set_spell_dam(25);
   set_chat_chance (5);
   load_chat("The keeper licks his lips.\n");
   load_chat("The keeper counts some dollar bills.\n");
   set_a_chat_chance(15);
   load_a_chat("The keeper says: Fuck off, damn thief!!!\n");
   load_a_chat("The keeper kicks your butt!\n");
   gold=clone_object("obj/money");
   gold->set_money(1200+random(51));
   move_object(gold,this_object());
}
