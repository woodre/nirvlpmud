
/*
 *           THE TRUE SIGHT OBJECT FOR BARDS 2.0  
 *           6.20.96
 *
 *           By Saber / Geoffrey Z.
 *
 */


#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

 
id(str)  {  return str == "true_sight";  }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
         
        
init()  {    
       add_action("true_sight","look");
       add_action("true_sight","l");
   /*  add_action("move_check"); add_verb("]"); */
        }
        

string WC, AC, SAVE, LEVEL, PWC, PAC, MWC, MAC;       
object ob;

true_sight(str)  {

  object ob_tmp, special;
  string item, short_str, extra_str, sh;
  int max;
  
  if(this_player()->test_dark())  { 
    write("Even with true sight, you can't see in "+BOLD+"dark"+NORM+"?\n");
    return 1;
        }
  
  if(!str)  {

     write(BOLD + call_other(environment(this_player()), "short") + NORM+"\n");
     call_other(environment(this_player()), "long");
          
     ob = first_inventory(environment(this_player()));
     max = 20;
     while(ob && max > 0)  {
       if(ob != this_player())  {
         short_str = call_other(ob, "short");
         if(short_str)  {
           max -=1;
           if(ob->is_player()) 
             write(BOLD+"[PLAY] " +
                   check_level() +
                   check_pwc() +
                   check_pac() +" " + NORM +
                   short_str+".\n");
           else if(ob->is_pet())
             write(HIB+"[PET ] "+NORM + BOLD +
                   check_level() +
                   check_mwc() +
                   check_mac()+" " + NORM +
                   short_str+".\n");
           else if(living(ob))
             write(HIR+"[MON ] "+NORM + BOLD +
                   check_level() +
                   check_mwc() +
                   check_mac()+" " + NORM +
                   short_str+".\n");
           else if(ob->weapon_class() > 0)
             write(HIM+"[WEAP] "+NORM + 
                   BOLD + check_wc() +
                   check_save() + NORM +" "
                   +short_str+".\n");
           else if(ob->armor_class() > 0)
             write(HIG+"[ARMR] "+NORM + 
                   BOLD + check_ac() +
                   check_save() + NORM +" "
                   +short_str+".\n");
           else if(ob->id() == "guild_obj")
             write(HIR+"[GLD ]     "+NORM + sh+".\n");
           else if(ob->id() == "base_obj")
             write(HIR+"[MINI]     "+NORM + sh+".\n");
           else if(ob->query_auto_load())
             write(BOLD+"[AUTO]     "+NORM + sh+".\n");
           else
             write(HIB+"[OTHR]     "+NORM + short_str +".\n");
          }
        }
       ob = next_inventory(ob);
     }
     return 1;
     }
     
     if(sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1)  {
       item = lower_case(item);
       ob = present(item, this_player());
       if(!ob && call_other(environment(this_player()), "id", item))
         ob = environment(this_player()); 
       if(!ob)
         ob = present(item, environment(this_player())); 
       if(!ob)  {
         write("There is no "+BOLD + item + NORM+" here.\n");
         return 1;
       }
       call_other(ob, "long", item);
       if(!call_other(ob, "can_put_and_get", item))
         return 1;
       if(living(ob))  {
         special = first_inventory(ob);
         while(special)  {
           extra_str = call_other(special, "extra_look");
           if(extra_str)
             write(extra_str+".\n");
           special = next_inventory(special);
          }
         }
        ob_tmp = first_inventory(ob);
        while(ob_tmp && call_other(ob_tmp, "short") == 0)
          ob_tmp = next_inventory(ob_tmp);
        if(ob_tmp)  {
          if(living(ob))  {
           if(ob->is_player())  {
            write("\t"+BOLD + capitalize(item)+ NORM+" is carrying:\n");
              }  else  {
            write("\t"+BOLD + HIR + capitalize(item)+ NORM+" is carrying:\n");
              }
          }  else  {
           if(ob->weapon_class() > 0)
              write("\t"+BOLD + HIM + capitalize(item) + NORM+" contains:\n");
           else if(ob->armor_class() > 0)
              write("\t"+BOLD + HIG + capitalize(item) + NORM+" contains:\n");
           else
              write("\t"+BOLD + HIB + capitalize(item) + NORM+" contains:\n");
         }
         max = 20;
         ob = first_inventory(ob);
         while(ob && max > 0)  {
          sh = call_other(ob, "short");
          if(sh)  {
           if(ob->is_player()) 
             write(BOLD+"[PLAY] " +
                   check_level() +
                   check_pwc() +
                   check_pac()+" " + NORM +
                   sh+".\n");
           else if(ob->is_pet())
             write(HIB+"[PET ] "+NORM + BOLD +
                   ob->check_level() +
                   ob->check_mwc() +
                   ob->check_mac()+" " + NORM +
                   sh+".\n");
           else if(living(ob))
             write(HIR+"[MON ] "+NORM + BOLD +
                   check_level() +
                   check_mwc() +
                   check_mac()+" " + NORM +
                   sh+".\n");
           else if(ob->weapon_class() > 0)
             write(HIM+"[WEAP] "+NORM + 
                   BOLD + check_wc() +
                   check_save() + NORM +" "+
                   sh+".\n");
           else if(ob->armor_class() > 0)
             write(HIG+"[ARMR] "+NORM + 
                   BOLD + check_ac() +
                   check_save() + NORM +" "+
                   sh+".\n");
           else if(ob->id() == "guild_obj")
             write(HIR+"[GLD ]     "+NORM + sh+".\n");
           else if(ob->id() == "base_obj")
             write(HIR+"[MINI]     "+NORM + sh+".\n");
           else if(ob->query_auto_load())
             write(BOLD+"[AUTO]     "+NORM + sh+".\n");
           else
             write(HIB+"[OTHR]     "+NORM + sh +".\n");
           }
           ob = next_inventory(ob);
           max -= 1;
         }
         return 1;
       }
       return 1;
     }
     write("Look "+BOLD+"AT"+NORM+" something, or what?\n");
     return 1;
   }



check_wc()  {

       if(ob->weapon_class() < 10)                            WC = ".";
  else if(ob->weapon_class() > 9 && ob->weapon_class() < 16)  WC = "o";
  else WC = "O";
  return WC;
  
          }


check_ac()  {

  if(ob->query_type() == "armor")  {
  
       if(ob->armor_class() < 2)                           AC = ".";
  else if(ob->armor_class() > 1 && ob->armor_class() < 4)  AC = "o";
  else AC = "O";
  
        }  else  {
 
       if(ob->armor_class() < 1)               AC = ".";
  else if(ob->armor_class() == 1)              AC = "o";
  else AC = "O";
 
        }
        
  return AC;
  
        }


check_save()  {

  if(ob->query_save_flag())  { 

    SAVE = " N"; }  else  {  SAVE = "  ";  }
    return SAVE;
        }
  

check_level()  {

       if(ob->query_level() < 8)                            LEVEL = ".";
  else if(ob->query_level() > 7 && ob->query_level() < 15)  LEVEL = "o";
  else   LEVEL = "O";
  return LEVEL;

          }


check_pac()  {

       if(ob->query_ac() < 4)                        PAC = ".";
  else if(ob->query_ac() > 3 && ob->query_ac() < 7)  PAC = "o";
  else   PAC = "O";
  return PAC;

          }
    
          
check_mac()  {

       if(ob->query_ac() < 7)                         MAC = ".";
  else if(ob->query_ac() > 6 && ob->query_ac() < 13)  MAC = "o";
  else   MAC = "O";
  return MAC;

          }


check_pwc()  {

       if(ob->query_wc() < 10)                        PWC = ".";
  else if(ob->query_wc() > 9 && ob->query_wc() < 16)  PWC = "o";
  else   PWC = "O";
  return PWC;

          }
 
    
check_mwc()  {

       if(ob->query_wc() < 10)                        MWC = ".";
  else if(ob->query_wc() > 9 && ob->query_wc() < 19)  MWC = "o";
  else   MWC = "O";
  return MWC;

          }


/*
move_check(str)  {

  object HERE;
  
  if(str == "north" || str == "n" || str == "south" || str == "s" ||
     str == "west" || str == "w" || str == "east" || str == "e" ||
     str == "northwest" || str == "nw" || str == "southwest" || str == "sw" ||
     str == "up" || str == "u" || str == "down" || str == "d")  {
  
  HERE = environment(this_player());
  
  command(str, this_player());
  if(HERE != environment(this_player()));
    command("look", this_player());
    return 1;
  
        }
        }
*/
/*      
    write("\n"+BOLD+"The world comes into focus."+NORM+"\n\n");
    return 1;
          }
  
  if(str == "off")  {
  
    SIGHT_ON = 1;
    
    write("\n"+BOLD+"The wor"+NORM+"l"+BOLD+"d d"+NORM+"ro"+
           BOLD+"ps"+NORM+" o"+BOLD+"u"+NORM+"t of focus.\n\n");
    return 1;
           }

    write("\n");
    write("Key:  \t"+BOLD+"PLAY"+NORM+" = Player       "+HIR+"MON"+NORM+"  = Monster\n");
    write("      \t"+HIB+"PET"+NORM+"  = Kid or Pet   "+BOLD+"AUTO"+NORM+" = Autoload Object\n");
    write("      \t"+HIM+"WEAP"+NORM+" = Weapon       "+HIG+"ARMR"+NORM+" = Armor\n");
    write("      \t"+HIC+"OTHR"+NORM+" = Other\n");
    return 1;
          }
*/
