inherit "obj/armor";

reset(arg) {
if(!arg) {
   set_id("buckler");
   set_name("hard leather buckler");
   set_short("Hard leather buckler");
   set_value(100);
   set_weight(1);
   set_ac(1);
   set_alias("shield");
   set_long("A hard leather buckler which straps to the sword arm of\n"+
            "a fighter enabling them to use a shield and weapon together.\n");
   set_type("misc");
   set_info("A shield from a dead Scoti Raider.  It offers average protection.\n");
   }
}
