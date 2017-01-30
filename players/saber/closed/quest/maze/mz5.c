#define tp this_player()->query_name()
#define TP this_player()
inherit "room/room";

reset(int arg){
if(!present("stream"))  {
move_object(clone_object("/players/saber/closed/quest/maze/stream.c"),this_object());  }
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
 "/players/saber/closed/quest/maze/mz5.c","north",
 "/players/saber/closed/quest/maze/mz6.c","east",
 "/players/saber/closed/quest/maze/mz10.c","south",
      });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You don't find anything.\n");
say (tp +" searches the area\n");
 return 1;  }

realm()  {  return "NT";  }
light()  { return "DARK";  }
