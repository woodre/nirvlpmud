main(){
  int s;
  object *us;
  us = users();
  s = sizeof(us);
  while(s--) {
    if(us[s]->query_level() < 21 && us[s]->query_pl_k() && !us[s]->is_testchar()) {
     write(us[s]->query_real_name()+"\t\t"+us[s]->query_guild_name()+"\n");
  }
  }
  return 1;
}
