inherit "/obj/armor.c";
id(str) { return str=="collar" || str=="spiked collar"; }
reset(arg) {
 ::reset(arg);
 set_short("A spiked collar");
 set_name("collar");
 set_long(
  "  A black leather collar, softened with age.  Rusted metal spikes\n"+
  "protrude through the collar, evenly spaced.  A large rusty buckle\n"+
  "is used to fasten the collar around its owners neck.\n");
 set_ac(1);
 set_type("amulet");
 set_weight(2);
 set_value(300+random(700));
}
