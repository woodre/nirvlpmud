/*
 * Newer police station for cops
 * Rumplemintz
 */
inherit "room/room";

void reset(status arg) {
  ::reset(arg);

  if (!present("cop")) {
    move_object(clone_object("/players/boltar/things/cop.c"), this_object());
    move_object(clone_object("/players/boltar/things/cop.c"), "room/shop");
    move_object(clone_object("/players/boltar/things/cop.c"), "room/pub2");
    move_object(clone_object("/players/boltar/things/cop.c"),
                             "room/vill_road3");
    move_object(clone_object("/players/boltar/things/cop.c"),
                             "room/vill_road3");
    move_object(clone_object("/players/boltar/things/cop.c"),
                             "room/vill_road3");
  }
  if (!present("whistle"))
    move_object(clone_object("/players/boltar/things/polw.c"), this_object());

  if (arg) return;

  set_light(1);
  short_desc = "The police station";
  long_desc =
"This is the town police station. It consists of a single large room \n" +
"with benches, desks, and other seating locations. One may find the \n" +
"village peace keepers here or prisoners locked up in the small barred \n" +
"cell to the west. The station looks quite old as if it has been in \n" +
"service for a century or more. The floor is worn as well as the \n" +
"greeting desk. Everything is kept clean and tidy, despite the worn \n" +
"conditions. \n";
  items = ({
    "floor", "A beaten, worn out, old wood floor",
    "benches", "Ordinary wood benches with green flaking paint on them",
    "bench", "Ordinary wood benches with green flaking paint on them",
    "desks", "A beat up wood desk that has seen many years of use",
    "desk", "A beat up wood desk that has seen many years of use",
    "greeting desk", "A large elevated desk where the officer working the " +
                     "desk \n would greet people entering the station house",
  });
  dest_dir = ({
    "/room/southroad1", "east",
  });
}

void init() {
  ::init();
  add_action("cell_look", "look");
}

int cell_look(string str) {
   string bb;

   if (str == "at cell" || str == "in cell") {
     "/room/prison"->cmd_list();
     return 1;
   }
   else
     return 0;
}
