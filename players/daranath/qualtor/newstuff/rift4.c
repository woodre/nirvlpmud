/* More damage, after all, you are in the hole itself */

#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";
int a, peeps;

reset(int arg){
if(!present("corpse")) {
move_object(clone_object(ROOT+"obj/pet_corpse.c"),this_object());
}
move_object(clone_object(ROOT+"mon/golem_ash.c"),this_object());
move_object(clone_object(ROOT+"mon/golem_ash.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"Demonic Lair"+NORM+")");
    long_desc=
"               "+HIR+"Demonic Lair"+NORM+"\n"+
"The demonic lair continues here, a short tunnel leading from one large chamber\n"+
"to the next. Light streams from the northern chamber, natural flames casting\n"+
"brightly down the length of the tunnel itself. The dark ash that plagues the\n"+
"Ghost Ward of Qual'tor is abundant here, the northern chamber obviously\n"+
"the source of the ash.\n";

    items=({
"lair","The demonic lair is split into two distinct chambers seperated by a short\n"+
     "tunnel. The natural stone is covered in dark ash",
"tunnel","The short tunnel is naturally formed",
"chambers","The two chambers are naturally formed, one north and one south of here",
"chamber","The two chambers are naturally formed, one north and one south of here",
"ash","The dark ash streams from the northern chamber into the tunnel and out into the\n"+
     "Ghost Ward of Qual'tor",
"flames","The flames are casting light down the tunnel",
"light","Flickering light fills the short tunnel",
    });

    dest_dir=({
ROOT+"pit_lair.c","north",
ROOT+"rift.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_block","north");
if(find_call_out("ash") == -1)
 call_out("ash", random(10) + 3);
    }

dar_block() {
if(present("golem")) {
write("The Ashen Golem blocks your way, it doesn't want you to head north.\n");
return 1; }
return 0;
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

if(a == 0) {msg = "Hot ash settles about the demonic chamber.\n"; }
if(a == 1) {msg = "The "+HIR+"heat"+NORM+" from the chamber is overwhelming.\n"; }
if(a == 2) {msg = "The "+HIR+"flames"+NORM+" within the chamber burn brightly.\n"; }
if(a == 3) {msg = "The "+HIR+"flames"+NORM+" within the chamber burn your flesh.\n"; }
if(a == 4) {msg = "The "+BOLD+BLK+"Dark Ash"+NORM+" chokes everything within the chamber.\n"; }
 

  tell_room(this_object(),msg);
   ob=first_inventory(this_object());
   while(ob) {
      next=next_inventory(ob);
      if(living(ob) && ob->is_player() && !present("br_scarf", ob))
         if(a > 0) ob->hit_player(8, "other|fire");
      ob=next;
   }
   call_out("ash", random(10) + 3); 
}
