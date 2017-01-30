#include <ansi.h>

inherit "room/room.c";

status hurt;
toggle_hurt() { hurt = !hurt; }

int hit;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(0);
  short_desc = HIC+""+NORM;
  long_desc =
"A dark cavern .\n\
\n";

items =
  ({
   });
}

init() {
  ::init();
    add_action("jump","jump");
    add_action("search_room","search");
    add_action("pull","pull");
    add_action("walk","bash");
}

jump(str) {
	say(capitalize(this_player()->query_name())+
    " jumps over the wood rail.\n");
    this_player()->move_player(
    " jumps over the wood rail futher into the cavern#/players/angel/area/mansion/room/cavern_basin_01");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

DoDamage(object who) {
 if(hurt) { hurt = !hurt; return 1; }
  tell_object(who, HIR+"You feel the scaffolding slip downward!"+NORM);

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
    ste = 4;
    if (this_player()->query_attrib("ste") >= 19) ste = 3;
    if (random(ste) == 0) {
      write("You find the strength and pull the platform up.\n");
      call_other(this_player(),"move_player","in#players/angel/area/mansion/room/hiram_lair_03");
}
else {
    write("You fall over and hit a wood poll. Ouch!\n");
    this_player()->hit_player(7 + random(9));
}

return 1;
}
walk(str) {
	say(capitalize(this_player()->query_name())+
    "bashes in the brick wall and steps through the hole.\n");
    this_player()->move_player(
    "bashes in the brick wall and steps through the hole.#/players/angel/area/mansion/room/hiram_lair_01");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

realm() {return "NT";}
