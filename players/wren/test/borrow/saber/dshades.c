
/*
 *           SABER'S COOL SHADES  -  6.15.96
 *
 *           SEE NIRVANA IN A WHOLE NEW LIGHT.
 *                    HONEST
 *
 */


#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"
   
inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_name(BOLD+"dark shades"+NORM);
   set_short(BOLD+"Dark Shades"+NORM);
   set_alias("shades");
   set_long("\nA pair of exquisitly crafted sunglasses.  They have been\n"+
            "constructed from some sort of adamantite alloy, and are\n"+
            "both lightweight and indestructable.\n\n"+
            "Upon closer inspection, you notice tiny mesh wiring running\n"+
            "through both the lens and frame.  Typing "+BOLD+"shades help"+
            NORM+" will\n"+
            "give you instructions on how to use the "+BOLD+"Dark Shades"+
            NORM+".\n\n");
   set_type("helmet");
   set_ac(1);
   set_weight(1);
   set_value(500);
        }
         
        
init()  {
  ::init();
      
       add_action("special_sight","look");
       add_action("special_sight","l");       
       add_action("activate","shades");
       
        }
        

special_sight(str, remote)  {

  object ob, ob_tmp, special;
  string item, short_str, extra_str, sh;
  int max, line_check;
  
  if(this_player()->test_dark())  { 
    write("You're wearing "+BOLD+"shades"+NORM+".  How are you going "+
    "to see in the "+BOLD+"dark"+NORM+"?\n");
    return 1;
        }
  
  if(!str)  {
   if(remote && call_other(this_player(), "query_brief"))  {
     write(BOLD + call_other(environment(this_player()), "short") + NORM);
     write("\n");
     
        }  else  {
     
     write(BOLD + call_other(environment(this_player()), "short") + NORM+"\n");
     call_other(environment(this_player()), "long");
     
   }
     
     line_check = 0;
     ob = first_inventory(environment(this_player()));
     max = 20;
     while(ob && max > 0)  {
       if(ob != this_player())  {
         short_str = call_other(ob, "short");
         if(short_str)  {
           max -=1;
           if(ob->is_player()) 
             write(BOLD+"[PLAY] "+NORM + short_str +".\n");
           else if(ob->is_pet())
             write(HIB+"[PET ] "+NORM + short_str +".\n");
           else if(living(ob))
             write(HIR+"[MON ] "+NORM + short_str +".\n");
           else if(ob->weapon_class() > 0)
             write(HIM+"[WEAP] "+NORM + short_str +".\n");
           else if(ob->armor_class() > 0)
             write(HIG+"[ARMR] "+NORM + short_str +".\n");
           else
             write(HIC+"[OTHR] "+NORM + short_str +".\n");
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
         ob = environment(this_player()); line_check = 1;
       if(!ob)
         ob = present(item, environment(this_player())); line_check = 0;
       if(!ob)  {
         write("There is no "+BOLD + item + NORM+" here.\n");
         return 1;
       }
       write("\n"+BOLD+"]]"+NORM + HIB+" Data Feed:"+NORM+"\n");
       if(!line_check) write("\n");
       call_other(ob, "long", item);
       if(!call_other(ob, "can_put_and_get", item)) {
         write(BOLD+"]]"+NORM + HIB+" End Feed..."+NORM+"\n\n");
         return 1;
         }
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
              write("\t"+BOLD + HIC + capitalize(item) + NORM+" contains:\n");
         }
         max = 20;
         ob = first_inventory(ob);
         while(ob && max > 0)  {
          sh = call_other(ob, "short");
          if(sh)  {
           if(ob->is_player()) 
             write(BOLD+"[PLAY] "+NORM + sh+".\n");
           else if(ob->is_pet())
             write(HIB+"[PET ] "+NORM + sh+".\n");
           else if(living(ob))
             write(HIR+"[MON ] "+NORM + sh+".\n");
           else if(ob->weapon_class() > 0)
             write(HIM+"[WEAP] "+NORM + sh+".\n");
           else if(ob->armor_class() > 0)
             write(HIG+"[ARMR] "+NORM + sh+".\n");
           else if(ob->query_auto_load())
             write(BOLD+"[AUTO] "+NORM + sh+".\n");
           else
             write(HIC+"[OTHR] "+NORM + sh+".\n");
           }
           ob = next_inventory(ob);
           max -= 1;
         }
         write("\n"+BOLD+"]]"+NORM + HIB+" End Feed..."+NORM+"\n\n");
         return 1;
       }
       return 1;
     }
     write("Look "+BOLD+"AT"+NORM+" something, or what?\n");
     return 1;
   }
       


activate(str)  {

/*
  if(str == "on")  {
    
    SIGHT_ON = 0;
      
    write("\n"+BOLD+"The world comes into focus."+NORM+"\n\n");
    return 1;
          }
  
  if(str == "off")  {
  
    SIGHT_ON = 1;
    
    write("\n"+BOLD+"The wor"+NORM+"l"+BOLD+"d d"+NORM+"ro"+
           BOLD+"ps"+NORM+" o"+BOLD+"u"+NORM+"t of focus.\n\n");
    return 1;
           }
*/

    write("\n");
/*
    write("To disengage the special sight:  shades off\n\n");
    write("To activate your special sight:  shades on\n");
*/
    write("Key:  \t"+BOLD+"PLAY"+NORM+" = Player       "+HIR+"MON"+NORM+"  = Monster\n");
    write("      \t"+HIB+"PET"+NORM+"  = Kid or Pet   "+BOLD+"AUTO"+NORM+" = Autoload Object\n");
    write("      \t"+HIM+"WEAP"+NORM+" = Weapon       "+HIG+"ARMR"+NORM+" = Armor\n");
    write("      \t"+HIC+"OTHR"+NORM+" = Other\n");
    return 1;
          }
