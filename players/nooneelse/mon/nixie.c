/*
 nixie.c
*/

inherit "players/nooneelse/mon/nooneelse_monster";

object coins;

reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  if (arg) return;
  ::reset(arg);

  set_name("nixie");
  set_level(7);
  set_hp(60);
  set_wc(5);
  set_ac(5);
  set_al(120);
  set_ep(31500);
  set_short("A nixie");
  set_long("A 4' tall green haired humanoid with pointed ears and "+
           "webs between his fingers.\n");
  set_aggressive(0);
  set_whimpy(1);
  coins=clone_object("obj/money");
  coins->set_money(180);
  move_object(coins, this_object());
}


run_away() {
  say("The nixie screams in agony, dives into the water and disappears.\n");
  call_other("players/nooneelse/green/groad35", "???", 0);
  move_object(this_object(), "players/nooneelse/green/groad35");
  this_object()->heal_self(15);
  this_object()->set_whimpy(0);
  if (present("nymph")) present("nymph")->attack_object(attacker_ob);
  return 1;
}
