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
if(c == 0) {move_object(clone_object(ROOT+"newstuff/mon/gloom.c"),this_object()); }
if(c == 1) {move_object(clone_object(ROOT+"mon/drifter.c"),this_object()); }
if(c == 2) {move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object()); }
if(c == 3) {move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object()); }
if(c == 4) {move_object(clone_object(ROOT+"newstuff/mon/doomdrifter.c"),this_object()); }
if(b == 0) {
move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object()); }
   }
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Ghost Ward"+NORM+")");
    long_desc=
"               "+BOLD+"Children's Pathway"+NORM+" (north, south)\n"+
     "At the northern end of Children's Pathway, the destruction of\n"+
     "Qual'tor does not look so bad. A large stone building sits to the\n"+
     "east from here, a small alley opening in front of it. The path\n"+
"leads north and south from here, the entire street covered in a\n"+
"thick layer of hot ash.\n";

    items=({
     "building","The building looks as if it has been taken care of\n"+
                "since the destruction of Qual'tor. The entrance of the\n"+
                "appears to be on its northside",
     "alley","The alley is commonly known as Scimitar Alley as its\n"+
             "known to be home to ruffians and thieves",
     "walls","The walls of the building should be blackened from fire",
    });

    dest_dir=({
      "/players/daranath/qualtor/war_way1.c","north",
      "/players/daranath/qualtor/child_path4.c","south",
  "/players/daranath/qualtor/redtowr_ct.c","enter",
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
