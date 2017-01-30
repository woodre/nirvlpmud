/* More damage, after all, you are in the hole itself */

#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";
int a, peeps;

reset(int arg){
move_object(clone_object(ROOT+"mon/ash_grind.c"),this_object());
move_object(clone_object(ROOT+"mon/ash_grind.c"),this_object());
move_object(clone_object(ROOT+"mon/ash_grind.c"),this_object());
move_object(clone_object(ROOT+"mon/ash_grind.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"Demonic Lair"+NORM+")");
    long_desc=
"               "+HIR+"Demonic Lair"+NORM+"\n"+
"A large natural chamber has been revealed by the hole leading down from the \n"+
"North Road in Qual'tor. Its dark grey stone walls are typical of the region,\n"+
"while a short tunnel leads northwards, towards a strong light source.\n";

    items=({
"chamber","The natural cavern opens into a tunnel leading northwards",
"cavern","The natural cavern opens into a tunnel leading northwards",
"ash","The dark ash covers everything within the cavern, and streams upwards out\n"+
     "into the Ghost Ward itself",
"stone","The dark grey stone is typical of the area around Qual'tor",
"region","The area is known as the CityState of Qual'tor",
"light","The light is coming from the tunnel itself, flickering as if flame",
"source","The light is coming from the tunnel itself, flickering as if flame",
"walls","The natural stone walls of the cavern show signs of extreme heat and\n"+
     "abuse by otherworldly life forms",
"tunnel","A short, natural stone tunnel leads north to a second chamber",
    });

    dest_dir=({
ROOT+"rift4.c","north",
/*
ROOT+"rift1.c","south",
ROOT+"rift2.c","east",
ROOT+"rift3.c","west",
*/
"/players/daranath/qualtor/nor_road1.c","up",
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
if(present("grinder")) {
write("The Ashen Grinder blocks your way, it doesn't want you to leave.\n");
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
