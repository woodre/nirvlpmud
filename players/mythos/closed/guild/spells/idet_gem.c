inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("idgem");
    set_alias("orb");
    set_short("A small orb");
    set_weight(1);
    set_value(0);
}

get() { return 0;}
