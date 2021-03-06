#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Tunnel within the UnderDark";
  long_desc=
  "A split within the rocky path causes the twisting pathway to fork both northeast\n"+
  "and southeast from here. Footprints made from travellers long since past circle the\n"+
  "area. The tunnels continue west from here as well.\n"

items=({
 "paths", "The paths lead further into the darkness",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 });

  dest_dir=({
  "/players/daranath/underdark/level1/k,13.c","west",
  "/players/daranath/underdark/level1/j,15.c","northeast",
  "/players/daranath/underdark/level1/l,15.c","southeast",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing special about the footprints.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
