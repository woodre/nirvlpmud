#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Tanner's Road Crossing";
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
  "/players/daranath/outside/northtan1.c","north",
  "/players/daranath/outside/southtan1.c","south",
  "/players/daranath/outside/west_vil.c","east",
  "/players/daranath/outside/bridge.c","bridge",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("dar_east","east");
add_action("dar_north","north");
}

search(){
write("Old wagon tracks and many, many footprints run all around the crossroad.\n"+
      "Heavy, armored bootprints stop here and seem to turn back to the east.\n");
  say(tp +" searches the area.\n");
 return 1;
}

dar_north(){
write("Area is under construction.  Thanks\n-Dar\n");
return 1; 
}

dar_east(){
write("Area is under construction.  Thanks\n-Dar\n");
return 1; 
}

