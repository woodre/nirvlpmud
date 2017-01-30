#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("silversword"))  {
move_object(clone_object("/players/saber/weapons/silversword.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc="Circle of Power";
long_desc=
 "This is an empty room.  You think it could use a little work.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 });

  dest_dir=({
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

realm()  { return "NT"; }
