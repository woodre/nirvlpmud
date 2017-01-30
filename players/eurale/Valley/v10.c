/*  10/04/2006 - Rumplemintz
      Fixed code for up(str) to pass string if one is supplied
*/

/*  The Park Valley  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);

    short_desc = "Hidden valley";
    long_desc =
    "  The valley is much different than the jungle above.  The trees \n"+
    "are taller but much less sparce allowing more sunlight to pass \n"+
    "through their canopy.  The area is dotted with large boulders \n"+
    "which probably broke away when the valley was formed.  The path \n"+
    "up disappears in the ferns which are growing in abundance here.\n";

    items = ({
      "ferns","Shrubby, nonflowering plants with large stems and huge \n"+
      "fronds that reproduce by spores instead of seeds",
      "trees","Very tall trees with smaller tops, able to withstand \n"+
      "the heat of the valley",
      "boulders","Large rocks",
    });

    dest_dir = ({
      "players/eurale/Valley/v11.c","east",
      "players/eurale/Valley/v26.c","southeast",
      "players/eurale/Valley/v25.c","south",
      "players/eurale/Valley/v24.c","southwest",
      "players/eurale/Valley/v9.c","west",
    });

}

init() {
    ::init();
    add_action("up","up"); }

up(str) {
    if(str) return;
    this_player()->move_player("up#players/eurale/Valley/v32.c");
    return 1;
}
realm() { return "NT"; }
