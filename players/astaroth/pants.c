inherit "obj/armor";
reset(arg) {
  if(!arg) 
  ::reset(arg);
  set_name("pants");
  set_alias("pants");
  set_ac(1);
  set_type("misc");
  set_weight(3);
  set_value(800);
  set_short("Pants of the family");
  set_long("These are the pants of the family.\n" +
           "Wear them well and watch yourself.\n" +
           "");
}
