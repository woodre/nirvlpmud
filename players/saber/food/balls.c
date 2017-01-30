inherit "obj/food";

reset(arg) {
 if(!arg)  {
   set_name("balls");
   set_short("The balls of somebody");
   set_value(0);
   set_strength(0);
   set_eater_mess("You stuff the balls into your mouth and eat them...yummm.\n");
   set_eating_mess(" stuffs the bloody balls into "+this_player()->query_possessive()+" mouth and eats them.\n");
   set_weight(0);
  }
}
