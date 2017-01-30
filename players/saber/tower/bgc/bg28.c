#define tp this_player()->query_name()

inherit "room/room";
int i;

reset(int arg){

if(!present("mason"))  {
move_object(clone_object("/players/saber/monsters/mason.c"),this_object());
        }

  if(!arg){

  set_light(1);
  short_desc="BGC Tokyo";
  long_desc=
"You stand is a small room filled with rows of flashing computer\n"+
"terminals.  There is a single black chair in the middle of the room.\n";

items=({
 "room","You stand in a room filled with computers",
 "chair","A large black chair",
 "computer","There are many computers in the room",
 "computers","There are many computers in the room",
 "terminals","There are many computers in the room",
 });


  dest_dir=({
 "/players/saber/tower/bgc/bg27.c","west",
           });
    }    }


init(){
 ::init();
  add_action("search","search");
        }

search() {
 write("You find nothing\n");
 say (tp +" searches the area\n");
 return 1;  }
