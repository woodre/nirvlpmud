inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_id("snake helm");
  set_alias("helm");
  set_short("Snake Helm");
  set_long(
"A large dark helm shaped like a snakes head.  A set of eyes gleams \n"+
"from atop the head.  There is a pair of small and sharp fangs just \n"+
"at the tip of the helms opening.\n"
  );
  set_ac(30);
  set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
}

