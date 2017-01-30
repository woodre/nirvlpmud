#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
if(!present("banshee")) {
move_object(clone_object("/players/saber/monsters/banshee.c"),this_object()); }
 if(!arg){
  set_light(1);
 short_desc="Mountain Turn";
long_desc=
 "The wind continues, it howling fury bearing a faint resemblance\n"+
 "to the screams of a dying woman.  Out of the corner of your eye\n"+
 "you see movement, yet there is no one in this icy clearing.  Or\n"+
 "is there?  The trail continues to the east and to the south.\n";

items=({
 "trail","A thin, icy trail covered with a fresh layer of virgin snow",
 "clouds","Dark, ominous looking storm clouds",
 "mountain","You can't see it because of the clouds",
 "peak","You can't see it because of the clouds",
 "snow","A fresh layer of virgin snow coveres the ground",
 "ground","A fresh layer of virgin snow coveres the ground",
 "movement","You think that you see something moving..",
 });

  dest_dir=({
 "/players/saber/tower/tower20+1.c","east",
 "/players/saber/tower/tower20+4.c","south",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
   add_action("south","south");
   add_action("east","east");
   add_action("sneak","sneak");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

south(){
if(present("banshee")){
write("The banshee materializes in front of you.\n");
write("The banshee wails: Dooooo nooooooooot leeeeeeeeaaaaveeeee meeee.\n");
say("The banshee materializes in front of "+tp+"\n");
say("The banshee wails: Dooooo nooooooooot leeeeeeeeaaaaveeeee meeee.\n");
return 1; }
call_other(this_player(),"move_player","south#players/saber/tower/tower20+4.c");
say(tp+" leaves south.\n");
return 1; }

east(){
if(present("banshee")){
write("The banshee materializes in front of you.\n");
write("The banshee wails: Dooooo nooooooooot leeeeeeeeaaaaveeeee meeee.\n");
say("The banshee materializes in front of "+tp+"\n");
say("The banshee wails: Dooooo nooooooooot leeeeeeeeaaaaveeeee meeee.\n");
return 1; }
call_other(this_player(),"move_player","east#players/saber/tower/tower20+1.c");
say(tp+" leaves south.\n");
return 1;}

sneak(str){
if(!str){
write("Sneak where?\n");
return 1;}
if(str == "south" || str == "s"){
call_other(this_player(),"move_player","south#players/saber/tower/tower20+4.c");
return 1; }
if(str == "east" || str == "e"){
call_other(this_player(),"move_player","east#players/saber/tower/tower20+1.c");
return 1;}
else
write("Sneak where?\n");
return 1; }
