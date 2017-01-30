inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("taffy");
   set_race("human");
   set_alias("clerk");
      set_short("Taffy, a clerk");
     set_long("This clerk is here to aid the students in the preparation of their\n"+
              "study plans.  She is very nice both in her behaviour and in her\n"+
              "physical aspect:  short frame figure,  well modelled body,  about\n"+
              "5'1\" tall.\n");

   set_level(9);
   set_hp(150);
   set_al(100);
   set_wc(14);
   set_ac(7);
 gold = clone_object("obj/money");
 gold->set_money(360+random(150));
 move_object(gold,this_object());
}
