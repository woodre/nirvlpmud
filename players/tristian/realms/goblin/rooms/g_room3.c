#include "/players/tristian/lib/goblin_define.h"
inherit "/players/vertebraker/closed/std/room.c";
int found;
int dig;
int climb;
int rope;

reset(arg) {
    if(arg) return;

      dig = 0;

      set_light(1);

      short_desc = "Goblin Trash Heap";

      long_desc =
          " The large trash pile in the center of this area leads you\n"+
          "to believe this is a garbage heap. Lying around the area\n"+
          "are half eaten carcasses and various other debris.  Flies buzz\n"+
          "all around, and the smell is noxious, almost makeing vomiting\n"+
          "necessary even from 20 yards away. There is a tower strategically\n"+
          "nestled among the trees on the far side of the heap. The sunlight\n"+
          "shining on the heap of disgusting debris glitters like a sparkling\n"+
          "diamond.\n";

      items = ({
          "carcasses",
              "Half eaten dead bodies, humanoid in appearance",
          "flies",
              "Common flies that buzz around your face",
          "fly",
              "Common flies that buzz around your face",
          "glitter",
              "Something buried in the trash, perhaps you\n"+
              "should 'dig' through it....",
          "dirt",
              "Dirt. Plain old ordinary dirt",
          "trash",
              "debris and garbage",
          "debris",
              "trash and garbage",
          "garbage",
              "GARBAGE - you know GARBAGE!",
          "pile",
		  "A large pile of smelly garbage",
          "heap",
		  "A large heap of smelly garbage",
          "tower",
              "A crude tower with a rope ladder hanging from it",
          "ladder",
              "A rope ladder with wooden rungs, perhaps you\n"+
              "can 'climb' the 'rope'",
          "rope",
              "A rope ladder with wooden rungs, perhaps you\n"+
              "can 'climb' the 'rope'",
          "pines", 
              "Evergreen pines well over 100' tall",
          "forest",
              "An array of hardwoods and evergreens with a dazzaling display\n"+
              "of light that falls down through the tree tops that tower far above",
          "trees",
              "Tall pines, that have probably been growing since this forest was new", 
  });


      if(!present("wolf1",this_object()))
          move_object(
              clone_object(NPC+"wolf1.c"),
          this_object());

      if(!present("wolf2",this_object()))
          move_object(
              clone_object(NPC+"wolf1.c"),
          this_object());

      dest_dir = ({
           RMS+"g_room1.c", "east",
   
  });

}

init() {
    ::init();
        add_action("dig_garbage","dig");
        add_action("climb","climb");
        add_action("Smell","smell");
        add_action("Search","search");
        
}

     dig_garbage()   {
         if(dig == 0)   {
              write("You dig around in the disgusting junk and find a sword.\n");
              say (this_player()->query_name() +" searches through the garbage. \n");
         move_object(
              clone_object("/players/tristian/realms/goblin/obj/goblin_sword.c"),this_object()); 
         dig = 1;
              return 1; 
          
}

     else    {
         write("You search the garbage and find nothing except things you wish you hadn't.\n"+
               "Maybe there wasn't a glitter.\n");
         say(this_player()->query_name() +" digs through the garbage to no avail.\n");
             return 1;

  }
}

    climb(str)   {
         if(!str)   {
             write("Climb what?\n");
         return 1;
}

     if(str == "rope") {
          write("You climb up into the tower.\n");
          say (this_player()->query_name() +" climbs the rope into the tower.\n");
     move_object(
         this_player(),"/players/tristian/realms/goblin/rooms/tower.c");
     command("look",this_player()); 
         return 1;
}

     write("Climb what?\n");
         return 1;
}

    Smell(str)   {
         if(!str || str == "air")   {
             write("The smells of rotting vegetation and meat assails your nostrils.\n");
         return 1;
}
     return 1;
}

    Search()   {
         write("You find nothing special.\n");
    return 1;
}
