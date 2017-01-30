#define tp this_player()->query_name()
inherit "room/room";
object light;
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Middle Valley";
long_desc=
 "You have reached the middle of the green valley, enclosed to the north and\n"+
 "south by crags and peeks of the Spine of the Moon mountain range.  By the\n"+
 "pale illumination of the stars you make out the shape of a dark tower,\n"+
 "silhouetted against a crescent moon.\n"+
 "A dark tower.\n";

items=({
 "tower","A massive tower constructed of dark stone.\n"+
              "Perhaps you can enter it",
 "mountain", "The valley is sheltered by tall, snow covered mountains",
 "moon","A distant crescent moon",
 "crags","The valley is sheltered by tall, snow covered mountains",
 "peeks","The valley is sheltered by tall, snow covered mountains",
 "ground","The valley floor is covered with lush green grass",
 "stars","Softly gleaming stars are visible overhead",
 "valley","A luscious green valley with a pleasantly warm climate",
 "walls","The valley is sheltered by tall, snow covered mountains",
 });

  dest_dir=({
 "/players/saber/ryllian/gv3.c","west",
 "/players/saber/ryllian/gv1.c","east",
 "/players/saber/tower/tower1.c","enter",
      });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("enter","enter");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

enter() {
call_other(this_player(),"move_player","enter#players/saber/tower/tower1.c");
say (tp+" enters the dark tower.\n");
write("->>\n");
write("The torch flickers, casting strange shadows across the room.\n");
return 1;
}
