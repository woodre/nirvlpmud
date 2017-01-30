#include "../defs.h"

status main(string str, object PO, object User) 
{
  object target, comp;
  object temp;  
  int amt; 
  int cost;
  int x, y, z;
  string str1, str2, str3, rcol, how;
  
  if(GHOST) return 0;
  if(!PO->query_venomed()) return 0;

  if(User->query_attack())
    target = (object)User->query_attack();
  else if(!User->query_attack())
  {
    TOU "You can only do this in combat!\n");
    return 1;
  }
  if(!present(target, ENV(User)))
  {
    TOU "You don't see them here!\n");
    return 1;
  }
  if(!target->query_npc())
  {
    TOU "You cannot do this to players!\n");
    return 1;
  }

  cost = (int)target->query_hp() / 3;
  if(cost > User->query_hp())
  {
    TOU	"You are too weak.\n");
    return 1;
  }

  switch(random(5))
  {
    case 0: rcol = HIG; break;
    case 1: rcol = HIB; break;
    case 2: rcol = HIR; break;
    case 3: rcol = HIY; break;
    case 4: rcol = HIK; break;
  }

  switch(random(5))
  {
    case 0: how = "drops"; break;
    case 1: how = "falls"; break;
    case 2: how = "tumbles"; break;
    case 3: how = "slumps"; break; 
    case 4: how = "collapses"; break;
  }

  if(User->query_attack() && target->query_hp() < 50)
  {
    if(((int)target->query_hp() * 10) / ((int)target->query_mhp()) < 1)
    {
      switch(random(7))
      {
        case 0:
          TOU "<"+rcol+"impale"+NORM+"> A lone tentacle shoots out from your body towards "+CAP((string)target->QN)+".\n"+
              "         "+CAP((string)target->QN)+" is struck between "+(string)target->POS+" eyes by a shard of dark matter.\n");
          TRU "<"+rcol+"impale"+NORM+"> A lone tentacle shoots out from "+BOLD+CAP((string)PO->query_symbiote())+NORM+"'s body towards "+(string)target->QN+".\n"+
              "         "+CAP((string)target->QN)+" is struck between "+(string)target->POS+" eyes by a shard of dark matter.\n", ({ User }));
          TRU "         The lifeless corpse of "+CAP((string)target->QN)+" "+how+" to the ground.\n");
          break;
        case 1:        
          TOU "<"+rcol+"dismember"+NORM+"> Tentacles of dark matter lash out and grab "+CAP((string)target->QN)+"'s extremities.\n"+
              "            "+CAP((string)target->QN)+" howls in pain as "+(string)target->POS+" body is pulled to pieces.\n");
          TRU "<"+rcol+"dismember"+NORM+"> Tentacles of dark matter lash out from "+BOLD+CAP((string)PO->query_symbiote())+NORM+" and grab "+CAP((string)target->QN)+"'s extremities.\n"+
              "            "+CAP((string)target->QN)+" howls in pain as "+(string)target->POS+" body is pulled to pieces.\n", ({ User }));
          x = 2 + random(4);
          z = 1;
          for(y = 0; y < x  ; y++)
          {
            switch(y)
            {  
              case 0:
                str1 = "A mutilated torso";
                str2 = "This is the torso of "+CAP((string)target->QN)+".  It appears to have\n"+
                       "had the extremities ripped from it.\n";
                str3 = "torso";
                break;
              case 1..2:
                str1 = "A leg";
                str2 = "This is the leg of "+CAP((string)target->QN)+".  It appears to have\n"+
                       "been ripped from the socket of "+CAP((string)target->QN)+"'s corpse.\n";
                str3 = "leg";
                break;
              case 3..4:
                str1 = "An arm";
                str2 = "This is the arm of "+CAP((string)target->QN)+".  It appears to have\n"+
                       "been ripped from the socket of "+CAP((string)target->QN)+"'s corpse.\n";
                str3 = "arm";
                break; 
            }
            temp = clone_object("obj/corpse.c");
            temp->add_id(str3);
            temp->set_short(str1);
            temp->set_level(5);
            temp->set_long(str2);
            move_object(temp, environment(User));    
          }
          break;
        case 2:        
          TOU "<"+rcol+"decapitate"+NORM+"> A black tendril swings out from you towards "+CAP((string)target->QN)+".\n"+
              "             The dark matter takes "+CAP((string)target->QN)+"'s head off in one quick motion.\n");
          TRU "<"+rcol+"decapitate"+NORM+"> A black tendril swings out from "+BOLD+CAP((string)PO->query_symbiote())+NORM+" towards "+CAP((string)target->QN)+".\n"+
              "             The dark matter takes "+CAP((string)target->QN)+"'s head off in one quick motion.\n", ({ User }));
          TRU "             "+CAP((string)target->QN)+"'s headless body "+how+" to the ground.\n");
          temp = clone_object("obj/corpse.c");
          temp->add_id("head");
          temp->set_short("The head of "+CAP((string)target->QN));
          temp->set_level(1);
          temp->set_long("The head of "+CAP((string)target->QN)+".  It appears to have been\n"+
                         "cleanly severed from the body.\n");
          move_object(temp, environment(User));
          break;  
        case 3:
          TOU "<"+rcol+"devour"+NORM+"> Your symbiotic mouth elongates to a massive size.\n"+
              "         Descending on "+CAP((string)target->QN)+", your jaws of razor sharp teeth snap shut.\n");
          TRU "<"+rcol+"devour"+NORM+"> "+BOLD+CAP((string)PO->query_symbiote())+NORM+"'s symbiotic mouth elongates to a massive size.\n"+
              "         Descending on "+CAP((string)target->QN)+", "+BOLD+CAP((string)PO->query_symbiote())+NORM+"'s jaws of razor sharp teeth snap shut.\n", ({ User }));
          TRU "         "+CAP((string)target->QN)+"'s headless body "+how+" into a heap.\n");
          break;  
        case 4:
          TOU "<"+rcol+"eviscerate"+NORM+"> You point at "+CAP((string)target->QN)+".\n"+
              "             Dozens of strands of dark matter fly out, lashing at "+CAP((string)target->QN)+"'s guts.\n");
          TRU "<"+rcol+"eviscerate"+NORM+"> "+BOLD+capitalize((string)PO->query_symbiote())+NORM+" points at "+(string)target->QN+".\n"+
              "             Dozens of strands of dark matter fly out from "+BOLD+CAP((string)PO->query_symbiote())+NORM+", lashing at "+CAP((string)target->QN)+"'s guts.\n", ({ User }));
          TRU "             "+CAP((string)target->QN)+" "+how+" dead as "+(string)target->POS+" bowels spill out of "+(string)target->POS+" wounds.\n");
          break;  
        case 5:
        	TOU "<"+rcol+"pummel"+NORM+"> Dark matter flails around you striking "+CAP((string)target->QN)+" with blow after blow.\n"+
              "         "+CAP((string)target->QN)+" is dropped to "+(string)target->POS+" knees by the onslaught.\n");
          TRU "<"+rcol+"pummel"+NORM+"> Dark matter flails around "+BOLD+CAP((string)PO->query_symbiote())+NORM+" striking "+(string)target->QN+" with blow after blow.\n"+
              "         "+CAP((string)target->QN)+" is dropped to "+(string)target->POS+" knees by the onslaught.\n", ({ User }));
          TRU "         Within seconds, "+CAP((string)target->QN)+" "+how+" to the ground dead.\n");
          break;   
        case 6:         
          TOU "<"+rcol+"strangle"+NORM+"> Tentacles leap from your free hand and coil around "+CAP((string)target->QN)+"'s neck.\n"+
              "           "+CAP((string)target->QN)+" struggles to free "+(string)target->POS+" neck from the dark matter.\n");
          TRU "<"+rcol+"strangle"+NORM+"> Tentacles leap from "+BOLD+CAP((string)PO->query_symbiote())+NORM+"'s hand and coil around "+CAP((string)target->QN)+"'s neck.\n"+
              "           "+CAP((string)target->QN)+" struggles to free "+(string)target->POS+" neck from the dark matter.\n", ({ User }));
          TRU "           "+CAP((string)target->QN)+"'s eyes roll back into "+(string)target->POS+" head as the life is squeezed from "+(string)target->OBJ+".\n");
          break;    
        }
      User->add_hit_point(-cost);
      target->heal_self(-((int)target->query_hp()));
      target->hit_player(500);
      if(z)
      {
        destruct(present("corpse", ENV(User)));
        z = 0;
      }
      return 1;
    }
    TOU "Your opponent is still too strong.\n");
    return 1;
  }
  TOU "Your opponent is still too strong.\n");
  return 1;
}
