inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("jacket");
  set_short("Black Jacket");
  set_alias("black jacket");
  set_type("armor");
  set_long("A black leather jacket.  It is a protective and\n"+
           "fearsome looking thing- metal studs decorate the\n"+
           "sleeves and a gold brooch seems permantenly affixed\n"+
           "to it.\n");
  set_ac(4);
  set_weight(2);
  set_value(1000);
}
