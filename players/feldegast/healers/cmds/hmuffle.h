do_hmuffle() {
  int toggle;
  toggle=MYOB->query_muffle();
  MYOB->set_muffle(!toggle);
  write("Guild Channel "+(toggle?"ON":"OFF")+"\n");
  MASTER->rebuild_channel();
  return 1;
}
    
