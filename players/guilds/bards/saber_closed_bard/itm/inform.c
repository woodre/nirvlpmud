/*
 * A spell which will inform the bard when somebody enters the room.
 * Bard v3.0
 */

inherit "obj/treasure";

int inform, count, COUNT;
string bard;
object BARD;

reset(arg)  {
  if(arg) return;
    set_id("inform");
    set_short();
    set_long("What?\n");
    set_value(1);
    COUNT = random(100) + 1;
        }

get()    { return 1;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }

init()  {
  ::init();
  add_action("inform_on","inform_on");
  add_action("alarm_off","inform");
  
  if(this_player()->query_level() < 100 && inform == 1) {
   if(!present("pro_from_cant", this_player()))  {
   
    BARD = find_player(bard);
    if(!BARD) { bye_bye(); }
    tell_object(BARD, "\nYou are informed that "+this_player()->query_name()
      +" has entered "+call_other(environment(this_player()),"short")+".\n");
    count = count + 1;
    if(count > COUNT)  { 
      tell_object(BARD, "Your inform cantrip has worn off.\n");
      bye_bye(); 
         }
         }
         }
         }
         

bye_bye() {
  destruct(this_object());
  return 1;
        }
        

inform_on()  {
  inform = 1;
  bard = this_player()->query_real_name();
  write("The inform cantrip has been activated.\n");
  return 1;
        }


alarm_off(str)  {
  if(str == "off")  {
   if(present("instrument", this_player()))  {
    write("You dispel the inform cantrip.\n");
    destruct(this_object());
    return 1;
        }
        }
        }
