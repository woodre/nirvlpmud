inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("boots");
   set_alias("boots");
   set_short("A Pair of Soft Boots");
   set_long(
      "A Pair of Soft Boots, you feel these will help protect you feet on your travels.\n"
   );
   set_ac(1);
   set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(100);
}
