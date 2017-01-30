#define tp this_player()->query_name()

short() { return "The Temple of Arate"; }
long()  {  write("\nIt is dark.\n\n");  }

init(){
  set_light(-6);
  add_action("search","search");
  add_action("north","north");
}

north()  {
  call_other(this_player(), "move_player",
            "north#players/saber/closed/quest/arate/arate11.c");
  return 1;
         }
         
search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
