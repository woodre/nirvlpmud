inherit "obj/food";
reset(arg) {
if(arg) return;
  set_name("loaf of bread");
  set_alias("bread");
  set_short("A large loaf of bread");
  set_long("This is a large loaf of bread. It was created by a knight.\n");
  set_value(0);
  set_weight(0);
  set_eating_mess(" eats a large loaf of bread.\n");
  set_eater_mess("You eat the loaf of bread and feel healed.\n");
}

