/*
  Changed the wc from 18(max storable) to 16 for thematic reasons.
  It just doesn't make sense to have a butcher's knife with the same
  wc as a deathmace.         -Feldegast 9-23-00
*/
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("knife");
   set_alt_name("large knife");
   set_alias("bloody knife");
   set_short("A large and bloody knife");
   set_long("A large knife with shades of red on its edge.\n");
  set_class(16);
   set_weight(2);
   set_value(800);
}
