/*
 * Daemon to control pregnancy instead of inheriting variables and functions
 * into player.c
 * Rumplemintz
 */

#pragma strict_types

/* Put how long to carry the baby before birth here */
#define FULL_TERM (16200 + random(500))

string *pregos;  /* Array of all prego players */

int set_pregnancy(string donor, string carrier) {
  if ((string)carrier->query_gender() != "female")
    return 0;
  if (member(carrier, pregos) > -1)
    return 0;
  if (carrier->query_phys_at(3) > 1200)
    if (random(100) > 20)
      return 0;

  if (!pregos) pregos = ({ });
  else pregos += ({ carrier });

  carrier->set_due_date((int)carrier->query_age() + FULL_TERM);

  tell_object(find_living(donor), "You have made " +
              carrier->query_name() + " pregnant.\n");
  return 1;
}

varargs int clear_pregnancy(string carrier, int silently) {
  if (member(carrier, pregos) < 0) return 0;
  pregos -= ({ carrier });
  if (!silently)
    tell_object(carrier, "You are no longer pregnant.\n");
  return 1;
}


int child_birth(object carrier, object donor) {
  object kid;

  if (!environment(carrier)) return 0;

  /* Not sure why this is here, no premies maybe? */
  if (16199 > ((int)carier->query_due_date() - (int)carrier->query_age()))
    return 0;
  if (carrier->query_ghost()) {
    carrier->set_due_date((int)carrier->query_due_date() + 300);
    return 1;
  }
  if ((string)carrier->query_gender() != "female") {
    tell_object(carrier, "You feel a great deal of pain...\n");
    tell_room(environment(carrier),
              carrier->query_name() + " doubles over from a severe pain.\n",
              carrier);
    tell_object(carrier, "The baby can't find the way out!!\n");
    carrier->hit_player(15 + random(30));
    carrier->set_due_date((int)carrier->query_due_date() + 500);
    return 1;
  }
  clear_pregnancy(carrier, 1);
  tell_room(environment(carrier),
            carrier->query_name() +
            " falls to the ground, and through much pain and screaming, " +
            "gives birth to a child.\n", carrier);
  tell_object(carrier, "The labor pains become too great...\n" +
               "You need to lay down.\n" +
               "You have the urge to PUSH.\n" +
               "Through much pain and agony... you have given birth.\n");
  carrier->add_hit_point(-6);
  carrier->hit_player(10);    /* Why this and the above one? */
  carrier->add_phys_at(3, -5);
  carrier->add_phys_at(3, -random(25));
  if (present("boobs", carrier)) {
    present("boobs", carrier)->add_cup(-(random(2) + 1)); /* To avoid neg 0 */
    present("boobs", carrier)->add_bust(-(random(2) + 1)); /* To avoid neg 0 */
  }
  tell_object(carrier, "You can name your child with 'childname <name>'\n");
  kid = clone_object("obj/kid");
  if (random(100) < 50)
    kid->set_gender("male")
  else
    kid->set_gender("female");
  kid->set_name("baby");
  kid->set_hp(30);
  kid->set_short(carrier->query_name() + "'s baby");
  kid->set_long("A little newborn baby.\n");
  kid->set_parent(carrier->query_real_name());
  kid->set_nrparents(carrier->query_real_name() + "#" +
                     donor->query_real_name());
  kid->set_level(1);
  kid->set_chat_chance(10);
  kid->load_chat("The baby cries.\n");
  kid->load_chat("The baby drools.\n");
  kid->load_chat("The baby smiles.\n");
  kid->load_chat("The baby says: OOGA BOOGA MMOOMY\n");
  kid->load_chat("The baby says: OCA PYUPY ORCI SUM\n");
  move_object(clone_object("obj/soul"), kid);
  move_object(kid, carrier);

/* Add stuff here for twins, 5 percent chance, 15 percent if fertility */
  return 1;
}

int query_pregnancy(object carrier) {
  if (member(carrier, pregos) > -1)
    return 1;
  return 0;
}

string preggers_long(object carrier) {
  int months;

  switch((carrier->query_due_date() - carrier->query_age())) {
    case 14400..16299: months = 3; break;
    case 12700..14399: months = 4; break;
    case 10800..12699: months = 5; break;
    case 9000..10799: months = 6; break;
    case 7200..8999: months = 7; break;
    case 5001..7199: months = 8; break;
    case 0..5000: months = 9; break;
    default: months = 10; break;
  }
  return months + " months pregnant " + (months == 10 ? ", WOW!" : ".") + "\n";
}

