#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
  short_desc= "Bridge across Blackstone River";
    long_desc=
  "Sturdy wood beams easily support your weight as you stand upon the ancient\n"+
  "bridge. The surface beams of the bridge has been worn smooth over the years\n"+
  "the wood itself now has a stone-like feel to it. The bridge seems to be\n"+
  "the only way across the river that you can find.\n";

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
  "/players/daranath/outside/crossroad.c","east",
  "/players/daranath/outside/field2.c","west",
    });

    }
  }

init() {
  ::init();
add_action("search","search");
  }

search() {
  write("The wood is old yet strong, the bridge obviously built by ancient dwarves.\n");
  say(tp +" searches the area.\n");
return 1;
}

