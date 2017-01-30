/*
  camera_picture.c
*/

inherit "obj/treasure";

reset(arg) {
  set_short("a picture");
  set_long("It is a poloroid picture.\n");
  set_value(0);
  set_weight(1);
}

id(str) { return str=="picture" || str=="poloroid picture"; }
