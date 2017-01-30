inherit "obj/armor";

reset(arg) {
  set_name("shield");
  set_alias("steel shield");
  set_short("A steel shield");
  set_long(
    "A round steel shield approximately a foot and a half in diameter.\n"
  );
  set_ac(1);
  set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(200);
}
do_special(owner)
{
  if(!random(12))
  {
    tell_object(owner, "You manage to partially deflect the blow with your shield.\n");
    return 1;
  }
}
