inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("compass");
  set_short("Compass");
  set_long("This is a gold-plated sailor's compass.\n"+
           "It points north.\n");
  set_weight(1);
  set_value(600);
}
