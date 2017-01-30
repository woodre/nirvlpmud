#include "/players/jareel/define.h"
inherit "/obj/armor.c";

#define SETNAME HIG+"Set of Shadows"+NORM
#define FULLSETNAME HIG+"Full Set of Shadows"+NORM

string *Armor_pieces;
string soulbinder;

int armor_set;
void add_armor_set();
void del_armor_set();
int query_full_set();

void
reset(int arg) {
    ::reset(arg);
    if (arg) return;

  set_ac(4);
  set_value(40000);
  set_weight(2);
  set_type("armor");
  set_name("plate of darkness");
  set_alias("plate");
  set_short(HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"); 
  set_long(
    "Plate Armor forged in the moon forge of the Red Goddess by the\n"+
	"high blacksmith Kar-relk, The Mighty.  A palpable clinging darkness\n"+ 
	"seeps out of the magical armor.  The encircling darkness seems to\n"+ 
	"empower the magical energy within the encrusted armor.\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "PlateOfDarkness", "BraceletOfDarkness", "MiscOfDarkness", "GuardOfDarkNess" });
     }

status id(string arg) { return ( ::id(arg) || arg == "PlateOfDarkness" || arg == "plate of darkness"); }

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
  else {
    armor_set = 0;
    check_full_set();
    return ::wear(str);
  }
}

set_binder( string str ) { soulbinder = str; }
query_binder() { return soulbinder; }


locker_arg(){        return soulbinder; }
locker_init(arg){    set_binder(arg); }

status check_full_set() {
  int i;

  if(!USER) return 0;
  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if( t && (status)t->query_worn())
      add_armor_set();
  }
  return 1;
}

#if 0 /* Gnar - moved to query_short */
string short() {

  if (query_full_set())
    return (HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+FULLSETNAME+"]"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+" (worn)"+NORM);

  return HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+""+NORM+NORM;
}
#endif

string query_short() {
  string msg;
  if (query_full_set())
    msg = HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+FULLSETNAME+"]"+NORM;
  else
    msg = HIK+"Plate of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM;
  
  if( this_player() && this_player()->query_level() > 50 )
    msg += " <"+armor_set+">";
  return msg;
}

/* Gnar - used to keep track of the set instead of looping through inventory each time **/
query_guild_bonus(){ return 1; }

add_guild_bonus() {
  add_armor_set();
}

remove_guild_bonus() {
  armor_set = 0;
}

do_special(owner) {
  int i;
  if (random(1000) > 200) /* It only hits 20% of the time */
    return 0; 
  if( query_full_set() )
    set_params("physical",2,10,"powerupneck");
}
  
powerupneck(){
  int i;
  i = random(4);

  if(i==1){	
    tell_room(environment(USER),
           HIK+"D A R K N E S S "+NORM+"engulfs "+environment()->query_name()+"'s body "+NORM+BOLD+"\n"+NORM);
	  USER->add_hit_point(10+random(10));
    return 1;
  }
  return 1;
} 

void add_armor_set() {
  armor_set ++;
}

void del_armor_set() {
  if( armor_set > 0 )
    armor_set--;
}

int query_full_set() {
  return (armor_set >= sizeof(Armor_pieces) ? 1 : 0);
}