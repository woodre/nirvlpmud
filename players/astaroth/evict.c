inherit "obj/weapon";
reset(arg) {
  if(!arg) 
  ::reset(arg);
  set_name("notice");
  set_class(14);
  set_weight(2);
  set_value(750);
  set_short("eviction notice");
  set_long("An eviction notice for the person in the house he.\n" +
           "wants to demolish.\n" +
           "");
  set_alias("notice");
}
