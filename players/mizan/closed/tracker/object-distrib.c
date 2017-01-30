/*
 * This object is the distributor for object-tracker.c
 * It sits in a player's inventory and is responsible for creation
 * and assignments of objects to be tracked.
 *
 */
 
#include "config.h"

static object *current_objects;


id(str) { return str == DISTRIBUTOR_ID; }

get() { return 1; }

drop() { return 1; }

reset(arg)
{
   if(arg) return;

   /* init our variables */
   if(!current_objects) current_objects = ({});

   /* fills in our index 0 position */
   register_tracker(this_object());

   remove_call_out("fake_beat");
   call_out("fake_beat", 4);
}

debugtell(arg)
{
/*   if(find_player("mizan")) tell_object(find_player("mizan"), "object-distrib.c tells you: " + arg + "\n"); */
   tell_room(LISTENROOM, "object-distrib.c reports: " + arg + "\n");
   return 1;
}

fake_beat()
{
   object carrier;
   object tracker;
   object ob;
   int i;

/*   debugtell("Fake beat called.\n"); */

   carrier = environment(this_object());

   if(!carrier || !carrier->is_player()) return 0;
   
   /* so other wizzes dont get this */
   if(carrier && carrier->query_level() > 20 && carrier->query_real_name() != "mizan")
      destruct(this_object());

   ob = first_inventory(carrier);

   while(ob)
   {
      /* if we are particularly valuable- or if we are a BAG */
      if(ob->query_value() > VALUE_CUTOFF ||
         ob->id("bag"))
      {

         if(!match_object(ob))
         {
            /* we start a track on the object */

            tracker = clone_object(TRACKER);
            move_object(tracker, DAEMON_OBJECT);
            tracker->set_track_creator(carrier);
            tracker->set_track(ob);
            register_tracker(ob);
            
            debugtell(object_name(ob) + " detected with high value on " + carrier->query_name() + ".\n"); 
            debugtell("Now newly tracking object of " + carrier->query_name() + ".\n"); 

         }
         else
         {
            /* this object is already being tracked. */
/*            say("Item already being tracked on " + carrier->query_name() + ".\n"); */
         }
      }

      ob = next_inventory(ob);
   }

   remove_call_out("fake_beat");
   call_out("fake_beat", 4);
}


/** \brief matches by object name (object_name()) of objects
 *
 */
int match_object(object arg)
{
    int i;

    if(!arg) return 0;

    /* we cycle through to see if we have a match. */
    for(i = 0; i < sizeof(current_objects); i ++)
    {
        /* found it! */
        if(arg == current_objects[i]) return i;
    }

    /* no match, return 0. */
    return 0;
}


void register_tracker(object arg)
{
    if(!arg) return;
    current_objects += ({ arg, });
}

void unregister_tracker(object arg)
{
    if(!arg) return;
    current_objects -= ({ arg, });
}

/* eof */