#define tp this_player()->query_name()
#define TP this_player()
inherit "room/room";

reset(int arg){
if(!present("waterfall"))  {
move_object(clone_object("/players/saber/closed/quest/maze/wfallb.c"),this_object());  }
 if(!arg){
 set_light(0);
  short_desc="Caves of Mist";
  long_desc=
"You stand at the base of a towering waterfall.  All about you\n"+
"the mist flickers in chaotic patterns, dancing to the deafening\n"+
"roar of the cascading water.\n";

items=({
 "mist","The mist seems to almost be alive",
 "cave","You are in the Caves of Mist",
 "walls","The walls are of worn stone, carved by an ancient river",
 "shapes","You're not quite sure what they are",
 "water","You stand at the base of a waterfall",
 });

  dest_dir=({
 "/players/saber/closed/quest/maze/mz10.c","north",
 "/players/saber/closed/quest/maze/mz12.c","west",
 "/players/saber/closed/quest/maze/mz6.c","up",
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
