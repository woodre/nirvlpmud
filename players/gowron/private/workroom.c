inherit "room/room";

reset(arg) {
  if(arg) return;
   set_light(1);
   short_desc = "Gowron's Lounge";
   long_desc = format("72 degrees and well lit are the first things that strike you as you enter this room. There are chairs to your left, and a long sofa on your right. There is a desk and a chair over in the far corner of this room. This place appears to be ideal for relaxation, conversation, and some occasional work.", 72);
   dest_dir = ({ "room/church", "church",
              "players/balowski/guild/room/grotto", "grotto",
           "room/adv_guild", "advance", });
}
