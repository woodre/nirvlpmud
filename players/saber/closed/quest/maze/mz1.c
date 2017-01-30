#define tp this_player()->query_name()
#define TP this_player()
inherit "room/room";

object ob;


reset(int arg){
 if(!arg){
  set_light(0);
  short_desc="Caves of Mist";
  long_desc=
"You stand in a small mist enshrouded cave.  The walls are of worn\n"+
"river carved stone, smooth and featureless.  In the dim light you\n"+
"see shapes moving in the darkness around you, and in the distance\n"+
"you hear a faint dripping noise.  Above you shines a faint light.\n";

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
 "/players/saber/closed/quest/maze/mz0.c","up",
 "/players/saber/closed/quest/maze/mz4.c","south",
      });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("south","south");
}

search() {
write("You don't find anything.\n");
say (tp +" searches the area\n");
 return 1;  }


south()  {
int RANDOM;
  RANDOM = random(6);

if(RANDOM == 0 || RANDOM == 5)  {
  call_other(TP,"move_player","south#players/saber/closed/quest/maze/mz4.c");
        }
else if(RANDOM == 1 || RANDOM == 4)  {
  call_other(TP,"move_player","south#players/saber/closed/quest/maze/mz5.c");
        }
else if(RANDOM == 2 || RANDOM == 3)  {
  call_other(TP,"move_player","south#players/saber/closed/quest/maze/mz8.c");
         }
  if(!(ob = find_living("devourer")))  {
    ob = clone_object("/players/saber/closed/quest/maze/devo.c");
    move_object(ob,"/players/saber/closed/quest/maze/mz4.c");
        }
  return 1;
         }

realm()  {  return "NT";  }
light()  { return "DARK";  }
