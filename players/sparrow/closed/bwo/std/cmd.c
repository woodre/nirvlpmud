status need_mana(int x)
{
  if((int)this_player()->query_sp() < x)
  {
    write("You don't have enough energy. ["+x+"]\n");
  }
  else
  {
    this_player()->add_sp(-x);
    return 1;
  }
}

status need_renown(int x)
{
  if((int)caller()->queryRenown() < x)
  {
    write("You are not renowned enough. ["+x+"]\n");
  }
  else
  {
    return 1;
  }
}

status need_parish(int x)
{
  if((int)caller()->queryParish() < x)
  {
    write("Your parish is not strong enough! ["+x+"]\n");
  }
  else
  {
    return 1;
  }
}
