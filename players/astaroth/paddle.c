inherit "obj/weapon";
reset(arg) {
  if(!arg) 
  ::reset(arg);
  set_name("paddle");
  set_weight(3);
  set_value(250);
  set_short("A big canoe paddle");
  set_long("I don't think you want to eat it.\n" +
           "");
}
 
wield(str) {
   set_class(8 + (call_other(this_player(), "query_level"))/3);
   return ::wield(str);
}
