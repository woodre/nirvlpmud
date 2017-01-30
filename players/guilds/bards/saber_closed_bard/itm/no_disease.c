/* 
 * A cantrip that keeps bards from being sick for a while
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
    set_id("no_disease");
    call_out("go_away",400+random(300));
        }

drop()   { return 1;   }
can_put_and_get()  { return 0; }

go_away() {
  tell_object(environment(this_object()),
    "\nYour cantrip of health expires.\n\n");
  remove_call_out("go_away");
  destruct(this_object());
  return 1;
        }
