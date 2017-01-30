 inherit "obj/monster";
  reset(arg)
 {
object gold;
   ::reset(arg);
   if(arg) return;
 set_name("skeleton");
 set_short("A Skeleton");
 set_long("A musty pile of bones who appears ready for a fight.\n");
 set_level(9);
  set_aggressive(1);
  set_hp(130);
 set_al(-1000);
 set_wc(13);
 set_ac(7);
   gold=clone_object("obj/money");
   gold->set_money(random(76)+325);
   move_object(gold,this_object());
 }
