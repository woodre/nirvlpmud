inherit "obj/treasure";
 
reset(arg) {
  if(!arg) {
     set_id("shadow gem");
     set_value(3000);
     set_alias("gem");
     set_short("A dusky gem");
     set_long(
"This is an extremely valuable shadow gem.\n"+
"In its flawless angles you know your fate resides.\n");
  }
}
