#define TPN this_player()->query_name()
#define AN attacker->query_name()
#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_light(-3);
  set_name("gladius");
  set_alias("sword");
  set_short(YEL+"A Bronze Gladius"+NORM);
  set_long(
"This is a short bronze sword or long knife, with a rope grip\n"+
"and a wolfhead pommelstone. \n"
  );
  set_type("sword");
  set_class(19);
  set_weight(4);
  set_value(1500);
  set_hit_func(this_object());
  message_hit=({
    YEL+"stabbed"+NORM,YEL+" with pinache"+NORM,
    YEL+"hit"+NORM,YEL+" with pinache"+NORM,
    YEL+"stabbed"+NORM,"",
    YEL+"cut"+NORM,"",
    YEL+"slashed at"+NORM,"",
    YEL+"slapped"+NORM,YEL+" with the flat of the the blade"+NORM,
    YEL+"feinted at"+NORM,""
  });
}
weapon_hit(attacker) {
  int W;
  W=random(10);
  if (W>8) {
    this_player()->add_hit_point(-2);
    say(
TPN+"'s gladius quivers uncontrollably as it releases a\n high pitched sound.\n"
    );
    write(
"Your gladius seems to quiver uncontrollably as it releases a\n high pitched sound.\n"
    );
    return 4;
  }
  if (W>7) {
    say(
TPN+" plunges the gladius into "+AN+"'s stomach.\n"
);
    write(
"You plunge the gladius into "+AN+"'s stomach.\n"
    );
    return 3;
  }
  return;
}

