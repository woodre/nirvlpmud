inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("guard");
   set_race("human");
   set_alias("guard");
      set_short("A guard");
     set_long("The guard is usually willing to help students to maintain\n"+
              "a polite and sound behaviour within the university.\n"+
              "To do this, sometimes he needs to be rude menacing, but\n"+
              "you do know that he is a nice individual.  His uniform\n"+
              "is black, with a pin with the symbol of the University.\n");

   set_level(10);
   set_hp(150);
   set_al(100);
   set_wc(14);
   set_ac(8);
 gold = clone_object("obj/money");
 gold->set_money(380+random(150));
 move_object(gold,this_object());
}
