inherit "room/room";
int i;
init() {
   ::init();
   add_action("seek","seek");
}

seek(str) {
   object who;
   string name;
   if(!str || sscanf(str, "%s", name) != 1) {
     write("Usage: seek <player name>\n");
     return 1;
   }
   who = find_player(name);
   if(!who) {
     write("That person is not in the Realm of Nirvana at present.\n");
     return 1;
   }
/*  Added a check so ppl can't look at wizards.  Maledicta 6/29 */
    if(who->query_level() > 19){ write("That person is not in the Realm of Nirvana at present.\n"); return 1; }
     if(who->query_invis()) {
     write("That person is not in the Realm of Nirvana at present.\n");
     return 1;
   }
   write(call_other(who, "look"));
   return 1;
}
reset(arg) {
   if(!present("odin")) {
      move_object(clone_object("players/sandman/MONSTERS/odin"), this_object());
   }
   if(!present("raven")) {
      for(i=0;i<2;i++) {
         move_object(clone_object("players/sandman/MONSTERS/raven"), this_object());
      }
   }
   if(!arg) {
      set_light(1);
      short_desc=("A mountain top");
      long_desc=
   "As you gain the summit of the mountain, you stand before an awe\n"
+  "inspiring throne. Standing before the throne is a grimm face man with\n"
+  "one eye. One each shoulder sits a stately raven. From this high vantage\n"
+  "point you can see all the land of Nirvana by typing 'seek <playername>.\n";
      dest_dir=
      ({
        "players/sandman/ASGARD/stairs", "down"
      });
   }
}
