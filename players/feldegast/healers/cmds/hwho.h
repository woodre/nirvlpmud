#define LINE HIB+"------------------------------------------------------\n"+NORM
int do_hwho() 
{
  object *all;
  object gob;
  int i;
  int max;
  all = users();
  max = sizeof(all);
  write(
    LINE+
    " Name            Rank Karma    Where\n"+
    LINE
  );
  for(i=0;i<max;i++) 
  {
    gob = present(GUILD_ID, all[i]);
    if(gob && !((int)all[i]->query_invis()))
    {
      if((int)gob->query_muffle())
        write(HIB+"X"+NORM);
      else
        write(" ");
      write(pad((string)all[i]->query_name(),16));
      write(pad((int)all[i]->query_guild_rank(), 5));
      write(pad((string)gob->query_karma_string(), 9));
      if(!all[i]->query_invis())
        write(environment(all[i])->short());
      write("\n");
    }
  }
  write(LINE);
  return 1;
}
