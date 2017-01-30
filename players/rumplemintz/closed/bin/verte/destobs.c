main(str)
{
  int s;
  object *obs;
  obs = "/obj/invasion/i-daemon"->query_monster_obs();
  s=sizeof(obs);
  while(s--)
  { 
    if(objectp(obs[s]))
    {
      write("Destroying: "+file_name(obs[s])+"... ");
      destruct(obs[s]);
      write("Ok.\n");
    }
  }
  write("All obs destroyed.\n");
  return 1;
}
