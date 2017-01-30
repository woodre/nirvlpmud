#define tp this_player()->query_name()
inherit "room/room";
int searcher;

reset(int arg){
move_object(clone_object("/players/daranath/mons/fungi6.c"),this_object());
move_object(clone_object("/players/daranath/mons/fungi4.c"),this_object());
move_object(clone_object("/players/daranath/mons/fungi5.c"),this_object());
move_object(clone_object("/players/daranath/mons/fungi0.c"),this_object());
move_object(clone_object("/players/daranath/mons/fungi0.c"),this_object());
move_object(clone_object("/players/daranath/mons/fungi0.c"),this_object());
searcher = 0;

 if(!arg){

  set_light(1);
  short_desc="King's Hut";
  long_desc=
  "The interior of the fungal hut is one that you might find anywhere in\n"+
  "the surface world, as if the inhabitants here seemed to try and be human.\n"+
  "A large wooden throne is located against the far wall, with a fireplace\n"+
  "burning bright alongside it, filling the room with warmth. The flooring\n"+
  "is covered with a large circular rug, and the walls here have various\n"+
  "items hanging from them. The only exit appears to be out.\n";

items=({
 "chamber", "The large chamber is circular in nature, a naturally formed\n"+
            "cave within the rock",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/farm9.c","out",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
if(searcher) { write("You find nothing of interest.\n"); return 1; }
write("You find something under the circular rug.\n");
move_object(clone_object("/players/daranath/items/fungi_treats.c"),this_object());
searcher = 1;
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
