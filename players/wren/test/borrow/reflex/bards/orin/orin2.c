#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("sign")){
move_object(clone_object("players/saber/food/orinpub.c"),this_object());
}
 if(!arg){
  set_light(1);
short_desc="Orin's Common Room";
long_desc=
 "This is the common room of Orin's Inn, where adventurers of all stations and\n"+
 "status may socialize in comfort.  The Inn is dimly lit both by the massive\n"+
 "fireplace to the east and the lanterns hung upon the north wall.  The heat\n"+
 "from the fires has brought the temperature of the room to a very comfortable\n"+
 "level, giving the entire chamber a relaxing aura.  Every object in the Inn\n"+
 "has been carved from a dark mahogany wood; the tables, the chairs and even\n"+
 "the huge mugs filled with Orin's renown Dark Ale.  A comely barmaid maneuvers\n"+
 "through the common room, delivering drinks to patrons from the bar located\n"+
 "to the north.  There is a polished wooden sign on the wall and a beautifully\n"+
 "crafted wooden door to the south.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "fireplace","A large fire, blazing in the hearth in the room to the east",
"chamber","You are in the common room of Orin's Inn",
 "mugs","Dark mahogany mugs filled with Orin's famed Dark Ale",
 "lantern","Small brass lanterns attached onto the walls",
 "wood","A deep, beuatiful dark mahogany wood imported from the forest of dreams",
 "mahogany","A deep, beuatiful dark mahogany wood imported from the forest of dreams",
 "table","One of several large mahogany tables - perhaps you can 'sit' at it",
 "chair","One of several mahogany chairs - perhaps you can 'sit' in it",
 "barmaid","A comely barmaid who brings patrons their drinks",
 "bar","There is a bar located to the north, with several patrons leaning up against it",
 "door","An exquisite mahogany door leading south.\n"+
  "It is covered with beautiful elvish symbols and letters",
 "Inn","You are in the common room of Orin's Inn",
 "lanterns","Small brass lanterns attached onto the walls",
 "fire","A large fire, blazing in the hearth in the room to the east",
 });

  dest_dir=({
 "/players/reflex/guilds/bards/orin/orin1.c","west",
 "/players/reflex/guilds/bards/orin/orin3.c","north",
 "/players/reflex/guilds/bards/orin/orin4.c","east",
 "/players/reflex/guilds/bards/bardrooms/enterance.c","up",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
   add_action("sit","sit");
   add_action("read","read");
   add_action("south","south");
   add_action("translate_elvish","translate");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

sit(str) {
if (str == "chair"){
write("You sit down in a mahogany chair.\n");
say(tp+" sits down in a mahogany chair.\n");
 return 1;   }
if (str == "table") {
write("You sit down at one of the mahogany tables.\n");
say(tp+" sits down at one of the mahogany tables.\n");
  return 1;}
if (str == "floor") {
write("You sit down on the floor.\n");
say(tp+" sits down upon the floor.\n");
  return 1;
}
else {
write("Sit where?\n");
say(tp+" looks for a place to sit down.\n");
 return 1;
}
}
read(str) {
if (str == "door") {
write("You can't read this style of elvish.\n");
say(tp+" looks at the runes on the door to the south.\n");
  return 1;
}
else {
write("The light is too dim here to read.\n");
 return 1;
}
}

south() {
write("You cannot seem to open the door.\n");
say(tp+" tries to open to door to the south.\n");
  return 1;
}

translate_elvish(str)  {
object ob;

 if(!str || str != "elvish")  {
  write("Translate what?\n");
  return 1;
        }
 ob = present("instrument",this_player());
if(!present("instrument",this_player()))  {
  write("You can not seem to translate the elvish.\n");
  return 1;
        }
if(ob->query_approval() != 9){
  write("You are not approved for this task yet.\n");
  return 1;
  }
if(this_player()->query_level() < 18)  {
  write("You are not high enough level to do this trial.\n");
  return 1;
        }

if(ob->query_bard_level() !=8)  {
  write("You must be bard level 8 to do this trial.\n");
  return 1;
        }

call_other(this_player(), "move_player","south#players/reflex/guilds/bards/bardrooms/hades_q.c");
 command("begin",this_player());
  return 1;
        }
