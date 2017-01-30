#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "room/room";

#include "/players/jaraxle/ansi.h"





reset(arg) {

if(!present("cont_dragon", this_object())){

move_object(clone_object("/players/jaraxle/cont/mobs/rdragon1.c"), this_object());

move_object(clone_object("/players/jaraxle/cont/mobs/rdragon1.c"), this_object());

}

  if(arg) return;

set_light(1);



short_desc = "The Caves of the "+HIR+"Red"+NORM+RED+"Dragon Clan"+NORM;

long_desc =

"  This is a long tunnel that leads deeper into the volcanic\n"+

"mountain.  The walls here glow with a red light and give off\n"+

"a terrible heat. The tunnel continues to the east and west.\n";



items = ({

"walls",

"Smooth black volcanic rock walls. They are covered in several\n"+

"cracks that glow",

"cracks",

"Large cracks that have formed in the rock walls. Looking closer\n"+

"you see that lava flows from within, lending light and heat to\n"+

"the area",

"light",

"A glowing red light that is emitted from the cracks in the walls",

});



dest_dir = ({

  "/players/jaraxle/cont/rdragon/rooms/r12.c","west",

  "/players/jaraxle/cont/rdragon/rooms/r10.c","east",



});



}



/* Thanks Feldegast for providing an easy template for messages */



int peeps;



void init() {

  ::init();

  peeps++;

  add_action("no_west", "west", 1);

  if(find_call_out("flames") == -1)

   call_out("flames", random(10) + 3);

  }



no_west(){

if(present("cont_dragon", this_object())){

write("The Red Dragon blocks you from going deeper into the volcano!\n");

return 1;

}

return;

}



void exit() {

  peeps--;

  if(peeps <= 0)

    while(remove_call_out("flames") != -1) ;

  }



void flames() {

  object ob,next;

  string msg;



  switch(random(4)) {

    case 0: msg= "A terrible heat fills the room.\n"; break;

    case 1: msg= "Molten rock leaks from a nearby crack and oozes onto the floor.\n"; break;

    case 2: msg= "There is a light hiss as steam slips from a crack.\n"; break;

    case 3: msg= "The light flickers slightly as molten rock flows.\n"; break;

    }

  tell_room(this_object(),msg);

  call_out("flames", random(10) + 3); 

  }

