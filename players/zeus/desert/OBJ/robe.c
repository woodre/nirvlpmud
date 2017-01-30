inherit "obj/armor";

reset(arg){
  ::reset(arg);

  set_name("robe");
  set_short("An old brown hooded robe");
  set_long(
"This old brown robe appears to be almost ancient.  It is seems to be\n"+
"coated by sand which simply won't come off.  It has a large hood\n"+
"which was once used to protect the wearer from the sand storms.\n");
  set_type("misc");
  set_ac(1);
  set_weight(2);
  set_value(400);
}
