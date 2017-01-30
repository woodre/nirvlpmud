#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/iceangel.c"), this_object()); }
  if(arg) return;
set_light(0);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   This rooms appears to be an old practice room.  Burned and torn\n"+
"practice dummies are spread throughout the dark room.  Ashes and\n"+
"partial remains of mats can be found covering the floor.  The walls\n"+
"and ceiling here are surprisingly intact.  Archways leading to other\n"+
"rooms can be found to the north and west.\n";

items = ({
  "dummies",
  "Once used for practice with wooden weapons, they are\n"+
  "now useless moldy burnt bags",
  "dummy",
  "A wobbly looking dummy that looks like it has been pushed\n"+
  "too many times",
  "mats",
  "You barely recognize them as such, but a single corner of\n"+
  "one reveals it to be a once heavily used practice mat",
  "floor",
  "It is covered in ash and thick soot",
  "walls",
  "The walls here are blackened from the fire, but surprisingly"+
  "untouched. Proof the fire was concentrated into areas",
  "ceiling",
  "The ceiling here is only slightly blackened as if small fires"+
  "had burned briefly and yet savagely beneath it",
  "remains",
  "You look carefully and see that they are what is left of\n"+
  "several old practice mats. They are torn and burned almost\n"+
  "beyond recognition",
  "ash",
  "Proof that some horrible fire raged throughout this room",
  "soot",
  "Proof that some horrible fire raged throughout this room"
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r6.c","north",
  "/players/maledicta/ruins/rooms/r5.c","west",
});

}


init(){
	::init();
	if(this_player())
		if(present("clan_symbio", this_player())){
			write(HIR+"\n\n\nAs a member of the clan, you may 'push dummy' here.\n\n\n"+NORM);
	        add_action("backroom", "push");
		}
}

backroom(str){
if(!present("clan_symbio", this_player())) return;
if(this_player()->query_attack()) return 0;
if(!str){ write("Push what?\n"); return 1; }
if(str == "dummy"){
move_object(this_player(), "/players/maledicta/ruins/rooms/backroom2");
tell_object(this_player(), "You enter the secret lair of Clan Incognito.\n");
command("look", this_player());
return 1;
}
write("Push what?\n");
return 1;
}