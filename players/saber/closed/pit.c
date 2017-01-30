#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("dog"))  {
  for(t=0;t<4;t++)  {
move_object(clone_object("/players/saber/monsters/dog.c"),this_object());  }
        }
 if(!arg){
  set_light(1);
  short_desc = "The dog pit";
long_desc=
  "You are in a large pit filled with the bones of various creatures.\n"+
  "From all around you comes faint growling noises.\n";

items=({
 "pit","Yep, you're in a dark pit",
 });

  dest_dir=({
           });
  }   }

init(){
 ::init();
  write("\nAhhhhhhhhhhhhhhhhhhh\n"+
         "  You find yourself FALLING into a large, dark pit...\n\n"+
        "THUD.\n");
  add_action("search","search");
  add_action("climb","climb");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

climb()  {
write("You climb out of the pit.\n");
call_other(this_player(), "move_player", "up#room/church");
return 1;
        }

realm()  { return "NT"; }
