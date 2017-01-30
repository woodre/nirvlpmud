status cmd_whisper(string str) {
  object ob;
  string who;
  string msg;

  if (ghost) {
    write("You fail.\n");
    return 1;
  }
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Whisper what?\n");
    return 1;
  }
  it = lower_case(who);
  ob = find_player(it, 1);
  if (!ob || !present(it, environment(this_player()))) {
write("No player with that name in this room.\n");
return 1;
  }
  who = (string)ob->query_name();
  tell_object(ob, cap_name + " whispers to you: " + msg + "\n");
  write("Ok.\n");
  checked_say(cap_name + " whispers something to " + who + ".\n");
  return 1;
}

