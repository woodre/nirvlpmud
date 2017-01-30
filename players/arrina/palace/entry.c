inherit "room/room";
reset(arg) {
   if(!arg) {
      set_light(1);
      short_desc="Entry Hall";
      
      long_desc=
      "You are standing in the entry hall of a great castle. Before\n"+
      "you stands a massive archway with double wooden doors.\n"+
      "Near the archway begins a marble stairway that rises and\n"+
      "turns out of sight through a smaller archway. Doorways lead\n"+
      "to the left and right. In the center of the hall stands a carved\n"+
      "stone figure of a Paladin in full plate mail holding aloft a mighty\n"+
      "steel sword. The sword blazes with red holy fire that lights\n"+
      "the room.\n";
      
      items=({
          "doors","Solid wooden doors stand before you. They are unlocked",
          "stairway","This beautiful marble stairway leads to a small\n"+
          "archway set midway up the north wall",
          "statue"," The stone statue is of a mighty Paladin from the days when\n"+
            "their numbers were many and they were sworn to protect the\n"+
            "land and its people. Only a few of their order now remain",
          "figure"," The stone statue is of a mighty Paladin from the days when\n"+
            "their numbers were many and they were sworn to protect the\n"+
            "land and its people. Only a few of their order now remain",
          "paladin"," The stone statue is of a mighty Paladin from the days when\n"+
            "their numbers were many and they were sworn to protect the\n"+
            "land and its people. Only a few of their order now remain",
          "sword"," The sword burns with the holy fire of power and righteousness",
          "fire"," The sword burns with the holy fire of power and righteousness",
            });
      
      dest_dir=({
            "/players/arrina/palace/courtyard","north",
            "/players/arrina/palace/chapel","east",
            "/players/arrina/palace/sitting","west", 
            "/players/arrina/palace/walkway","up",
            });
   } }



