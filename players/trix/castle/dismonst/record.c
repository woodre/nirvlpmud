/*
  Changed the wc from 18 to 14.  It's a record.  Duh!
    -Feldegast 9-23-00
*/
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("record");
   set_alt_name("record");
   set_alias("record");
   set_short("A platinum record");
   set_long("This is a nice platinum record , it could hurt monsters a lot.\n");
  set_class(14);
  set_weight(1);
   set_value(2000);
}
