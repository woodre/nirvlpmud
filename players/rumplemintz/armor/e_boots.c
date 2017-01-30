inherit "/obj/armor.c";

void reset(status arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("boots of elvenkind");
  set_alias("boots");
  set_short("Boots of Elvenkind");
  set_long("\
    These boots are designed to let the wearer walk silently in even the \n\
    most adverse of conditions. Someone wearing Boots of Elvenkind could \n\
    walk over broken glass and bubble wrap without making a sound. These \n\
    boots are made of soft leather. \n\
    \n");
  set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc */
  set_ac(2);
  set_weight(1);
  set_value(5000);
}
