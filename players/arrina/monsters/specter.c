  inherit "obj/monster";
   reset(arg)
  {
 object gold;
    ::reset(arg);
    if(arg) return;
 set_name("specter");
 set_short("A Specter");
 set_long("A disembodied spirit.  He seems to look through you.\n");
 set_level(8);
  set_hp(120);
 set_al(-900);
 set_wc(12);
 set_ac(7);
   gold=clone_object("obj/money");
   gold->set_money(random(76)+275);
   move_object(gold,this_object());
  }
