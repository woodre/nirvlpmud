inherit "obj/armor";
reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("robe");
  set_short("Sohei's Robes");
  set_alias("robes");
  set_type("armor");
  set_long("This is the robe armor of the Sohei- the warrior monks.\n"+
    "It has gauze as the outer part and inside a do-maru\n"+
    "protects the body.  A headcowl protects the head.\n");
  set_ac(4);
  set_weight(3);
  set_value(1000);
}
