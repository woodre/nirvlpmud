/*
  e_forest8.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="A dimly lit forest.  A booth sits off to the side";
  long_desc="You are in part of a dimly lit forest.\n"+
           "The entrance to a graveyard is to the north\n"+
           "and the forest gets really dark to the west.\n"+
           "Off to the side sits Nancy's Souvenir Booth.\n";
  items=({
         "forest", "It is full of trees",
         "trees", "They are mostly oak",
         "tree", "This one seems to be a sturdy redwood",
         "trails",
           "They seem to be somewhat clear paths between the trees",
         "trail",
           "It seems to be a somewhat clear path between the trees",
         "booth", "It's a small booth packed with various items designed\n"+
                  "to please the tourist.  Perched on the awning is a sign\n"+
                  "indicating available merchandise",
         "souvenir booth",
                  "It's a small booth packed with various items designed\n"+
                  "to please the tourist.  Perched on the awning is a sign\n"+
                  "indicating available merchandise",
         "sign",
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
           "~                    Nancy's Souvenirs                    ~\n"+
           "~                      Tourist Aides                      ~\n"+
           "~                         Sex Toys                        ~\n"+
           "~                                                         ~\n"+
           "~     Maze maps to Sebastian               1 coin         ~\n"+
           "~     Maze maps to Barnabas                1 coin         ~\n"+
           "~     Maze maps to Baphomet                1 coin         ~\n"+
           "~     Maps to Burried treasure             1 coin         ~\n"+
           "~                                                         ~\n"+
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
         "maze map to sebastian",
            "    _________________________________________________________\n"+
            "   /                                                      /  \\\n"+
            "  |          X (Sebastian is here)                       |___/\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |          X (You are here)                            |\n"+
            " _____________________________________________________   |\n"+
            "/                                                    /   /\n"+
            "\\____________________________________________________\\__/\n",
         "maze map to barnabas",
            "    _________________________________________________________\n"+
            "   /                                                      /  \\\n"+
            "  |          X (Barnabas is here)                        |___/\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                         X (You are here)             |\n"+
            " _____________________________________________________   |\n"+
            "/                                                    /   /\n"+
            "\\____________________________________________________\\__/\n",
         "maze map to baphomet",
            "    _________________________________________________________\n"+
            "   /                                                      /  \\\n"+
            "  |  X (Baphomet is here)                                |___/\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                     X (You are here) |\n"+
            " _____________________________________________________   |\n"+
            "/                                                    /   /\n"+
            "\\____________________________________________________\\__/\n",
         "map to burried treasure",
            "    _________________________________________________________\n"+
            "   /                                                      /  \\\n"+
            "  |                                                      |___/\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  |                                                      |\n"+
            "  | X (You are here but the treasure isn't)              |\n"+
            " _____________________________________________________   |\n"+
            "/                                                    /   /\n"+
            "\\____________________________________________________\\__/\n",
       });
  dest_dir=({
             "players/nooneelse/graveyard/g_path0", "north",
             "players/nooneelse/entryforest/e_forest4", "east",
             "players/nooneelse/entryforest/e_forest7", "south",
             "players/nooneelse/mazeforest/m_forest0", "west",
          });
}


init() {
  ::init();

  add_action("read_sign", "read");
  add_action("no_buy",    "buy");
  add_action("no_buy",    "purchase");
}

read_sign(str) {
  if (!str || str!="sign") return 0;
  command("look at sign", this_player());
  return 1;
}

no_buy(str) {
  write("Sorry, we're sold out.  You can look at the desk copy if you wish.\n"+
        "Use commands like 'look at maze map to sebastian'.\n");
  return 1;
}
