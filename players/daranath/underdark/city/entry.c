#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Entrance into Baereghel";
  long_desc=
  "You stand at the base of the rocky trail leading up from cavern\n"+
  "floor and out of the dark city. To the north of your location\n"+
  "a series of stalagmites and stalactites form the pathways and\n"+
  "base structures of the underdark dwellings. Buildings are built\n"+
  "around the larger formations, making for strongly fortified\n"+
  "and well defended areas. The largest of the stalagmites within\n"+
  "the center of the small city, glowing brightly with a magical\n"+
  "energy. The pathway leads southeast and up the side of the rocky\n"+
  "cavern floor.\n";

items=({
  "trail", "The rocky trail leads up out of the cavern",
  "floor", "The cavern floor is covered with a layer of dirt",
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
 "/players/daranath/underdark/city/main1.c","north",
 "/players/daranath/underdark/level3/pathway3.c","southeast",
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
