inherit "/players/vertebraker/closed/std/room";

void reset(status arg)
{
  ::reset(arg);
  if(arg) return;
}
int query_undead_ghall()
{
  return 1;
}

void long(string str)
{
  if(str) {
    write("It is impossible to focus your eyes here.\n");
    return;
  }
  ::long(str);
}
