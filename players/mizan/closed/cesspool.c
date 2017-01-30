/*
 * Based straight off of
 * Damian's Prison.
 *
 * Don't mess with this unless you know what you're doing!
 */

#define VIEW "/players/mizan/workroom"

reset (arg) {
     if (arg) return;
     set_light(1);
}

short () { return "The cesspool"; }

long (str) {
     if ( str == "door" ) {
          write("It is covered with poop.\n");
          return; 
     }
     write("You are in a cesspool. It is filled with poop.\n"+
           "There is a door here.\n");
     return 1;
}

id (str) { return str == "door"; }

init () {
     add_action("say_here", "say");
#ifndef __LDMUD__
  add_action("say_here"); add_xverb("'");
#else
  add_action("say_here", "'", 3);
#endif
     if ( secure() )
          return;
     write_file("/players/mizan/logs/prison.log", 
                ctime(time()) + " " +
                (this_player() ? this_player()->query_real_name() : "") +
                object_name(previous_object()) + "\n");
     else {
          write("You are imprisoned.\n");
          add_action("shout", "shout");
          add_action("tell", "tell");
          add_action("gossip", "gossip");
          add_action("stop", "risque");
          add_action("stop", "equip");
          add_action("stop", "quit");
          if(this_player()->query_level() > 19) {
               object *ob;
               int i;

#ifndef __LDMUD__
  add_action("stop"); add_xverb("");
#else
  add_action("stop", "", 3);
#endif
               ob = all_inventory(this_player());
               i = sizeof(ob);

               while ( i-- )
                   destruct(ob[i]);

          }
    }
}

stop () {
    string verb;

    verb = query_verb();
    if ( member_array(verb, ({ "star", "tell", "shout", "gossip", "say", "'" })) != -1 )
        return 0;
    write("Thick poop prevents you from doing so.\n");
    return 1;
}

say_here (str) {
    tell_room(VIEW, "You hear " + this_player()->query_name() + " say: " +
              str + "\n");
    write("You say: " + str + "\n");
    say(this_player()->query_name() + " says: " + str + "\n");
    return 1;
}

tell (str) {
     string who, what;
     string sort;

     if (!str) return;
     sort = sscanf(str, "%s %s", who, what);
     tell_room(VIEW, this_player()->query_name() + " tries to tell " +
               capitalize(who) + ": " + what + "\n");
     say(this_player()->query_name() + " tries to tell " +
               capitalize(who) + ": " + what + "\n");
     write("Thick poop prevents you from doing so.\n");
     return 1;
}

shout (str) {
     tell_room(VIEW, this_player()->query_name() + " tries to shout: " +
               str + "\n");
     say(this_player()->query_name() + " tries to shout: " +
               str + "\n");
     write("Thick poop prevents you from doing so.\n");
     return 1;
}

gossip (str) {
     tell_room(VIEW, this_player()->query_name() + " tries to gossip: " +
               str + "\n");
     say(this_player()->query_name() + " tries to gossip: " +
               str + "\n");
     write("Thick poop prevents you from doing so.\n");
     return 1;
}

realm () { return "NT"; }

secure () {
    return this_player() == find_player("mizan") ||
           this_player() == find_player("boltar")  ||
           this_player() == find_player("fred"); 
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
    tell_object(find_player(X), capitalize(this_player()->query_real_name()) +
                                " is freed!\n");
    X = 0;
}

