inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("tobias");
   set_race("human");
   set_alias("technician");
      set_short("Tobias, the audiovisual technician");
     set_long("This technician have been working for years in this dark room\n"+
              "and therefore his eyes seem very skillful at seeing in the dark.\n"+
              "He seems to be aggressive and slightly temperamental guy because\n"+
              "he wishes to see the sunlight at sometime.\n");

   set_aggressive(1);
   set_level(18);
   set_hp(450);
   set_al(-100);
   set_wc(30);
   set_ac(13);
 gold = clone_object("obj/money");
 gold->set_money(3000+random(500));
 move_object(gold,this_object());
   set_spell_dam(20);
   set_chance(22);
   set_spell_mess2("Tobias kicks you hard!");
   set_spell_mess1("Tobias kicks you hard!");

}
