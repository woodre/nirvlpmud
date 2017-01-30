#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Laboratory East Wing";
  long_desc=
  "The east wing to the wizard's lab.\n";

items=({
 "paths", "The paths lead further into the darkness",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/wiz_entry.c","west",
 "/players/daranath/underdark/level1/wiz_lab4.c","south",
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
