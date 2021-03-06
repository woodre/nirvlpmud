/* Newbie library. Uses a simple cat system to give information
   on locations of newbie areas.  Also can get a copy of Eurales
   Newbie book here. */

#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
	
set_light(1);

short_desc = "Hall of Apprentices [Library]";
long_desc =
"  This is the Library of the Hall. Lining the walls are\n"+
"numerous books containing information on the realm of\n"+
"Nirvana. A stairway leads down to the main hall. To the\n"+
"east is an archway leading to the Portal Chamber.\n"; 

items = ({
"archway",
"A stone archway that leads into the portal chamber",
"books",
"You find here a large leather bound book that you can\n"+
"'study'. You also see another book that you can 'grab' and\n"+
"take with you",
"walls",
"Polished white rock which is carefully laid in a silver mortar",
"stone",
"A heavy strong stone that is nearly unbreakable",
"mortar",
"An enchanted mortar that holds the hall together",
"floor",
"A polished marble floor that you can even see your reflection in",
"staircase",
"A long marble staircase leading down to the main chamber"
});

dest_dir = ({
  "/players/maledicta/nhall/rooms/n1.c","down",
  "/players/mythos/locker.c", "east",
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
add_action("read_book", "study");
add_action("get_book", "grab");
}

get_book(str){
if(!str){
write("grab what?\n");
return 1;
}
if(present("newbie_book", this_player())){
write("You already have one!\n");
return 1;
}

write("You take a small book from the shelf.\n");

move_object(clone_object("/players/eurale/newbie_book"), this_player());

return 1;
}


read_book(str){
if(!str){
write("read what?\n");
return 1;
}
if(str == "book"){
write(
"You open the large leather book and begin to read...\n\n"+
"You find the following topics available for reading:\n"+
"  [advance]     [shop]         [bandits]  [imps]\n"+
"  [mystic]      [zombieland]   [mash]     [snow]\n"+
"  [fire]        [dopple]       [manes]    [cathedral]\n"+
"  [gangster]    [hut]          [rats]\n\n"+
"\nTo find more information on any of these topics\n"+
"just: study <topic>.   GOOD LUCK!!!\n\n\n");
return 1;
}
cat("/players/maledicta/nhall/help/"+str+"");
return 1;
}

