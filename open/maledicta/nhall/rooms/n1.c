#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
	
set_light(1);

short_desc = "Hall of Apprentices [Main]";
long_desc =
"  You stand within the main Hall of the Apprentices. The walls here\n"+
"are made of a white stone, each block carefully laid and set in a\n"+
"silver mortar. The marble floor is polished to a high shine, and\n"+
"large banners hang from the ceiling.  To the west is the healer of\n"+
"the apprentices, and to the east is the halls armory.  A long spiral\n"+
"staircase leads up to the halls portal chamber. A large door leads\n"+
"out to the main road.\n"; 

items = ({
"walls",
"Polished white rock which is carefully laid in a silver mortar",
"stone",
"A heavy strong stone that is nearly unbreakable",
"mortar",
"An enchanted mortar that holds the hall together",
"floor",
"A polished marble floor that you can even see your reflection in",
"banners",
"Heavy cloth banners with the symbols of powerful lords imprinted in gold upon\n"+
"their surface",
"ceiling",
"A high ceiling made of stone.  A spiral staircase disappears into its\n"+
"center",
"staircase",
"A long marble staircase leading up to the portal chamber"
});

dest_dir = ({
  "/players/maledicta/nhall/rooms/n2.c","west",
  "/players/maledicta/nhall/rooms/n3.c","east",
  "/players/maledicta/nhall/rooms/n4.c","up",
  "/room/vill_green.c","out"
});

}
init(){
 ::init();
if(this_player()->query_level() > 5 && this_player()->query_level() < 20){
		write("You don't belong here!\n");
        move_object(this_player(), "/room/vill_green.c");
        tell_room(environment(tp), tpn+" arrives suddenly.\n", ({tp}));
        command("look", this_player());
	}
if(this_player()->query_level() < 20){
if(this_player()->query_guild_exp() || this_player()->query_guild_name() ||
   this_player()->query_guild_rank()){
        write("You don't belong here!\n");
        move_object(this_player(), "/room/vill_green.c");
        tell_room(environment(tp), tpn+" arrives suddenly.\n", ({tp}));
        command("look", this_player());
	}
}
}