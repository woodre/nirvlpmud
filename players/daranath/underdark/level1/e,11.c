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
  "that you are not alone. A slight luminescent glow is coming from the\n"+
  "tunnel to the east of here.\n";

items=({
 "paths", "The paths lead further into the darkness",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 "glow", "An almost fungal type of glow eminates from the area to the east",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/d,11.c","north",
 "/players/daranath/underdark/level1/f,11.c","south",
 "/players/daranath/underdark/level1/farm1.c","east",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing amongst the dirt.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
