string trackee_creator;
string trackee_short;

object trackee;
object trackee_room;
object trackee_old_room;

status switched_on;

id(str) { return str == "tracker" || str == "device";  }

get() { return 1; }
drop() { return 1; }

short()
{
  if(trackee) return "A tug tracking device (" + trackee_short + ")";
  else return "A tug tracking device (idle)"; 
}

reset(arg)
{
  remove_call_out("do_tracking");
  call_out("do_tracking",1);
  if(arg) return;
  switched_on = 0;
}

query_track_short()
{
  return trackee_short;
}

set_track_creator(arg)
{
  trackee_creator = arg->query_name();
}

set_track(arg)
{
  trackee = arg;
  
  if(!trackee) { return 0; }
  switched_on = 1;
  trackee_short = trackee->short();
  
  if(environment(trackee))
  {
     trackee_room = environment(trackee);
  } else return 0;
}

do_tracking() 
{
  if(!trackee || trackee == 0)
  {
/*
     log_file("mizan.tugtracker", "[" + ctime() + "] (" + trackee_creator + ") " + trackee_short + " has disappeared.\n");
*/
     say("Object disappeared!\n");
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
             log_file("mizan.tugtracker", "[" + ctime() + "] (" + trackee_creator + ") " + trackee_short + " carried by " + trackee_room->query_name() + ".\n");
          else
             log_file("mizan.tugtracker", "[" + ctime() + "] (" + trackee_creator + ") " + trackee_short + " located in " + trackee_room->short()+ ".\n");
       }
       else
          log_file("mizan.tugtracker", "[" + ctime() + "] (" + trackee_creator + ") " + trackee_short + " (location unknown)\n");
    }

    trackee_old_room = trackee_room;

  }
  remove_call_out("do_tracking");
  call_out("do_tracking", 1);
}


