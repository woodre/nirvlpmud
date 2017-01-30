inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("peach");
  set_alias("peach");
  set_weight(1);
  set_value(25);
  set_strength(5);
  set_short("A Half Eaten Peach");
  set_long("Do you dare eat a peach?\n"+
        "Apparently Robert Frost did dare, and look what\n"+
	"happened to him.\n");
  set_eater_mess("The juice fills your mouth as you indulge in the\n"+
                "ever so ripe peach.\n");
  set_eating_mess(" indulges in a sweet tasty peach.\n");
}

