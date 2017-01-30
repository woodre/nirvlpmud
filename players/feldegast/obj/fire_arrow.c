#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "obj/treasure";
int burns;
status hb;
reset(arg) {
  if(arg) return;
  set_id("arrow");
  set_alias("fire_arrow");
  set_short(RED+"a flaming arrow"+NORM);
  set_light(1);
  set_long(
"This flaming arrow is burning you alive.  To remove it from\n"+
"your gut, you must 'yank arrow'.\n"
  );
  set_value(0);
  set_weight(0);
  burns=8;
  hb=1;
}
init() {
  ::init();
  add_action("yank","yank");
  burn();
}
yank(str) {
  if(!str=="arrow") {
    write("Yank what?\n");
    return 1;
  }
  write("You yank the burning arrow out of your gut.\n");
  say(TPN+" yanks a burning arrow out of his gut.\n");
  hb=0;
  burns=0;
  return 1;
}
burn() {
  if(environment()->is_player()) {
    environment()->heal_self(-random(10));
    tell_room(environment(environment()),
      environment()->query_name()+
      RED+" burns"+NORM+".\n"
    );
  }
  if(!burns) {
    tell_object(environment(),
      "The burning arrow fizzles out.\n"
    );
    hb=0;
    destruct(this_object());
  }
  burns--;
  if(hb) call_out("burn",random(10));
}
drop() {
  return 1;
}
