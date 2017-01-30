/*
  ruby_ring.c - made from skins
*/

inherit "obj/armor";

reset(arg) {
  ::reset(arg);

  set_name("ruby ring");
  set_short("A ruby ring");
  set_long("A heavy gold ring, with a huge blood red ruby set in it.\n");
  set_value(25);
  set_weight(1);
  set_ac(1);
  set_type("ring");
}

id(str) {
  return str=="ring" ||
         str=="ruby ring" ||
         str=="gold ring" ||
         str=="gold ruby ring";
}
