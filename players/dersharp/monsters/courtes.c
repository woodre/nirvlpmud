inherit "obj/monster";
reset(arg) {
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("courtesan");
   set_race("human");
   set_alias("courtesan");
   set_short("A beautiful courtesan");
   set_long("Her beauty radiates from her as an aura.  She looks at you with\n"+
            "green eyes and a warm smile.  However when you try to compare \n"+
            "her with one of the others you find she is exactly alike! \n");
   set_level(8);
   set_hp(120);
   set_al(100);
   set_wc(12);
   set_ac(7);
   set_chat_chance(2);
   load_chat("Courtesan says: I hope Lord Markham doesn't find you here.\n");
   load_chat("Courtesan lays back in one of the chairs and relaxes\n");
   gold=clone_object("obj/money");
   gold->set_money(100);
   move_object(gold,this_object());
   armor=clone_object("/players/dersharp/armors/veil");
   move_object(armor,this_object());
}
