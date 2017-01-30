/* Changed from lev.20 to 15, hp500 to 300, wc30 to 20, ac 17 to 14,
   and coins from 3950 to 700 (stats and money both bit higher than lev.15)
   -Snow */
inherit "obj/monster";
reset(arg){
   object diamond,gold;
   ::reset(arg);
   if(arg) return;
   set_name("jeweller");
   set_race("human");
   set_alias("jeweller");
   set_short("The jeweller");
   set_long("An elegant and rich man wearing a golden monocle and with a big\n"+
            "diamond in his hands.\n");
   set_level(15);
   set_hp(300);
   set_al(300);
   set_wc(20);
   set_ac(14);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("The jeweller looks at you through his monocle.\n");
   load_chat("The jeweller says: Would you like to see some stones, sir?\n");
   set_a_chat_chance(25);
   load_a_chat("The jeweller says: Well, I don't think this is a good way to deal!\n");
   load_a_chat("The jeweller smashes you with a bone crashing sound.\n");
   diamond=clone_object("/players/trix/castle/town/monst/diamond");
   move_object(diamond,this_object());
   gold=clone_object("obj/money");
   gold->set_money(700+random(51));
   move_object(gold,this_object());
}
