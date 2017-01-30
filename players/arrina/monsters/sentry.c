 inherit "obj/monster";
  reset(arg)
 {
object gold;
   ::reset(arg);
   if(arg) return;
 set_name("sentry");
 set_short("A Sentry");
 set_long("A smallish sentry, keeping watchful eyes on you.\n");
 set_level(6);
  set_hp(90);
 set_al(-750);
 set_wc(10);
 set_ac(5);
   gold=clone_object("obj/money");
   gold->set_money(random(76)+175);
   move_object(gold,this_object());
 }
