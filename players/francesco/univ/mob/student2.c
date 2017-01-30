inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("student");
   set_race("human");
   set_alias("student");
      set_short("A student");
     set_long("This is a senior student.  He is very happy about his studies\n"+
               "and very tired from the efforts he needed to pursue his degree.\n"+ 
               "He should graduate very soon.\n");
   set_level(11);
   set_hp(165);
   set_al(100);
   set_wc(15);
   set_ac(9);
 gold = clone_object("obj/money");
 gold->set_money(425+random(150));
 move_object(gold,this_object());
}
