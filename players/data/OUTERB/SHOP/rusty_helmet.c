
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("helmet");
   set_alias("helmet");
   set_short("A Rusty Helmet");
   set_long(
      "After careful examination, you feel you should trust this helmet, even though it has seen better days.\n"
   );
   set_ac(2);
   set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(200);
}


