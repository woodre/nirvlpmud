#define tp this_player()->query_name()
#define TP this_player()
inherit "room/room";

reset(int arg){
if(!present("man"))  {
move_object(clone_object("/players/saber/closed/quest/maze/starshop.c"),this_object());  }
if(!present("troll"))  {
move_object(clone_object("/players/saber/monsters/supertroll.c"),this_object());  }
 if(!arg){
  set_light(1);
  short_desc="Caves of Mist";
  long_desc=
"You stand in the mouth to the Cave of Mist.  The walls are of worn\n"+
"river carved stone, descending into the depths of a supernaturally\n"+
"dark tunnel.  The mist around you seems to flow in and out of the\n"+
"tunnel in some sort of vaguely recognizable pattern.\n";

items=({
 "mist","The mist seems to almost be alive",
 "cave","You are in the Caves of Mist",
 "walls","The walls are of worn stone, carved by an ancient river",
 "pattern","You're not quite sure what the pattern is",
 "dark","Yea, its dark",
 "dripping","In the distance you hear a faint dripping noise",
 "light","Actually, its rather dark",
 });

  dest_dir=({
 "/players/saber/ryllian/gv4.c","out",
 "/players/saber/closed/quest/maze/mz1.c","down",
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
