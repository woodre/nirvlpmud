
inherit "room/room";

reset(arg){

if(!present("guard"))  {
move_object(clone_object("/players/traff/mon/kguard.c"),this_object());  }

if(!present("rose"))  {
move_object(clone_object("/players/traff/mon/flower_girl.c"),this_object());  }

 if(!arg){

 set_light(1);
 short_desc="Delnoch";
 long_desc=
("You stand on the grounds of one of the mightiest fortresses ever\n"+
"built, Delnoch Pass.  Far to the north you see the Skoda mountains\n"+
"that this fortress defends.  To the south are the 6 walls\n"+
"that span the pass and protect it from the tribesmen of the\n"+
"southern plains.  Nearby you see the Keep to the north.\n"+
"Wall 1 is South of you.  To the West is a small tavern and\n"+
"to the East is an arena.\n");

items=({
"ground","The ground is dirt that has been hard packed from much traffic",
"mountains","The mountains rise steadily to the north.  You see snow capped peaks",
"walls","Between sheer cliffs, 6 walls span the pass controlling access",
"plains","Beyond the walls semi-arrid plains stretch as far as you can see",
"keep","Once the residence of the Earl of Bronze, it now houses minions of Casca",
"tavern","A small tavern.  It could be a good place to rest and gather information",
"arena","It looks like a place for some sort of sporting events",
"cliffs","Grey stone cliffs tower above the pass",
 });

  dest_dir=({
"/players/traff/room/kentry.c","north",
"/players/traff/room/wall1.c","south",
"/players/traff/room/arena.c","east",
"/players/traff/room/tavern.c","west",
"/room/eastroad3.c","leave",
      });
  }   }


init()  {
 ::init();
  add_action("north","north");
  add_action("search","search");
}


north()  {

if(present("guard"))  {
  write("Guard says: No one may enter!\n");
 say("Guard prevents "+this_player()->query_name()+"from going north\n");
return 1;
     }
call_other(this_player(),"move_player","north#players/traff/room/kentry.c");
 return 1;
         }
search(str)  {

  if(str=="room" || str=="floor" || str=="ground") {
  write("You search the "+str+" but find nothing of interest.\n");
    return 1; }

    write("Search what?\n");
  return 1; }
