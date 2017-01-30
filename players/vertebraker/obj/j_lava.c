#include "/players/vertebraker/ansi.h"

#define DAMAGE (5 + random(5))  /* the dmg you want done */
#define LOGDIR "/players/vertebraker/log/"
#define BOOTS_ID "FIRE_BOOTS"  /* the id of the flaming boots */

status id(string str)
{
    return str == "lava_object" || str == "lava" || str == "river" || str == "river of lava";
}

string
short()
{
    return HIR + "A flowing river of lava" + NORM;
}

void
long()
{
    return write(HIR + "\
A steaming, boiling hot river of lava... the temperature\n\
of this shifting mass of bubbling molten liquid will\n\
reach into the thousands...\n" + NORM);
}

void
lava_wave()  /* this function is started when it is cloned by
                the eruption_master object, fyi */
{
    int i, s;
    object e, n, k, *a;

    if(e = environment())  /* if it has an environment */
    {
            /* tell the room */
      tell_room(e, HIR + "\
A wave of lava rolls over the room...\n" + NORM);
      a = all_inventory(e); /* add the inventory of the room to an array */
      s = sizeof(a); /* count up the number of items */

      for(i = 0; i < s; i ++)
      {
        n = a[i];
        if(living(n))  /* if the obj is alive.. */
        {
          if(!n->query_npc() && !present(BOOTS_ID, n)) /* is it a player
                                                       and does it have
                                                       the boots on */
          {
            n->add_hit_point(-DAMAGE);  /* if not, do damage */
                /* and tell em */
            tell_object(n, "\
Steaming hot lava pours through your flesh...\n");
          }
          else    /* otherwise */
          {
            if(creator(n) == "jaraxle") /* if you made the mob */
              n->heal_self(DAMAGE);  /* heal it */
            else                     /* if you didn't */
            {
              if((status)n->is_player()) n->add_hit_point(-DAMAGE);
              else n->heal_self(-DAMAGE);  /* hurt it */
            }
          }
          if((status)n->is_player() &&  
           (int)n->query_hp() < 1) /* if the ob should be dead .. */
          {
            k = clone_object("/obj/monster"); /* make a monster */
            k->set_name(HIR + "Volcanic Lava" + NORM);
               /* with the name volcanic lava */
            move_object(k, environment());
               /* move it to the ob */
            n->attacked_by(k);
               /* make it so the lava is the 'enemy' */
            n->death();
               /* and kill the ob */
            write_file(LOGDIR + "VOLCANO", ctime()[4..19] + " " +
(string)n->query_name() + ".\n");
            destruct(k);
               /* and dest the lava 'monster', it is useless now */
          }
        }
      }
    }

    call_out("lava_wave", 20);  /* call me again in a bit will ya? */
}


/* 02/23/06 Earwax: Logging to see where this is cloned from 

void reset(status arg)
{
  object ob;

  if (arg)
    return;

  ob = previous_object();

  if (!ob)
    ob = this_player();

  if (ob)
    log_file("verte.lava_wave", ctime()+": "+file_name(ob)+"\n");
}
*/
