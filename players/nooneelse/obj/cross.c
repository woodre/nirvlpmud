/*
  cross.c
*/

inherit "obj/treasure";

reset(arg) {
  set_id("cross");
  set_alias("holy item");
  set_short("A little cross");
  set_long("This is a beautiful little silver cross with "+
           "ancient holy symbols etched in it.\n");
  set_value(50);
  set_weight(1);
}

id(str) { return str=="cross" || str=="holy item" || str=="nooneelsecross"; }
