#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Cloak Room- Ruins";
long_desc=
 "You have entered what was the anteroom of Orin's Inn but what is\n"+
 "now a shattered shell of burnt wood and blasted earth.  To the east\n"+
 "you see what remains of the once beautiful Inn.\n";

  dest_dir=({
 "/players/saber/ryllian/ryllian2.c","west",
 "/players/saber/closed/old_bard/room/orin_ruin2.c","east",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
   add_action("down","down");
}

search() {
 write("You find a staircase leading down to the wine cellar\n");
say (tp +" searches the area\n");
 return 1;  }

down() {
write("You walk down the staircase.\n");
call_other(this_player(),"move_player",
"walking down the staircase#/players/saber/ryllian/orin5.c");
  return 1;
  }
