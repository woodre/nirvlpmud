#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Tanner's Road South";
    long_desc=
  "The old Tanner's Road continues south from the crossroads and the area\n"+
  "around the bridge. Small hills are becoming quite frequent in the \n"+
  "surrounding landscape, with larger ones looming to the south.\n";

    items=({
  "bridge","A small weather worn bridge cross the river here",
  "footprints","A variety of footprints run around the area, mostly human",
  "grass","Tall yellowing grass grows in the place of crops",
  "ruins","The ruins of the city extend to the south from here",
  "field","The fields have long since been forgotten, with noone needing food",
  "fields","The fields have long since been forgotten, with noone needing food",
  "road","The packed dirt roadway narrows as it runs east from the Northgate",
  "roadway","The packed dirt roadway narrows as it runs east from the Northgate",
  "trail","The road narrows into little more then a trail leading east",
    });

    dest_dir=({
  "/players/daranath/outside/crossroad.c","north",
  "/players/daranath/outside/southtan2.c","south",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Footprints run all around the area, both normal and heavily armored.\n");
  say(tp +" searches the area.\n");
 return 1;
}

