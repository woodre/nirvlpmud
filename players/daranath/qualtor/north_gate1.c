#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";
int a, b, peeps;

reset(int arg){
b = random(3);
if(b == 0) {
if(!present("giant")) {
move_object(clone_object(ROOT+"mon/dstone1.c"),this_object());
move_object(clone_object(ROOT+"mon/dstone2.c"),this_object());
move_object(clone_object(ROOT+"mon/dstone2.c"),this_object());
  }
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(North Gate)");
    long_desc=
"               "+BOLD+"Children's Pathway"+NORM+" (south)\n"+
     "The northern gateway stands as it did during Qual'tor's glory,\n"+
     "still watching over the north end of the cities great wall.\n"+
     "Stone towers flank an enormous archway, although the drawbridge\n"+
     "has long since rotted away. A strong iron door leads into the\n"+
     "gateway's complex. The archway leads south into the city and\n"+
     "north into the wilds of Nirvana.\n";

    items=({
     "door","The iron door is in good shape, and still looks like it is used",
     "stone","The stone of the towers is a dark grey in color",
     "tower","A pair of identical tower rise up along either side of the archway,\n"+
             "protecting the northern gateway from invaders",
     "towers","A pair of identical tower rise up along either side of the archway,\n"+
              "protecting the northern gateway from invaders",
     "archway","The stone archway has many arrow slits facing north as well as\n"+
               "multiple murder holes looking down upon the sparse courtyard",
     "drawbridge","The drawbridge is gone, having rotted away from neglect",
    });

    dest_dir=({
      "/players/daranath/qualtor/nor_qual1.c","north",
      "/players/daranath/qualtor/war_way1.c","south",
      "/players/daranath/qualtor/gateway1.c","tower",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_tower","tower");
add_action("dar_north","north");
if(find_call_out("ash") == -1)
 call_out("ash", random(10) + 3);
    }

    search(){
write("Everything in the area is covered with a thick layer of dark ash.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_tower() {
    write("You do not have the proper key for the tower's door.\n");
     return 1;
    }

dar_north() {
if(present("giant")) {
write("The Darkstone Giant prevents you from moving northwards.\n");
return 1; }
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
         if(a > 1) ob->hit_player(2, "other|fire");
      ob=next;
   }
   call_out("ash", random(10) + 3); 
}
