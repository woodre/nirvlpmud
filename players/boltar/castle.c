#define NAME "The gates of The Big House are to the west"
#define DEST "room/forest3"

object plob,sqr,pcmd;
object gate, clc, trail, clock;
object harm,quest;

id(str) { return str == "house" || str == "big house"; }

short() { return NAME; }
long() {
   write("\n\n\n");
   write("You are just inside the gates of the Big House.\n");
   write("Before you stands the large and once magificent Big House. The \n"+
  "the meaning of its name seems to come from its size, however there may\n"+
  "be more to it than that.  You remember an old legend from your childhood\n"+
  "about an old house where anyone or anything that entered was forced to \n"+
  "remain there for the rest of their years.There also stories of unreal\n"+
  "creatures that looked more like the drawings of some deranged artist\n"+
  "and not like a creature at all.  You feel some fear, yet your curiousity\n"+
  "is pulling you closer and closer to the enterance.  More and more you\n"+
  "wonder what is behind those old stories. But you can't decide if it's\n"+
  "worth the risk. \n");
  plob = environment(this_player());
  write("\n");
  write("\n");
  if (plob == this_object()) 
    write("You may enter (west) the house or leave (east) the grounds.\n");
}

init() {
  add_action("enter", "enter");
  add_action("west", "west");
  add_action("leave", "leave");
  add_action("leave", "east");
    /* call_other("room/forest3.c", "short", 0);*/
   }
reset(arg) {
  move_object(this_object(), DEST);
/* see if this is what ld don't like -Bp
  log_file("FTP.log", "----<break line to force log to break at 50k>----\n");
*/
  if(!present("gates")) {
    gate = clone_object("players/boltar/things/gates.c");
    move_object(gate, "room/forest3");
  }
  call_other("room/slope", "short", 0);
  if(!present("trail", find_object("room/slope.c"))) {
    trail = clone_object("players/boltar/santaland/trail.c");
    move_object(trail, "room/slope");
  }
  if(!present("ring", find_object("room/quest_room.c"))) {
    quest = clone_object("obj/quest_obj.c");
    call_other(quest, "set_name", "ring");
    call_other(quest, "set_hint", "find the legion decoder ring that was hidden below and put it in its rightful\n"+
    "place\n");
    move_object(quest, "room/quest_room.c");
  }
  call_other("players/boltar/sprooms/moneyroom.c", "short", 0);
  if(!present("harmonica", find_object("players/boltar/sprooms/moneyroom.c"))) {
    harm = clone_object("players/boltar/things/thi6.c");
    move_object(harm, "players/boltar/sprooms/moneyroom");
    move_object(clone_object("players/boltar/things/amulet"),"players/boltar/sprooms/moneyroom");
    move_object(clone_object("players/boltar/motel/key"),"players/boltar/sprooms/moneyroom"); 
    move_object(clone_object("players/boltar/casino/key"),"players/boltar/sprooms/moneyroom");
  }
  if(!present("boobs", find_object("players/boltar/sprooms/moneyroom.c"))) {
    pcmd = clone_object("players/boltar/sprooms/clinic/boobs.c");
    move_object(pcmd, "players/boltar/sprooms/moneyroom");
  }
  call_other("room/slope", "short", 0);
  if(!present("squirrel", find_object("room/slope.c"))) {
    sqr = clone_object("players/boltar/things/sqrl2.c");
    move_object(sqr, "room/slope.c");
  }
  call_other("room/clearing", "short", 0);
  if(!find_living("hoth monster")) {
    sqr=clone_object("players/boltar/things/hoth.c");
    move_object(sqr, "room/clearing.c");
  }
  call_other("room/pub3", "short", 0);
  if(!find_living("batarsis") || !environment(find_living("batarsis")) ) {
    sqr = clone_object("players/boltar/things/antipk.c");
    move_object(sqr, "room/pub3.c");
  }
  if(!present("anti-life", find_object("room/slope.c"))) {
    sqr = clone_object("players/boltar/things/life.c");
    move_object(sqr, "room/slope.c");
  }
  call_other("room/vill_road3", "short", 0);
  if(!present("clock", find_object("room/vill_road3.c"))) {
    clc = clone_object("players/boltar/things/clock_tower.c");
    move_object(clc, "room/vill_road3.c");
  }
  call_other("room/northroad2", "short", 0);
  if(!present("hotel", find_object("room/northroad2.c"))) {
    clc = clone_object("players/boltar/hotel/hotel_ent.c");
    move_object(clc, "room/northroad2.c");
  }
  call_other("room/southroad1", "short", 0);
  if(!present("motel", find_object("room/southroad1.c"))) {
    clc = clone_object("players/boltar/hotel/motel_ent.c");
    move_object(clc, "room/southroad1.c");
  }
}

west() {
  if(environment(this_player()) != this_object())
    call_other(this_player(),"move_player","through the gates#players/boltar/castle.c");
  else
    enter();
  return 1;
}

enter() {
  write("\n\n");
  write("As you near the large wooden doors, they swing open in front of you.\n"+
  "However you do not see anyone around who could have opened them.\n");
  write("\n\n");
  call_other(this_player(), "move_player", "into house#players/boltar/lv1/room1.c");
  return 1;
}
leave() {
  if(environment(this_player()) != this_object()) return 0;
  write("\n\n");
  write("As you walk through the gates and off the grounds you hear a loud\n"+
  "slaming sound.  Upon turning around to see what it was you notice\n" +
  "that the doors have been slammed behind you.\n\n\n");
   if(this_player())
   call_other(this_player(), "move_player", "into leaves#room/forest3.c");
 return 1;
}
is_castle(){
    return 1;
  }
