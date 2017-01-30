#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {

  if(arg) return;
set_light(1);

short_desc = "Templar Inner Chamber";
long_desc =
"  This is a magical room in the Knights Castle. Here\n"+
"you can feel safe from those that might lie in wait\n"+
"for you to enter the world. To leave this place, go\n"+
"down.";

dest_dir = ({
  "/players/maledicta/templar/rooms/adv_inner.c","down",
});

}

init(){ 
  ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



realm(){ return "NT"; }


