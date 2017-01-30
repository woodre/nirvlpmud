inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;
  
  set_light(1);
  set_short("A "+HIG+"tropical"+NORM+" honeymoon villa");
  set_long(
     "A short fieldstone path leads through a small cultivated garden to a "
    +"large, white stuccoed villa, trimmed with dark varnished wood.  The "
    +"villa only rises one story, but sprawls out generously to either side "
    +"of the slightly recessed entrance.  The garden is a fountain of "
    +"tropical color, from the palm trees to the many smaller blooming "
    +"plants.  Above, the sun shines brightly in a clear sky, warming your "
    +"skin.");
  
  add_item("path","The path is made of closely-set, flat stones, in shades "
                 +"of brown and grey.");
  add_item("villa","The perfect house for the tropics, low and painted "
                  +"white to deflect the heat.");
  add_item("entrance","A beautifully carved wooden door is set slightly into "
                     +"the villa wall, to shield it from the sun.  You can't "
                     +"help but notice there is no knocker or bell, and no "
                     +"mailbox, either.");
  add_item("garden","Beautiful greens, whites, and almost every other color "
                   +"fill your eyes with the beauty tropical plants can offer, "
                   +"somehow arranged into cultivated patterns to make them "
                   +"even more attractive.");
  add_item("trees","The slightly bent palm trees wave their branches in the "
                  +"wind, as if welcoming you to the villa.");
  add_item("plants","Plants of all kinds, most in bloom, fill the garden "
                   +"with an explosion of color.");
  add_item("sun","A typical tropical sun, friendly and bright, but hot.");
  add_item("sky","A clear, hot sky, with only the occasional cloud visible.");
  
  add_exit("in",VILLA+"hall");
  add_exit("nirvana","room/church");
}
