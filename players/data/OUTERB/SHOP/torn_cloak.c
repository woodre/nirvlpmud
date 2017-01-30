
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("cloak");
   set_alias("cloak");
   set_short("A Torn Cloak");
   set_long(
      "This cloak may be torn, but would provide excelent protection against the weather still.\n"
   );
   set_ac(1);
   set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(200);
}


