#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int a, b, c, peeps;

reset(int arg){
 b = random(3);
if(b < 2) {
 c = random(5);
if(!present("gravemon")) {
if(c == 0) {move_object(clone_object(ROOT+"newstuff/mon/gloom.c"),this_object()); }
if(c == 1) {move_object(clone_object(ROOT+"mon/drifter.c"),this_object()); }
if(c == 2) {move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object()); }
if(c == 3) {move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object()); }
if(c == 4) {move_object(clone_object(ROOT+"newstuff/mon/doomdrifter.c"),this_object()); }
   }
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Ghost Ward"+NORM+")");
    long_desc=
"               "+BOLD+"North Road"+NORM+" (east, west)\n"+
"North Road runs east and west along the northern edge of the city. At\n"+
"one point, the roadway itself marked the border of Qual'tors limits, but\n"+
"someone has since constructed a large citadel to the north of here.\n"+
"The lack of traffic in the area makes North Road rather secluded now.\n";

    items=({
"road","The north road is made of crushed rock and stone",
"roadway","The north road is made of crushed rock and stone",
"edge","This used to be the northern edge of the city, but someone has\n"+
     "punched hole through the outer wall leading to a large citadel\n"+
     "looking building to the north",
"citadel","A large stone building, it looks more like a fortress then any\n"+
     "living quarters within Qual'tor",
    });

    dest_dir=({
  "/players/daranath/qualtor/newstuff/citadel/entry.c","north",
      "/players/daranath/qualtor/grif_flight4.c","east",
      "/players/daranath/qualtor/nor_road1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_north","north");
add_action("dar_east","east");
if(find_call_out("ash") == -1)
 call_out("ash", random(10) + 3);
    }

    search(){
write("Everything in the area is covered with a thick layer of dark ash.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_north(){
write("The "+BOLD+"Citadel of the Black Zodiac"+NORM+" is not open yet.\n"+
      "   Coming Soon...    -Daranath\n");
return 1; 
}

dar_east() {
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

