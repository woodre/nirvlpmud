/*
  adherer.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
  if (arg) return 0;
  ::reset();

  set_name("adherer");
  set_level(18);
  set_alias("nooneelseadherer");
  set_race("adherer");
  set_hp(200);
  set_al(-395);
  set_short("An adherer");
  set_long(
    "A 6' tall humanoid that looks like it is wrapped in sticky bandages.\n");
  set_wc(17);
  set_ac(4);
  set_aggressive(0);
  obj=clone_object("obj/money");
  obj->set_money(660);
  move_object(obj, this_object());
}

heart_beat() {
  object stuck_weapon;

  ::heart_beat();

  if (query_attack() && random(100) <= 10) {
    /* Find out if the attacker has a wielded weapon */
    stuck_weapon=0;
    stuck_weapon=query_attack()->query_weapon();
    if (stuck_weapon==query_attack()) stuck_weapon=0;
    if (stuck_weapon->get()) stuck_weapon=0; /* Prevents stealing guild objects - Feldegast 7/11/00 */
    if (stuck_weapon) {
      tell_room(environment(this_object()),
                query_attack()->query_name()+"'s "+stuck_weapon->short()+
                " sticks to the creature\n"+
                "and is ripped out of "+query_attack()->query_possessive()+
                " hand!\n");
      stuck_weapon->unwield_weapon();
      move_object(stuck_weapon, this_object());
    }
  }
}
