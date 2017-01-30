object tree,tree2,light;
object santa;


reset() {
  /** Gnar - Only have this load in December **/
  if( ctime()[4..6] != "Dec" )
    return; 

    call_other("room/vill_green", "short", 0);
    if(!present("tree", find_object("room/vill_green.c"))) {
     tree = clone_object("players/boltar/things/tree2.c");
     move_object(tree, "room/vill_green");
     call_other(tree, "light", "tree");
      }
    call_other("room/pub2", "short", 0);
    if(!present("tree", find_object("room/pub2.c"))) {
     tree2 = clone_object("players/boltar/things/tree2.c");
     move_object(tree2, "room/pub2");
     call_other(tree2, "light", "tree");
      }
    call_other("room/pub3", "short", 0);
    if(!present("lights", find_object("room/pub3.c"))) {
     light = clone_object("players/boltar/things/xmaslights2.c");
     move_object(light, "room/pub3");
     call_other(light, "light", "lights");
      }
    call_other("room/shop", "short", 0);
    if(!find_living("Christmas Turkey")) {
     santa = clone_object("players/boltar/things/lightupsanta.c");
     move_object(santa, "room/shop");
     call_other(santa, "light", "santa");
      }
    call_other("room/shop", "short", 0);
    if(!present("santa", find_object("room/shop.c"))) {
     santa = clone_object("players/boltar/sprooms/xmas_turkey.c");
     move_object(santa, "room/shop");
      }
}
