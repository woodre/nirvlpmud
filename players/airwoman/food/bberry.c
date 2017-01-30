inherit "obj/food";
 
reset(arg) {
  if(arg) return;
  set_name("blueberry");
  set_alias("berry");
  set_weight(1);
  set_value(25);
  set_strength(20);
  set_short("A magical blueberry");
  set_long("A sweet tender juicy blueberry...\n");
  set_eater_mess("You indulge in the juicy blueberry.\n");
  set_eating_mess(" eats a magical blueberry.\n");
}
