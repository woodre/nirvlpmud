/*
  Changed the wc from 18 to 16 for thematic reasons.
   -Feldegast 9-23-00
*/
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("razor");
   set_alt_name("shining razor");
   set_alias("bloody knife");
   set_short("A shining razor");
   set_long("A shining and sharpened razor.  You'd better not touch its edge.\n");
   set_class(16);
   set_weight(2);
   set_value(2000);
}
