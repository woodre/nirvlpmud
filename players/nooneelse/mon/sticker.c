/*
 sticker.c
*/

inherit "obj/monster";

object sticker, coins, items, stuck_weapon;

int found_one_to_stick, its_wielded, weight;

string str, str2, stuck_weapon_name;

reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  ::reset(arg);
  if (arg) return;

  set_name("sticker");
  set_alias("adherer");
  set_alt_name("nooneelsesticker");
  set_level(18);
  set_hp(220);
  set_wc(17);
  set_ac(13);
  set_ep(115500);
  set_al(-395);
  set_short("A sticker");
  set_long(
    "A 6' tall humanoid that looks like it is wrapped in sticky bandages.\n");
  set_whimpy(0);
  set_aggressive(0);
  coins=clone_object("obj/money");
  coins->set_money(660);
  move_object(coins, this_object());
}

heart_beat() {
  ::heart_beat();

  if (random(100) > 10) return;

/* Find out if the attacker has a wielded weapon */
  stuck_weapon=0;
  stuck_weapon=query_attack()->query_weapon();
  if (!stuck_weapon) return;
  stuck_weapon_name=stuck_weapon->query_name();
  tell_room(environment(this_object()),
      query_attack()->query_name()+"'s "+stuck_weapon_name+
      " sticks to the creature and is ripped out of "+
      query_attack()->query_possessive()+" hand!\n");
  weight=stuck_weapon->query_weight();
  if (!weight) { weight=0; }
  query_attack()->add_weight(-weight);
  move_object(stuck_weapon, this_object());
  return;
}
