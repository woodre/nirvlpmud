/*
  Changed the wc from 18 to 15 for thematic reasons.
   -Feldegast 9-23-00
*/
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("shovel");
   set_alt_name("trixshovel");
   set_alias("big shovel");
   set_short("A big metal shovel");
   set_long("A huge shovel made out of metal.  It's useful for digging.\n");
  set_class(15);
   set_weight(2);
   set_value(1000);
}
