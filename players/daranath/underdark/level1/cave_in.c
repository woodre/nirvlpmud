#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/mons/orc_thief.c"),this_object());
move_object(clone_object("/players/daranath/mons/orc1.c"),this_object());
move_object(clone_object("/players/daranath/mons/orc1.c"),this_object());
move_object(clone_object("/players/daranath/mons/ogre.c"),this_object());
 if(!arg){

  set_light(-1);
  short_desc="Collapsed Tunnel";
  long_desc=
  "The darkened tunnels come to an end here, suddenly and without warning.\n"+
  "A large pile of debris blocks any farther movement down the tunnel, it\n"+
  "seems that a large cave in has taken over the area.\n";

items=({
 "debris", "Large piles of rock and stone lie about, blocking any further\n"+
           "movement eastard",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/c,13.c","west",
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
