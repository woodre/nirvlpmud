#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Dark Trail";
    long_desc=
  "Running paralel to the river, the old Tanner's Road continues north and\n"+
  "south from here. The tanner guild once used the bridge to cross the river\n"+
  "and bring thier goods into the city of Qual'tor. A small village can be\n"+
  "seen to the east from here, while the bridge sits just to the west.\n";

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
  "/players/daranath/outside/dtrail2.c","northeast",
  "/players/daranath/outside/northtan4.c","west",
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

