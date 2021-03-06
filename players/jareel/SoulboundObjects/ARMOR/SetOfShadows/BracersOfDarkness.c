inherit "/obj/armor.c";
#include "/players/jareel/define.h"
 
#define SETNAME HIG+"Set of Shadows"+NORM
#define FULLSETNAME HIG+"Full Set of Shadows"+NORM
 
string *Armor_pieces;
string soulbinder;
status SuperSpeed; 
object Owner;

void
init()
{
  ::init();
  add_action("SuperSpeedGo","SuperSpeedGo");
}
  
void
reset(int arg) {
    ::reset(arg);
    if (arg) return;

  set_name("bracers");
  set_ac(0);
  set_value(4000); 
  set_weight(1);
  set_type("bracelet");
  set_short(HIK+"Bracers of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]");
  set_long(
    "Bracers forged in the moon forge of the Red Goddess high blacksmith\n"+
	"Kar-relk, the mighty. A palpable clinging darkness seeps out of the\n"+ 
	"magical bracelet.  The encircling darkness seems to empower the magical\n"+ 
	"energy withing the encrusted braclet, great power lies within.\n");

	/* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "PlateOfDarkness", "BraceletOfDarkness", "MiscOfDarkness", "GuardOfDarkNess" });
     }

status id(string arg) { return ( ::id(arg) || arg == "BraceletOfDarkness" || arg == "bracelet of darkness"); }

long() {
  ::long();
  if( soulbinder )
    write(this_object()->short()+" is soulbound to "+capitalize(soulbinder)+".\n");
}

wear( string str ) {
  if (str && !id(str))
        return 0;
  if( id(str) && this_player() && present(this_object(), this_player()) &&
      this_player()->query_real_name() != soulbinder )
  {
    write("For some reason you are unable to wear this armor.\n");
    return 1;
  }
  else
    return ::wear(str);
}

set_binder( string str ) { soulbinder = str; }
query_binder() { return soulbinder; }


locker_arg(){        return soulbinder; }
locker_init(arg){    set_binder(arg); }

status check_full_set() {
  object PlateOfDarkness;
  if( USER ) {
    PlateOfDarkness = present("PlateOfDarkness", USER);
    if( PlateOfDarkness )
      return (int) PlateOfDarkness->query_full_set();
  }
  return 0;
}

/* string short() {

  if (check_full_set())
    return (HIK+"Bracelet of "+HIK+"Darkness"+NORM+" ["+FULLSETNAME+"]"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Bracelet of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+" (worn)"+NORM);

  return HIK+"Bracelet of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+""+NORM+NORM;
} */

string query_short() {
  
  if (check_full_set())
    return HIK+"Bracelet of "+HIK+"Darkness"+NORM+" ["+FULLSETNAME+"]"+NORM;
  else
    return HIK+"Bracelet of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM;
}

int do_special(object owner) {

  if( check_full_set() && !random(10)  ) {
    SuperSpeed = 1;
      command("SuperSpeedGo", owner);
    return 1;
  }
}

/* Gnar - used to keep track of the set instead of looping through inventory each time **/
query_guild_bonus(){ return 1; }

add_guild_bonus() {
  object PlateOfDarkness;
  PlateOfDarkness = present("PlateOfDarkness", USER);
  if( PlateOfDarkness )
    return (int) PlateOfDarkness->add_armor_set();
}

remove_guild_bonus() {
  object PlateOfDarkness;
  PlateOfDarkness = present("PlateOfDarkness", USER);
  if( PlateOfDarkness )
    return (int) PlateOfDarkness->del_armor_set();
}

int SuperSpeedGo() {
  object wep, att, me;
  if (!SuperSpeed)
    return 1;
  SuperSpeed = 0;
  me = this_player();
  att = (object)me->query_attack();
  wep = (object)me->query_weapon();
  if (!att)
    return 1;
  me->toggle_already_fight(1);
  me->attack();

  if (wep)
    wep->hit(att);
tell_room(environment(me), 
 ""+BOLD+me->query_name()+"'s body is engulfed in the swirling "+HIR+"D A R K N E S S"+NORM+"\n"+
 ""+BOLD+me->query_name()+" attacks again with blinding speed!!!"+NORM+"\n");
  return 1;
}

