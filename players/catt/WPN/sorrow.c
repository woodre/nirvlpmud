inherit"obj/weapon";
reset(arg) {
  ::reset(arg);
  set_name("sorrow");
  set_alias("sword");
  set_short("Sorrow");
  set_long(
        "The great sword of the Storm King. The blade is grey and\n"+
        "holds a great but sorrowful power. It is a named weapon\n"+
        "and therefore holds great power.\n");
  set_value(6000);
  set_weight(3);

  set_class(17);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  if(random(100) < 30) {
  write("Sadness fills the air as sorrow remembers a long lost time.\n"+
    "You smash "+attacker->query_name()+" with a bone crushing sound.\n");
  say("Sadness fills the air as sorrow remembers a long lost time.\n"+
  attacker->query_name()+" is smashed by a bone crushing sound.\n");
  return 3;
}
return 0;
}
