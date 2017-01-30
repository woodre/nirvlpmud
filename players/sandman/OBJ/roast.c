inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("roast");
  set_alias("human roast");
  set_alt_name("roast of human");
  set_weight(1);
  set_value(50);
  set_strength(15);
  set_short("A Human Roast");
  set_long("A side of Roast Human. It looks to be Medium Rare.\n");
  set_eater_mess("You dig into the roast of human. I it does taste like chicken!\n");
  set_eating_mess(" is a canibal, and eats the roast of human!\n");
}

