#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Center of Baereghel";
  long_desc=
  "You stand within the center of the dark underground city, the\n"+
  "large stalagmite dwarfing even the largest person you have ever\n"+
  "seen. Large decorated buildings are all about, the largest of\n"+
  "them surrounded with large walls making them seem like complexes\n"+
  "then just single structures. Roads lead in all directions from\n"+
  "here.\n";

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
 "/players/daranath/underdark/city/center.c","north",
 "/players/daranath/underdark/city/main3.c","south",
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
