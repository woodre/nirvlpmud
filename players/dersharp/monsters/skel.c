inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("skeleton");
   set_alias("bones");
   set_short("A skeleton");
   set_long("The mangled remains of a fighter long since dead and turned \n"+
            "to the evil side by the Shadow Master.\n");
   set_level(2);
   set_wc(6);
   set_ac(3);
   set_hp(30);
   set_al(-20);
   gold=clone_object("obj/money");
   gold->set_money(60);
   move_object(gold,this_object());
}
