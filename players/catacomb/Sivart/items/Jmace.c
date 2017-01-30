inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("mace");
  set_short("A light mace");
  set_long(
 "  A small mace used by Jortar when the customers get unruly.  There\n"+
 "are a few red stains on the head of the mace but nothing too great.\n"+
 "The mace has a decent weight distribution, it could make an ok weapon.\n" );
  set_type("mace");
  set_class(16);
  set_weight(2);
  set_value(1000);
  
}  