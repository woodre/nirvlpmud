
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shield");
   set_alias("shield");
   set_short("A Wooden Shield");
   set_long(
      "A small wooden shield that has been warped from exposure to the weather.\n"
   );
   set_ac(1);
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(200);
}

