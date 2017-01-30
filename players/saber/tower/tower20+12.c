#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
if(!present("storm")) {
move_object(clone_object("/players/saber/effects/storm.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Mountain Top";
long_desc=
 "You are on the mountain peak, in the midst of a raging storm.  Thunder\n"+
 "crashes, lightning flashes and the wind lashes at your body.  In the middle\n"+
 "of the chaos you believe that you see a figure.\n";


  dest_dir=({
 "/players/saber/tower/tower20+13.c","center",
 "/players/saber/tower/tower20+11.c","down",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("look","look");
  add_action("l","l");
   add_action("look","exa");
}

search() {
  write("You cannot see anything in the middle of this storm.\n");
 return 1;  }

look()  {
  write("You cannot see anything in the middle of this storm.\n");
return 1;  }

l()  {
  write("You cannot see anything in the middle of this storm.\n");
  return 1;  }
