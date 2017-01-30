/* 
 * Makes sure a monster is only bound once.
 * Stores origional monster stats.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

#define TO this_object()
#define ENV environment(this_object())

int AC;
string MASTER;

reset(arg)  {
  if(arg) return;
    set_id("bind_mark");
    call_out("check_here", 50);
        }

drop()   { return 1;   }
can_put_and_get()  { return 0; }

query_arg_ac()  { return AC;  }

set_org_ac(str)  { 
    int ark;  if(sscanf(str, "%d", ark))  { AC = ark; }   }

set_master(str)  {  MASTER = str; }


check_here()  {
  if(!present(MASTER, environment(ENV)))  {
  tell_room(environment(ENV),
    "\n"+ENV->short()+" seems to grow stronger.\n");
  ENV->set_ac(AC);
  destruct(this_object());
  return 1;
  }
  call_out("check_here", 50);
  return 1;
  }
