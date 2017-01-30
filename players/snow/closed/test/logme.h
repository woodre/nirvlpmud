logMyDeath() {
  object list;
  int i;
  list = users();
  for(i=0; i<sizeof(list); i++) {
    if(present(list[i], environment(this_object()))) {
    write_file("/players/snow/closed/test/log",ctime(time())+
    " "+query_real_name()+
    "\n"+list[i]->query_real_name()+" "+
    "Level: "+list[i]->query_level()+" "+
    "Extra Level: "+list[i]->query_extra_level()+"\n"); }
  }
  return; }
