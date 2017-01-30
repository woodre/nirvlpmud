inherit "room/room";
reset(arg) {
if(!present("board"))
  move_object(clone_object("/players/grimm/closed/obj/badge_stuff/ninjboard"),this_object());
if(arg) return;
short_desc="Ninja's Faction Party Room";
long_desc="This is the Ninja's Party Room.  You are obviously in\n"+
"the guild so this is the place for you to mingle with everybody and spend\n"+
"some time away from the scum of the mud since only the chosen can enter this\n"+
"room.\n";
dest_dir=({
           "/players/grimm/nguild","east",
           "/room/church","church",
           "/room/shop","shop",
           "/players/grimm/guild","doppguild",
           "/room/adv_guild","adventures",
           "/room/pub2","pub",
           "/players/grimm/nguild","guild",
           });
}
 
init() {
  if((!present("Dopple-Ninja",this_player()) && !this_player()->query_npc())
     || environment(this_player())->id("cloud")) {
    write("YOU ARE NOT A NINJA!\nOnly the chosen will be allowed to enter this room!\n");
    say(capitalize(this_player()->query_real_name())+" tried to enter the room but gets kicked out!\n");
    move_object(this_player(),"/players/grimm/nguild");
    write("Join our guild before entering the faction's party room.\n");
    return 1;
  }
  ::init();
}
