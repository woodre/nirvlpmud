#pragma strict_types
#include "/players/llew/Bcrystal/rooms/bc_rooms.h"

/* This file holds a number of different descriptions for areas of the
 *  crystal, so I don't have to write 100 unique descriptions.  It has
 *  the added feature of being random every reboot. 
 */


string *describe_room(int section)
{
   int x;

   if (section == XETRA_FRONT || section == CHAOTI_FRONT)
   {
      x = random(4);
      switch (x)
      {
         case 0:
            return
            ({ "     Brittle crystal chips little the floor of this passage.  The walls\n" +
               "are rough, but let through a dim blue light.  The ceiling crystals angle\n" +
               "down at many angles.  Blue lights of energy zip about.\n",
               "chips", "The crystal chips crunch and break when stepped on",
               "passage", "The passage is somewhat narrow",
               "walls", "The walls are clear enough to see the deep crystal world behind",
               "light", "The warm blue glow illuminates the tunnel",
               "crystals","The hanging crystals look very sharp",
               "energy", "The energy quickly darts through the passage",
            });
         case 1:
            return
            ({ "     A round circular room of carved from the crystal.  Light focuses in\n" +
               "the center of the room, leaving the rest in dark shadow.  The walls are\n" +
               "rough, letting in little light.  The focused light in the center comes\n" +
               "from the finely cut crystal above.  Blue lights spin around in circles\n" +
               "near the focused light.\n",
               "room", "The room definitely looks to be created by some intelligence",
               "crystal", "The crystal pulses with blue",
               "light", "The light is bright, spotlighting the center of the room",
               "lights", "The energy dances around the focused light",
            }); 
         case 2:
            return
            ({ "     A small room is quite dim.  The crystal walls let in hardly any\n" +
               "light.  There is a low deep humming pervades the passage.  The small\n" +
               "energy bits in the room drift slowly on unseen currents.\n",
               "room", "The small room is about ten feet square",
               "walls", "The walls look thick with rough crystal edges",
               "bits", "The energy is mellow and calm here",
            });
         case 3:
            return
            ({ "     The crystal room here is round and tall.  Light streams down from\n" +
               "the high ceiling above.  Debris from battle is strewn about the floor,\n" +
               "blood and some rotting bits of flesh, crystal chips fallen from the walls.\n" +
               "A melee of blue energy flutters about the room frantically.\n",
               "room", "The large room is probbaly twenty feet in diameter",
               "light", "The clear light is shot down from the shafts of crystal above",
               "ceiling", "The ceiling high above has crystal formations protruding this\n" +
                          "way and that",
               "debris", "The debris consists of bits of broken crystal",
               "energy", "The energy is very disturbed and anxious, zipping about chaotically",
            }); 
      }           
   }

   if (section == XETRA_CONTROL)
   {
      x = random(4);
      switch (x)
      {
         case 0:
            return
            ({ "     Carved crystal walls let in an abundance of blue light.  The square\n" +
               "chamber is carved for untility.  Various evidence of mining activity can\n" +
               "be seen in the room.  Some blue energy floats aimlesslessy.\n",
               "walls", "The walls are smooth and square cut",
               "light", "The light is bright, outlining the well used room",
               "evidence", "Small squares of crystal have been removed from the walls.  Crystals\n" +
                           "little the floor waiting to be removed",
               "energy", "The energy is calm, floating along the shafts of light"
            });
         case 1:
            return
            ({ "     Smooth passages lead away from this small chamber.  The walls gleam\n" +
               "with refracted and reflected light.  The shining walls brighten the room.\n" +
               "The floor is flat clear.  Particles of energy dance with the light.\n",
               "passages", "The passages are also clearly carved by unnatural means",
               "chamber", "The smooth chamber rounds to about twelve feet in diameter",
               "walls", "The clear shining walls have been polished smooth",
               "floor", "The flat floor is slightly worn from passing feet",
               "particles", "The playful energy spins and whirls about"
            });
         case 2:
            return
            ({ "     A wide crystal passage opens filled with the light of the blue\n" +
               "crystal.  The ground is worn smooth from traffic.  The walls are smooth\n" +
               "as well, but show a large number of slash and scorch marks.  The blue\n" +
               "energy flutters around the walls and ceiling.\n",
               "passage", "The passage opens to a small chamber",
               "light", "The light is clear through the smooth walls",
               "ground", "Fine particles of crystal littler the floor with signs of passage",
               "walls", "The walls are clear and smooth",
               "marks", "The marks are a sign of some sort of recent combat",
            });
         case 3:
            return
            ({ "     This chamber is dark.  The crystal world is difficult to see through\n" +
               "the dense cloudly walls.  The room glows with a dim purplish light, unlike\n" +
               "the usual blue.    The particles of energy are less here.  The few that are\n" +
               "struggle to move through the air.\n",
               "chamber", "The round room is well cut, but the walls still let through little light",
               "walls", "The walls seem thicker, more dense, somewhat blocking the world beyond",
               "light", "The light contains the blue of the crystal, with some other red mixed in",
               "particles", "The tiny particles push through the think air slowly",
            });
      }
   }

   if (section == CHAOTI_CONTROL)
   {
      x = random(4);
      switch (x)
      {
         case 0:
            return
            ({ "     Carved crystal walls let in an abundance of blue light.  The square\n" +
               "chamber is carved for untility.  Various evidence of mining activity can\n" +
               "be seen in the room.  Some blue energy floats aimlesslessy.\n",
               "walls", "The walls are smooth and square cut",
               "light", "The light is bright, outlining the well used room",
               "evidence", "Small squares of crystal have been removed from the walls.  Crystals\n" +
                           "little the floor waiting to be removed",
               "energy", "The energy is calm, floating along the shafts of light"
            });
         case 1:
            return
            ({ "     Smooth passages lead away from this small chamber.  The walls gleam\n" +
               "with refracted and reflected light.  The shining walls brighten the room.\n" +
               "The floor is flat clear.  Particles of energy dance with the light.\n",
               "passages", "The passages are also clearly carved by unnatural means",
               "chamber", "The smooth chamber rounds to about twelve feet in diameter",
               "walls", "The clear shining walls have been polished smooth",
               "floor", "The flat floor is slightly worn from passing feet",
               "particles", "The playful energy spins and whirls about"
            });
         case 2:
            return
            ({ "     A wide crystal passage opens filled with the light of the blue\n" +
               "crystal.  The ground is worn smooth from traffic.  The walls are smooth\n" +
               "as well, but show a large number of slash and scorch marks.  The blue\n" +
               "energy flutters around the walls and ceiling.\n",
               "passage", "The passage opens to a small chamber",
               "light", "The light is clear through the smooth walls",
               "ground", "Fine particles of crystal littler the floor with signs of passage",
               "walls", "The walls are clear and smooth",
               "marks", "The marks are a sign of some sort of recent combat",
            });
         case 3:
            return
            ({ "     This chamber is dark.  The crystal world is difficult to see through\n" +
               "the dense cloudly walls.  The room glows with a dim greenish light, unlike\n" +
               "the usual blue.    The particles of energy are less here.  The few that are\n" +
               "struggle to move through the air.\n",
               "chamber", "The round room is well cut, but the walls still let through little light",
               "walls", "The walls seem thicker, more dense, somewhat blocking the world beyond",
               "light", "The light contains the blue of the crystal, with some other green mixed in",
               "particles", "The tiny particles push through the think air slowly",
            });
      }
   }

   /* For now, just return a general description. */
   return ({ "This is a blank description in the crystal area.\nYou are in section " + 
             section + ".\n", "crystal", "The crystal is crystaline" });
}
