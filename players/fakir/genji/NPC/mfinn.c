#include "/players/fakir/color.h"
inherit "obj/monster.c";
  
reset(arg)  {
object armor;
  ::reset(arg);
  if(arg) return;
  
set_name("murfinn");
set_alias("finn");
set_race("snake");
set_short("Murfinn");
set_long(
  "Shimmering scales of yellow and red cover the snakelike body of\n"+
"the Murfinn, and glisten with the rhythm of her breathing. A long\n"+
"white gown, open in the front, covers her from shoulders to just\n"+
"past her double jointed knees.  A slender tri-forked tongue flicks\n"+
"from time to time, testing the air.  Her eyes never blink.\n");
 
move_object(clone_object("/players/fakir/genji/ARM/gown.c"),
(this_object()));
init_command("wear gown");
set_level(15);
set_hp(220+random(50));
set_al(-300);
set_wc(20);
set_ac(12);
set_aggressive(0);
}
