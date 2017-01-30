#define REALM call_other(environment(this_player()), "realm", 0)
 
inherit "obj/treasure";
 
reset(arg)  {
  if(arg) return;
 
   set_id("glider");
   set_short("An ether-glider");
   set_long(
"One of Snow's fabled ether-gliders. As you grasp the handle, you feel\n"+
"you could travel quickly through the ether.. if only you knew the \n"+
"commands...There are a series of glyphs on the wings.. perhaps if you\n"+
"concentrate you could 'read' them.\n");
   set_weight(1);
   set_value(400);
}
 
init()   {
  add_action("read", "read");
  add_action("glide","glide");
  add_action("drop", "drop");
   }
 
read(str){
  if(str == "glyphs")  {
 
  write(
   "As you peer at the glyphs, a wave of comprehension washes over\n"+
   "you. You realize that with a little mental energy you could use this\n"+
   "device to transport yourself quickly and safely through the ether. \n"+
   "All you have to do is 'glide' to one of these preset destinations-\n"+
   "Church\n"+ "Shop\n"+ "Hotel\n"+ "Lockers\n"+ "Pub\n"+ 
   "Snow's 'Gate'\n"+ "Saber's 'Ryllian'\n"+ "Hippo's '51' game room\n");
 
    return 1;   }
        }
 
glide(arg) {
if(REALM !="NT")  {
  if(!(arg == "church" || arg == "shop" || arg == "hotel"
    || arg == "lockers" || arg == "pub" || arg == "mountain"
    || arg == "ryllian" || arg == "51")) {
       write("That is not a valid destination.\n");
       return 1;
  }
    say(capitalize(this_player()->query_name()) +
       " takes off into the ether in a glider.\n");
    write("You take off into the ether.\n"+"\n");
    write("You are chilled to the bone as you glide through the ether.\n"+"\n"+
            "You return from the ether...\n");
  if(arg == "church") {
  call_other(this_player(), "move_player", "#room/church.c"); }
  if(arg == "shop") {
  call_other(this_player(), "move_player", "#room/shop"); }
  if(arg == "hotel") {
  call_other(this_player(), "move_player", "#players/boltar/hotel/hotel.c"); }
  if(arg == "lockers") {
  call_other(this_player(), "move_player", "#players/catwoman/tl.c"); }
  if(arg == "pub") {
  call_other(this_player(), "move_player", "#room/pub2"); }
  if(arg == "mountain") {
  call_other(this_player(), "move_player", "#room/plane10"); }
  if(arg == "ryllian") {
  call_other(this_player(), "move_player", 
"#players/saber/ryllian/ryllian1.c"); }
  if(arg == "51") {
  call_other(this_player(), "move_player", "#players/hippo/games/fo_room.c"); }
    write("You glide softly to the ground.\n");
    say(call_other(this_player(),"query_name") + 
          " glides from nothingness into the room.");
  call_other(this_player(), "add_spell_point", -40);
return 1;  }
    write("The ether-access seems to be shut off at this point in space.\n");
return 1;
}
drop(str) {
    if (str == "all") {
        drop_object("glider");
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The glider rips into tiny ether-shreds as you drop it.\n");
    destruct(this_object());
    return 1;
}
