int rreview(string str){
  object ob;
  if(!str) ob = this_player();
  else ob = find_player(str);
  if(!ob){
    notify_fail("Cannot find "+str+" currently.\n");
    return 0;
  }
  write("mout:\t"+(string)ob->query_msgout()+
    "\nmin:\t"+(string)ob->query_msgin()+
    "\nmmout:\t"+(string)ob->query_mmsgout()+
    "\nmmin:\t"+(string)ob->query_mmsgin()+
    "\nmhome:\t"+(string)ob->query_msghome()+"\n");
  return 1;
}
