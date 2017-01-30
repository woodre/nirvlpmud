/*
 * Get the environment of logged in players
 */

int renv() {
  object *players;
  int i;

  players = users();
  for (i = 0; i < sizeof(players); i ++ ) {
    object pl_env;
    pl_env = environment(players[i]);
    write(players[i]->query_real_name() + ": \n");
      if (!pl_env)
        write("     No environment!\n");
    else
      write("     "+file_name(pl_env)+"\n");
  }
  return 1;
}
