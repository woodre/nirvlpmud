/* 
 * Makes sure a monster is only confused once.
 * Stores origional monster stats.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

#define TO this_object()
#define ENV environment(this_object())

int WC;
string MASTER;
object HIT_ME;

reset(arg)  {
  if(arg) return;
    set_id("confuse_mark");
    call_out("check_here", 10);
        }

drop()   { return 1;   }
can_put_and_get()  { return 0; }

query_arg_wc()  { return WC;  }

set_org_wc(str)  { 
    int ark;  if(sscanf(str, "%d", ark))  { AC = ark; }   }

set_master(str)  {  MASTER = str; }


check_here()  {
  if(!present(MASTER, environment(ENV)))  {
  tell_room(environment(ENV),
    "\n"+ENV->short()+" stops attacking itself and looks around.\n");
  ENV->set_wc(WC);
  destruct(TO);
  return 1;
  }
  call_out("check_here", 50);
  return 1;
  }


end_game() {
  ENV->set_wc(WC);
  
  if(HIT_ME = present(MASTER, environment(ENV))) {
  tell_room(environment(ENV), "\n"+
    ENV->short()+" screams in fury and attacks "+capitalize(MASTER)+"!\n\n");
   ENV->attack_object(HIT_ME); 
   }

  destruct(TO);
  return 1;
  }
