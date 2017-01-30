inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("gauntlets");
  set_alias("gloves");
  set_short("Durkor gauntlets");
  set_long(
     " The gauntlets are made of a strange material unfamiliar to surface\n"+
     "dwellers.  Along the top of the gauntlets are the finely carved \n"+
     "coiled snakes representing the Sivart Durkor.\n");
  set_type("ring");
  set_ac(1);
  set_weight(1);
  set_value(1000);
}
