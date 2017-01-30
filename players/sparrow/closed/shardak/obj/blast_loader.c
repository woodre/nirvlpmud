#include "/players/vertebraker/closed/load_object.h"

#define blast_id "holy_blast"
#define blast    "/players/vertebraker/closed/shardak/obj/holy"


#define a ({ "/room/church", \
             "/players/trix/castle/primo/altar6", \
             "/players/dreamspeakr/WEDDING/chapel", \
             "/players/saber/closed/quest/larn/larn2", \
             "/players/saber/closed/quest/larn/larn3", \
             "/players/saber/closed/quest/larn/larn4", \
             "/players/saber/closed/quest/larn/larn5", \
             "/players/saber/closed/quest/larn/larn6", \
             "/players/saber/closed/quest/larn/larn7", \
             "/players/saber/closed/quest/larn/larn8", \
             "/players/saber/closed/quest/larn/larn9", \
             "/players/saber/closed/quest/larn/enter", \
             "/players/saber/closed/quest/larn/larn1", \
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
