inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("acorn");
  set_alias("black acorn");
  set_alt_name("acorns");
  set_weight(2);
  set_value(150);
  set_strength(20);
  set_short("A black acorn");
  set_long("A black musty acorn. It looks barely eatable.\n");
  set_eater_mess("You eat the acorn. You black out for a moment.\n");
  set_eating_mess(" eats an acorn.\n");
}

