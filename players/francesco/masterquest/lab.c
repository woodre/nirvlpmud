#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

long_desc =
 "   The basement laboratory is a wide open area, just divided in three \n"+
 "subzones by colored lines painted on the floor.  They can be accessed by \n"+
 "typing their name.  A sign on a stand shows their names.  Some students \n"+
 "and technicians work here and there.\n",

items = ({
     "laboratory","Wide open area, about 60 by 40 feet large",
     "area","Wide open area, about 60 by 40 feet large",
     "subzones","They are delimited by colored lines painted on the floor",
     "lines","They delimitate the different zones of the laboratory",
     "floor","The floor is made of tiles and shiny",
     "students","They seem very busy and concentrated on their work",
     "technicians","They are wearing overalls",
     "overalls","Blue dresses, sturdy and comfortable",
     "sign","It reports:  machining, foundry, computer",
});

dest_dir = ({
/*    "/players/francesco/masterquest/machining.c","machining",
    "/players/francesco/masterquest/foundry.c","foundry",
    "/players/francesco/masterquest/computer.c","computer",*/
    "/players/francesco/univ/rooms/dimec18.c","up"

});
}

init() {
::init();
    add_action("machining","machining");
    add_action("foundry","foundry");
    add_action("computer","computer");
}

machining() {
 int a,b,c;
  object *inv;
  object room;
   room= "players/francesco/masterquest/machining.c";
    inv = all_inventory(room);
     if((c = sizeof(inv) > 0))
      {
      for(b = 0; b < c; b++)
       {
        if(inv[b]->is_player() && inv[b]->query_level()<20){
         write("The machining lab is already in use.\n");
         return 1;}
       }
      }
   this_player()->move_player("to the machining lab#players/francesco/masterquest/machining.c");
   return 1;
}

foundry() {
 int a,b,c;
  object *inv;
  object room;
   room= "players/francesco/masterquest/foundry.c";
    inv = all_inventory(room);
     if((c = sizeof(inv) > 0))
      {
      for(b = 0; b < c; b++)
       {
        if(inv[b]->is_player() && inv[b]->query_level()<20){
         write("The foundry lab is already in use.\n");
         return 1;}
       }
      }
   this_player()->move_player("to the foundry lab#players/francesco/masterquest/foundry.c");
   return 1;
}

computer() {
 int a,b,c;
  object *inv;
  object room;
   room= "players/francesco/masterquest/computer.c";
    inv = all_inventory(room);
     if((c = sizeof(inv) > 0))
      {
      for(b = 0; b < c; b++)
       {
        if(inv[b]->is_player() && inv[b]->query_level()<20){
         write("The machining lab is already in use.\n");
         return 1;}
       }
      }
   this_player()->move_player("to the computer lab#players/francesco/masterquest/computer.c");
   return 1;
}
short() {return ""+"Basement laboratory";}  

