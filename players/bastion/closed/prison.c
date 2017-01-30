/*
 * Damian's Prison.
 *
 * Don't mess with this unless you know what you're doing!
 */

#define VIEW "/players/bastion/isle/wiz/prisonview"

reset (arg) {
     if (arg) return;
     set_light(1);
}

short () { return "Damian's Prison"; }

long (str) {
     if ( str == "door" ) {
          write("It is a formidable barrier.\n");
          return; 
     }
     write("You are in a bare cubicle. A heavy door leads north. You get\n"+
           "the feeling you are being watched.\n");
     return 1;
}

id (str) { return str == "door"; }

init () {
     add_action("say_here", "say");
     add_action("say_here"); add_xverb("'");
     if ( secure() )
          return;
     write_file("/players/bastion/prison.log", 
                ctime(time()) + " " +
                (this_player() ? this_player()->query_real_name() : "") +
                file_name(previous_object()) + "\n");
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

               add_action("stop"); add_xverb("");
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
     write("Strong magic prevents you from doing so.\n");
     return 1;
}

shout (str) {
     tell_room(VIEW, this_player()->query_name() + " tries to shout: " +
               str + "\n");
     say(this_player()->query_name() + " tries to shout: " +
               str + "\n");
     write("Strong magic prevents you from doing so.\n");
     return 1;
}

gossip (str) {
     tell_room(VIEW, this_player()->query_name() + " tries to gossip: " +
               str + "\n");
     say(this_player()->query_name() + " tries to gossip: " +
               str + "\n");
     write("Strong magic prevents you from doing so.\n");
     return 1;
}

realm () { return "NT"; }

secure () {
    return this_player() == find_player("bastion") ||
           this_player() == find_player("boltar")  ||
           this_player() == find_player("sandman"); 
}

string X;

set_X (val) {
    if ( !secure() )
        return 0;
    return X = val;
}

/*
exit () {
    if ( secure() )
        return;
    tell_object(find_player(X), capitalize(this_player()->query_real_name()) +
                                " is freed!\n");
    X = 0;
}
*/
