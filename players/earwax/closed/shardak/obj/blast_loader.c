#include "/players/vertebraker/closed/load_object.h"

#define blast_id "holy_blast"
#define blast    "/players/vertebraker/closed/shardak/obj/holy"


#define a ({ "/room/church", \
             "/players/dreamspeakr/WEDDING/chapel", \
             "/players/wocket/turtleville/tville_church", \
             })

void
load_holy_blasts()
{
    int i, s;
    object c;

    s=sizeof(a);
    for(i = 0; i < s; i ++)
    {
      if(!(c = loadObject(a[i]))) /* will never load */
        return;
      if(!present(blast_id, c)) 
        move_object(clone_object(blast), c);
    }

call_out("load_holy_blasts", 1800);
}
