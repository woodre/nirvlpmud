inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("whip");
  set_alias("tails");
  set_short("Cat o'nine tails");
  set_long("The cat o'nine tails is a whip made of nine knotted cords attached\n"+
            "to a handle.\n");
  set_class(15);
  set_weight(2);
  set_value(400);
  set_type("club");
}
