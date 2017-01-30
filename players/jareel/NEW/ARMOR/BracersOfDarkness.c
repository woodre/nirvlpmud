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
  set_light(1);
  set_short(HIK+"Bracers of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]");
  set_long(
    "Bracers forged in the moon forge of the Red Goddess high blacksmith Kar-relk, the mighty.\n"+
    "A palpable clinging darkness seeps out of the magical bracelet.  The encircling darkness\n"+
	"seems to empower the magical energy withing the encrusted braclet, great power lies within\n");

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

generic_object(){    return 1; }
restore_thing(str){  restore_object(str); return 1; }
save_thing(str){     save_object(str);    return 1; }
locker_arg(){        return soulbinder; }
locker_init(arg){    set_binder(arg); }

status check_full_set() {
  int i;

  if(!USER) return 0;
  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if (!t || !((status)t->query_worn()))
      return 0;
  }
  return 1;
}

string short() {

  if (check_full_set())
    return (HIK+"Bracelet of "+HIK+"Darkness"+NORM+" ["+FULLSETNAME+"]"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Bracelet of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+" (worn)"+NORM);

  return HIK+"Bracelet of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+""+NORM+NORM;
}

int do_special(object owner) {
  int i;
  object hh;
    i = random(10);
      if (i > 1) return 0;
    SuperSpeed = 1;
      command("SuperSpeedGo", owner);
   return 1;
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
 ""+BOLD+me->query_name()+"'s body is engulfed in the swirling "+HIR+"D A R K N E S S"+NORM+" \n      "+BOLD+me->query_name()+" attacks again with blinding speed!!!"+NORM);
  return 1;
}

