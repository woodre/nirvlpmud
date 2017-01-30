#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
inherit "room/room";

int a, b, c, peeps;

reset(int arg){
 b = random(2);
if(b == 0) {
if(!present("reaver")){
move_object(clone_object(ROOT+"newstuff/mon/reaver.c"),this_object()); 
  }
}
   if(!arg){
      
      set_light(1);
      short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Ghost Ward"+NORM+")");
      long_desc=
"               "+BOLD+"Warrior's Way"+NORM+" (east, west)\n"+
"The Way of the Warrior continues here, travelling east and west\n"+
"along the northern end of the city. The walkway was built to\n"+
"commemorate those who gave thier lives fighting for the city,\n"+
"and a large statue remains here, a grim reminder of better\n"+
"times.\n";
      
      items=({
"statue","The large statue shows a gruesome scene of a group of gaurdsmen from\n"+
     "the city fought against many orcs, goblins, and ogres\n"+
     "while defending the city. It is quite impressive",
"walkway","The walkway is made of stone and gravel",
  });
      
      dest_dir=({
 "/players/daranath/qualtor/old_road4.c","east",
   "/players/daranath/qualtor/war_way1.c","west",
    });
      
   }
}
/* Ash code from Feldegast via Maledicta, thanks to both */
init(){
   ::init();
   add_action("search","search");
   if(find_call_out("ash") == -1)
      call_out("ash", random(10) + 3);
}

search(){
write("Everything in the area is covered with a thick layer of dark ash.\n");
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

