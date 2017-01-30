id(str) { return str == "foo"; }
long() { 
   write("The Foo of Life...\n"+
         "Only true messiahs may perform the foo.\n");
return 1;
}
short() {
   return "The Foo";
}
get() {return 1;}
query_weight() { return 0; }
drop() {return 1;}
 
init() {
  if(this_player()->query_real_name() != "snow"  &&
     this_player()->query_real_name() != "dune") {
    shout("*** *** KA - BLAM! *** ***\n");
    destruct(this_player()); destruct(this_object()); }
  add_action("talk","talk");
}
 
talk(string str) {
  int level;
  level = 80;
  sprintf("My lev: [%1d]\n", level);
  return 1;
  }
