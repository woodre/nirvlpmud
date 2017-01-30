#include "/players/vertebraker/ansi.h"

int cnt, loaded;

void
init()
{
    object x;

    if((x = environment()) && !loaded)
    {
      x->RegisterArmor(this_object(),
         ({ "physical", 1, 0, "do_special" }));
      call_out("end_ac", (360 + random(100)));
      loaded = 1;
    }
}

void
end_ac()
{
    object e;

    if(!(e = environment())) return;
    tell_object(e, BOLD + "You feel less protected.\n" + NORM);
    e->RemoveArmor(this_object());
    destruct(this_object());
}

status
drop()
{
    return 1;
}

status
id(string str)
{
    return str == "verte_defend_thing";
}
