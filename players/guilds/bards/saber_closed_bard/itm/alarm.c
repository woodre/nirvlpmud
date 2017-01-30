/*
 * A spell which will inform people when somebody enters the room.
 * Note: This spell has no range, so it will only work if the caster is in the room.
 * Bard v2.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

int alarm;

reset(arg)  {
  if(arg) return;
    set_id("alarm");
    set_short();
    set_long("What?\n");
    set_value(1);
        }

get()    { return 1;   }
can_put_and_get()  { return 0; }

init()  {
  ::init();
  add_action("alarm_on","alarm_on");
  add_action("alarm_off","alarm");
  if(this_player()->query_level() < 100 && alarm == 1) {
   if(!present("pro_from_cantrips", this_player()))  { 
    ring();
         }
         }
         }

ring() {
  tell_room(environment(this_object()),
    "\nRRRRRIIIIIIIIIIIINNNNNNNNNNGGGGGGGGGGGGGG.\n"+
    "\n"+this_player()->query_name()+" has entered the room.\n\n");
  destruct(this_object());
  return 1;
        }
        
alarm_on()  {
  alarm = 1;
  write("The alarm cantrip has been activated.\n");
  return 1;
        }

alarm_off(str)  {
  if(str == "off")  {
   if(present("instrument", this_player()))  {
    write("You dispel the alarm cantrip.\n");
    destruct(this_object());
    return 1;
        }
        }
        }
