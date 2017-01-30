inherit "obj/monster.c";
#include "/players/fakir/color.h"

reset(arg)  {
  object treasure;
  ::reset(arg);
  if(arg) return;
add_money(100);
set_name("fairy");
set_race("fairy");
set_short(MAGENTA+"Fairy"+OFF);
set_long(
  "Enchantingly beautiful and with a devilish sparkle in her eye, the\n"+
  "fairy creature captivates you without even using her dust.  Silver\n"+
  "hair and deep green eyes are enhanced by the layered dress of white\n"+
  "batiste trimmed with chiffon sleeves. Wings the shape and texture of\n"+
  "rose petals softly fan the air and lift her just inches above the\n"+
  "ground.  Of all the fairy folk, only these of the pure blood are\n"+
  "good and kind.\n");


set_level(5);
set_hp(75);
set_al(600);
set_wc(9);
set_ac(5);
set_aggressive(0);

treasure=clone_object("/players/fakir/woods/OBJ/dust.c");
move_object(treasure,this_object());

}

