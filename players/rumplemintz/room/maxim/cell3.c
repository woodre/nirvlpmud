/* ========================================================================== */
/*                                                                            */
/*   cell3.c                                                                  */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Prison cell 3 inside King Maxim's castle.                                */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
   if(arg) return;
   set_light(0);
   short_desc = "A prison cell in King Maxim's castle";
   long_desc =
   "     You are in a bright, clean, warm, dry, prison cell. The armoma of\n"+
   "rose petals brushes your nose with excitement. The walls have been cleared\n"+
   "of all markings on them. There are no signs of dust or dirt. This cell has\n"+
   "been immaculately kept. In the corner there is a small pile of books and\n"+
   "a stack of folded blankets.\n";
   items = ({
         "walls", "They are clean and dry",
         "books", "A various assortment of war strategies and history tomes",
         "blankets", "They are attached to the floor, but look warm and comfortable",
         "cell", "It's an atypical prison cell"
    });
   dest_dir = ({
         "/players/rumplemintz/room/maxim/dungeon4", "south"
    });
}
