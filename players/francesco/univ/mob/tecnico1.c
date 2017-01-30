inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("mike");
   set_race("human");
   set_alias("technician");
      set_short("Mike, the mechanical technician");
     set_long("This technician works all the time with the machine tools.  He\n"+
              "is very skilled and willing to help both students and staff.\n"+
              "Yet, he is very jealous of the machines he is in charge of,\n"+
              "thus you'd rather not mess with him.\n");

   set_level(20);
   set_hp(600);
   set_al(-100);
   set_wc(33);
   set_ac(16);
   set_chance(30);
   set_spell_mess2("Mike yells:  how should i tell you not to mess with the machine tools?!?!");
   set_spell_mess1("Mike yells:  how should i tell you not to mess with the machine tools?!?!");
   set_spell_dam(50);
 gold = clone_object("obj/money");
 gold->set_money(2500+random(150));
 move_object(gold,this_object());
 set_dead_ob("/players/francesco/univ/items/laser.c");

}
init() {
  ::init();

}
