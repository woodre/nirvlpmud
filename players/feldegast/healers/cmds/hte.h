
do_hte(str) {
  MASTER->broadcast(this_player()->query_name()+" "+str);
  return 1;
}

