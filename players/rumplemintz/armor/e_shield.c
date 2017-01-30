inherit "/obj/armor.c";

void reset(status arg) {
  if(arg)
    return;
  ::reset(arg);
  set_name("high elven warrir shield");
  set_alias("shield");
  set_short("High Elven Warrior Shield");
  set_long("\
    The High Elven Warrior Shield is a reflection of the stately army of \n\
    Elves that fought agains Sauron and his forces, and was designed \n\
    around a leaf motif, adorned with an elven vine design to reflect the \n\
    organic nature-based culture of the Elves. \n\
    \n");
  set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc */
  set_ac(2);
  set_weight(1);
  set_value(5000);
}
