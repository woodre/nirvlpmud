#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
inherit "room/room";

int a, b, c, peeps;

reset(int arg){
 b = random(3);
if(b < 2) {
 c = random(5);
if(!present("ghostmon")) {
if(c == 0) {move_object(clone_object(ROOT+"newstuff/mon/gloom.c"),this_object()); }
if(c == 1) {move_object(clone_object(ROOT+"mon/drifter.c"),this_object()); }
if(c == 2) {move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object()); }
if(c == 3) {move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object()); }
if(c == 4) {move_object(clone_object(ROOT+"newstuff/mon/doomdrifter.c"),this_object()); }
   }
}
if(b == 2) {
if(!present("ghostmon")) {
move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object());
move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object());
   }
}
   if(!arg){
      
      set_light(1);
      short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Ghost Ward"+NORM+")");
      long_desc=
"               "+BOLD+"Old Road"+NORM+" (north, south)\n"+
      "Old road continues from here, traveling north and south across\n"+
      "Qual'tor. A large and rusted iron gate rests on the eastern\n"+
      "side of the roadway, it has not been opened for over twenty\n"+
      "years. The gate leads into the old keep, where the ruling family\n"+
      "of Qual'tor lived before the destruction of the city. Burnt and\n"+
      "useless, the keep is just a shadow of its former glory.\n";
      
      items=({
            "road","The old road is made of stone and gravel",
            "gate","The iron gateway once led into the keep of Qual'tor, where\n"+
            "the ruling family was kept in safety during times of warfare\n"+
            "about the area. The many treasures of Qual'tor were also\n"+
            "kept in safe keeping here",
            "keep","The great stone keep was like a small castle within the\n"+
            "city itself. During times of warfare, it was capable of\n"+
            "holding the majority of the populace within, as well as\n"+
            "enough food for several months", });
      
      dest_dir=({
            "/players/daranath/qualtor/old_road3.c","north",
            
            "/players/daranath/qualtor/old_road2.c","south", });
      
   }
}
/* Ash code from Feldegast via Maledicta, thanks to both */
init(){
   ::init();
   add_action("search","search");
   add_action("open","open");
   add_action("dar_south","south");
   if(find_call_out("ash") == -1)
      call_out("ash", random(10) + 3);
}

dar_south() {
   write("You feel a sense of relief as you head back into\n\n"+
      "              "+HIW+"CITY WARD"+NORM+"\n\n"+
      "You are able to relax a bit being back in civilized areas.\n\n");
   return 0;
}
search(){
write("Everything in the area is covered with a thick layer of dark ash.\n");
   say(tp +" searches the area.\n");
   return 1;
}

open(){
   write("That would be impossible, for the gateway is rusted in place.\n");
   say(tp +" tries to open the gateway.\n");
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

