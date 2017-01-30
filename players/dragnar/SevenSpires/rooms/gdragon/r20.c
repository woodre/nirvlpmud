inherit "room/room";
#include <ansi.h>
#include "/players/dragnar/SevenSpires/defs.h"

int coins;
string *scrolls;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIG+"Green "+NORM+GRN+"Dragon Clan"+NORM;
long_desc =
"  This is a large open cavern hidden within the side of the\n"+
"volcano's rim. Scattered across the floor are piles of bones\n"+
"and bits of armor and clothing. A large altar stands at the\n"+
"far side of the room. Large amounts of steam rise up and out\n"+
"the gap you entered from.\n";

items = ({
"floor",
"A smooth floor with bones, bits of armor and clothing scattered\n"+
"across it's surface",
"bones",
"Human and animal remains that are half chewed and broken up",
"armor",
"The chewed remains of iron and leather armor",
"clothing",
"Short scraps of clothing that are now useless",
"altar",
"A huge marble altar that is caked with blood and remains of\n"+
"past sacrifices. A large gold and silver symbol is hanging\n"+
"over it on the wall",
"symbol",
"The symbol is of a huge serpent intertwined around a flaming\n"+
"cloud.  It appears as though something can be inserted into\n"+
"the center of the stars that are over the scene",
"stars",
"A cluster of stars shining as bright as the sun",
"steam",
"Huge gusts of steam that rise up and out the gap",
"gap",
"A large gap in the wall that leads back out to the rim of the\n"+
"volcano", 
});

dest_dir = ({
  "/players/dragnar/SevenSpires/rooms/gdragon/r18.c","out",
});

}

init(){
 ::init();
 add_action("insert", "insert");
 }

insert(str){
if(!str){ write("insert what into what?\n"); return 1; }
if(str == "scimitar into stars"){
  if(present("scimitar_green_dragon", this_player())){
    write("You insert the scimitar into the stars on the symbol...\n");
    scrolls = get_dir( SCROLLDIR+"/*.c" );
    destruct(present("scimitar_green_dragon", this_player()));
    call_out("start", 4);
    }
  else{ write("You don't have that!\n"); return 1; }
  }
else{ write("insert what into what?\n");
      return 1;
}
return 1;
}
   
start(){
 tell_room(this_object(),
 "\nThe ground begins to shake and bits of rock fall from the ceiling...\n\n");
 call_out("next1", 6);
 }

next1(){
 tell_room(this_object(),
 "\nThe altar begins to slowly move aside...\n\n");
 call_out("next2", 6);
 }

next2(){
  tell_room(this_object(),
  "\nAs the altar slides over, you catch a glimpse of something shining behind it...\n\n");
  call_out("next3", 6);
  }

next3(){
object coins1;
object coins2;
object coins3;
object coins4;
object coins5;
object coins6;
int i;

  tell_room(this_object(),
  "\nSuddenly, as the altar screeches to a halt, treasure pours from the wall behind it\n"+
  "and scatters into the room at your feet!\n\n");
  coins1 = clone_object("obj/money");
  coins1->set_money(random(5000) + 10000);
  move_object(coins1, this_object()); 
  coins2 = clone_object("obj/money");
  coins2->set_money(random(5000) + 10000);
  move_object(coins2, this_object());
  coins6 = clone_object("obj/money");
  coins6->set_money(random(5000) + 10000);
  move_object(coins6, this_object());
  coins3 = clone_object("obj/money");
  coins3->set_money(random(5000) + 10000);
  move_object(coins3, this_object());
  coins4 = clone_object("obj/money");
  coins4->set_money(random(5000) + 10000);
  move_object(coins4, this_object());
  coins5 = clone_object("obj/money");
  coins5->set_money(random(5000) + 10000);
  move_object(coins5, this_object());

  move_object( clone_object( SCROLLDIR +"/"+scrolls[random(sizeof(scrolls))] ), this_object());
  move_object( clone_object( SCROLLDIR +"/"+scrolls[random(sizeof(scrolls))] ), this_object());
  move_object( clone_object( SCROLLDIR +"/"+scrolls[random(sizeof(scrolls))] ), this_object());
  return 1;
}
