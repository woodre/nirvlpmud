/* 
 * An object to make a monster fumble.
 * Bard v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/treasure";

#define TO this_object()
#define ENV environment(this_object())

object MAST;
int AC, WC, DAMAGE, TOTAL, HITS, OPPONENT, HIT_TOT, OVER;
string MASTER, how, what;

reset(arg)  {
  if(arg) return;
    set_id("fumble_obj");
    call_out("start", 1);
        }

drop()   { return 1;   }
can_put_and_get()  { return 0; }


set_hit(str)  { 
    int ark;  if(sscanf(str, "%d", ark))  { HIT_TOT = ark; }   }

set_master(str)  {  MASTER = str; }


start()  {

  AC = ENV->query_ac();   WC = ENV->query_wc();
  set_heart_beat(1);
  return 1;
    }


heart_beat()  {
int chance;

  chance = random(2);
  
  if(chance < 1)  {
  
  if(DAMAGE = random(WC) - random(AC) > 0)  {
    if(DAMAGE > ENV->query_hp()) DAMAGE = ENV->query_hp() - 1;
     if(!(living(ENV)) )  { end(); } else {
      ENV->hit_player(DAMAGE);
      
    if (DAMAGE < 30) {
      how = " with a bone crushing sound";       what = "smashes";  }
    if (DAMAGE < 20) { how = " very hard";       what = "hits";     }
    if (DAMAGE < 10) { how = " hard";            what = "hits";     }
    if (DAMAGE < 5)  { how = "";                 what = "hits";     }
    if (DAMAGE < 3)  { how = "";                 what = "grazes";   }
    if (DAMAGE == 1) { how = " in the stomach";  what = "tickles";  }
     
    tell_room(environment(ENV), 
      ENV->query_name()+" fumbles and "+what+" "+ENV->query_name()+how+".\n");  
        }
        
     TOTAL = TOTAL + DAMAGE;
     if(TOTAL > 20 && OVER < 20)  { OVER = TOTAL + DAMAGE; 
        DAMAGE = TOTAL - 20;  } else { OVER = TOTAL + DAMAGE; }
     if(TOTAL > 20)  {
       if(!(MAST = find_player(MASTER)))  { end(); }  else  {
         OPPONENT = ENV->query_hp() * 100 / ENV->query_mhp();
         call_other(MAST, "add_spell_point", -DAMAGE);
         tell_object(MAST, 
            BOLD+"[ "+OPPONENT+"% opponent  "+DAMAGE+" fumble mana spent]\n"+NORM);
    }
    }
    }
   HITS = HITS + 1;
   if(HITS > HIT_TOT)  {
   tell_room(environment(ENV),
     ENV->short()+" stops fumbling.\n");
   end();
    }
    }

    }


end()  {
  set_heart_beat(0);
  destruct(this_object());
  return 1;
    }
