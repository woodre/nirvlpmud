inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("imp");
   set_alias("imp");
set_short("Impassioned");
set_long("This chick seems to be enamored by every male, female,\n"+
"or neutered creature that comes in. Do the world a favor and get\n"+
"rid of her.\n");
   set_level(3);
   set_hp(45);
   set_al(100);
   set_wc(7);
   set_ac(4);
   gold=clone_object("obj/money");
   gold->set_money(100);
   move_object(gold,this_object());
}
