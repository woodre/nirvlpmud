#define MONEY_OB  "obj/money"
#define MONEY     (int)this_object()->query_money()
#define NAME      (string)this_object()->query_name()
#define LEVEL     (int)this_player()->query_level()


/***************************************************************************/
/* Generic moving function */

void move_ob(object *items, object to, string verb) {
  string item_name, item, container;
  int i, size, abort;
  int wt;
  object from;
  status flag;

  for (i = 0, size = sizeof(items); i < size; i++) {
    if (items[i] == to) continue; /* can't move items into self */
    if (!objectp(items[i]) || living(items[i])) continue; /* no move living */
    if (!(item_name = (string)items[i]->short())) continue; /* no move invis */
    flag = 1;
    if (++abort > 30) {
      tell_object(this_object(), "*** " + capitalize(verb) +
                  " Truncated ***\n");
      return;
    }
    item_name = ((item = (string)items[i]->query_name())) ? item : item_name;
    from = environment(items[i]);
    if (items[i]->drop()) {
      if (living(from)) {
        tell_object(this_object(), "You cannot " + verb + " " + item_name +
                    ".\n");
        continue;
      }
    }
    if (!items[i]) continue; /* some things destruct on drop */
    if (items[i]->query_money() && to == this_object()) {
      this_object()->add_money((int)items[i]->query_money());
      if (MONEY < 0) this_object()->set_money(0);
      this_object()->save_me(1);
      destruct(items[i]);
      continue;
    }
    if (from != environment() && from != this_object()) { /* from container */
      container = (from->query_name())
                ? " from " + (string)from->query_name()
                : " from " + (string)from->short();
    }
    else if (to != environment() && to != this_object()) { /* to container */
      container = (living(to)) ? " to " : " in ";
      container += (to->query_name())
                ? (string)to->query_name()
                : (string)to->short();
      if (!living(to)) {
        if (!to->can_put_and_get(0)) {
          tell_object(this_object(), "You cannot do that!\n");
          return;
        }
        if (items[i]->prevent_insert()) continue;
      }
    }
    if (!container) container = "";
    if (from != this_object() && !items[i]->get()) {
      write("You cannot " + verb + " " + item_name + container + ".\n");
      continue;
    }
    wt = (int)items[i]->query_weight();
    if (to != environment() && !to->add_weight(wt)) {
      tell_object(to, "You do not have the strength to carry the " +
                  item_name + ".\n");
      if (to != this_object()) {
        tell_object(this_object(), "You are unable to " + verb + " " +
                    item_name + container + ".\n" +
                    "It seems to have a weight problem.\n");
/*
        ((living(to))
        ? capitalize((string)to->query_possessive())
        : ((container != "") ? "The " + container : "It")) +
        " cannot carry " + item_name + ".\n");
*/
      }
      continue;
    }
    from->add_weight(-wt);
    move_object(items[i], to);
    write("You " + verb + " the " + item_name + container + ".\n");
    say(NAME + " " + verb + "s the " + item_name + container + ".\n");
  }
  if (!flag) tell_object(this_object(), "You have nothing to " + verb + ".\n");
  this_object()->recalc_carry();
}


/***************************************************************************/
/* put */

status put(string item) {
  int wt;
  object *items;
  string container;
  object ob, to;

  if (this_object()->query_ghost()) {
    tell_object(this_object(), "It passes straight through your hands...\n");
    return 1;
  }
  if ((int)this_object()->query_real_light() < 1) {
    tell_object(this_object(), "It's too dark to do that.\n");
    return 1;
  }
  if (!item) {
    tell_object(this_object(), "Usage: put <item> in <container>\n");
    return 1;
  }
  sscanf(item, "%s in %s", item, container);
  sscanf(item, "%s on %s", item, container);
  if (!container) return put(0);
  container = lower_case(container);
  if (!(to = present(container, this_object()))) {
    if (!(to = present(container, environment()))) {
      tell_object(this_object(), "There are no " + container + "s here!\n");
      return 1;
    }
    if (living(to)) {
      tell_object(this_object(), "You cannot do that!\n");
      return 1;
    }
  }
  if (item == "all") {
    items = all_inventory();
  }
  else if (!(ob = present(item, this_object()))) {
    tell_object(this_object(), "You do not have " + item + ".\n");
    return 1;
  }
  if (ob) items = ({ ob, });
  move_ob(items, to, query_verb());
  return 1;
}


/***************************************************************************/
/* get */

status pick_up(string item) {
  string container;
  object from;
  object *items, ob;

  if (this_object()->query_ghost()) {
    tell_object(this_object(), "It passes straight through your hands...\n");
    return 1;
  }
  if ((int)this_object()->query_real_light() < 1) {
    tell_object(this_object(), "It's too dark to do that.\n");
    return 1;
  }
  if (!item) {
    tell_object(this_object(), "Usage: get <item|all>\n" +
                "       get <item|all> from <container>\n");
    return 1;
  }
  sscanf(item, "%s from %s", item, container);
  if (container) {
    container = lower_case(container);
    if (!(from = present(container, this_object()))) {
      if (!(from = present(container, environment()))) {
        write("There is no " + container + " here.\n");
        return 1;
      }
    }
    if (living(from)) {
      tell_object(this_object(), "You cannot do that!\n");
      return 1;
    }
  }
  else {
    from = environment();
  }
  if (item == "all") {
    items = all_inventory(from);
  }
  else if (!(ob = present(item, from))) {
    tell_object(this_object(), "There is no " + item + " in the " +
                ((container) ? container : "room") + ".\n");
    return 1;
  }
  if (ob) items = ({ ob, });
  move_ob(items, this_object(), query_verb());
  return 1;
}


/***************************************************************************/
/* give */

status give_object(string item) {
  string who;
  object *items;
  object ob, dest_ob;
  int amt;

  if (this_object()->query_ghost()) {
    write("It passes straight through your hands...\n");
    return 1;
  }
  if ((int)this_object()->query_real_light() < 1) {
    tell_object(this_object(), "It's too dark to do that.\n");
    return 1;
  }
  if (!item) {
    write("Usage: give <item|all> to <who>\n" +
          "       give <amount> coins to <who>\n");
    return 1;
  }
  sscanf(item, "%s to %s", item, who);
  sscanf(item, "%d coins to %s", amt, who);
  sscanf(item, "%d coin to %s", amt, who);
  if (!who) return give_object(0);
  if (!(dest_ob = present(who, environment()))) {
    write(capitalize(who) + " is not here.\n");
    return 1;
  }
  if (!living(dest_ob)) {
    write("That's not giving it away, it's throwing it away.\n");
    return 1;
  }
  if (amt) {
    if (amt < 1) {
      write("Are you looking for a loan?\n");
      return 1;
    }
    if (LEVEL < 2) {
      write("Your level is not high enough to be a money lender.\n");
      return 1;
    }
    if (amt > MONEY) amt = MONEY;
    this_object()->add_money(-amt);
    this_object()->save_me(1);
    dest_ob->add_money(amt);
    dest_ob->save_character();
    write("You give " + capitalize(who) + " " + amt + " copper coin" +
          ((amt == 1) ? "" : "s") + ".\n");
    say(NAME + " gives " + capitalize(who) + " " + amt + " copper coin" +
        ((amt == 1) ? "" : "s") + ".\n", dest_ob);
    tell_object(dest_ob, NAME + " gives you " + amt + " copper coin" +
                ((amt == 1) ? "" : "s") + ".\n");
    return 1;
  }
  if (item == "all") {
    items = all_inventory();
  }
  else if (!(ob = present(item, this_object()))) {
    if (!(ob = present(item, environment()))) {
      tell_object(this_object(), "You do not have " + item + ".\n");
      return 1;
    }
  }
  if (ob) items = ({ ob, });
  move_ob(items, dest_ob, query_verb());
  return 1;
}


/***************************************************************************/
/* drop */

status drop_thing(string item) {
  string container;
  object ob, to;
  object *items;
  int amt;

  if (!item) {
    write("Usage: drop <item|all>\n" +
          "       drop <item|all> in <container>\n" +
          "       drop <amount> coins\n");
    return 1;
  }
  sscanf(item, "%d coins", amt);
  sscanf(item, "%d coin", amt);
  sscanf(item, "%s in %s", item, container);
  if (amt) {
    if (amt < 1) {
      write("Are you looking for a loan?\n");
      return 1;
    }
    if (LEVEL < 2) {
      write("Something prevents you.\n");
      return 1;
    }
    if (amt > MONEY) amt = MONEY;
    this_object()->add_money(-amt);
    this_object()->save_me(1);
    ob = clone_object(MONEY_OB);
    ob->set_money(amt);
    move_object(ob, environment());
    write("You drop " + amt + " copper coin" + ((amt == 1) ? "" : "s") +
          ".\n");
    say(NAME + " drops " + amt + " copper coin" + ((amt == 1) ? "" : "s") +
        ".\n");
    return 1;
  }
  if (container) {
    container = lower_case(container);
    if (!(to = present(container, this_object()))) {
      if (!(to = present(container, environment()))) {
        write("There is no " + container + " here.\n");
        return 1;
      }
    }
    if (living(to)) {
      write("You can't do that!\n");
      return 1;
    }
  }
  else {
    to = environment();
  }
  if (item == "all") {
    items = all_inventory();
  }
  else if (!(ob = present(item, this_object()))) {
    tell_object(this_object(), "You do not have " + item + ".\n");
    return 1;
  }
  if (ob) items = ({ ob, });
  move_ob(items, to, query_verb());
  return 1;
}

