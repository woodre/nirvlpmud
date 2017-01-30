
inherit "room/room";

reset(arg){


 if(!arg){

 set_light(1);
 short_desc="Killing ground";
 long_desc=
("You are between walls 5 and 6.  From one side of the pass to the\n"+
"other you see nothing but grass.  The walls here are much taller\n"+
"blocking your view of everything else.  There are no obstructions\n"+
"here that would block the flight of an arrow.  As you look up at\n"+
"wall 5 you can see how even a few archers could be devastating\n"+
"to attackers, and provide a shield of protection for troops\n"+
"retreating from wall 6.  Just the thought of thousands of arrows\n"+
"falling like rain around you makes you shudder.\n");

items=({
"ground","Lush green grass covers the ground here",
"wall 5","Not quite as big as wall 6, it is still impressive",
"wall 6","It resembles the great wall of China, only taller",
 });

  dest_dir=({
"/players/traff/room/wall1.c","north",
"/players/traff/room/wall6.c","south",
      });
  }   }


init()  {
 ::init();
  add_action("north","north");
}


north()  {

  write("You approach the gate in wall 5.\n");
  write("You pass through the gate and continue north.\n");
  write("You keep going, through gates 4, 3, 2, and 1.\n");
  write("You climb the few short stairs to the top of the wall.\n");

call_other(this_player(),"move_player","north#players/traff/room/wall1.c");
 return 1;
         }
