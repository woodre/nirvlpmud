inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("pp");
   set_race("human");
   set_alias("pp");
    set_short("pp");
     set_long("This is a freshman student, or maybe he is still on\n"+
               "deciding if to enroll or not. He is probably worried\n"+
               "about Calculus I.\n");
   set_level(20);
   set_hp(10000);
   set_al(100);
   set_wc(15);
   set_ac(30);
 gold = clone_object("obj/money");
 gold->set_money(1);
 move_object(gold,this_object());
}
