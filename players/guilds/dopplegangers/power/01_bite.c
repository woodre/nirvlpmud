/*
 * bite
 *
 * Cosmetic spell that bites players in neck - no damage
 *
 * Rumplemintz
 */

status main(string str) {
  object ob;

  if (!str) return 0;
  ob = present(str, environment(this_player()));
  if (!ob) {
    write("That player is not here.\n");
    return 1;
  }
  if (this_player()->query_ghost()) {
    write("You try to bite " + capitalize(str) + " but your ghost " +
          "teeth pass right through.\n");
    return 1;
  }
  if ((string)ob->query_real_name() == "grimm" ||
      (string)ob->query_real_name() == "rumplemintz" ) {
    write("As you try to bite your master, " + ob->query_pronoun() +
          " grabs you by the head and threatens to \nrip out your fangs!!\n");
    say("As " + this_player()->query_name() + " tries to bite " +
        ob->query_name() + ", the Doppleganger Master threatens to\n" +
        "rip out " + this_player()->query_possessive() + " fangs.\n");
    tell_object(ob, this_player()->query_name() + " just tried to bite you.\n");
    return 1;
  }
  tell_object(ob, this_player()->query_name() + " grabs you by the neck and " +
              "sucks a pint of blood from your body!\n");
  say(this_player()->query_name() + " bites " + ob->query_name() +
      " in the neck!\n", ob);
  write("You bite " + ob->query_name() + " in the neck!\n");
  return 1;
}
