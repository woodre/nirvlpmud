#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset();
  if(arg) return;
move_object(clone_object("/players/wocket/graveyard/dring.c"),this_object());
move_object(clone_object("/players/wocket/graveyard/dstaff.c"),this_object());
move_object(clone_object("/players/wocket/graveyard/dcrown.c"),this_object());
set_name("vreeland");
set_alias("lady");
set_alt_name("lady vreeland");
set_race("goddess");
set_short(MAG+"Lady Vreeland"+NORM);
set_level(20);
set_hp(700);
set_wc(70);
set_ac(20);
set_long("She was the dryant princess before her demise.  Her eyes sparkle like the moon\n"+
"as they mystify you.  Auburn long hair flows gently down, off her shoulders,\n"+
"upon the ground as light flickers across it.  Her pale white skin is as \n"+
"smooth and as deleate as china.  She may appear delecate and fragile\n"+
"but emminates and aura of strength.\n");
}

init(){
::init();
add_action("movenorth","north");
}

movenorth(){
  if(present("necro_ob", this_player())) return 0;
  write(MAG+"Lady Vreeland"+NORM+" blocks your exit.\n");
  return 1;
}
