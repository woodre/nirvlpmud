inherit "room/room";
reset(arg) {
  if(!arg) {
    set_light(-100);
    short_desc = "SAND";
    long_desc = "SAND\n";
} }
realm() { return "NT";}
init() { ::init(); 
  if(this_player()->is_player()) {
    log_file("mythos.sandbad",
             this_player()->query_real_name()+" "+ctime(time())+"\n");
    destruct(this_player());
  return 1; }
}
