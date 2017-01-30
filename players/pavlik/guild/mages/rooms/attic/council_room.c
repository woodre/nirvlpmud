#include "/players/pavlik/guild/mages/rooms/ROOMS"
#include <ansi.h>
inherit "room/room";
int shields;

reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Mage's Tower";
long_desc="The Mage's Tower";

items=({
"walls",
"The high sweeping walls of the chamber are empowered with ancient spells.\n"+
"You know that absolutely noone could enter this chamber uninvited.\n",
"glyph",
"The glyph symbolizes the power and unity of the Circle of Mages.  The\n"+
"image is carved into the marble floor and is larger than 50 feet.\n",
"floor",
"The floor is contructed of black marble.  The glyph for the Circle of\n"+
"Mages is carved into the marble.\n",
});

  shields = 0;

  if(!present("table", this_object()))
    move_object(clone_object("players/pavlik/guild/mages/obj/council_table"), this_object());
  }

}

long() {
write(
"The Mages Council Chamber.  This high-domed chamber resides somewhere\n"+
"amongst the fringes of reality.  You know you are now beyond the boundries\n"+
"of the mortal Universe.  The sweeping walls are empowered with ancient\n"+
"spells of protection and privacy.  The atmosphere holds a sense of powerful\n"+
"magic and importance.  A large askeon-wood table stands in the center of\n"+
"the room.  There is a circular glyph of power inscribed on the floor.\n");
if(shields == 1) 
  write("The glyph glows brightly.  The chamber is closed to others.\n");
else
  write("The glyph is dark.  The chamber is open to all members.\n");

return;
}

query_mguild(){ return "Council Chamber"; }
set_shields(i){ shields = i; }
query_shields(){ return shields; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("open_session","deactivate");
  add_action("close_session","activate");
  security_check();
}

open_session() {
  if(!("players/pavlik/guild/mages/mage-master2")->is_gc()) return 0;

  if(shields == 0) {
    write("The power glyph is not active.\n");
    return 1;
  }

  write(
  "With a word of magic and a wave of the hand the Power Glyph deactivates.\n");
  say(capitalize(this_player()->query_real_name())+
  " deactivates the Power Glyph.\n"+
  "The council chamber is now open to all members.\n");

  shields = 0;
  if(present("board", this_object())) {
    destruct(present("board", this_object()));
    tell_room(this_object(), "The council's board distingrates.\n");
  }

  return 1;
}

close_session() {
  object ob;
  int i;

  if(!("players/pavlik/guild/mages/mage-master2")->is_gc()) return 0;

  if(shields == 1) {
    write("The power glyph is already active.\n");
    return 1;
  }

  write("You activate the Power Glyph.\n");
  say(capitalize(this_player()->query_real_name())+" activates the Power Glyph.\n");
  tell_room(this_object(), "The circular power glyph burns brightly.\n");

  shields = 1;

  ob = all_inventory(environment(this_player()));
  for(i=0; i<sizeof(ob); i++) {
    if(living(ob[i])) {
      if(!("players/pavlik/guild/mages/mage-master2")->is_gc(ob[i])) {
        tell_room(environment(this_player()),
        capitalize(ob[i]->query_name())+" is escorted out.\n");
        move_object(ob[i], "players/pavlik/guild/mages/rooms/guild_room5");
      }
    }
  }

  if(!present("board", this_object())) {
    move_object(clone_object("players/pavlik/guild/mages/obj/gc_board"), this_object());
    tell_room(this_object(), "The council's board appears.\n");
  }

  return 1;
}
 
security_check(){
  if(!this_player()->is_player()) {
    if(this_player()->query_mage_pet())
      return 1;
    else {
      tell_room(this_object(),
      "The walls blaze with light and "+
      capitalize(this_player()->query_name())+" disappears.\n");
      destruct(this_player());
      return 1;
    }
  }
  else if(!this_player()->query_guild_name() == "mage" ||
          !present("mageobj", this_player())) {
    tell_room(this_object(),
    "The walls blaze with light and "+
    capitalize(this_player()->query_real_name())+" disappears!\n");
    move_object(this_player(), "room/void");
    return 1;
  }
  else if(shields == 1 && !("players/pavlik/guild/mages/mage-master2")->is_gc()) {
    tell_object(this_player(),
    "You council chamber is sealed for a closed session.\n");
    move_object(this_player(), "players/pavlik/guild/mages/rooms/guild_room5");
    return 1;
  }
}

