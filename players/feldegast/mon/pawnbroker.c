inherit "obj/monster";

void reset(int arg) {
  ::reset(arg);
  set_name("pawnbroker");
  set_alias("shopkeeper");
  set_short("Pawnbroker");
  set_long(
"The pawnbroker is a fat potbellied man in a floral shirt.  He chews\n\
upon a fat stinky cigar as though his life depended upon it and he\n\
twitches violently whenever he hears a loud noise out on the street.\n"
  );
  set_level(12);
  set_wc(16);
  set_ac(9);
  set_hp(120);
  set_al(300);
  add_money(400+random(400));
  set_gender("male");
  set_race("human");
}
