inherit "obj/food";

reset(arg) {
 if(!arg)  {
   set_name("tits");
   set_short("The tits of somebody");
   set_value(0);
   set_strength(0);
   set_eater_mess("You stuff the tits into your mouth and eat them...yummm.\n");
   set_eating_mess(" stuffs the bloody tits into "+this_player()->query_possessive()+" mouth and eats them.\n");
   set_weight(0);
  }
}
