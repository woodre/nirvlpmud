/*
 * Things ripped from living.c concerning paladin code
 * -- Rumplemintz
 *
 */

static object second_weapon;
static second_wc;
static object paladin_shield;

string custom_room_death_mess;
string custom_attacker_death_mess;

void stop_offwielding() {
  if (!second_weapon) {
    log_file("offwield_bug", "Weapon not offwielded!\n");
    write("Bug! The weapon was marked as offwielded! (fixed)\n");
    return;
  }
  second_weapon->un_wield(dead);
  second_weapon = 0;
  second_wc = 0;
}

void offwield(object w) {
  if (second_weapon) stop_offwielding();
  second_weapon = w;
  second_wc = w->weapon_class();
  say(capitalize(this_player()->query_name()) +
      " offwields " + w->query_name() + ".\n");
  write("Ok.\n");
}

