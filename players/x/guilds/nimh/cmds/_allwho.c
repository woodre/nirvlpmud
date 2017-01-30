int cmd_allwho()
{
 object *us;
 int s;
  if((string)this_player()->query_real_name()!="x") return 0;
 us = users();
 s= sizeof(us);
 while(s--) if(us[s] && us[s]->query_level() > 20) write(us[s]->query_real_name()+" "+query_idle(us[s])+"\n");
 return 1;
}
