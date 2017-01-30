/* A cat collar, Created <5/11/00> by Jara */

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

  set_id("collar");
  set_short("A cat collar");
  set_long("The cat collar is made of a thick leather, well worn with age.\n");
  set_weight(1);
  set_value(150);
}
