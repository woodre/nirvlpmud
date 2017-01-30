/* 
 * An object to make a monster hit another for a limited time.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

#define TO this_object()
#define ENV environment(this_object())

object MAST, MARK;
int WC, TIME, COUNT;
string MASTER;


reset(arg)  {
  if(arg) return;
    set_id("mislead_obj");
    call_out("start", 1);
        }


drop()   { return 1;   }
can_put_and_get()  { return 0; }


set_time(str)  { 
    int ark;  if(sscanf(str, "%d", ark))  { TIME = ark; }   }


set_master(str)  {  MASTER = str; }


start()  {  set_heart_beat(1);  return 1;  }


heart_beat()  {

  if(COUNT > TIME)  {
    set_heart_beat(0);
    WC = ENV->query_ac() + 1;
    ENV->set_wc(WC);
    
    if(MAST = present(MASTER, environment(ENV)))  {
       ENV->attack_object(MAST);
       tell_room(environment(ENV), ENV->short()+" screams in rage and attacks "+
       MAST->query_name()+".\n");
    
         }  else  {
       
    MARK = first_inventory(environment(ENV));
  
    while(MARK)  {
  
    MARK->stop_fight();          MARK->stop_fight();
    MARK->stop_fight();
    MARK->stop_hunter();         MARK->stop_hunter();
    MARK = next_inventory(MARK);
    
        }
        }
         
    
    destruct(this_object());
    return 1;
       }

  COUNT++;
       }
