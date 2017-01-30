inherit "obj/treasure";
reset(arg) {
  if(arg) return;

    set_id("gemstone");
    set_alias("ruby");
    set_short("A small red ruby");
    set_long("A small, yet perfectly cut ruby.\n");
    set_weight(1);
    set_value(1250);
}
