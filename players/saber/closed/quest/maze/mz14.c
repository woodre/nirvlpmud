#define tp this_player()->query_name()
#define TP this_player()
inherit "room/room";

int done;


reset(int arg){
 if(!arg){
 set_light(0);
  short_desc="Caves of Mist";
  long_desc=
"You stand in an expansive mist enshrouded cavern.  All about you\n"+
"lie shallowly dug graves, some of them looking quite fresh.  The\n"+
"mist shifts about you, seeming to form familiar looking faces.\n";

items=({
 "mist","You think you see familiar looking faces in the mist",
 "cave","You are in the Caves of Mist",
 "walls","The walls are of worn stone, carved by an ancient river",
 "shapes","You're not quite sure what they are",
 "graves","There are a lot of graves here that you could 'dig' up",
 "grave","There are a lot of graves here that you could 'dig' up",
 });

  dest_dir=({
 "/players/saber/closed/quest/maze/mz10.c","west",
      });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("dig","dig");
}

search() {
write("You find some shallow graves.\n"+
       "Perharps you could dig here.\n");
say (tp +" searches the area\n");
 return 1;  }

dig()  {
int i;
if(done < 1)  {
object OBJ;
write("You disturb something with your digging...\n\n"+
     "You hear a strange moaning sound...\n\n"+
     "The dead begin to rise from their graves...\n");
say(tp+" begins digging around...\n\n"+
     "You hear strand moaning sounds...\n\n"+
     "The dead begin to rise from their graves...\n");
OBJ = clone_object("/players/saber/monsters/zombie.c");
move_object(OBJ,this_object());
move_object(clone_object("/players/saber/closed/quest/items/coin.c"),OBJ);
  for(i=0;i<5;i++)  {
move_object(clone_object("/players/saber/monsters/zombie.c"),this_object());
        }
  done++;
  return 1;
        }
  write("You find nothing.\n");
  say(tp+" digs around.\n");
  return 1;
        }

realm()  {  return "NT";  }
light()  { return "DARK";  }
