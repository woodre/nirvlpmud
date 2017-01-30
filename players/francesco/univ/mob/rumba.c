inherit "obj/monster";
   object gold;
   object acid;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("rumba");
   set_race("human");
   set_alias("technician");
      set_short("Rumba, the chemical technician");
     set_long("After working for several years in a chemical plant, Rumba\n"+
              "was hired by this University.  His skill is very well known\n"+
              "and all faculties appreciate his activity very much.  Of course,\n"+
              "he must be very careful with his job and with the items he\n"+
              "handles:  that is why he looks at you with a suspicious \n"+
              "expression.  You better not mess with him, since he looks\n"+
              "like very jealous of his items and he looks like he has the\n"+
              "power to keep you away from them.\n");

   set_level(19);
   set_hp(475);
   set_al(-300);
   set_wc(28);
   set_ac(16);
 acid = clone_object("/players/francesco/univ/items/acid.c");
 move_object(acid,this_object());
 gold = clone_object("obj/money");
 gold->set_money(2000+random(2000));
 move_object(gold,this_object());
   set_chance(20);
   set_spell_dam(20);
   set_spell_mess2("Rumba slaps you hard!");
   set_spell_mess1("Rumba slaps you hard!");
}
