
/*
 *           SABER'S COMBAT TOY
 *
 *           IF FOUND IN THE HANDS OF A PLAYER
 *           JUST DEST THE PLAYER.  REALLY.
 *
 */


#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

#define tp this_player()->query_name()
#define TP this_player()
#define TPQ this_player()->query_real_name()
#define TARG capitalize(target)
#define CAP capitalize(str)
 
  id(str)  {
  return str == "ankh"  ||
         str == "Ankh"  ||
         str == "Ankh";
          }

  drop()  { return 1; }
  can_put_and_get()  { return 0; }
  
  short()  { 
  return "An Ankh of worked black silver (worn)";
        }
        
  long()  {
     write( "A gleaming silver ankh hung from a strand of chaos.\n"+
            "It's aura of power almost blinds you.\n");
         }

  get()   {
     object thief;
     if(TP->query_level() < 21) {
     thief = TP;
     write("You touch the silver ankh and recieve an electric shock.\n");
     write("You find yourself somewhere new.\n");
     say(tp+" touches the silver ankh and recieves a shock.\n");
     say(tp+" is turned to dust and blown away by a gust of wind.\n");
     call_other(TP,"move_player","church#room/church.c");
        }
     return 1;
        }
        
  init()  {
    if(((TPQ)=="saber") || ((TPQ)=="devon") || ((TPQ)=="dusty"))  {
    
       add_action("fire_spell","Fire");
       add_action("heal_spell","Heal");
       add_action("powers","Ankh");
       add_action("summon_blade","Soulblade");
       add_action("statue_player","Statue");
       add_action("Terror","Terror");
   }
   else
   {
     write("This ankh was not created for you.\n");
     write("You find yourself some place new.\n");
     say(tp+" is turned to dust and blown away by a gust of wind.\n");
     call_other(TP,"move_player","church#room/church.c");
     return 1;
   }
   }
   
   
fire_spell(str)  {
string target;
int number, check_hp, rnumber;
object ob;

  if(!str || sscanf(str, "%s %d", target, number) != 2)  {
    write("What mere mortal do you wish to incinerate with fire?\n");
    return 1;
        }
        
  ob = present(target,environment(this_player()));
  
  if(!ob)  {
    write("There is no "+TARG+" here to incinerate.\n");
    return 1;
        }
        
  if(number > 500)  {
    write("Do you really wish to do *that* much damage?  Just use zap...\n");
    return 1;
        }
        
   write("\n"+
    "You incinerate "+TARG+" with an inferno of crimson fire.\n\n");
   say("\n"+
    tp+" incinerates "+TARG+" with an inferno of crimson fire.\n\n");
   tell_object(ob, "\nYou feel your blood begin to boil.\n\n");
  check_hp = ob->query_hp();  
  rnumber = random(number);
  ob->hit_player(rnumber);
  write("You did "+rnumber+" points of damage.\n");
  if(number < check_hp)  ob->attck_object(this_player());
  return 1;
        }
 
heal_spell(str)  {
object ob;
string target;
int heal_amount;

  if(!str || sscanf(str, "%s %d", target, heal_amount) !=2)  {
    write("Your ankh whispers: \"\Master, you must type: Heal <player > <#>\n"+
    "to use this power.\n\nThe ankh hums with power.\n");
    return 1;
        }
        
  if(!find_living(target))  {
    write("The ankh hums.\n"+
      "The ankh whispers: \"\Master, I can't find "+capitalize(target)+".\"\n");
    return 1;
        }
        
  ob = find_living(target);
  ob->heal_self(heal_amount);
  
  write("You channel your ankh's powers into "+capitalize(target)+"\n"+
    capitalize(target)+" has been healed "+heal_amount+".\n");
  tell_room(environment(ob), "\n"+
    capitalize(target)+" is covered in an evil gray aura.\n\n");
  return 1;
        }

summon_blade()  {
move_object(clone_object("/players/saber/closed/evil/soulsword.c"),TP);
write("\nThe room dims.\n\nA gate opens, and a demon steps forth.\n"+
  "\nThe demon hands you a SOULBLADE.\n\n");
say("\nThe room dims.\n\nA mystic gate opens, and a demon steps forth.\n"+
  "\nThe demon hands "+this_player()->query_name()+" a SOULBLADE.\n\n");
tell_room(environment(this_player()),
  "\nThe demon departs.\n\n");
  return 1;
        }
  
  
statue_player(str)  {
 object target, curse;
 string room;
 
   if(!str)  {
     write("To use type < Statue 'player name' >\n");
     return 1;
        }
        
   target = find_player(str);
   room = environment(target);

   if(!target)  {
     write("This person is beyond the realms of magic.\n");
     return 1;
        }
        
   curse = clone_object("/players/saber/closed/kill.c");
   move_object(curse,target);
   
   tell_room(room, CAP+
     "\nA silver coin flies into the head and embeds itself into "+
     CAP+"'s forehead.\n\n"+
    "A blue aura of magic turns "+CAP+"'s body to stone.\n");
     write(CAP+" is surrounded by an aura of blue magic.\n"+
     target->query_name()+" has been transformed into a statue!\n");
     return 1;
        }

      
Terror(str)  {
object ob, ob2;
int a;

  if(!str)  {
  ob = first_inventory(environment(this_player()));
  write("You use your Evil Wizard powers to terrorize EVERYBODY!!!\n");
  say(this_player()->query_name()
    +"fills the room with an aura of POWER.\n"+
    "You are VERY afraid.\n");
  while(ob)  {
  if(ob->query_interactive())  {
  if(ob->query_level() < 21)  {
  ob2 = ob;
  ob2->run_away();
        }
        }
  ob = next_inventory(ob);
        }
  return 1;
        }

  ob = present(str, environment(this_player()));
  if(!ob)  {
  write("You do not see "+capitalize(str)+" here to inspire terror in.\n");
  return 1;
        }
        
  write("You use your Evil Wizard power to terrorize "+capitalize(str)+" .\n");
  say(this_player()->query_name()+" uses "+this_player()->query_possessive()
  +" Silver Ankh to terrorify "+capitalize(str)+".\n");
  ob->run_away();
  return 1;
        }
        

powers()  {
  write("Fire\n");
  write("Heal\n");
  write("Soulblade\n");
  write("Statue\n");
  write("Terror\n");
  return 1;
          }
