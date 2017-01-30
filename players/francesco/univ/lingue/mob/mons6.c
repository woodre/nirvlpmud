inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("termite");
   set_alias("termite");
   set_short("The termite of the library");
   set_long("A little termite, that jumping around the shelves of the library has\n"+
            "learned at least as much as you did.  Side, it must be as skilled\n"+
            "as you are also as far as the ability in fights is concerned.\n");
   set_level(6);
   set_hp(90);
   set_al(0);
   set_wc(10);
   set_ac(5);
 gold = clone_object("obj/money");
 gold->set_money(random(70)+220);
 move_object(gold,this_object());

}
