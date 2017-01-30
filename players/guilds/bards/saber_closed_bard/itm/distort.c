/* 
 *  Temp ac item for Bards 3.0
 *
 */

inherit "obj/treasure";

string ORG_AC;

reset(arg)  {
   if (arg) return;
    set_id("mask_distort");
    set_short();
    set_long("");
    set_weight(0);
    set_value(0);
    
    call_out("start", 1);
        }

drop()  { return 1; }


start() {
int CURR_AC, CALLOUT, NEW_AC;

  CURR_AC = this_player()->query_ac();
  ORG_AC  = 10 - CURR_AC;
  NEW_AC  = 10;
  
  CALLOUT = 1000 / (10 - CURR_AC);
  
  write("* "+CALLOUT+".\n");
  
  call_other(this_player(), "armor_class", NEW_AC);

  call_out("end_it", CALLOUT);
  return 1;
         }


end_it() {
int RESET_AC;
  
  RESET_AC = this_player()->query_ac() - ORG_AC;
  
  call_other(this_player(), "armor_class", RESET_AC);
  
  tell_object(this_player(), "\nYour spell of distortion fades away.\n\n");
  destruct(this_object());
  return 1;
        }
