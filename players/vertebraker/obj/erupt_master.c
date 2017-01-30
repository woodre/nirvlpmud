/* rebuilt by verte.. sigh.. wish i had a backup */

#include "../ansi.h"

#define CAVES "/players/jaraxle/3rd/volcano/rooms/"
#define LAVA "/players/vertebraker/obj/j_lava"

string *heh;
int erupting;

void
reset(status arg)
{
    if(arg) return;
    heh = ({ "a", "b", "c", "d", "e", "f" });
}

void
init_lava()
{
    call_out("exploder", 5, 7);
    erupting = 1;
}

void
exploder(int cnt)
{
    int i, s;
    object *us, grr;
    string neato;

    if(cnt == 7)
    {
      s = sizeof(us = users());
      while(s --)
        if(us[s]->on_channel("junk"))
          tell_object(us[s], "\
An earthquake trembles the earth floor beneath your feet.\n\
Far off in the distance, " + HIR + "lava" + NORM + " bursts from an erupting volcano.\n");
    }
    s = sizeof(heh);
    for(i = 0; i < s; i ++)
    {
      grr = clone_object(LAVA);
      if(cnt == 1)
        neato = "";
      else
        neato = "" + cnt + "";
      move_object(grr, CAVES + heh[i] + "_cave" + neato);
      grr->lava_wave();
    }

    cnt --;
    if(!cnt)
    {
      erupting = 0;
      return;
    }
    call_out("exploder", 600, cnt);
}

status
query_erupting() { return erupting; }
