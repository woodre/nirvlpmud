inherit "/obj/armor.c";

void reset(status arg) {
  if(arg)
    return;
  ::reset(arg);
  set_name("nenya");
  set_alias("ring");
  set_short("Nenya, the Ring of Adamant");
  set_long("\
    This ring is wielded by Galadrial of Lothlorien, and possesses radiance \n\
    that matches the stars. Nenya's power was preservation, protection, and \n\
    possibly concealment from evil. Galadriel used these powers to create \n\
    and sustain Lothlorien, but it also increased in her the longing for the \n\
    Sea and her desire to return to the Undying Lands. \n\
    \n");
  set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc */
  set_ac(2);
  set_weight(1);
  set_value(5000);
}
