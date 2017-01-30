/* Bardsword speical attacks */

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
  ROM "+tp+"'s sword sings \""+BOLD+"The Ride of the Valkyries"+NORM+"\"\n\n");
        }
if(w == 3)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"March to the Scaffold"+NORM+"\" from Symphonie Fantastique\n\n");
        }
if(w == 4)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"The Hut on Fowls Legs"+NORM+"\" from Pictures at an Exhibition\n\n");
        }
if(w == 5)  {
  ROM  "+tp+"'s sword sings the conclusion to \""+BOLD+"The 1812 Overture"+NORM+"\"\n\n");
        }
if(w == 6)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Allegro Molto Vivace"+NORM+"\" from Symphony No.6 \"\Pathetique\"\n\n");
        }
if(w == 7)  {
  ROM  "+tp+"'s sword sings the \""+BOLD+"Polovtslan Dance"+NORM+"\" from Prince Igor.\n\n");
        }
if(w == 8)  {
  ROM  "+tp+"'s sword sings the \""+BOLD+"Hungarian March"+NORM+"\" from The Damnation of Faust\n\n");
        }
if(w == 9)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Mars, The Bringer of War"+NORM+"\" from The Planets\n\n");
        }
if(w == 10)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Prelude to Act III"+NORM+"\" from the Lohengrin\n\n");
        }
if(w == 11)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Infernal Dance"+NORM+"\" from The Firebird\n\n");
        }
if(w == 12)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Sturmisch Bewegt"+NORM+"\" from \"\Titan\"\n\n");
        }
if(w == 13)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"O Fortuna"+NORM+"\" from Carmina Burana\n\n");
        }
if(w == 14)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Fortune plango vulnera"+NORM+"\" from Camarina Burana\n\n");
        }
if(w == 15)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Ella mi fu rapita"+NORM+"\" from Rigoletto\n\n");
        }
if(w == 16)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Allegro Con Brio"+NORM+"\" from Symphony No. 25\n\n");
        }
if(w == 17)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Don Giovanni, A Cenar Teco"+NORM+"\"!!!\n\n");
        }
if(w == 18)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Dies Irae"+NORM+"\" from Requiem, K 626\n\n");
        }
if(w == 19)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Rex Tremendae"+NORM+"\" from Requiem, K 626\n\n");
        }
if(w == 20)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Toccata and Fuge in D-Minor"+NORM+"\"\n\n");
        }
if(w == 21)  {
  ROM  "+tp+"'s sword sings the Act 1 Chorus from \""+BOLD+"The Bartered Bride"+NORM+"\"\n\n");
        }
if(w == 22)  {
  ROM  "+tp+"'s sword sings the Servants Chorus from \""+BOLD+"Don Pasquale"+NORM+"\"\n\n");
        }
if(w == 23)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Chorus of the Warriors"+NORM+"\" from Norma\n\n");
        }
if(w == 24)  {
  ROM  "+tp+"'s sword sings the Soldiers Chorus from \""+BOLD+"Faust"+NORM+"\"\n\n");
        }
if(w == 25)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Carmen, les voici!"+NORM+"\" from Carmen\n\n");
        }
if(w == 26)  {
  ROM  "+tp+"'s sword sings the Gypsy Chorus from \""+BOLD+"Il Tovatore"+NORM+"\"\n\n");
        }
if(w == 27)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Gli avredi festivi"+NORM+"\" from Nabucco!!!\n\n");
        }
if(w == 28)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Allegro con brio"+NORM+"\" from Symphony No.5 in C minor \n\n");
        }
if(w == 29)  {
  ROM  "+tp+"'s sword sings the \""+BOLD+"Moonlight"+NORM+"\" Sonata, Op.27 in C sharp minor!\n\n");
        }
if(w == 30)  {
  ROM  "+tp+"'s sword sings the \""+BOLD+"Choral"+NORM+"\" Symphony No.9 in D minor\n\n");
        }
if(w == 31)  {
  ROM  "+tp+"'s sword sings the \""+BOLD+"Fantasie-Impromptu"+NORM+"\" from Impromptu Nr.4 cis-Moll 66\n\n");
        }
if(w == 32)  {
  ROM  "+tp+"'s sword sings the Allegretto from \""+BOLD+"Faust"+NORM+"\"\n\n");
        }
if(w == 33)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Gira la cote"+NORM+"\" from the Turandot\n\n");
        }
if(w == 34)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Non piangere, Liu!"+NORM+"\" from the Turandot\n\n");
        }
if(w == 35)  {
  ROM  "+tp+"'s sword sings \""+BOLD+"Ah! per l'ultima volta"+NORM+"\" from the Turandot\n\n");
        }

  return 6;
        }

    return;
       }
       }
