
inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("brown cloak");
  set_alias("cloak");
  set_short("An elegant brown cloak");
  set_long(
"This is a very finely woven brown cloak.  It is quite a few feet long,\n"+
"reaching from your shoulders almost all the way down to the ground.  It\n"+
"flows like water as the breeze blows through it.\n");
  set_value(450);
  set_weight(1);
  set_ac(1);
  set_type("misc");
  set_save_flag(1);
}

