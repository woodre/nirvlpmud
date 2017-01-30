
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("ring");
   set_alias("ring");
   set_short("A Cracked Ring");
   set_long(
      "A small ring, cracked due to overuse. You may 'wear' this ring.\n"
   );
   set_ac(1);
   set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(100);
}

