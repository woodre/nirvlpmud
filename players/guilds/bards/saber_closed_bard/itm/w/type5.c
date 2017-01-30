/* Bardsword special attacks */

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

#define tp this_player()->query_name()
#define ENV environment(this_object())
#define ATTACKER capitalize(attacker->query_real_name())
#define INSTR present("instrument", this_player())
#define BLVL INSTR->query_bard_level()/2
#define ROM tell_room(environment(this_player()), "\n

weapon_hit(attacker)  {
int w;
    
 if(this_player()->query_guild_name() == "bard")  {
 if(random(75) < (BLVL + this_player()->query_attrib("mag")))  {
  w = random(34) + 2;
  
  write("The "+BOLD+"Bardsword"+NORM+" gleams with "+
              HIR+"Stormfire"+NORM+" as it cleaves through your foe.\n");
  say(tp+"'s "+BOLD+"Bardsword"+NORM+" gleams with "+HIR+"Stormfire"+NORM+" as "+
           this_player()->query_pronoun()+" cleaves through "+
           this_player()->query_possessive()+" foe.\n"); 
    
if(w == 2)  {
  ROM "+tp+"'s sword sings \""+BOLD+"Relax"+NORM+"\" by \"Frankie Goes to Hollywood\".\n\n");
        }
if(w == 3)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Love You More"+NORM+"\" by \"Sun Scream\".\n\n");
        }
if(w == 4)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"True Faith"+NORM+"\" by \"New Order\".\n\n");
        }
if(w == 5)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Terrible Lie"+NORM+"\" by \"Nine Inch Nails\".\n\n");
        }
if(w == 6)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"More Human Then Human"+NORM+"\" by \"White Zombie\".\n\n");
        }
if(w == 7)  {
  ROM  "+tp+"'s sword sings the \""+BOLD+"Thunder Kiss 65"+NORM+"\" by \"White Zombie\".\n\n");
        }
if(w == 8)  {
  ROM  "+tp+"'s sword sings the \""+BOLD+"Spice"+NORM+"\" by \"EON\".\n\n");
        }
if(w == 9)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Send Me an Angel"+NORM+"\" by \"Real Life\".\n\n");
        }
if(w == 10)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Join in the Chant"+NORM+"\" by \"Nitzer Ebb\".\n\n");
        }
if(w == 11)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"White Lions"+NORM+"\" by \"Duran Duran\".\n\n");
        }
if(w == 12)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Brand New Lover"+NORM+"\" by \"Dead or Alive\".\n\n");
        }
if(w == 13)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Sensuality"+NORM+"\" by \"Bjork\".\n\n");
        }
if(w == 14)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Head Like A Hole"+NORM+"\" by \"Nine Inch Nails\".\n\n");
        }
if(w == 15)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Headhunter"+NORM+"\" by \"Front 242\".\n\n");
        }
if(w == 16)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Lightning Man"+NORM+"\" by \"Nitzer Ebb\".\n\n");
        }
if(w == 17)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Strangelove"+NORM+"\" by \"Depesh Mode\".\n\n");
        }
if(w == 18)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"A Little Respect"+NORM+"\" by \"Erasure\".\n\n");
        }
if(w == 19)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Bizzare Love Triangle"+NORM+"\" by \"New Order\".\n\n");
        }
if(w == 20)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Spin Me Round"+NORM+"\" by \"Dead or Alive\".\n\n");
        }
if(w == 21)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Cuts You Up"+NORM+"\" by \"Peter Murphy\".\n\n");
        }
if(w == 22)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Boy"+NORM+"\" by \"Book of Love\".\n\n");
        }
if(w == 23)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Sin"+NORM+"\" by \"Nine Inch Nails\".\n\n");
        }
if(w == 24)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"I Sit on Acid"+NORM+"\" by \"Lords of Acid\".\n\n");
        }
if(w == 25)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Down In It"+NORM+"\" by \"Nine Inch Nails\".\n\n");
        }
if(w == 26)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Halloween"+NORM+"\" by \"Ministry\".\n\n");
        }
if(w == 27)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Just Like Heaven"+NORM+"\" by \"The Cure\".\n\n");
        }
if(w == 28)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Images of Heaven"+NORM+"\" by \"Peter Godwin\".\n\n");
        }
if(w == 29)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Its My Life"+NORM+"\" by \"Talk Talk\".\n\n");
        }
if(w == 30)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"The Promise"+NORM+"\" by \"When In Rome\".\n\n");
        }
if(w == 31)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Living In Oblivion"+NORM+"\" by \"Anything Box\".\n\n");
        }
if(w == 32)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"On'Lamour"+NORM+"\" by \"Erasure\".\n\n");
        }
if(w == 33)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"1979"+NORM+"\" by \"Smashing Pumpkins\".\n\n");
        }
if(w == 34)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Closer"+NORM+"\" by \"Nine Inch Nails\".\n\n");
        }
if(w == 35)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"O Fortuna"+NORM+"\" by \"Apotheosis\".\n\n");
        }

  return 6;
        }

    return;
       }
       }
