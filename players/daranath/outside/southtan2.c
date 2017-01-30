#define tp this_player()->query_name()
#define ROOT "/players/daranath/outside/"
inherit "room/room";

reset(int arg){
if(!present("portal"),this_object()) {
move_object(clone_object("/players/daranath/wastes/obj/portal1.c"),this_object());
}
  if(!arg){
    
    set_light(1);
    short_desc= "Tanner's Road South";
    long_desc=
  "Tanner's Road ends suddenly, with a large pile of rock and rubble blocking\n"+
  "any further passage southwards. It looks as if one of the nearby hills has\n"+
  "collapsed upon the roadway, blocking any passage. The only option is to\n"+
  "turn back north.\n";

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
  "/players/daranath/outside/southtan1.c","north",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("dar_south","south");
}

search(){
write("Footprints run all around the area, both normal and heavily armored.\n");
  say(tp +" searches the area.\n");
 return 1;
}

dar_south(){
write("At some point in the past, you were indeed able to continue south from\n"+
      "here. The rockslide prevents anyone from continuing south now.\n");
return 1;
}

