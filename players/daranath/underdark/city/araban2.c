#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Side road in dark city";
  long_desc=
  "A small side road leads from the main street with the underground\n"+
  "city Baereghel. The pathway itself leads to an iron gateway just\n"+
  "to the west of here, while the main road lies to the east.\n"+
  "The gateway is emblazened with a large spider crest in its center,\n"+
  "matching the other decor of this bizarre town.\n";

items=({
  "gateway", "The iron gateway is to the west from here, standing\n"+
             "within the deep shadows, obscuring your view",
  "road", "The side road runs east and west from here",
  "spider", "The spider insignia is everywhere in this dark city",
 });

  dest_dir=({
 "/players/daranath/underdark/city/araban1.c","east",
 "/players/daranath/underdark/city/araban3.c","west",
           });
  }
}

init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the dark city.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
realm() { return "NT"; }
