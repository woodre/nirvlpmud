inherit "obj/weapon";
 
reset(arg) {
  if(!arg) 
  ::reset(arg);
  set_name("biscuit");
  set_weight(2);
  set_value(4000);
  set_short("A large dog biscuit");
  set_long("It goes with the armor...\n" +
           "What more do you want???\n" +
           "");
}
 
wield(str) {
   set_class(10 + (call_other(this_player(), "query_level"))/2);
   return ::wield(str);
}
