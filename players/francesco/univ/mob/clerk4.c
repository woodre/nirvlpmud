inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("katya");
   set_race("human");
   set_alias("clerk");
      set_short("Katya, a clerk");
     set_long("This clerk is here to aid the students in the preparation of their\n"+
              "study plans.  She is of short frame figure,  well modelled body,\n"+
              "about 5'2\" tall, with short brown hair, hazel eyes and pale skin.\n"+
              "Rumors say she learned karate.  She has a temper. \n");

   set_level(15);
   set_hp(250);
   set_al(-20);
   set_wc(23);
   set_ac(13);
 gold = clone_object("obj/money");
 gold->set_money(960+random(150));
 move_object(gold,this_object());
}
