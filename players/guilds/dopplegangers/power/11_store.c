/*
 * store
 * Doppleganger command to store hp or sp
 * Rumplemintz
 */

status main(string str) {
  int amt, barb, myst, stored;
  object badge;
  string type;

  if (this_player()->query_guild_rank() < 11) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  badge = present("V-GUILD", this_player());

  barb = (int)badge->query_faction("barbarian");
  myst = (int)badge->query_faction("mystic");

  if (!str) {
    if (barb)
      write("You are currently storing " + badge->query_hp_stored() + " hp.\n");
    if (myst)
      write("You are currently storing " + badge->query_sp_stored() + " sp.\n");
    return 1;
  }

  sscanf(str, "%d %s", amt, type);

  if (barb && myst) {
    if (!type) {
      write("You must specify hit or spell points to be stored.\n");
      return 1;
    }
    if (type == "hp" || type == "hit point" || type == "hit" ||
        type == "hit points") {
      type = "hit";
      stored = (int)badge->query_hp_stored();
    } else
    if (type == "sp" || type == "spell point" || type == "spell" ||
        type == "spell points") {
      type = "spell";
      stored = (int)badge->query_sp_stored();
    }
    else {
      write("You must specify hit or spell points to be stored.\n");
      return 1;
    }
  } else if (barb && !myst) {
    type = "hit";
    stored = (int)badge->query_hp_stored();
  } else if (myst && !barb) {
    type = "spell";
    stored = (int)badge->query_sp_stored();
  }

  if (!amt || amt <= 0) {
    write("How many " + type + " points do you want to store?\n");
    return 1;
  }

  if ((this_player()->query_hp() < amt && type == "hit") ||
      (this_player()->query_sp() < amt && type == "spell")) {
    write("You do not have enough " + type + " points for that.\n");
    return 1;
  }

  if ((stored + (amt/2)) > 100) {
    write("That would put you over the limit...");
    if (stored = 100) {
      write("you are at the max.\n");
      return 1;
    }
    amt = (100 - stored);
    write("adding " + amt + " to max it.\n");
  }

  if (type == "hit") {
    this_player()->add_hit_point(-amt);
    badge->add_hp_stored(amt/2);
    call_out("hp_check", 1, this_player());
  } else {
    this_player()->add_spell_point(-amt);
    badge->add_sp_stored(amt/2);
    call_out("sp_check", 1, this_player());
  }
  return 1;
}

status hp_check(object ob) {
  object badge;

  badge = present("V-GUILD", ob);
  tell_object(ob, badge->query_hp_stored() + " hit" +
              " points now stored.\n->> ");
  return 1;
}

status sp_check(object ob) {
  object badge;

  badge = present("V-GUILD", ob);
  tell_object(ob, badge->query_sp_stored() + " spell" +
              " points now stored.\n->> ");
  return 1;
}

