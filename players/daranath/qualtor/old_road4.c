/* Damage from ash is increased here, due to proximity to demonic hole
   combined with a change for 2 glooms and the gloom asssassin, should make
   for a somewhat dangerous room    -dar   */

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
move_object(clone_object(ROOT+"newstuff/mon/gloom_assassin.c"),this_object());
move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object());
move_object(clone_object(ROOT+"newstuff/mon/gloom2.c"),this_object());
   }
}
   if(!arg){
      
set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Ghost Ward"+NORM+")");
long_desc=
"               "+BOLD+"Old Road"+NORM+" (south)\n"+
"               "+BOLD+"North Road"+NORM+" (east)\n"+
"               "+BOLD+"Warrior's Way"+NORM+" (west)\n"+
"Old road ends at the ruins of the crystal tower in the northern\n"+
"region of Qual'tor. The tower was once one of the grandest sights\n"+
"in all of Nirvana, but now there is little more then,\n"+
"crystalline rubble strewn all about.\n"+
"A large grey stone sticks from the earth\n";
      
items=({
 "tower","The tower is nothing but a pile of crystal shards\n"+
 "A small path leads "+HIR+"<"+NORM+"around"+HIR+">"+NORM+" the tower",
 "rubble","The crystal shards that make up the rubble have no value",
 "ruins","The ruins are that of the crystal tower",
 "stone","A large grey stone juts from the ground as if forced out\n"+
     "by nature itself. The stone has an inscription on it which\n"+
     "you can "+HIR+"<"+NORM+" read "+HIR+">"+NORM+" while here",
});
      
dest_dir=({
  ROOT+"old_road3.c","south",
  ROOT+"nor_road1.c","east",
  ROOT+"war_way2.c","west",
});
      
   }
}
/* Ash code from Feldegast via Maledicta, thanks to both */
init(){
   ::init();
   add_action("search","search");
add_action("move_around","around");
add_action("read_stone","read");
   if(find_call_out("ash") == -1)
      call_out("ash", random(10) + 3);
}

search(){
write("Everything in the area is covered with a thick layer of dark ash.\n");
   say(tp +" searches the area.\n");
   return 1;
}

read_stone() {
    write("The stone's inscription reads:\n\n"+
          "Angels have the powers of the light...\n\n"+
          "The Fallen have the powers of shadow...\n\n"+
          "The Pyromancers have the powers of flame...\n\n"+
          "The Fury have the powers of ice...\n\n"+
          "Warders have the powers of the soul...\n\n"+
          "A Necromancer has the power of death...\n\n"+
          "Druids have the powers of nature...\n\n"+
          "-Taken from the writings of Agamonar,\n"+
 "    Historian of Qual'tor\n\n"+
          "The children of the crystals shall bring\n"+
          "Qual'tor's glory back in full....\n\n"+
          "-is scrawled at the base of the stone\n");
    say(tp +" reads the grey stone's inscription.\n");
     return 1;
}

move_around() {
write("You traverse the path around the back of the tower.\n");
this_player()->move_player("around the tower#/players/daranath/qualtor/back.c");
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
         if(a > 1) ob->hit_player(4, "other|fire");
      ob=next;
   }
   call_out("ash", random(10) + 3); 
}

