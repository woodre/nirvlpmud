#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

items = ({
"pool",
"You concentrate on the pool and find that you may do any of the\n"+
"following:\n"+
"   renew_symbiote   -  Get a new symbiote object. Use this to update\n"+
"                       or if you have lost your object.\n"+
"   news             -  Use this command to see any news on the guild",
});

dest_dir = ({
  "/players/maledicta/castle/rooms/m3.c","out",
});

}

short(){ return ""+BOLD+"Dark Matter"+NORM+""; }
long(){
write(

BOLD+"  You find yourself standing in a room made of dark matter.  The walls\n"+
"glisten in the dim light.  A small blackish pool stands in the center\n"+
"of the room."+NORM+"\n");
}

init(){
::init();
add_action("renew_object", "renew_symbiote");
add_action("news_stuff", "news");
}

renew_object(str){
if(tp->query_guild_name() != "symbiote") return 0;
if(!present("venom_object", tp)){
move_object(clone_object("/players/maledicta/venom/venom.c"), tp);
write("Your lost object has been restored...\n");
return 1;
}
else{
if(present("venom_object", tp)->query_venomed()){
write("You must return to normal shape first!\n");
return 1;
}
command("ssave", tp);
destruct(present("venom_object", tp));
move_object(clone_object("/players/maledicta/venom/venom.c"), tp);
write("Object updated...\n");
return 1;
}
return 1;
}

realm() { return "NT"; }

news_stuff(){
if(tp->query_guild_name() != "symbiote") return 0;
cat("/players/maledicta/venom/news");
return 1;
}
