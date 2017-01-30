inherit "obj/armor";

reset(arg) {
set_name("Leather Apron");
set_alias("apron");
set_short("A leather apron");
set_long(
  "A mid-calf length leather apron used by blacksmiths to protect\n"+
  "them from the intense heat of the forge.  It covers almost the\n"+
  "entire front of the body and ties in the back. \n");

set_ac(1);
set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(500);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}