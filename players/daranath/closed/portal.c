inherit "room/room";
#define tp this_player()->query_name()

reset(arg){

    if(!arg){

    set_light(1);
    short_desc="Swirling Portal";
    long_desc=
  "Swirling mist surrounds you as you stand within the portal room.\n";

items=({
  "mist", "The swirling mist is all about you.",
 });


dest_dir=({
  "/players/daranath/clearing/path.c","path",
  "/players/daranath/qualtor/newstuff/marketsq.c","market",
  "/players/mythos/healerguild/room/hall.c","healr",
  "/players/saber/ryllian/portal.c","black",
  "/players/daranath/qualtor/newstuff/bone_shop.c","bone",
  "/players/cosmo/apt/rooms/lobby.c","cosmo",
  "/players/daranath/closed/battle.c","battle",
  "/players/daranath/qualtor/newstuff/new_entry.c","entry",
  "/players/daranath/qualtor/old_road4.c","rock",
  "/players/daranath/druid/room/adv_hall.c","druid",
  "/players/daranath/wastes/entry.c","wastes",
  "/players/daranath/vale/entry.c","vale",
  "/players/daranath/dungeon/entry.c","dungeon",
           });
        }
        }

init(){
  ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the mist.\n");
say (tp +" searches the area.\n");
  return 1;
}

