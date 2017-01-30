/*
 alchemist.c
*/

inherit "obj/monster";

object coins;

reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  if (arg) return;
  ::reset(arg);

  set_name("alchemist");
  set_alias("Justin");
  set_alt_name("nooneelsealchemist");
  set_level(12);
  set_hp(325);
  set_ep(350000);
  set_al(-400);
  set_wc(19);
  set_ac(4);
  set_short("An alchemist");
  set_long("An old man wearing a heavy apron with strange stains on it.\n");
  set_whimpy(1);
  set_aggressive(0);
  set_spell_dam(25);
  set_chance(8);
  this_object()->load_chat("Justin mumbles a formula to himself.\n");
  this_object()->load_chat(
    "The alchemist glares at you and yells: GET OUT!\n");
  this_object()->load_chat(
    "The old man screeches:  Try to steal my formulas will you?\n");
  this_object()->set_chat_chance(40);
  coins=clone_object("obj/money");
  coins->set_money(250);
  move_object(coins, this_object());
  move_object(clone_object("players/nooneelse/obj/alchemist_ring"),
              this_object());
  move_object(clone_object("players/nooneelse/obj/vial"), this_object());
}

weapon_hit(attacker) {
  if (call_other(this_player(), "query_name") == "Alchemist" && !random(5)) {
    tell_room(environment(attacker),
              "Justin picks you up and tosses you through the door.\n");
    call_other(attacker, "run_away", 1);
    return 0;
  }
}
