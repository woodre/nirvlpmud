inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("bone");
  set_alias("dog bone");
  set_alt_name("bones");
  set_weight(1);
  set_value(25);
  set_strength(5);
  set_short("A dog bone");
  set_long("A crunchy dog bone. It tastes like liver, YUMMMM!!!!!!\n");
  set_eater_mess("You eat the bone. It tastes excellent.\n");
  set_eating_mess(" eats a dog bone.\n");
}

