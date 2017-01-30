inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("teddy bear");
  set_alias("bear");
  set_alt_name("teddy");
  set_weight(1);
  set_value(150);
  set_strength(50);
  set_short("A chocolate teddy bear");
  set_long("A cuddly teddy bear made of chocolate. You just can't wait to eat it.\n");
  set_eater_mess("You eat the teddy, and it makes you smile.\n");
  set_eating_mess(" eats a teddy bear.\n");
}

