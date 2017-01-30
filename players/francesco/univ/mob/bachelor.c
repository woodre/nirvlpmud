inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("student");
   set_race("human");
   set_alias("student");
      set_short("An undergraduate student");
     set_long("This is likely a freshman student, very worried about his upcoming finals.\n"+
              "From his long hair, from his tired eyes and from his cheap low decore\n"+
              "outfit you can understand that he didnt sleep much in the last days.\n");

   set_level(14);
   set_hp(210);
   set_al(0);
   set_wc(18);
   set_ac(11);
   set_chance(25);
   set_spell_mess2("The student says:  Go away!!!   Lemme concentrate on studying");
   set_spell_mess1("The student says:  Go away!!!   Lemme concentrate on studying");
   set_spell_dam(20);
 gold = clone_object("obj/money");
 gold->set_money(random(160)+1150);
 move_object(gold,this_object());
}
