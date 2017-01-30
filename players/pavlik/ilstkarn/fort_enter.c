inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 10

reset(arg) {
if(arg) {
  return;
}
set_light(0);
short_desc="In the Dungeons of Arcydia";
long_desc=
"You have successfully entered the dungeons of Arcydia.  The over-\n"+
"whelming darkness covers you like a blanket.  The slow, desolate\n"+
"sound of dripping water echoes all around you.  You can no longer see\n"+
"the secret door from which you entered, but there is a doorway to\n"+
"the north.  The northern wall is made of thick iron bars.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/dungeon1", "north",
});

}

query_ilstkarn(){ return "fortress entrance"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
