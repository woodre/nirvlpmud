
id(str) { return str == "lighter"; }

short() { return "A lighter"; }

get() { return 1; }

init() {
   add_action("light","light");
}

light() {
   object dest;
   object light;
   dest = environment(this_player());

   light = clone_object("players/molasar/MISC/light");
   move_object(light, dest);
   return 1;
}

