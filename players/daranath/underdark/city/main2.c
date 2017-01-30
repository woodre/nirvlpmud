#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Main Road within Baereghel";
  long_desc=
  "Darkness fills the area as you walk along one of the main roads\n"+
  "in Baereghel. The city itself stands to the north of here,\n"+
  "spreading about the bowl-shaped cavern like the legs of a large\n"+
  "spider. Various rock formations rise all about you, giving the\n"+
  "city more of an enclosed feel.\n";

items=({
  "trail", "The rocky trail leads up out of the cavern",
  "floor", "The cavern floor is covered with a layer of dirt",
  "road", "The main road of the city runs north and south",
  "stalagmites", "The stalagmites rise up from the floor of the cavern\n"+
                 "and have the buildings of the dark city intertwined\n"+
                 "within them. Outer walls are built within their given\n"+
                 "and natural measure of support",
  "stalactites", "Natural formations this deep with the UnderDark",
  "cavern", "A bowl shaped cavern opens wide within the embrace of\n"+
            "the surrounding rock. The opening is large enough to have\n"+
            "an entire underground city growing within",
 });

  dest_dir=({
 "/players/daranath/underdark/city/main3.c","north",
 "/players/daranath/underdark/city/main1.c","south",
 "/players/daranath/underdark/city/araban1.c","west",
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
