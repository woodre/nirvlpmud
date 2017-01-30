#define tp this_player()->query_name()
#define TP this_player()
inherit "room/room";

reset(int arg){
if(!present("waterfall"))  {
move_object(clone_object("/players/saber/closed/quest/maze/wfallt.c"),this_object());
        }
 if(!arg){
 set_light(0);
  short_desc="Caves of Mist";
  long_desc=
"You stand in a large mist enshrouded cavern, deafened by the\n"+
"roar of a towering waterfall.  The top of a large waterfall\n"+
"lies before you, illuminated faintly by a dark light gleaming\n"+
"through its churning waters.\n";

items=({
 "mist","The mist seems to almost be alive",
 "cave","You are in the Caves of Mist",
 "walls","The walls are of worn stone, carved by an ancient river",
 "shapes","You're not quite sure what they are",
 "darkness","Yea, its dark",
 "water","The waters are dark and churning",
 "waters","The waters are dark and churning",
 "light","Actually, its rather dark",
 });

  dest_dir=({
 "/players/saber/closed/quest/maze/mz2.c","north",
 "/players/saber/closed/quest/maze/mz5.c","west",
 "/players/saber/closed/quest/maze/mz13.c","down",
      });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("west","west");
  add_action("north","north");
}

search() {
write("You don't find anything.\n");
say (tp +" searches the area\n");
 return 1;  }


north()  {
int RANDOM;
  RANDOM = random(6);

if(RANDOM == 0 || RANDOM == 5)  {
  call_other(TP,"move_player","north#players/saber/closed/quest/maze/mz2.c");
        }
else if(RANDOM == 1 || RANDOM == 4)  {
  call_other(TP,"move_player","north#players/saber/closed/quest/maze/mz3.c");
        }
else if(RANDOM == 2 || RANDOM == 3)  {
  call_other(TP,"move_player","north#players/saber/closed/quest/maze/mz12.c");
         }
  return 1;
         }

west()  {
int RANDOM;
  RANDOM = random(4);

if(RANDOM == 0 || RANDOM == 3)  {
  call_other(TP,"move_player","west#players/saber/closed/quest/maze/mz5.c");
        }
else if(RANDOM == 1 || RANDOM == 2)  {
  call_other(TP,"move_player","west#players/saber/closed/quest/maze/mz8.c");
        }
  return 1;
        }

realm()  {  return "NT";  }
light()  { return "DARK";  }
