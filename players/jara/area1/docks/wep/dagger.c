/* A dagger, Created <5/12/00> by Jara */

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("dagger");
  set_alias("knife");
  set_short("A wicked dagger");
  set_long("The steel dagger has a wicked curve and a hilt carved of bone.\n"+
    "A strip of leather has been slipped over the hilt for added grip.\n");
  set_class(13);
  set_weight(1);
  set_value(450);
}
