#include <ansi.h>

inherit "room/room.c";

status hurt;
toggle_hurt() { hurt = !hurt; }

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(0);
  short_desc = HIC+"Cavern"+NORM;
  long_desc =
"A dark cavern.\n\
\n";

items =
  ({
   });

}

init() {
  ::init();
    add_action("release","release");
    add_action("search_room","search");
    add_action("pull","pull");

      if(this_player())
    DoDamage(this_player());
}

release(str) {
	say(capitalize(this_player()->query_name())+
    "releases the rope and the scafold drops down 50 yards.\n");
    this_player()->move_player(
    "releases the rope and drops futher into the cavern#/players/angel/area/mansion/room/hiram_lair_02");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

DoDamage(object who) {
 if(hurt) { hurt = !hurt; return 1; }
  tell_object(who, HIR+"\t\n\n\n\nYou feel the scaffolding slip downward!\n\n\n\n"+NORM);

  if(who->is_player()) {
  who->hit_player(40);

  }
  return 1;
}

  search_room() {
    write("You search and find a better way to control the rope.\n"+
      "You could attempt to pull the platform up again.\n");
      say (this_player()->query_name() +" searches the room.\n");
      return 1;
}
pull() {
    int ste;
    ste = 6;
    if (this_player()->query_attrib("ste") >= 19) ste = 3;
    if (random(ste) == 0) {
      write("You find the strength and pull up the platform up.\n");
      call_other(this_player(),"move_player","in#players/angel/area/mansion/room/hiram_lair_04");
}
else {
    write("You fall over and hit a wood poll. Ouch!\n");
    this_player()->hit_player(7 + random(9));
}

return 1;
}

realm() {return "NT";}
