#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Tunnel within the UnderDark";
  long_desc=
  "The darkened tunnels come to an end here, suddenly and without warning.\n"+
  "A large pile of debris blocks any farther movement down the tunnel, it\n"+
  "looks as if a wizards spell has collapsed the area.\n";

items=({
 "debris", "Large piles of rock and stone lie about, blocking any further\n"+
           "movement westard",
 "spell", "Areas of the stone are blackened, leading you to believe that\n"+
          "a spell of some sort has brought down the tunnel",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/c,9.c","east",
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
