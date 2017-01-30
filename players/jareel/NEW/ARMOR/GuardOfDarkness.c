#include "/players/jareel/define.h"
inherit "/obj/armor.c";

#define SETNAME HIG+"Set of Shadows"+NORM
#define FULLSETNAME HIG+"Full Set of Shadows"+NORM

object ob;
string *Armor_pieces;
string soulbinder;

     reset(arg) {
       ::reset(arg);

  set_ac(1);
  set_res(1);
  set_value(10000);
  set_weight(1);
  set_type("chest");
  set_name("guard of darkness");
  set_alias("guard");
  set_short(HIK+"Guard of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"); 
  set_long(
    "Guard of Darkness is forged in the moon forge of the Red Goddess by the high blacksmith Kar-relk,\n"+
    "The Mighty.  A palpable clinging darkness seeps out of the magical guard.  The encircling\n"+
	"darkness seems to empower the magical energy within the encrusted armor.\n");


                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "PlateOfDarkness", "BraceletOfDarkness", "MiscOfDarkness", "GuardOfDarkNess" });
     }

status id(string arg) { return ( ::id(arg) || arg == "GuardOfDarkNess" || arg == "guard of darkness"); }

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
    return (HIK+"Guard of "+HIK+"Darkness"+NORM+" ["+FULLSETNAME+"]"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Guard of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+" (worn)"+NORM);

  return HIK+"Guard of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+""+NORM+NORM;
}


do_special(owner) {
  int i;
  if (random(1000) > 200) /* Random 20 returns nothing until you have the full set worn then it gives you some Physical res */ 
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }
    set_params("physical",2,2,"AbsorbDamage");
}
  
    AbsorbDamage(){  /* Special only Triggers if the entire set is worn */
	    int i;
          i = random(4);
        if(i==1){	
         tell_room(environment(USER),
           HIK+"D A R K N E S S "+NORM+"engulfs "+environment()->query_name()+"'s body "+NORM+BOLD+" you feel empowered as the "+HIK+"D A R K N E S S"+NORM+" flows within you!!!@!\n"+NORM);
		 USER->add_hit_point(5+random(15)); /* Entire Set Needs to be Worn for Item to do anything */
		 USER->add_spell_point(5+random(15)); /* Entire Set Needs to be Worn for Item to do anything */
         return 1;}
         return 1;} 