inherit "/obj/armor.c";

void reset(status arg) {
  if(arg)
    return;
  ::reset(arg);
  set_name("helm of vital protection");
  set_alias("helm");
  set_short("Helm of Vital Protection");
  set_long("\
    A beautifully constructed helm made with what appears like a mithril \n\
    alloy. The helm is very light, yet will supply superior protection from \n\
    even the most savage of head blows.\n\
    \n");
  set_type("helm");  /* armor,helmet,boots,ring,amulet,shield,misc */
  set_ac(2);
  set_weight(1);
  set_value(5000);
}
