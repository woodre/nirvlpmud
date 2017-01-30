#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Laboratory Entrance";
  long_desc=
  "Boiling cauldrons and colorful liquids fill this area, most of which\n"+
  "are set up upon a large table in its center. Brimstone and sulfur assault\n"+
  "your sense of smell as you walk about this area. The walls are lined with\n"+
  "shelves containing large ceramic jars and small wooden boxes. An archway\n"+
  "leads to the west from here, while the room continues around the table\n"+
  "to the east.\n";

items=({
 "jars", "The ceramic jars line the walls of this area, stacked upon shelf\n"+
         "after shelf",
 "boxes", "Small wooden boxes sit alongside the jars on the shelves",
 "table", "The large alchemy table blocks travel directly through the\n"+
          "room, boiling liquids and beakers upon it",
 "cauldrons", "The cauldrons have boiling liquids within",
 "liquids", "Trust me, you wouldn't want to drink any of these",
 "archway", "The open archway leads to the west from here, into some sort\n"+
            "of storage area",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/wiz_doors.c","out",
 "/players/daranath/underdark/level1/wiz_lab5.c","east",
 "/players/daranath/underdark/level1/wiz_lab1.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the lab.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
