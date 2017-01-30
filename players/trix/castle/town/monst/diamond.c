inherit "obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("diamond");
  set_short("A huge diamond");
  set_long("A very huge and valuable diamond.\n");
  set_weight(3);
  set_value(1000);
}
