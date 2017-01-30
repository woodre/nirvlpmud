inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 10

reset(arg) {
if(arg) {
  POR->create_monster(this_object());
  return;
}
set_light(1);
short_desc="Somewhere in the Mountains of Ilstkarn";
long_desc=
"You have wandered deep into the Ilskarken Mountains.  Tall jagged peaks\n"+
"thrust defiantly into the sky.  The ageless mountains cast deep\n"+
"impenatrable shadows across the uneven ground.  A bone chilling wind\n"+
"cuts mercilessly at your skin.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/path9", "northwest",
 "/players/pavlik/ilstkarn/path6", "southeast",
 "/players/pavlik/ilstkarn/path7", "southwest",
});

POR->create_monster(this_object());

}

query_ilstkarn(){ return "path8"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
