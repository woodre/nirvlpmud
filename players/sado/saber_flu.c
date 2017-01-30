/*
 *    A flu virus coded by Saber.
 *    5/4/95
 *
 *    To destory, simply <dest flu>
 *
 */

#include "/obj/clean.c"

#define tp  this_player()->query_name()
#define TP  this_player()
#define TPQ environment(this_object()) 

  id(str)  { return str == "flu" || str == "infection";  }
  
  get()    { return 1;   }
  drop()   { return 1;   }
  can_put_and_get()  { return 0; }
query_auto_load() { return "/players/sado/saber_flu.c:"; }
  
  init()  {
    add_action("sneeze","sneeze");
    if(TPQ->query_level() < 6)  destruct(this_object());
    if(present("no_disease", this_player()))  {
      destruct(this_object());
            }
    call_out("disease_check", 45);
    call_out("go_away",1000 + random(6000));
           }


sneeze(str)  {
object target, flu;
int sneeze_check;

  if(!str || !(target = present(str, environment(TP))))  {
    sneeze_check = random(4);
    if(sneeze_check == 0)  {
      write("You let off a *huge* sneeze.\n");
      say(tp+" lets of a *huge* sneeze.\n");
              }
    if(sneeze_check == 1)  {
      write("You sneeze, sending snot flying across the room.\n");
      say(tp+" sneezes, sending snot flying across the room.\n");
              }
    if(sneeze_check == 2)  {
      write("You sneeze a mighty sneeze.\n");
      say(tp+" sneezes a mighty sneeze.\n");
              }
    if(sneeze_check == 3)  {
      write("You sneeze, spraying the room with mucus.\n");
      say(tp+" sneezes, spraying the room with mucus.\n");
              }
    return 1;
              }
    
    if(TP->query_real_name() == str)  {
      write("You sneeze on yourself.  Eeeewww...\n");
      say(tp+" sneezes on "+target->query_objective()+"self.  Eewwwww...\n");
      return 1;
              }
    
     if(target->query_invis() > 20) return 1; /* Added this in so that players wont sneeze on invis wizes - mythos <12/5/95> */

    write("You sneeze on "+capitalize(str)+", covering "+
          target->query_objective()+" with mucus.\n");
    say(tp+" sneezes on "+capitalize(str)+", covering "+
          target->query_objective()+" with mucus.\n");
    sneeze_check = random(10);
    if(sneeze_check > 7)  {
      if(!present("flu", target))  {
flu = clone_object("/players/sado/saber_flu.c");
        move_object(flu, target);
        tell_object(target, "\nYou begin to feel sick.\n");
              }
              }
    return 1;
              }
        

disease_check()  {
int sneeze_chance, count, all_wet;
object target, flu, check;
string name;

  sneeze_chance = random(50);
  count = 0;
  
  if(sneeze_chance > 35  && sneeze_chance < 42)  {
    command("sneeze", TPQ);
    call_out("disease_check",45);
    return 1;
            }

  if(sneeze_chance > 41)  {
    check = first_inventory(environment(TPQ));
    while(check)  {
      if(check->is_player()) count = count + 1;
      check = next_inventory(check);
            }
    
    if(count < 2)  {
      command("sneeze", TPQ);
      call_out("disease_check",45);
      return 1;
            }
    
    sneeze_chance = (1 + random(count));
            
    check = first_inventory(environment(TPQ));
    while(check)  {
      if(check->is_player())  {
         all_wet = all_wet + 1;
         if(sneeze_chance == all_wet)  {
flu = clone_object("/players/sado/saber_flu.c");
            name = check->query_real_name();
            target = present(name, environment(TPQ));
            if(!target)  {
               command("sneeze "+name, TPQ);
               call_out("disease_check",45);
               return 1;
                          }
            if(!present("flu", target))  {
              move_object(flu, target);
              command("sneeze "+name, TPQ);
              tell_object(target, "\nYou begin to feel sick.\n");
                    }
                    }
            }
        check = next_inventory(check);
            }
    
    say("\nYou feel sick.\n");
    call_out("disease_check", 45);
    return 1;
            }
    call_out("disease_check", 45);
    return 1;
            }


go_away()  {
  say("\nYou suddenly feel better.\n"+
      "You are no longer sick.\n\n");
  remove_call_out("disease_check");    
  destruct(this_object());
  return 1;
          }
