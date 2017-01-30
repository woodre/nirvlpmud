inherit "obj/armor";
reset(arg) {
  if(!arg) 
  ::reset(arg);
  set_name("strap");
  set_alias("strap");
  set_ac(1);
  set_type("shield");
  set_weight(3);
  set_value(800);
  set_short("Guitar strap");
  set_long("This is Satriani's guitar strap.\n" +
           "Wear it well and watch yourself.\n" +
           "");
}
