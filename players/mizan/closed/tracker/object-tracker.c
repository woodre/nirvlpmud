/**
 * This little object sits in a room, and updates a log file or database
 * whenever the object it is observing has been moved to a new location.
 *
 */


#include "config.h"

string trackee_creator;
string trackee_short;
string trackee_ipaddr;

object trackee;
object trackee_room;
object trackee_old_room;

status switched_on;
int random_id;
string my_rid;

id(str) { return str == "tracker" || str == "device" || str == my_rid;  }

get() { return 1; }

short()
{
  if(trackee) return "An object tracking device #" + my_rid + " (" + trackee_short + ")";
  else return "An object tracking device #" + my_rid + " (idle)"; 
}

long()
{
   write("This is an object tracker.\n");
   
   if(trackee)
   {
      write("It is currently tracking an object originally from " + trackee_creator + ".\n");

      write("The object being tracked is:\n" +
            "Short desc: " + trackee_short + "\n" +
            "Filename:   " + object_name(trackee) + "\n");
   }
   else
   {
      write("It is not currently tracking anything.\n");
   }
}

reset(arg)
{
  remove_call_out("do_tracking");
  call_out("do_tracking",1);
  if(arg) return;
  
  /* turn ourselves on */
  switched_on = 0;
  
  /* generate a random ID for ourselves */
  random_id = random(10000) + 10000;
  my_rid = "r" + random_id;
}

query_track_short()
{
  return trackee_short;
}

set_track_creator(arg)
{
  trackee_creator = arg->query_real_name();
  trackee_ipaddr = query_ip_number(arg);
}

query_track() { return trackee; }

set_track(arg)
{
  trackee = arg;
  
  if(!trackee) { return 0; }
  switched_on = 1;
  trackee_short = object_name(trackee);
  
  if(environment(trackee))
  {
     trackee_room = environment(trackee);
  } else return 0;
}

do_tracking() 
{
  string ipaddr;
  string reportmsg;

  if(!trackee || trackee == 0)
  {
     log_file("mizan.objtracker", "[" + ctime() + "] (" + trackee_creator + ") " + trackee_short + " has disappeared.\n");
     destruct(this_object());
     return 1;
  }

  else 
  {
    if(environment(trackee))
    {
       trackee_room = environment(trackee);
    }
    else 
    {
       trackee_room = 0;
       return;
    }
    
    if(trackee_room != trackee_old_room && trackee_short) 
    {
       if(trackee_room->short())
       {
          if(living(trackee_room))
          {
             log_file("mizan.objtracker", "[" + ctime() + "] (" + trackee_creator + ":" + trackee_short + 
                      get_container_stats() + " carried by " + trackee_room->query_name() + ".\n");

             /* check if has same IP as creator */
             if(trackee_room->is_player())
             {
               ipaddr = query_ip_number(trackee_room);
               reportmsg = "(" + trackee_creator + ":" + trackee_short + 
                           get_container_stats() + " now carried by " + trackee_room->query_name() + ".\n";


               /* if the ip is same but name is different.... */
               if(ipaddr == trackee_ipaddr &&
                  trackee_creator != trackee_room->query_real_name())
               {

                  reportmsg = "(" + trackee_creator + ":" + trackee_short + 
                  get_container_stats() + " now carried by " + trackee_room->query_name() + ", (" + ipaddr + ").\n";
                  
                  if(find_player("mizan")) tell_object(find_player("mizan"), reportmsg);
                  tell_room(LISTENROOM, "Object tracker reports: " + reportmsg);
                  log_file("mizan.objtracker.violations", "[" + ctime() + "] " + reportmsg);


                  /* someone from the same IP address has this object */
/*
                  if(trackee->is_weapon() &&
                     1 == random(3) &&
                     !trackee->query_broke()) call_other(trackee, "set_wc", 1);

                  if(trackee->is_armor() && 
                     1 == random(3) &&
                     !trackee->query_value()) call_other(trackee, "armor_breaks");
*/

               }
               else
               {
                  /* otherwise its just some other creature that has it. Log anyway. */
                  log_file("mizan.objtracker", "[" + ctime() + "] " + reportmsg);

               }
             }
          }
          else
          {
             /* otherwise we are in a room or monster somewhere. */
             log_file("mizan.objtracker", "[" + ctime() + "] (" + trackee_creator + ":" + 
                      trackee_short + get_container_stats() + " located in " + object_name(trackee_room)+ ".\n");
          }
       }
       else
       {
          /* even worse, we dont know where we are... (should not happen) */
          log_file("mizan.objtracker", "[" + ctime() + "] (" + 
          trackee_creator + ":" + trackee_short + get_container_stats() + ") (location unknown)\n");
       }
    }

    trackee_old_room = trackee_room;

  }
  remove_call_out("do_tracking");
  call_out("do_tracking", 1);
}

get_container_stats()
{
   object ob;
   int value;
   int count;
   
   if(!trackee) return "";
   
   ob = first_inventory(trackee);
   if(!ob) return "";
   
   value = 0;
   count = 0;
   
   while(ob)
   {
      value += ob->query_value();
      count ++;
      
      ob = next_inventory(ob);
   }
   
   if(count == 0)
   {
      return " with 0 items, 0 value";
   }
   else if(count == 1)
   {
      return " with 1 item, " + value + " value";
   }
   else
   {
      return " with " + count + " items, " + value + " value";
   }
   
}

/* eof */