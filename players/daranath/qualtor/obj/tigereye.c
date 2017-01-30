inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("gemstone");
    set_alias("gem");
    set_short("A huge multifacted gemstone");
    set_long("The gemstone was one of the eyes of the Earth Elemental,\n"+
             "left behind when the body of the creature crumbled back\n"+
             "into the earth it came from. This gem was left behind\n"+
             "as a reminder of the power of the creature.\n");
    set_weight(3);
    set_value(3750);
}
