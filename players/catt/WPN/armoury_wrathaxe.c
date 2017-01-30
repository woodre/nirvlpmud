inherit"obj/weapon";
reset(arg) {
  ::reset(arg);
  set_name("wrath axe");
  set_alias("axe");
  set_short("Wrath Axe");
  set_long(
   "A great battle axe that is just barely powerful enough to\n"+
   "be named, the wrath axe, because of its good killing ability.\n");
  set_value(1500);
  set_weight(2);
  set_class(14);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  if(random(100) < 15) {
   write("Wrath cleaves into "+attacker->query_name()+" viciously\n");
  say("Wrath cleaves into "+attacker->query_name()+" viciously\n");
 return 0;
}
return 0;
}
