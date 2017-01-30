inherit "obj/food";
 
reset(arg) {
  if(arg) return;
  set_name("strawberry");
  set_alias("berry");
  set_weight(1);
  set_value(25);
  set_strength(20);
  set_short("A magical strawberry");
  set_long("A sweet tender juicy strawberry...\n");
  set_eater_mess("You indulge in the juicy strawberry.\n");
  set_eating_mess(" eats a magical strawberry.\n");
}
