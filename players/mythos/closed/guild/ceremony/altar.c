inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("altar");
  set_short("A Black Altar");
  set_long("An Altar of deepest black.  Light seems be sucked\n"+
           "into it.  When examined closely, the top of the \n"+
           "Altar seems coated by a dark brown substance- blood.\n");
  set_weight(100000);
  set_value(0);
}
