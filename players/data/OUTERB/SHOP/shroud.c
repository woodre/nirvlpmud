
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shroud");
   set_alias("armor");
   set_short("A Shroud");
   set_long(
      "Made of some kind of supernatural material, you feel it would be decent protection.\n"
   );
   set_ac(1);
   set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(150);
}

