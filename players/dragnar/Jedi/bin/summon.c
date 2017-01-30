main() {
  object          droid, ob;
  string          idstr, ownstr;

  if (find_living(this_player()->query_real_name() + "droid")) {
     write("You already have a droid.\n");
     return 1;
  }
    droid = clone_object("/players/dragnar/Jedi/obj/droid.c");
    idstr = this_player()->query_real_name() + "droid";
    ownstr = this_player()->query_real_name();
    move_object(droid, environment(this_player()));
    droid->set_owner(ownstr);
    droid->set_variable(idstr);
    write("You summon a droid.\n");
    say(this_player()->query_name() + " summons a droid.\n");
    return 1;
}
