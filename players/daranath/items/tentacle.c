inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("tentacle");
    set_alias("length");
    set_short("A length of tentacle");
    set_long("A severed bit of tentacle from a creature wandering\n"+
             "about the tunnels of the underdark.\n");
    set_weight(1);
    set_value(15);
}
