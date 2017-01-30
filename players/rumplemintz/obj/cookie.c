#pragma strong_types

inherit "/obj/food";

void reset(status arg) {
  ::reset(arg);
  set_name("peanut butter cookie");
  set_alias("cookie");
  set_short("Peanut butter cookie");
  set_long("A peanut butter cookie from the oven of Rumplemintz.\n");
  set_value(10);
  set_weight(1);
  set_strength(2);
  set_eater_mess("You eat the peanut butter cookie.\n");
  set_eating_mess(this_player()->query_name()+
                  " eats a peanut butter cookie.\n");
}
