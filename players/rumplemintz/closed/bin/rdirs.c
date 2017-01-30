/*
 * Get the pwd of logged in wizards
 */

int rdirs() {
  object *wizards;
  int i;

  wizards = users();
  for (i=0; i<sizeof(wizards); i++)
    if (wizards[i]->query_level() >= 20)
      write(wizards[i]->query_real_name() +":\n"+
           "    " + wizards[i]->get_path() +"\n");
  return 1;
}
