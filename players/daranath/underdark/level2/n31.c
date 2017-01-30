#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Tunnel within the UnderDark";
  long_desc=
  "The myriad of dark tunnels continue from this area, naturally twisting\n"+
  "and turning along unseen paths. The walls are rough hewn and rocky,\n"+
  "making for an isolated feeling, yet well traveled enough that you know\n"+
  "that you are not alone. A black colored stone leads off in a tunnel\n"+
  "to the west from here.\n";

items=({
 "paths", "The paths lead further into the darkness",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "stone", "The black colored stone runs to the west from here",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 });

  dest_dir=({
 "/players/daranath/underdark/level2/m31.c","north",
 "/players/daranath/underdark/level2/o31.c","south",
 "/players/daranath/underdark/level2/n30.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing amongst the tunnels of the UnderDark.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
