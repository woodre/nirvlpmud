/* More damage, after all, you are in the hole itself */

#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";
int a, peeps;

reset(int arg){
if(!present("demon")) {
move_object(clone_object(ROOT+"mon/pit_lord.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"Demonic Lair"+NORM+")");
    long_desc=
"               "+HIR+"Demonic Lair"+NORM+"\n"+
"The heat from the ashen lair can be quite overwhelming to those with a lesser\n"+
"constitution. Large gaps and openings within the rocks themselves spew hot\n"+
"ash into the chamber, while gouts of pure demonic flame rise twice the height\n"+
"of a man from the floor. Not a place you would like to make your home.\n";

    items=({
"lair","The ashen lair was once a natural cavern, coverted by a demon to be home",
"cavern","The cavern has been warped into hell furnace itself",
"gaps","The gaps in the floor vent ash into the room",
"openings","The gaps in the floor vent ash into the room",
"ash","The dark ash covers everything within this area",
"floor","The natural floor of the cavern is covered in ash and soot",
"soot","The dark ash covers everything with soot",
"flame","The demonic flames rise high into the air, burning everything nearby",
"gouts","The demonic flames rise high into the air, burning everything nearby",
    });

    dest_dir=({
ROOT+"rift4.c","south",
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
         if(a > 0) ob->hit_player(9, "other|fire");
      ob=next;
   }
   call_out("ash", random(10) + 3); 
}
