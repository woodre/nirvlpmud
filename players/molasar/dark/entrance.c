
inherit "/players/molasar/dark/obj/room";

reset(arg) {
   if (arg)
      return;
   set_light(1);
   set_short("An entrance");
   set_long("A neat entrance.\n");
   add_item("junk", "You wish you had such nice junk at home.");
}
