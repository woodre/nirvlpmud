inherit "/obj/weapon.c";
#include "/players/jareel/define.h"

#define SETNAME HIG+"Set of the Berzerker"+NORM
#define FULLSETNAME HIG+"Full Set of the Berzerker"+NORM

object ob;


string *Weapon_pieces_The_Duo;

     reset(arg) {
       ::reset(arg);

     set_name("axe of the berzerker");
     set_value(4200);
	 set_class(20);
     set_weight(1);
     set_type("axe");
     set_short(RED+"Berserker Axe Roar"+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+SETNAME+"]"+NORM);
  set_long(
    "A Ward forged in the moon forge of the Red Goddess high blacksmith Kar-relk, the mighty.\n"+
    "A palpable clinging darkness seeps out of the magical Ward.  The encircling darkness\n"+
	"seems to empower the magical energy within the encrusted Ward, great power lies within\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Weapon_pieces_The_Duo = ({ "ChaosAxeRoar", "ChaosAxeBite" });
     }

status id(string arg) { return ( ::id(arg) || arg == "ChaosAxeRoar" || arg == "axe of roar"); }

init() {
  ::init();
  add_action("test","test");
}

test() {
  int i;
  object *k;
  mapping weaps;
  object wep, who;

  weaps = this_player()->QueryWeapons();
  k = keys( weaps );
  write("Size of weapons: "+ sizeof(k) +"\n");
  for( i=0; i < sizeof(k); i++) {
    write("Weapon["+i+"] : " + k[i]->query_name() + "\n");
  }
  wep = present( "ChaosAxeBite", USER ); 
  if( wep ) {
    write("Found weapon.\n");
    who = wep->query_wielded_by();
    if( who )
      write("Wielded by :"+who->query_name()+"\n");
    if( who == USER )
      write("Wielded by user\n");
  }
}

int wield(string str) { 

if (str && !id(str))
        return 0;
  if ((int)this_player()->query_level() < 19) {
    write("This weapon is too powerful for you to Wield.\n"); 
    return 1; 
  }

  return (::wield(str) ? 1 : 0);
}

status check_full_set() {
  object wep, who;

  if(!USER) return 0;

  wep = present( "ChaosAxeBite", USER ); 
  if( wep ) {
    write("Found weapon.\n");
    who = (object) wep->query_wielded_by();
    if( who )
      write("Wielded by :"+who->query_name()+"\n");
    /** If it is wielded **/
    if( who == USER )
      return 1;
    /** If it is offwield **/
    if( (object) USER->query_second_weapon() == wep )
      return 1;
  }
  return 0;
}

string short() {

  if (check_full_set())
    return (RED+"Berserker Axe Roar"+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+FULLSETNAME+"]"+NORM+" (Wielded)"+NORM);

  if ((status)this_object()->query_wielded())
    return(RED+"Berserker Axe Roar"+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+SETNAME+"]"+NORM+" (Wielded)"+NORM);

  return RED+"Berserker Axe Roar"+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+SETNAME+"]"+NORM+""+NORM+NORM;
}
