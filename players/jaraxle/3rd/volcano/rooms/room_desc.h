#include "/players/jaraxle/define.h"

status jaraxle_volcano() { return 1; }

void get_random_short() {
  string COLOR;

  switch(random(4)){
    case 0: COLOR = HIR; break;
    case 1: COLOR = RED; break;
    case 2: COLOR = YEL; break;
    case 3: COLOR = HIY; break;
  }
  short_desc = COLOR + "A volcanic cave" + NORM;
}

void get_random_long() {
  string COLOR;
  switch(random(4)){
    case 0: COLOR = RED; break;
    case 1: COLOR = HIR; break;
    case 2: COLOR = HIY; break;
    case 3: COLOR = YEL; break;
  }

  switch(random(14)){
    case 0:
      long_desc = COLOR +
      "  A long, dark, warm cave.  The walls sweat with boiling\n" +
      "water.  Cracks line the walls like strikes of lightning\n"+
      "in the sky." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "walls", "Dark red-orange walls create a dark tunnel",
                 "tunnel", "A tunnel which leads forward to unknown",
                 "water", "Hot water leaking through the cracks",
                 "cracks", "Thin cracks throughout the walls",
              });
      break;
    case 1:
      long_desc = COLOR +
      "  A long, dark, hot cave.  There are stalactites which\n" +
      "grow down from the ceiling of the cave.  Water drips\n" +
      "slowly from some of the stalactites." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "walls", "Dark red-orange walls create a dark tunnel",
                 "stalactites", "Long slabs of rock growing from the ceiling",
                 "water", "Water slowly drips from some of the stalactites",
              });
      break;
    case 2:
      long_desc = COLOR +
      "  A long, dark, unbearably hot cave.  There are stalagmites which\n" +
      "grow up from the floor of the cave.  The ground is coverd\n"+
      "with dark orange sand." + NORM + "\n";
      items = ({ "sand", "Dark orange sand which is very dry",
                 "cave", "A dark cave about seven feet in height",
                 "stalagmites", "Jagged rocks that grow out of the ground",
              });
      break;
    case 3:
      long_desc = COLOR +
      "  A long, dark, warm cave.  There are stalactites which\n" +
      "grow down from the ceiling of the cave.  Water drips\n" +
      "slowly from some of the stalactites.  There are\n" +
      "stalagmites rising out of the ground." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "walls", "Dark red-orange walls create a dark tunnel",
                 "stalactites", "Long slabs of rock growing from the ceiling",
                 "stalagmites", "Jagged rocks that grow out of the ground",
                 "water", "Water slowly drips from some of the stalactites",
              });
      break;
    case 4:
      long_desc = COLOR +
      "  A dark, hot cave.  The air is thin and burns your\n" +
      "lungs at every breath.  Rocks are scattered around\n" +
      "the ground, making passage through the cave rather\n" +
      "difficult." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "rocks", "Rocks the size of softballs broken off from the" +
                          " cave walls.\nThe rocks make the floor of the" +
                          " cave hard to manage",
                 "walls", "Dark red-orange walls lined with cracks and grooves",
              });
      break;
    case 5:
      long_desc = COLOR +
      "  A dark, scalding hot cave.  The air is thin and burns your\n" +
      "lungs at every breath.  A thick cloud of dust floats\n" +
      "throughout the cave, hindering vision." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "dust", "A thick cloud of red-orange dust, lifted from" +
                         " the dry ground by short gusts of air",
                 "ground", "The ground is hard and dry.\n" +
                 "The dirt is easilly kicked up into dust clouds",
                 "walls", "Dark red-orange walls lined with cracks and grooves",
              });
      break;
    case 6:
      long_desc = COLOR +
      "  The darkness surrounds this deep cave.\n" +
      "Short, quick gusts of air whip by you, picking\n" +
      "up clouds of dust and tiny rocks." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "dust", "A thick cloud of red-orange dust, lifted from" +
                         " the dry ground by short gusts of air",
                 "ground", "The ground is hard and dry.\n" +
                           "The dirt is easilly kicked up into dust clouds",
                 "walls", "Dark red-orange walls lined with cracks and grooves",
              });
      break;
    case 7:
      long_desc = COLOR + 
      "  A deep dark cave.  Lichen grows over the rocks\n" +
      "that litter the ground.  There is a small crevice\n" +
      "on the ground." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "ground", "The ground is hard and dry.\n" +
                           "The dirt is easilly kicked up into dust " +
                           "clouds.\n" +
                           "There is a small crevice in the middle of the" +
                           " ground",
                 "crevice", "A small crevice which has been cut into the" +
                            " ground",
                 "lichen", "Light grey moss that grows over the rocks",
                 "rocks", "Large rocks line the walls of the cave",
                 "walls", "Dark red-orange walls lined with cracks and grooves",
              });
      break;
    case 8:
      long_desc = COLOR +
      "  A deep dark cave with small crevices all over\n" +
      "the ground, making the impression of a golf ball.\n" +
      "Stalactites drop far down from the ceiling making the\n" +
      "cave look like a prison cell." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "ground", "The ground is hard and dry.\n" +
                           "The dirt is easilly kicked up into dust " +
                           "clouds.\n" +
                           "There are small crevices in the middle of the " +
                           "ground",
                 "crevices", "Small crevices which have been cut into the " +
                             "ground",
                 "stalactites", "Long slabs of rock growing from the ceiling",
                 "walls", "Dark red-orange walls lined with cracks and grooves",
              });
      break;
    case 9:
      long_desc = COLOR +
      "  A shallow cave about three feet high and four\n" +
      "feet wide.  The walls of the cave are very uneven\n" +
      "with crevices and cracks.  The ground is hard, and\n" +
      "blanketed with loose dirt." + NORM + "\n";
      items = ({ "cave", "A dark cave about three feet in height",
                 "ground", "The ground is hard and dry.\n" +
                           "The dirt is easilly kicked up into dust clouds",
                 "crevices", "Small crevices which have been cut into the wall",
                 "dirt", "Red-orange dirt that blankets the solid ground",
                 "walls","Dark red-orange walls lined with cracks and crevaces",
              });
      break;
    case 10:
      long_desc = COLOR +
      "  A shallow cave about three feet high and four\n" +
      "feet wide.  The cave smells of burned coal and cinder.\n" +
      "The walls of the cave are bumpy with a smooth texture." + NORM + "\n";
      items = ({ "cave", "A dark cave about three feet in height",
                 "ground", "The ground is hard and dry.\n" +
                           "The dirt is easilly kicked up into dust clouds",
                 "dirt", "Red-orange dirt that blankets the solid ground",
                 "walls", "Dark red-orange walls.\n" +
                          "The surface of the walls are smooth yet bumpy",
              });
      break;
    case 11:
      long_desc = COLOR +
      "  A long, dark, warm cave.  A pool of lava bubbles\n" +
      "in the center of the cave.  Steam hisses through cracks in\n" +
      "the walls." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "walls", "Dark red-orange walls with cracks full of steam",
                 "steam", "Scalding hot steam sizzles out of the cracks in" +
                          " the walls",
                 "lava", "Deadly hot lava bubbling in a small pool",
                 "cracks", "Thin cracks throughout the walls",
              });
      break;
    case 12:
      long_desc = COLOR +
      "  A long, dark, boiling hot cave.  A thin river of\n" +
      "deadly hot lava slowly slides its way through the middle of\n" +
      "cave." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "lava", "Deadly hot lava is sliding through the cave like" +
                         " a snake",
                 "river", "Deadly hot lava is sliding through the cave like" +
                          " a snake",
              });
      break;
    case 13:
      long_desc = COLOR +
      "  A long, dark, boiling hot cave.  A thin river of\n" +
      "deadly hot lava slowly rolls in between stalagmites sticking\n" +
      "up from the ground." + NORM + "\n";
      items = ({ "cave", "A dark cave about seven feet in height",
                 "lava", "Deadly hot lava is sliding through stalagmites " +
                         "like a snake",
                 "river", "Deadly hot lava is sliding through stagmites " +
                          "like a snake",
                 "stalagmites", "Jagged rocks that grow out of the ground.\n" +
                               "A river of lava flows between them",
              });
      break;
  }
}

void get_random_mob() { /* Recoded by Rumplemintz */
  string *mob_array;
  int i, num;

  mob_array = ({ "/players/jaraxle/3rd/volcano/mons/lava.c",
                 "/players/jaraxle/3rd/volcano/mons/lava2.c",
                 "/players/jaraxle/3rd/volcano/mons/mosquito.c",
                 "/players/jaraxle/3rd/volcano/mons/beetle.c",
                 "/players/jaraxle/3rd/volcano/mons/beetle2.c",
                 "/players/jaraxle/3rd/volcano/mons/rock.c",
                 "/players/jaraxle/3rd/volcano/mons/rock2.c",
              });
  switch(random(25)) {
    case 0..7:   num = 3; break;
    case 8..13:  num = 2; break;
    case 14..17: num = 4; break;
    case 18:     num = 1; break;
    case 19..23: num = 5; break;
    default:     num = 0; break;
  }
  for(i=0; i < num; i++) {
    move_object(clone_object(mob_array[random(6)]), this_object());
  }
}

void get_random_exit() {
  string EXIT, ROOM, NUM, EXITZ, EXITY;

  switch(random(12)) {
    case 0: EXIT = "northwest"; break;
    case 1: EXIT = "northeast"; break;
    case 2: EXIT = "north"; break;
    case 3: EXIT = "south"; break;
    case 4: EXIT = "back"; break;
    case 5: EXIT = "forward"; break;
    case 6: EXIT = "down"; break;
    case 7: EXIT = "southeast"; break;
    case 8: EXIT = "southwest"; break;
    case 9: EXIT = "west"; break;
    case 10: EXIT = "east"; break;
    case 11: EXIT = "up"; break;
  }
  switch(random(6)) {
    case 0: ROOM = "a_cave"; break;
    case 1: ROOM = "b_cave"; break;
    case 2: ROOM = "c_cave"; break;
    case 3: ROOM = "d_cave"; break;
    case 4: ROOM = "e_cave"; break;
    case 5: ROOM = "f_cave"; break;
  }
  switch(random(6)) {
    case 0: NUM = "2"; break;
    case 1: NUM = "3"; break;
    case 2: NUM = "4"; break;
    case 3: NUM = "5"; break;
    case 4: NUM = "6"; break;
    case 5: NUM = "7"; break;
  }
  dest_dir = ({ "/players/jaraxle/3rd/volcano/rooms/" + ROOM + NUM, EXIT, });
}

