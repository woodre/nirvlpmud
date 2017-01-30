#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Just west of a Village";
    long_desc=
  "Just outside a small village, this roadway has been well kept and used\n"+
  "frequently between Tanner's Road and the village itself. The dark brown and\n"+
  "grey earth is a sharp contrast to the surrounding landscape, making you\n"+
  "wonder where they got the material for the road. Not much else of interest\n"+
  "is here.\n";

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
  "/players/daranath/outside/vil_entry.c","east",
  "/players/daranath/outside/crossroad.c","west",
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

