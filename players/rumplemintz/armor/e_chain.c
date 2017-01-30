inherit "/obj/armor.c";

void reset(status arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("chain mail");
  set_alias("chainmail");
  set_short("Elven chain mail");
  set_long("\
    The construction of elven chain is the most closely guarded secret of \n\
    the elven race. The few who hold its secret will die before ever \n\
    revealing it to the wrong eyes. What is known is that the armor is made \n\
    of mithril alloyed with several unknown metals.\n\
    \n");
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc */
  set_ac(5);
  set_weight(1);
  set_value(5000);
}
