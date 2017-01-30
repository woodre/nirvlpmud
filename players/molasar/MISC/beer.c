
inherit "players/molasar/MISC/drink";

reset(arg) {
   if(!arg)
   ::reset(arg);
   set_name("beer");
   set_alias("booze");
   set_short("A bottle of beer");
   set_long("An icy cold bottle of beer.\n");
   set_drink_mess1("That feels good!\n");
   set_drink_mess2("chugs a beer.\n");
   set_heal(1);
   set_strength(3);
   set_value(5);
   set_container("bottle");
}

