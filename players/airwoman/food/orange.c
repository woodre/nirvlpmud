inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("orange");
  set_alias("orange");
  set_weight(1);
  set_value(25);
  set_strength(5);
  set_short("A Clockwork Orange");
  set_long("Anthony's Burgess's A CLOCKWORK ORANGE\n"+
 "A juicy ripe orange just ready for you to eat.\n"+
 "It's healthy to eat the peel too.  So eat the whole thang...\n");
  set_eater_mess("The juice fills your mouth as you indulge in the\n"+
		"ever so sweet orange.\n");
  set_eating_mess(" indulges in a sweet tasty orange.\n");
}

