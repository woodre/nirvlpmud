#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ============\n"+
"     ==        ==               All is darkness.\n"+
"     ==        ==\n"+
"     ============\n";

items=({
 "darkness","Yep.  It's really dark",
 });

dest_dir=({
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("east","east");
  add_action("south","south");
}

east()  {
  call_other(this_player(), "move_player", 
            "east#players/saber/closed/quest/arate/arate11.c");
  return 1;
         }

south()  {
  call_other(this_player(), "move_player",
            "south#players/saber/closed/quest/arate/arate16.c");
  return 1;
         }

search() {
 write("You find nothing.\n");
 say (tp +" searches the area\.n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
