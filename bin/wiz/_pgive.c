nomask int cmd_pgive(string str)
{
  if(!str) return 0;
  if((int)this_player()->query_level() < 80)
    return 0;

  this_player()->give_object("! "+str); 
}