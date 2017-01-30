#define tp this_player()->query_name()
#define TP this_player()
inherit "room/room";

reset(int arg){
 if(!arg){
  set_light(0);
  short_desc="Caves of Mist";
  long_desc=
"You stand in a small mist enshrouded cave.  The walls are of worn\n"+
"river carved stone, smooth and featureless.  In the dim light you\n"+
"see shapes moving in the darkness around you, and in the distance\n"+
"you hear a faint dripping noise.\n";

items=({
 "mist","The mist seems to almost be alive",
 "cave","You are in the Caves of Mist",
 "walls","The walls are of worn stone, carved by an ancient river",
 "shapes","You're not quite sure what they are",
 "darkness","Yea, its dark",
 "dripping","In the distance you hear a faint dripping noise",
 "light","Actually, its rather dark",
 });

  dest_dir=({
 "/players/saber/closed/quest/maze/mz1.c","north",
 "/players/saber/closed/quest/maze/mz11.c","east",
 "/players/saber/closed/quest/maze/mz4.c","south",
 "/players/saber/closed/quest/maze/mz3.c","west",
      });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("east","east");
  add_action("north","north");
  add_action("west","west");
}

search() {
write("You don't find anything.\n");
say (tp +" searches the area\n");
 return 1;  }


north()  {
int RANDOM;
  RANDOM = random(8);

if(RANDOM == 0 || RANDOM == 7)  {
  call_other(TP,"move_player","north#players/saber/closed/quest/maze/mz1.c");
        }
else if(RANDOM == 1 || RANDOM == 6)  {
  call_other(TP,"move_player","north#players/saber/closed/quest/maze/mz5.c");
        }
else if(RANDOM == 2 || RANDOM == 5)  {
  call_other(TP,"move_player","north#players/saber/closed/quest/maze/mz8.c");
         }
else if(RANDOM == 3 || RANDOM == 4)  {
  call_other(TP,"move_player","north#players/saber/closed/quest/maze/mz9.c");
        }
  return 1;
         }

west()  {
int RANDOM;
  RANDOM = random(4);

if(RANDOM == 0 || RANDOM == 3)  {
  call_other(TP,"move_player","west#players/saber/closed/quest/maze/mz3.c");
        }
else if(RANDOM == 1 || RANDOM == 2)  {
  call_other(TP,"move_player","west#players/saber/closed/quest/maze/mz13.c");
        }
  return 1;
        }

east()  {
int RANDOM;
  RANDOM = random(4);

if(RANDOM == 0 || RANDOM == 3)  {
  call_other(TP,"move_player","east#players/saber/closed/quest/maze/mz11.c");
        }
else if(RANDOM == 1 || RANDOM == 2)  {
  call_other(TP,"move_player","east#players/saber/closed/quest/maze/mz13.c");
        }
  return 1;
        }

realm()  {  return "NT";  }
light()  { return "DARK";  }
