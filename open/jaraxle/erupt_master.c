#include "/players/vertebraker/ansi.h"

#define LAVA "/players/vertebraker/obj/j_lava"
#define VOLCANO_PATH "/players/jaraxle/3rd/volcano/rooms/"
#define LAVA_ID "lava_object"

int erupting;

void
init_lava()  /* call this to start the eruption */
{
    if(!erupting)  /* is it presently erupting .. hmm */
    {
      call_out("volcano_erupt", 5, 0); /* call the func in 5 secs */
      erupting = 1;  /* flag it as erupting */
    }
}

void
build_lava(string path) /* this function makes the lava */
{
    object l, ob;

    l = clone_object(LAVA);

    if(!(ob = find_object(path)))  /* if the room isnt loaded, load it */
      path->load_it();

    ob = find_object(path); /* allocate the room */

    if(!present(LAVA_ID), ob) /* if there isnt lava in the room, */
      move_object(l, ob);     /* put some there !*/

    l->lava_wave(); /* blast em with some lava */
}

void
volcano_erupt(int cnt)  /* the meat */
{
    int i, s;
    object *us, p;
    string level;

    us = users();
    s = sizeof(us);

    if(!cnt) /* if we are just starting up.. */
    {
      for(i = 0; i < s; i ++)
      {
        p = us[i];
        if(environment(p) && p->on_channel("junk"))
          tell_object(p, "\
(junk) A fierce tremor shakes the land...\n\
In the distance, you see a mighty volcano erupting...\n");
      }
      level = "cave7";  /* starting on this level */
    }

    else switch(cnt)
    {
      case 1: level = "cave6"; break;
      case 2: level = "cave5"; break;
      case 3: level = "cave4"; break;
      case 4: level = "cave3"; break;
      case 5: level = "cave2"; break;
      case 6: level = "cave"; break;
    }

    if(cnt > 5) 
    {
      erupting = 0;
      return;
    }

     /* clone the lava to the level we are on.. */
    build_lava(VOLCANO_PATH + "a_" + level);
    build_lava(VOLCANO_PATH + "b_" + level);
    build_lava(VOLCANO_PATH + "c_" + level);
    build_lava(VOLCANO_PATH + "d_" + level);
    build_lava(VOLCANO_PATH + "e_" + level);
    build_lava(VOLCANO_PATH + "f_" + level);

    cnt ++;

    if(cnt > 5) /* if we've flooded every level... */
    {
      erupting = 0;
      return;  /* flag it as dormant and cancel the call */
    }

    /* the following line ensures we are not doing
       multiple call_outs */
    while(remove_call_out("volcano_erupt") != -1);

     /* call again in 300 :) */
    call_out("volcano_erupt", 300, cnt);
}
