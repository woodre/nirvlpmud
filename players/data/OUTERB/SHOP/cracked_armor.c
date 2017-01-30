
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("armor");
   set_alias("armor");
   set_short("Cracked Armor");
   set_long(
      "A piece of armor with a great rent, you wonder what could make such a tear in such a fine piece of equipment.\n"
   );
   set_ac(3);
   set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(400);

}