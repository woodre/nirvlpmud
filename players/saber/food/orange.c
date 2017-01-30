inherit "obj/food";

reset(arg) {
 if(!arg)  {
   set_name("orange");
   set_alias("fruit");
   set_short("An orange");
   set_long("A tasty looking orange.\n");
   set_value(30);
   set_strength(5);
   set_eater_mess("You eat the orange.  Yummm.\n");
   set_eating_mess(" eats an orange.\n");
   set_weight(1);
  }
}
