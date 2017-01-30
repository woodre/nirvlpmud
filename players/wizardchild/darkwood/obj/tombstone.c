/* tombstone.c: your personal tombstone */
string *names;
short() {
  return "A tombstone"; 
}
long()  {
  int i;
  write("A tombstone, with a collection of names of those who have died here today.\n");
  for(i = 0; i < sizeof(names); i++)
    write(names[i]+" ");
  write("\n");
  return 1;
}
id(str) { return str == "tombstone"; }
init() {
  if(this_player()->query_level() > 20) 
    return ;
  write("Adding your name to the tombstone...\n");
  names += ({this_player()->query_real_name()});
}
