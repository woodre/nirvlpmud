/* 
 * Makes sure a monster starts healing again.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

#define TO this_object()
#define ENV environment(this_object())

string MASTER;

reset(arg)  {
  if(arg) return;
    set_id("heal_stop");
    call_out("check_here", 100);
        }

drop()   { return 1;   }
can_put_and_get()  { return 0; }


set_master(str)  {  MASTER = str; }


check_here()  {
  if(!present(MASTER, environment(ENV)))  {
  tell_room(environment(ENV),
    "\n"+ENV->short()+" starts healing again.\n");
  ENV->set_heal(2,25);
  destruct(this_object());
  return 1;
  }
  call_out("check_here", 100);
  return 1;
  }
