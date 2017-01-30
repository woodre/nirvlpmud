#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Laboratory Entrance";
  long_desc=
  "The entrance to the wizard's lair.\n";

items=({
 "paths", "The paths lead further into the darkness",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/wiz_lab3.c","north",
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
