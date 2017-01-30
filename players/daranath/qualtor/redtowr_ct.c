#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";
int a, b, peeps;

reset(int arg){
b = random(4);
if(b < 3) {
if(!present("priest")) {
move_object(clone_object(ROOT+"mon/highpriest.c"),this_object());
  }
}
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+WHT+"Ghost Ward"+NORM+")");
    long_desc=
     "Once within the small wall that protects the Red Tower from stragglers,\n"+
     "you notice that the damage on the top couple of levels does not seem\n"+
     "so bad. The upper levels are in fact intact, despite how they\n"+
     "looked from the street. A small archway leads into the tower,\n"+
     "while a field of force seems to be protecting the tower.\n";

    items=({
     "wall","The low stone wall protects the tower from vermin and beggars",
     "levels","The top two levels looked destroyed from the street, but\n"+
             "thier appearance changed once you entered the gateway",
     "gate","The gate leads back to the street",
     "tower","The tower is made from a dark red stone",
     "stair","The small stair leads up and down",
     "staircase","The staircase leads to the top of the tower, while\n"+
                 "it also plummets into the darkness below",
     "field","The field of force seems to be protecting the tower from\n"+
             "the ash falling about the city",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr1.c","in",
      "/players/daranath/qualtor/child_path5.c","leave",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_in","in");
if(find_call_out("ash") == -1)
 call_out("ash", random(10) + 3);
    }

    search(){
    write("The area had long since been abandoned, and nothing of note is present.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_in() {
write("\nThe field envelopes you as you enter the Red Tower, protecting you\n"+
      "from the ash falling about the city.\n\n");
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
         if(a > 1) ob->add_hit_point(-3);
      ob=next;
   }
   call_out("ash", random(10) + 3); 
}

