#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);
short_desc = "Portal Room "+BOLD+"["+HIY+"Tower of Hope"+NORM+BOLD+"]"+NORM;
long_desc = 
"  This is the portal room of the Tower of Hope. The walls are\n"+
"made of a white stone, as well as the ceiling and floor. A large\n"+
"stone archway stands in the center of the room, connecting the\n"+
"tower to the Templars Castle. A doorway leads south to the inner\n"+
"chamber.\n";

items = ({
"walls",
"The walls are made from a beautiful white stone, bound by a glittering\n"+
"mortar.  Numerous holy symbols adorn each stone, binding and protecting\n"+
"the tower from harm",
"stone",
"A beautiful white stone",
"symbols",
"Small holy symbols etched into the stone",
"ceiling",
"A white stone ceiling, bound by a glittering mortar",
"floor",
"The floor here is made of the same white stone as the ceiling\n"+
"and walls",
"archway",
"A beautiful archway made of white stone and carrying a powerful\n"+
"charge of blue energy between its pillars.\n"+
"You can [enter] it anytime to be transported to the Templar Castle",
"doorway",
"A small doorway leading to the inner chamber",
});


dest_dir = ({
  "/players/maledicta/hope/rooms/hinner.c","south",
});

}
init(){
::init();
add_action("enter_it", "enter");
}


enter_it(str){
if(str != "archway"){
write("You cannot enter that!\n");
return 1;
}
if(!present("KnightInvite", this_player())){
write("You bounce off of the portal!\n");
return 1;
}
tell_room(this_object(),
this_player()->query_name()+" walks through the portal and disappears in a flash.\n");
move_object(this_player(), "/players/maledicta/templar/rooms/adv_inner.c");
command("look", this_player());
tell_room(environment(this_player()),
this_player()->query_name()+" appears in a flash of light.\n");
return 1;
}
no_hunter(){ return 1; }
