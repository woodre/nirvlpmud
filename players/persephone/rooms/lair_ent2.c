inherit "/players/persephone/closed/thingys.c";
reset (arg){
 if (arg) return;
  set_light(1);
  short_desc="Cave Entrance";
  long_desc="You have just stumbled into a smooth cave entrance. To the Northwest\n" +
            "you see the cave open up and from outside of the cave in the distance\n" +
            "you hear the sound of waves breaking against the rocks. The floor is \n" +
            "quite flat here while the ceiling and walls seem to join at a great\n" +
            "height.\n"; 
 dest_dir=({"players/persephone/rooms/drag_lair2","northwest",
             "players/persephone/rooms/beach6","out"
  });
}
realm() { return "NT"; }
