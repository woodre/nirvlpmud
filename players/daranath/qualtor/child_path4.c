#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int a, b, c, peeps;

reset(int arg){
 b = random(3);
if(b < 2) {
 c = random(5);
if(!present("ghostmon")) {
if(c == 0) {move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object()); }
if(c == 1) {move_object(clone_object(ROOT+"mon/drifter.c"),this_object()); }
if(c == 2) {move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object()); }
if(c == 3) {move_object(clone_object(ROOT+"newstuff/mon/gloom.c"),this_object()); }
if(c == 4) {move_object(clone_object(ROOT+"newstuff/mon/doomdrifter.c"),this_object()); }
   }
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Ghost Ward"+NORM+")");
    long_desc=
"               "+BOLD+"Children's Pathway"+NORM+" (north, south)\n"+
     "Children's Pathway runs north and south here, alongside a large\n"+
     "stone building, its walls mostly undamaged amidst all the ruin.\n"+
"Most of the arena is covered in a thick ash, burning the walls\n"+
"and everything on the street itself.\n";

    items=({
     "building","The building looks as if it has been taken care of\n"+
                "since the destruction of Qual'tor. The entrance of the\n"+
                "appears to be on its northside",
     "mountain","The mountain in the distance is getting pounded by the\n"+
                "lightning and storms about its peak",
     "clouds","You are glad you are not within the fury of the storm",
     "peak","The peak of the mountain is obscured by the clouds",
     "walls","The walls of the building should be blackened from fire",
    });

    dest_dir=({
      "/players/daranath/qualtor/child_path5.c","north",
      "/players/daranath/qualtor/child_path3.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_south","south");
 if(find_call_out("ash") == -1)
   call_out("ash", random(10) + 3);
    }

    search(){
write("Everything in the area is covered with a thick layer of dark ash.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


dar_south() {
   write("You feel a sense of relief as you head back into\n\n"+
      "              "+HIW+"CITY WARD"+NORM+"\n\n"+
      "You are able to relax a bit being back in civilized areas.\n\n");
   return 0;
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
