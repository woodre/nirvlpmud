inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("student");
   set_race("human");
   set_alias("student");
      set_short("A student");
     set_long("This is a freshman student.  He looks very worried about his\n"+
              "upcoming finals.  Maybe that his main concern is Calculus I.\n");
   set_level(10);
   set_hp(150);
   set_al(200);
   set_wc(14);
   set_ac(8);
 gold = clone_object("obj/money");
 gold->set_money(380 +random(100));
 move_object(gold,this_object());
}
