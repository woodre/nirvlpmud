inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("john");
   set_race("human");
   set_alias("technician");
      set_short("John, the mechanical test technician");
     set_long("This technician is older than the others you met in the other\n"+
              "laboratories of the department.  He must have been promoted to\n"+
              "this position beacuse of his care and precision in performing\n"+
              "the tests.  He is very reliable and doesnt speak much.\n");

   set_level(15);
   set_hp(240);
   set_al(-20);
   set_wc(20);
   set_ac(11);
   set_chance(20);
   set_spell_mess2("John tells you:  Arghh!  I told you that we need precision in our work.");
   set_spell_mess1("John says:  Arghh!  I already said that we need precision in our work.");
   set_spell_dam(12);
 gold = clone_object("obj/money");
 gold->set_money(970+random(120));
 move_object(gold,this_object());
}
