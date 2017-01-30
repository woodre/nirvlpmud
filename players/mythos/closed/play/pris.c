reset (arg) {
  if (arg) return;
  set_light(1);
}

short () { return "NOWHERE in particular"; }

long () {
  write("You are NOWHERE in particular.\n");
  return 1;
}

id (str) { return str == "none"; }

init () {
  add_action("say_here", "say");
#ifndef __LDMUD__
  add_action("say_here"); add_xverb("'");
#else
  add_action("say_here", "'", 3);
#endif
  if (secure()) return;
  else {
    write("You are imprisoned.\n");
    add_action("shout", "shout");
    add_action("tell", "tell");
    add_action("gossip", "gossip");
    add_action("stop", "risque");
    add_action("stop", "equip");
    add_action("stop", "quit");
    add_action("exit", "xyz");
    if (this_player()->query_level() > 19) {
      object *ob;
      int i;
#ifndef __LDMUD__
      add_action("stop"); add_xverb("");
#else
      add_action("stop", "", 3);
#endif
      ob = all_inventory(this_player());
      i = sizeof(ob);
/*
      while ( i-- )
        destruct(ob[i]);
*/
    }
  }
}

stop () {
  string verb;

  verb = query_verb();
  if ( member_array(verb, ({ "tell", "shout", "gossip", "say", "'" })) != -1 )
    return 0;
  write("Strong magic prevents you from doing so.\n");
  return 1;
}

say_here (str) {
  write("You say: " + str + "\n");
  say(this_player()->query_name() + " says: " + str + "\n");
  return 1;
}

tell (str) {
  string who, what;
  string sort;

  if (!str) return;
  sort = sscanf(str, "%s %s", who, what);
  say(this_player()->query_name() + " tries to tell " +
      capitalize(who) + ": " + what + "\n");
  write("Strong magic prevents you from doing so.\n");
  return 1;
}

shout (str) {
  say(this_player()->query_name() + " tries to shout: " +
      str + "\n");
  write("Strong magic prevents you from doing so.\n");
  return 1;
}

gossip (str) {
  say(this_player()->query_name() + " tries to gossip: " +
      str + "\n");
  write("Strong magic prevents you from doing so.\n");
  return 1;
}

realm () { return "NT"; }

secure () {
  return 1; /* Rumplemintz - no more personal prisons..... */
/*
  return this_player() == find_player("mythos") ||
         this_player() == find_player("boltar")  ||
         this_player() == find_player("sandman")
*/
}

string X;

set_X (val) {
  if ( !secure() )
        return 0;
    return X = val;
}

exit () {
  if ( secure() )
    return;
  if (find_player(X)) /* Rumplemintz */
    tell_object(find_player(X), capitalize(this_player()->query_real_name()) +
                " is freed!\n");
  X = 0;
}
