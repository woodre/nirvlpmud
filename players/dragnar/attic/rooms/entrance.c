inherit "room/room";
object tyme, sign;
init() {
	::init();
   add_action("reset_scar_obj","reset_scar_obj");
   add_action("ask","ask");
}
exit() {
  if(this_player())
    this_player()->clear_fight_area(); }
reset(arg) {
if(!present("tyme",this_object())){
    tyme = clone_object("players/dragnar/mons/tyme.c");
move_object(tyme, this_object());
        }
        if(!present("sign",this_object())){
        sign=clone_object("players/dragnar/items/sign.c");
move_object(sign, this_object());
        }
	if(arg) return;
set_light(1);
short_desc=("Entrance to the Wastelands");
long_desc=
"As you look to the sky you notice that the sun is blocked by what seems\n" +
"to be a huge cloud.  As you look north the land looks almost barren\n" +
"and you wonder what could have caused the land to turn into these wastelands.\n"+
"Maybe you should go back to a time were things are safe and secure...\n",
items=
({
});
dest_dir=
({
"players/dragnar/rooms/arena.c","north",
"room/sunalley2","back",
});
}

ask( string str ) {
  if( !str ) {
    write("Tyme says: Perhaps you want to ask about the scar or the quest?\n");
    return 1;
  }
  write("You ask: "+str+"\n");
  say(capitalize(this_player()->query_name())+" asks: "+str+"\n");
  return 1;
}
reset_scar_obj()
{
    object      gob;
  string name;

  if(!this_player()->query_interactive() ) return 1;
  name = lower_case(this_player()->query_name());
  if(!present("tyme", this_object())) {
    write("Tyme isn't here to help you.\n");
    return 1;
  }
   if(present("bloodscar", this_player())) {
      write("Tyme screams: You already have a scar, fool!\n");
      return 1;
   }

   if( restore_object("players/dragnar/kills/" + name) ) {
    gob = clone_object("players/dragnar/closed/scar");
    move_object(gob, this_player());
      write("Tyme says: Your scar has been returned.\n");
        return 1;
    }
   write("Tyme says:  Sorry, can't help you.\n");
   write("Tyme says: Perhaps Dragnar could assist in this matter?\n\n");
    destruct(gob);
    return 1;
}
