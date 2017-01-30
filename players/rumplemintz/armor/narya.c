inherit "/obj/armor.c";

void reset(status arg) {
  if(arg)
    return;
  ::reset(arg);
  set_name("narya");
  set_alias("ring");
  set_short("Narya, the Ring of Fire");
  set_long("\
    In the Third Age, Cirdan, recognizing Gandalf's true nature as one of \n\
    the Maiar from Valinor, gave him the ring to aid him in his labours. It \n\
    is described as having the power to inspire others to resist tyranny, \n\
    domination, and despair, as well as giving resistance to the weariness \n\
    of time. \n\
    \n");
  set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc */
  set_ac(2);
  set_weight(1);
  set_value(5000);
}
