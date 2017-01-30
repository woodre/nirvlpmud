/*
   This is based highly off of 
     /open/examples/OBJ/bartering.c
    written by Feldegast
  I added in the ability to chk how many times you've bartered.
*/
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_id("snake helm");
  set_alias("helm");
  set_short("Snake Helm");
  set_long(
"A large dark helm shapped like a snakes head.  A set of eyes gleams \n"+
"from atop the head.  There is a pair of small and sharp fangs just \n"+
"at the tip of the helms opening.\n"
  );
  set_ac(1);
  set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(1000+random(900));
}
