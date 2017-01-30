#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int a, b, peeps;

reset(int arg){
b = random(3);
if((b == 0) && (!present("spirit"))) {
move_object(clone_object(ROOT+"mon/drifter.c"),this_object());
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "The ruins of the Crystalline Tower here in Qual'tor stand as a ghostly\n"+
     "reminder of what was within the city. Nothing much is left of\n"+
    "the tower itself, save a pile of crystalline shards that spill\n"+
     "into a stairwell leading down from here. Nothing is evident from\n"+
     "the stairs save rubble and despair.\n";

    items=({
     "stairwell","The stairs are made from a dark grey stone",
     "darkness","The darkness hides many things from view, including\n"+
                "where the stairs lead",
     "stairs","The stairs are made from a dark grey stone",
     "shards","The broken shards of crystal are all that remains of the tower above",
    });

    dest_dir=({
      "/players/daranath/qualtor/old_road4.c","back",
      "/players/daranath/qualtor/cryst_stairs.c","down",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
if(find_call_out("ash") == -1)
 call_out("ash", random(10) + 3);
    }

    search(){
write("All of the Crystal shards are covered with a thick layer of dark ash.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

void exit() {
   peeps--;
   if(peeps <= 0)
      while(remove_call_out("ash") != -1) ; }

void ash() {
   object ob,next;
   string msg;
   a = random(5);

 if(a < 2) {msg= "Hot ash"+NORM+" falls from the sky, building upon the ground.\n"; }
 if(a == 2) {msg= "Hot ash"+NORM+" falls from the sky, "+HIR+"burning"+NORM+" your skin.\n"; }
 if(a == 3) {msg= "Hot ash"+NORM+" falls from the sky, "+HIR+"searing"+NORM+" your lungs as you breathe.\n"; }
 if(a == 4) {msg= "Hot ash"+NORM+" falls from the sky, "+HIR+"scorching"+NORM+" everything in the area.\n"; }

   tell_room(this_object(),msg);
   ob=first_inventory(this_object());
   while(ob) {
      next=next_inventory(ob);
      if(living(ob) && ob->is_player() && !present("br_scarf", ob))
         if(a > 1) ob->hit_player(3, "other|fire");
      ob=next;
   }
   call_out("ash", random(10) + 3); 
}
