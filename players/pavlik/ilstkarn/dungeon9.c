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
"dark corridor continues east-west and north.  There is a prison cell\n"+
"to the south.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/dungeon10", "east",
 "/players/pavlik/ilstkarn/dungeon8", "west",
 "/players/pavlik/ilstkarn/dungeon15", "north",
 "/players/pavlik/ilstkarn/cell4", "south",
});

}

query_ilstkarn(){ return "dungeon9"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
