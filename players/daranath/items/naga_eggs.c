inherit "obj/food";

reset(arg) {
 if(!arg)  {
   set_name("eggs");
   set_alias("egg");
   set_short("A clutch of eggs");
   set_value(120);
   set_strength(10);
   set_eater_mess("You greedily stuff the eggs into your mouth.\n"+
        "Bleh!\nThose were really awful...\n");
   set_eating_mess(" stuffs a clutch of eggs greedily into "+this_player()->query_possessive()+" mouth...\n"+
        "Ick...\n");
   set_weight(1);
  }
}
