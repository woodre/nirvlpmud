/* 
 * Makes sure a monster is only true_name'd once.
 * Stores origional monster stats.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

#define TO this_object()
#define ENV environment(this_object())

int AC, WC;
string MASTER;

reset(arg)  {
  if(arg) return;
    set_id("true_name");
    call_out("check_here", 50);
        }

drop()   { return 1;   }
can_put_and_get()  { return 0; }

query_arg_ac()  { return AC;  }
query_org_wc()  { return WC;  }

set_org_ac(str)  {  AC = str; } 

set_org_wc(str)  { WC = str; } 

set_master(str)  {  MASTER = str; }


check_here()  {
  if(!present(MASTER, environment(ENV)))  {
  tell_room(environment(ENV),
    "\n"+ENV->short()+" seems to grow stronger.\n");
  ENV->set_wc(WC);
  ENV->set_ac(AC);
  destruct(this_object());
  return 1;
  }
  call_out("check_here", 50);
  return 1;
  }
