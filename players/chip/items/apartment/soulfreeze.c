#include <ansi.h>
#define MAX_BEATS 14
#define DAMAGE    (12 + random(22))

int beats;

id(str) { return str=="soulfreeze"; }

drop() { return 1; }

start_it()
{
  set_heart_beat(1);
}

heart_beat()
{
  if(++beats == MAX_BEATS)
  {
    tell_object(environment(),
      ""+HIC+"Your soul has regained warmth"+NORM+".\n");
    return destruct(this_object());
  }
  
  tell_object(environment(), "\
"+CYN+"Your soul is frozen, making it more difficult to resist damage"+NORM+".\n");
  environment()->hit_player(DAMAGE, "other|chip");
}
