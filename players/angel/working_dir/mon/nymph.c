/*
 nymph.c
*/

inherit "players/angel/working_dir/mon/nooneelse_monster";

object coins;

reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  if (arg) return;
  ::reset(arg);

  set_name("nymph");
  set_level(13);
  set_hp(120);
  set_wc(8);
  set_ac(10);
  set_al(230);
  set_ep(63000);
  set_short("A nymph");
  set_long("A 5' tall beautiful humanoid female.\n");
  set_aggressive(0);
  set_whimpy(1);
  coins=clone_object("obj/money");
  coins->set_money(360);
  move_object(coins, this_object());
}


run_away() {
  say("The nymph screams in agony, dives into the water and disappears.\n");
  call_other("players/nooneelse/green/groad31", "???", 0);
  move_object(this_object(), "players/nooneelse/green/groad31");
  this_object()->heal_self(15);
  this_object()->set_whimpy(0);
  if (present("nixie")) present("nixie")->attack_object(attacker_ob);
  return 1;
}
