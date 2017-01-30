/*
 nautilus_bridge.c - bridge of the submarine nautilus
*/

#include "/players/nooneelse/sea/nautilus_rooms.h"

inherit "room/room";

object captain;
string what, trip_out_desc, trip_in_desc;
int nbr, nautilus_is_docked;

init() {
  ::init();

  add_action("out", "out");
}

out() {
  if (!query_nautilus_docked()) {
    what=this_player()->query_gender();
    if (what=="male") what="Sir";
    if (what=="female") what="Madam";
    if (what=="other") what="Creature";
    write("A crewman stops you, saying:\n"+
          "   You can't go out on deck until we're back in port "+what+".\n");
    return 1;
  }
  return;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a strange metal ship");
  no_castle_flag=1;
  long_desc="You're at the bridge of a strange metal ship.\n";
  items=
    ({
      "walls", "They are steel plates, with large rivets.",
      "wall", "They are steel plates, with large rivets.",
      "floor", "It is made of steel plates, covered with a beautiful carpet.",
      "carpet", "It is a richly colored persian rug.",
      "rug", "It is a richly colored persian rug.",
      "ceiling", "They are steel plates, with light panels set in them.",
      "lights", "They are some kind of translucent material that are "+
                "glowing with light.",
      "panels", "They are some kind of translucent material that are "+
                "glowing with light.",
      "panel", "It is some kind of translucent material that is "+
               "glowing with light.",
      "light panels", "They are some kind of translucent material that are "+
                      "glowing with light.",
    });
  dest_dir=
    ({
      "players/nooneelse/sea/nautilus_deck","out",
      "players/nooneelse/sea/nautilus_below_deck","down",
    });
  if (!find_living("nautilus captain")) {
    captain = clone_object("players/nooneelse/sea/nautilus_captain_nimo");
    move_object(captain, this_object());
  }
  nbr=0;
  nautilus_is_docked=1;
  enable_commands();
  call_out("sea_out", 60);
  return;
}

query_nautilus_docked() { return nautilus_is_docked; }

tell_ship(str) {
  tell_room(BELOW_DECK, str);
  tell_room(BRIDGE, str);
  tell_room(NIMO, str);
  tell_room(CHART_ROOM, str);
  tell_room(DECK, str);
  tell_room(ENGINE_ROOM, str);
  tell_room(OBSERVATION_ROOM, str);
}

docked() {
  tell_ship("The Captain shouts: We are in port!\n");
  return 1;
}

submerge() {
  tell_ship("\nThe Captain shouts: Dive!  Dive!  You feel light as "+
            "the ship goes down.\n\n");
  tell_room(OBSERVATION_ROOM,
            "\nOut the ports, you see water bubbling furiously as the\n"+
            "Nautilus starts to go below the surface.\n\n");
  tell_room(OBSERVATION_ROOM, trip_out_desc[nbr]);
  what="You see the water bubble furiously as the Nautilus starts\n"+
       "to go below the surface.\n";
  if (nautilus_is_docked==1) tell_room(BLUEENTRY, what);
  if (nautilus_is_docked==2) tell_room(ISLAND_DOCK, what);
  nautilus_is_docked=0;
}

surface() {
  tell_ship("\nThe Captain shouts: Surface!  You feel a light pressure on\n"+
            "your feet as the ship goes up.\n\n");
  tell_room(OBSERVATION_ROOM,
            "\nOut the ports, you see water bubbling furiously as the\n"+
            "Nautilus starts to raise to the surface.\n\n");
  tell_room(OBSERVATION_ROOM, trip_in_desc[nbr]);
  what="You see the water bubble furiously as the Nautilus starts\n"+
       "to rise to the surface.\n";
  if (nautilus_is_docked==1) tell_room(BLUEENTRY, what);
  if (nautilus_is_docked==2) tell_room(ISLAND_DOCK, what);
}

/* outbound trip */
sea_out() {
  if (!trip_out_desc) fill_trip_desc();
  tell_room(OBSERVATION_ROOM, "\nThrough the observation ports you can see:\n");
  if (!nbr) submerge();
  nbr = nbr + 1;
  tell_room(OBSERVATION_ROOM, trip_out_desc[nbr]);
  if (nbr==4) {
    tell_ship("\nYou hear the Captain shout: Fire on those sharks!\n");
    tell_room(OBSERVATION_ROOM,
          "You hear the throbbing of the engines raise deafeningly and see\n"+
          "what looks like a red beam of light flash from the nose of the\n"+
          "Nautilus to strike one of the sharks.  It writhes, then stops\n"+
          "moving.\n");
  }
  if (nbr==5) {
    tell_ship("\nYou hear the Captain shout: Again!  Fire on the other one!\n");
    tell_room(OBSERVATION_ROOM,
          "The pitch of the noise from the engines raises again as another\n"+
          "red beam flashes from the nose of the Nautilus to strike the\n"+
          "remaining shark.  It writhes, then stops moving.\n");
    tell_ship("You hear the Captain shout: Yes!  Nice shooting!\n");
  }
  if (nbr==9) {
    nautilus_is_docked=2;
    surface();
    nbr=0;
    call_out("sea_in", 60);
  }
  else
   call_out("sea_out", 10);
  return 1;
}

/* return trip */
sea_in() {
  if (!trip_out_desc) fill_trip_desc();
  tell_room(OBSERVATION_ROOM, "\nThrough the observation ports you can see:\n");
  if (!nbr) submerge();
  nbr = nbr + 1;
  tell_room(OBSERVATION_ROOM, trip_in_desc[nbr]);
  if (nbr==4) {
    tell_ship("\nYou hear the Captain shout: Charge the hull!\n");
    tell_room(OBSERVATION_ROOM,
          "You hear the throbbing of the engines raise deafeningly and see\n"+
          "what looks like blue lightning flash across the hull outside the\n"+
          "ports.  The squid writhes, but maintains its grip.\n");
  }
  if (nbr==5) {
    tell_ship("\nYou hear the Captain shout: Again!  Full capacity!\n");
    tell_room(OBSERVATION_ROOM,
          "The pitch of the noise from the engines raises again as another\n"+
          "arc of blue lightning crawls over the hull and the squid.  It\n"+
          "loosens its grip and falls away.\n");
    tell_ship("You hear the Captain say: That'll keep the bugger away!\n");
  }
  if (nbr==9) {
    nautilus_is_docked=1;
    surface();
    nbr=0;
    call_out("sea_out", 60);
  }
  else
   call_out("sea_in", 10);
  return 1;
}

fill_trip_desc() {
  trip_out_desc = allocate(10);

  trip_out_desc[0]="You see a lot of spindly red coral.  Dozens of\n"+
                   "tiny fish flash away at the Nautilus' approach.\n";
  trip_out_desc[1]="The ship submerges further.  You can now see sturdier\n"+
                   "white corals with dozens of star fish moving over them.\n";
  trip_out_desc[2]="The ship levels out and you can now see frenzied\n"+
                   "movement as several barracuda hunt and among the\n"+
                   "smaller fish.\n";
  trip_out_desc[3]="Several schools of fish and a couple of squid come\n"+
                   "flashing past in the opposite direction you're heading!\n";
  trip_out_desc[4]="There!  Ahead!  There are two sharks attacking a young\n"+
                   "humpbacked whale!\n";
  trip_out_desc[5]="The whale is swimming as fast as it can on a course that\n"+
                   "parallels that of the Nautilus, trying to outrun the\n"+
                   "remaining shark!\n";
  trip_out_desc[6]="The whale swims close to the Nautilus and lightly\n"+
                   "bumps noses with it, then swims tiredly away.\n";
  trip_out_desc[7]="The Nautilus is overtaking several schools of fish\n"+
                   "and a couple of manta rays that are racing swiftly\n"+
                   "in the direction you're heading.\n";
  trip_out_desc[8]="The ocean floor seems to be getting closer.  You can\n"+
                   "now see sturdier white corals with dozens of crabs\n"+
                   "moving over them.\n";
  trip_out_desc[9]="The ship starts to raise.  You see a lot of spindly\n"+
                   "red coral.  Several schools of tiny fish flash away\n"+
                   "at the Nautilus' approach.\n";

  trip_in_desc = allocate(10);

  trip_in_desc[0]="The ship starts down.  You see a lot of spindly\n"+
                  "red coral.  Several schools of tiny fish flash away\n"+
                  "at the Nautilus' approach.\n";
  trip_in_desc[1]="The ocean floor seems to be getting closer.  You can\n"+
                  "now see sturdier white corals with dozens of crabs\n"+
                  "moving over them.\n";
  trip_in_desc[2]="You see several schools of fish and a couple of\n"+
                  "manta rays that are starting to drift away from\n"+
                  "each other.\n";
  trip_in_desc[3]="You can barely see a young humpbacked whale in the\n"+
                  "distance as it swims sluggishly away.\n";
  trip_in_desc[4]="You see several barracuda flashing around the corpse\n"+
                  "of a shark.  What?  The ship jars as you see a giant\n"+
                  "squid attach itself to the nose of the Nautilus!\n";
  trip_in_desc[5]="You hear several ominous creaking noises from the\n"+
                  "ports as the squid applies pressure with its tentacles.\n"+
                  "Behind it you can see another group of barracuda tearing\n"+
                  "savagely into the remains of another shark.\n";
  trip_in_desc[6]="You see several schools of fish and a couple of squid\n"+
                  "come starting to swim lazily away from each other.\n";
  trip_in_desc[7]="The ship starts to raise and you can now see frenzied\n"+
                  "movement as several barracuda hunt and among the\n"+
                  "smaller fish.\n";
  trip_in_desc[8]="The ship raises further.  You can now see sturdier\n"+
                  "white corals with dozens of star fish moving over them.\n";
  trip_in_desc[9]="You see a lot of spindly red coral.  Dozens of\n"+
                  "tiny fish flash away at the Nautilus' approach.\n";
}
