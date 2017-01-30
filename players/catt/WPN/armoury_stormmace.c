inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("storm mace");
  set_alt_name("storm");
  set_alias("mace");
  set_short("Storm Mace");
  set_long("This powerful weapon is enchanted with great powers.\n"+
           "It has a thick shaft and massive crown, made of a\n"+
           "metal unknown to you. It is a red tinted black in color\n"+
           "and has a very unnatural feel to it.\n");
  set_value(6000);
  set_weight(2);
  set_class(17);
  set_hit_func(this_object());
}
/* changed 7/23 by wizardchild. the current setup of this object
   allows a player with 30 hps (like a newbie) to kill any monster
   in one round. It also lets a player kill any monster in one round. This
   *really* isn't a good idea, so please recode it using a method
   that maintains the theme
*/
weapon_hit(atk) { return 0; }
/*
weapon_hit(attacker) {
  object owner;
  int ototal;
  int total;
  if(attacker->query_npc() == 1) {
    if(random(100) < 60) {
  write("Arcane power BLASTS "+attacker->query_name()+" to ash!\n");
    say(attacker->query_name()+"'s body is turned to ash by storm mace!\n");
  total = attacker->query_hp();
  write("total hit points lost: "+total+"\n");
  call_other(attacker, "heal_self", -total);
  ototal = this_player()->query_hp();
  call_other(this_player(), "heal_self", -ototal+30);

  write("You feel weakened by the power of the mace.\n");
  say(owner+" slumps forward from the power drain.\n");
  return 1;
  }}
  return 0;
  }
*/
