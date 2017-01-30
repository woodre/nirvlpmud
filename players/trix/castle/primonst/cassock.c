inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_short("Priest's cassock");
   set_long(
"This is a long black cassock.  If you can deal with wearing such an\n"+
"ugly dress you can use it as armor.\n");
   set_ac(3);
   set_weight(2);
   set_value(500);
   set_alias("armor");
   set_name("cassock");
   set_type("armor");
}
