short() {
  return "A pair of BIIIG eyes";
}
id(str) { return str == "eyes"; }
get() { return 1; }
long()  {
  write("Type \"slook\"\n");
  return 1;
}
init() { 
  if(this_player()->query_level() < 40) 
    destruct(this_object()); 
  add_action("slook","slook");
}
slook() {
  object ob;
  ob = first_inventory(environment(this_player()));
  while(ob) {
    write("  ["+file_name(ob)+"]\n");
    ob = next_inventory(ob);
  }
  return 1;
}
