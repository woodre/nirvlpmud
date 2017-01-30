int main(string arg) {
  object ob;

  if (!arg) {
    notify_fail("Bump who?\n");
    return 0;
  }

  ob = find_player(arg);

  if (!ob) {
    notify_fail("Player not found: "+arg+"\n");
    return 0;
  }

  write("Forced disconnect on: "+arg+".\n");
  remove_interactive(ob);
  return 1;
}
