/* this is a weapon to replace saber's "HolySinger"
   so that the red dragon will actually have something
   on it that is worth fighting for - Mythos <12-23-97> */
/* Changed the weight to 3.  12 weight?  How very Mythos...
      - Maledicta
*/

#include "/players/mythos/closed/ansi.h"
#define BASE 750
#define DAM 20
#define to this_object()
#define eo environment(to)
#define tp this_player()
#define tpn tp->query_name()
#define tal tp->query_alignment()
#define ATT attacker->query_name()
#define ROM tell_room(environment(tp), "\n

inherit "obj/weapon";

/* id() tweaked 6.6.01 by verte */
id(str)
{
    if(::id(str)) return 1;
    else return(str == "weapon" || str == "holy" || str == "HOLY" || str == "holysinger" || str == "holy blade"); }

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_class(20);
   set_short(HIB+"Holysinger"+HIW+", the Blessed Blade"+NORM);
     set_long("An gleaming white longsword of blessed steel.\n"+
       "It is very light, and has a wicked edge to it.\n"+
       "There is a Bardic rune on the hilt.\n");
    set_type("sword"); /* 6.6.01 added by verte */
    set_value(20000);
   set_weight(3);
    set_hit_func(this_object());
}

weapon_hit(attacker) {
    int w;
    if(tal < BASE) { write("You are no longer worthy to wield the Holy Blade!\n");
                    write("Lightning from the heavens strike you!\n");
                    say("There is a blinding flash of energy!\n");
                    command("drop HOLY",tp);
                    tp->hit_player(DAM);
                    return -100; }
    if(tp->query_attrib("str") > random(30) &&
       tp->query_attrib("pie")/4 > random(13)) {
       w = random(36);

if(w < 2)  {
       write("Holysinger gleams with a pure white fire as it cleaves through your foe.\n");
       write(capitalize(attacker->query_real_name())+" staggers.\n");
       say(tpn+"'s Holysinger blade gleams with a pure white fire as "+this_player()->query_pronoun()+" cleaves through "+this_player()->query_possessive()+" foe.\n"+
         capitalize(attacker->query_real_name())+" staggers.\n");
    }
if(w == 2)  {
  ROM "+tpn+"'s sword sings \"\The Ride of the Valkyries\"\n\n");
        }
if(w == 3)  {
  ROM  "+tpn+"'s sword sings \"\March to the Scaffold\"\ from Symphonie Fantastique\n\n");
        }
if(w == 4)  {
  ROM  "+tpn+"'s sword sings \"\The Hut on Fowls Legs\"\ from Pictures at an Exhibition\n\n");
        }
if(w == 5)  {
  ROM  "+tpn+"'s sword sings the conclusion to \"\The 1812 Overture\"\n\n");
        }
if(w == 6)  {
  ROM  "+tpn+"'s sword sings \"\Allegro Molto Vivace\"\ from Symphony No.6 \"\Pathetique\"\n\n");
        }
if(w == 7)  {
  ROM  "+tpn+"'s sword sings the \"\Polovtslan Dance\"\ from Prince Igor.\n\n");
        }
if(w == 8)  {
  ROM  "+tpn+"'s sword sings the \"\Hungarian March\"\ from The Damnation of Faust\n\n");
        }
if(w == 9)  {
  ROM  "+tpn+"'s sword sings \"\Mars, The Bringer of War\"\ from The Planets\n\n");
        }
if(w == 10)  {
  ROM  "+tpn+"'s sword sings \"\Prelude to Act III\"\ from the Lohengrin\n\n");
        }
if(w == 11)  {
  ROM  "+tpn+"'s sword sings \"\Infernal Dance\"\ from The Firebird\n\n");
  attacker->heal_self(-5);      }
if(w == 12)  {
  ROM  "+tpn+"'s sword sings \"\Sturmisch Bewegt\"\ from \"\Titan\"\n\n");
        }
if(w == 13)  {
  ROM  "+tpn+"'s sword sings \"\O Fortuna\"\ from Carmina Burana\n\n");
  attacker->heal_self(-5);
        }
if(w == 14)  {
  ROM  "+tpn+"'s sword sings \"\Fortune plango vulnera\"\ from Camarina Burana\n\n");
        }
if(w == 15)  {
  ROM  "+tpn+"'s sword sings \"\Ella mi fu rapita\"\ from Rigoletto\n\n");
        }
if(w == 16)  {
  ROM  "+tpn+"'s sword sings \"\Allegro Con Brio\"\ from Symphony No. 25\n\n");
        }
if(w == 17)  {
  ROM  "+tpn+"'s sword sings \"\Don Giovanni, A Cenar Teco\"\!!!\n\n");
        }
if(w == 18)  {
  ROM  "+tpn+"'s sword sings \"\Dies Irae\"\ from Requiem, K 626\n\n");
        }
if(w == 19)  {
  ROM  "+tpn+"'s sword sings \"\Rex Tremendae\"\ from Requiem, K 626\n\n");
        }
if(w == 20)  {
  ROM  "+tpn+"'s sword sings \"\Toccata and Fuge in D-Minor\"\n\n");
        }
if(w == 21)  {
  ROM  "+tpn+"'s sword sings the Act 1 Chorus from \"\The Bartered Bride\"\n\n");
        }
if(w == 22)  {
  ROM  "+tpn+"'s sword sings the Servants Chorus from \"\Don Pasquale\"\n\n");
        }
if(w == 23)  {
  ROM  "+tpn+"'s sword sings \"\Chorus of the Warriors\"\ from Norma\n\n");
   attacker->heal_self(-5);        }
if(w == 24)  {
  ROM  "+tpn+"'s sword sings the Soldiers Chorus from \"\Faust\"\n\n");
        }
if(w == 25)  {
  ROM  "+tpn+"'s sword sings \"\Carmen, les voici!\"\ from Carmen\n\n");
        }
if(w == 26)  {
  ROM  "+tpn+"'s sword sings the Gypsy Chorus from \"\Il Tovatore\"\n\n");
        }
if(w == 27)  {
  ROM  "+tpn+"'s sword sings \"\Gli avredi festivi\"\ from Nabucco!!!\n\n");
        }
if(w == 28)  {
  ROM  "+tpn+"'s sword sings \"\Allegro con brio\"\ from Symphony No.5 in C minor \n\n");
        }
if(w == 29)  {
  ROM  "+tpn+"'s sword sings the \"\Moonlight\"\ Sonata, Op.27 in C sharp minor!\n\n");
        }
if(w == 30)  {
  ROM  "+tpn+"'s sword sings the \"\Choral\"\ Symphony No.9 in D minor\n\n");
        }
if(w == 31)  {
  ROM  "+tpn+"'s sword sings the \"\Fantasie-Impromptu\"\ from Impromptu Nr.4 cis-Moll 66\n\n");
        }
if(w == 32)  {
  ROM  "+tpn+"'s sword sings the Allegretto from \"\Faust\"\n\n");
        }
if(w == 33)  {
  ROM  "+tpn+"'s sword sings \"\Gira la cote\"\ from the Turandot\n\n");
        }
if(w == 34)  {
  ROM  "+tpn+"'s sword sings \"\Non piangere, Liu!\"\ from the Turandot\n\n");
        }
if(w == 35)  {
  ROM  "+tpn+"'s sword sings \"\Ah! per l'ultima volta\"\ from the Turandot\n\n");
        }

  return 6;
  }
    return;
}

get() {
    if(tal < BASE) {
        write("You are not worthy enough to touch this blade!\n");
        write("Lightning from the heavens strike you!\n");
        say(tpn+" yelps as "+tp->query_pronoun()+" attempts to touch the Holy Singer.\n");
        tp->hit_player(DAM);
    return 0;}
return 1; }

init()  {
  ::init();
add_action("new_wield","wield");
add_action("new_wield","ready");
        }
query_name() { return "HolySinger"; }

new_wield(str)  {
if(id(str))  {
write("\nYou feel a surge of power as you wield HOLYSINGER.\n\n");
say("\n"+tpn+" is surrounded by a blue aura as "+this_player()->query_pronoun()+" wields HOLYSINGER.\n\n");
  return 0;
        }
        }
