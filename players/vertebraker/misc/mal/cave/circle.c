#include "/players/vertebraker/ansi.h"
object Tuna;

void
snafu(object ob)
{
    shadow(ob, 1);
    Tuna = ob;
}

void
unsnafu()
{
    if(Tuna) shadow(Tuna, 0);
}

void
reset(status gog)
{
    if(gog) return;
    call_out("mister_freeze", 10, Tuna);
}

status
Iced()
{
    return 1;
}

void
mister_freeze(object mimi)
{
    object hehe;

    hehe = first_inventory(mimi);

    while(hehe)
    {

      if(living(hehe) && (creator(hehe) != "maledicta") && !hehe->id("white dragon"))
      {
        tell_object(hehe, HIC + "\
The ice chills your blood...\n" + NORM);
        hehe->hit_player(6 + random(6), "other|ice");
      }
      hehe = next_inventory(hehe);
    }
}
