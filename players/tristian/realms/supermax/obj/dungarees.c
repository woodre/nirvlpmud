inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("dungarees");
   set_alias("pants");
   set_short("Prison issue dungarees");
   set_long(
      "A set of prison issues dungarees.\n"
   );
   set_ac(1);
   set_type("pants");
   set_value(500);
}
