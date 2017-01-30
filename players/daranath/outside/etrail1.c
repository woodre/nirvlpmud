#define tp this_player()->query_name()
#define ROOT "/players/daranath/outside/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Eastern Trail";
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
  ROOT+"etrail2.c","east",
  ROOT+"vil_exit.c","west",
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

