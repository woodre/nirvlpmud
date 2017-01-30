 inherit "obj/monster";
  reset(arg)
 {
 object gold;
   ::reset(arg);
   if(arg) return;
 set_name("guard");
 set_short("Ghost Guard");
 set_long("A spectral guard, he looks through you with haunted eyes.\n");
 set_level(8);
  set_hp(120);
 set_al(-750);
 set_wc(12);
 set_ac(7);
   gold=clone_object("obj/money");
   gold->set_money(random(51)+300);
   move_object(gold,this_object());
 }
