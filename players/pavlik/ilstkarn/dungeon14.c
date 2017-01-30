inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 14

reset(arg) {
if(arg) {
  return;
}
set_light(0);
short_desc="In the Dungeons of Arcydia";
long_desc=
"You walk the narrow corridors of Arcydia's dungeons.  The cold dark\n"+
"prison cells of the fortress wait silently behind rusted bars.  The\n"+
"dark corridor continues westward. There are prison cells to the east,\n"+
"north and south.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/cell9", "east",
 "/players/pavlik/ilstkarn/dungeon6", "west",
 "/players/pavlik/ilstkarn/cell10", "north",
 "/players/pavlik/ilstkarn/cell8", "south",
});

}

query_ilstkarn(){ return "dungeon14"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
