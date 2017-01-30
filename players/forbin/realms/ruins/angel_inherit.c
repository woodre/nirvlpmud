int collect;

set_collect(int n) { collect = n; }
query_collect()    { return collect; }

collect_reward(string str)
{
  int coins;
  if(!str){ write("What?\n"); return 1; }
  if(str == "bounty")
  {
    if(!present("eghyron", environment(this_player())))
    {
      write("What?\n");
        return 1;
    }
  if(this_object()->query_wielded()){ write("You must unwield it first!\n"); return 1; }
  coins = this_object()->query_collect();
  this_player()->add_money(coins);
  write("Eghyron smiles and hands you your reward.\n");
  write("You receive "+coins+" coins for your work.\n");
  destruct(this_object());
    return 1;
  }
  write("What?\n");
    return 1;
}   
