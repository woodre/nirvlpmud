/* this is a weapon to replace saber's "HolySinger"
   so that the red dragon will actually have something
   on it that is worth fighting for - Mythos <12-23-97> */
/* Changed the weight to 3.  12 weight?  How very Mythos...
      - Maledicta
*/
/* Changed part of weapon's class and its return to be
   of holy type
     - Illarion Dec 2004
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
    set_class(15);  /* changed part of the wc to good */
   set_short(HIB+"Holysinger"+HIW+", the Blessed Blade"+NORM);
     set_long("An gleaming white longsword of blessed steel.\n"+
       "It is very light, and has a wicked edge to it.\n"+
       "There is a Bardic rune on the hilt.\n");
    set_type("sword"); /* 6.6.01 added by verte */
    set_value(20000);
   set_weight(3);
   set_params("other|good",6,"good_hit"); /* auto-randomized; gives 0-5 damage */
    set_hit_func(this_object());
}

good_hit(attacker) {
  int w;
  string mess, mess2;
  if(tal < BASE) { 
    write("You are no longer worthy to wield the Holy Blade!\n");
    write("Lightning from the heavens strike you!\n");
    say("There is a blinding flash of energy!\n");
    /* same effect as forcing a drop command, but more likely to work properly */
    transfer(this_object(),environment(tp));
    tp->hit_player(DAM);
    return -100; 
  }
  if(tp->query_attrib("str") > random(30) && 
    tp->query_attrib("pie")/4 > random(13)) {
       w = random(36);

    switch(w) {			 
      case 0..1:  
			  mess =  HIB+"Holysinger"+NORM+" gleams with a "+HIW+"pure white fire"+NORM+
				        " as it cleaves through your foe.\n"+
                capitalize(attacker->query_real_name())+" staggers.\n"; 
        mess2 = tpn+"'s "+HIB+"Holysinger"+NORM+" blade gleams with a "+HIW+"pure white fire"+NORM+
				        " as "+this_player()->query_pronoun()+" cleaves through "+
								this_player()->query_possessive()+" foe.\n"+
                 capitalize(attacker->query_real_name())+" staggers.\n";
				break;
		  case 2:
        mess =  "Your sword sings \""+colorize("The Ride of the Valkyries")+"!\"";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("The Ride of the Valkyries")+"!\"";
				break;
      case 3:
        mess =  "Your sword sings \""+colorize("March to the Scaffold")+"\" from Symphonie Fantastique!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("March to the Scaffold")+"\" from Symphonie Fantastique!";
				break;
		  case 4:
        mess =  "Your sword sings \""+colorize("The Hut on Fowls Legs")+"\" from Pictures at an Exhibition!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("The Hut on Fowls Legs")+"\" from Pictures at an Exhibition!";
				break;
		  case 5:
        mess =  "Your sword sings the conclusion to \""+colorize("The 1812 Overture")+"!\"";
        mess2 = this_player()->query_name()+"'s sword sings the conclusion to\""+
                colorize("The 1812 Overture")+"!\"";
				break;	
		  case 6:
        mess =  "Your sword sings \""+colorize("Allegro Molto Vivace")+"\" from Symphony No.6 \"\Pathetique!\"";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Allegro Molto Vivace")+"\" from Symphony No.6 \"\Pathetique!\"";
				break;
		  case 7:
        mess =  "Your sword sings \""+colorize("Polovtslan Dance")+"\" from Prince Igor!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Polovtslan Dance")+"\" from Prince Igor!";
				break;
		  case 8:
        mess =  "Your sword sings \""+colorize("Hungarian March")+"\" from The Damnation of Faust!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Hungarian March")+"\" from The Damnation of Faust!";
				break;
		  case 9:
        mess =  "Your sword sings \""+colorize("Mars, The Bringer of War")+"\" from The Planets!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Mars, The Bringer of War")+"\" from The Planets!";
				break;
		  case 10:
        mess =  "Your sword sings \""+colorize("Prelude to Act III")+"\" from the Lohengrin!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Prelude to Act III")+"\" from the Lohengrin!";
				break;
		  case 11:
        mess =  "Your sword sings \""+colorize("Infernal Dance")+"\" from The Firebird!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Infernal Dance")+"\" from The Firebird!";
				break;
		  case 12:
        mess =  "Your sword sings \""+colorize("Sturmisch Bewegt")+"\" from \"\Titan!\"";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Sturmisch Bewegt")+"\" from \"\Titan!\"";
				break;
		  case 13:
        mess =  "Your sword sings \""+colorize("O Fortuna")+"\" from Camarina Burana!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("O Fortuna")+"\" from Carmina Burana!";
				break;
		  case 14:
        mess =  "Your sword sings \""+colorize("Fortune plango vulnera")+"\" from Camarina Burana!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Fortune plango vulnera")+"\" from Camarina Burana!";
				break;
		  case 15:
        mess =  "Your sword sings \""+colorize("Ella mi fu rapita")+"\" from Rigoletto!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Ella mi fu rapita")+" from Rigoletto!";	
				break;		
		  case 16:
        mess =  "Your sword sings \""+colorize("Allegro Con Brio")+" from Symphony No. 25!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Allegro Con Brio")+"\" from Symphony No. 25!";	
				break;
		  case 17:
        mess =  "Your sword sings \""+colorize("Don Giovanni, A Cenar Teco")+"!\"";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Don Giovanni, A Cenar Teco")+"!\"";		
				break;
		  case 18:
        mess =  "Your sword sings \""+colorize("Dies Irae")+"\" from Requiem, K 626!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Dies Irae")+"\" from Requiem, K 626!";		
				break;	
		  case 19:
        mess =  "Your sword sings \""+colorize("Rex Tremendae")+"\" from Requiem, K 626!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Rex Tremendae")+"\" from Requiem, K 626!";			
				break;
		  case 20:
        mess =  "Your sword sings \""+colorize("Toccata and Fuge in D-Minor")+"!\"";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Toccata and Fuge in D-Minor")+"!\"";	
				break;	
		  case 21:
        mess =  "Your sword sings the Act 1 Chorus from \""+colorize("Ella mi fu rapita")+"!\"";
        mess2 = this_player()->query_name()+"'s sword sings the Act 1 Chorus from \""+
                colorize("Ella mi fu rapita")+"!\"";	
				break;			
		  case 22:
        mess =  "Your sword sings the Servants Chorus from \""+colorize("Don Pasquale")+"!\"";
        mess2 = this_player()->query_name()+"'s sword sings the Servants Chorus from \""+
                colorize("Don Pasquale")+"!\"";		
				break;									
		  case 23:
        mess =  "Your sword sings \""+colorize("Chorus of the Warriors")+"\" from Norma!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Chorus of the Warriors")+"\" from Norma!";
				break;
		  case 24:
        mess =  "Your sword sings the Soldiers Chorus from \""+colorize("Faust")+"!\"";
        mess2 = this_player()->query_name()+"'s sword sings the Soldiers Chorus from \""+
                colorize("Faust")+"!\"";	
				break;	
		  case 25:
        mess =  "Your sword sings \""+colorize("Carmen, les voici!")+"\" from Carmen!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Carmen, les voici!")+"\" from Carmen!";
				break;
		  case 26:
        mess =  "Your sword sings the Gypsy Chorus from \""+colorize("Il Tovatore")+"!\"";
        mess2 = this_player()->query_name()+"'s sword sings he Gypsy Chorus from \""+
                colorize("Il Tovatore")+"!\"";	
				break;	
		  case 27:
        mess =  "Your sword sings \""+colorize("Gli avredi festivi")+"\" from Nabucco!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Gli avredi festivi")+"\" from Nabucco!";
				break;
		  case 28:
        mess =  "Your sword sings \""+colorize("Allegro con brio")+"\" from Symphony No.5 in C minor!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Allegro con brio")+"\" from Symphony No.5 in C minor!";
				break;
		  case 29:
        mess =  "Your sword sings the \""+colorize("Moonlight")+"\" Sonata, Op.27 in C sharp minor!";
        mess2 = this_player()->query_name()+"'s sword sings the \""+
                colorize("Moonlight")+"\" Sonata, Op.27 in C sharp minor!";
				break;
		  case 30:
        mess =  "Your sword sings the \""+colorize("Choral")+"\" Symphony No.9 in D minor!";
        mess2 = this_player()->query_name()+"'s sword sings the \""+
                colorize("Choral")+"\" Symphony No.9 in D minor!";
				break;
		  case 31:
        mess =  "Your sword sings the \""+colorize("Fantasie-Impromptu")+"\" from Impromptu Nr.4 cis-Moll 66!";
        mess2 = this_player()->query_name()+"'s sword sings the \""+
                colorize("Fantasie-Impromptu")+"\" from Impromptu Nr.4 cis-Moll 66!";
				break;
		  case 32:
        mess =  "Your sword sings the the Allegretto from \""+colorize("Faust")+"!\"";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Faust")+"!\"";
				break;
		  case 33:
        mess =  "Your sword sings \""+colorize("Gira la cote")+"\" from the Turandot!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Gira la cote")+"\" from the Turandot!";
				break;
		  case 34:
        mess =  "Your sword sings \""+colorize("Non piangere, Liu")+"\" from the Turandot!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Non piangere, Liu")+"\" from the Turandot!";
				break;
		  case 35:
        mess =  "Your sword sings \""+colorize("Ah! per l'ultima volta")+"\" from the Turandot!";
        mess2 = this_player()->query_name()+"'s sword sings \""+
                colorize("Ah! per l'ultima volta")+"\" from the Turandot!";	
				break;																																																																																																																																																																																																																																																																																																																																															
    }
  }		
  if(mess) {
    tell_object(environment(), "\n"+mess+"\n\n");
    tell_room(environment(environment()), "\n"+mess2+"\n\n", ({ environment() }) );
		if(!random(7)) attacker->heal_self(-5); 
  }    
  return 6;
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

string colorize(string str) {
  string msg, letter;
  int i;
  if(!random(4)) {
    msg = "";
    for(i = 0; i < strlen(str); i++) {
      letter = extract(str,i,i);
      switch(random(13)) {
        case 0: letter = RED+letter; break; 
        case 1: letter = YEL+letter; break;
        case 2: letter = GRN+letter; break;
        case 3: letter = BLU+letter; break;
        case 4: letter = CYN+letter; break;
        case 5: letter = MAG+letter; break;
        case 6: letter = HIR+letter; break;
        case 7: letter = HIY+letter; break;
        case 8: letter = HIG+letter; break;
        case 9: letter = HIB+letter; break;
        case 10: letter = HIC+letter; break;                  
        case 11: letter = HIM+letter; break;
        case 12: letter = HIW+letter; break;
      }
      msg += letter;
    }
    msg += NORM;
    return msg;
  }
  else {
    switch(random(13)) {
      case 0: msg = RED+str+NORM; break; 
      case 1: msg = YEL+str+NORM; break;
      case 2: msg = GRN+str+NORM; break;
      case 3: msg = BLU+str+NORM; break;
      case 4: msg = CYN+str+NORM; break;
      case 5: msg = MAG+str+NORM; break;
      case 6: msg = HIR+str+NORM; break;
      case 7: msg = HIY+str+NORM; break;
      case 8: msg = HIG+str+NORM; break;
      case 9: msg = HIB+str+NORM; break;
      case 10: msg = HIC+str+NORM; break;                  
      case 11: msg = HIM+str+NORM; break;
      case 12: msg = HIW+str+NORM; break;
    }
  return msg;    
  }
}
