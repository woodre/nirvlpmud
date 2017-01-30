inherit "/obj/armor.c";
#include "/players/jareel/define.h"

#define SETNAME HIG+"Set of Shadows"+NORM
#define FULLSETNAME HIG+"Full Set of Shadows"+NORM
string soulbinder;

object ob;


string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("ward of darkness");
     set_ac(1);
	 set_res(1);
     set_value(4200);
     set_weight(1);
     set_type("misc");
     set_short(HIK+"Ward of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM);
  set_long(
    "A Ward forged in the moon forge of the Red Goddess high blacksmith Kar-relk, the mighty.\n"+
    "A palpable clinging darkness seeps out of the magical Ward.  The encircling darkness\n"+
	"seems to empower the magical energy within the encrusted Ward, great power lies within\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "PlateOfDarkness", "BraceletOfDarkness", "MiscOfDarkness", "GuardOfDarkNess" });
     }

status id(string arg) { return ( ::id(arg) || arg == "MiscOfDarkness" || arg == "ward of darkness"); }


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
    return (HIK+"Ward of "+HIK+"Darkness"+NORM+" ["+FULLSETNAME+"]"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Ward of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+" (worn)"+NORM);

  return HIK+"Ward of "+HIK+"Darkness"+NORM+" ["+SETNAME+"]"+NORM+""+NORM+NORM;
}


do_special(owner) {
  int i;
  if (random(1000) > 900) 
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }
    set_params("physical",2,2,"ProfromPhys");
    set_params("other|dark",2,2,"ProfromDark");
}

    ProFromDark(){
         tell_room(environment(USER),
           ""+BOLD+" <<>>"+RED+"Power returns to "+environment()->query_name()+"'s body "+NORM+BOLD+"<<>>\n"+NORM);
		 USER->add_hit_point(5+random(5));
         return 1;}
		 
    ProFromPhys(){
         tell_room(environment(USER),
           ""+BOLD+" <<>>"+RED+"Power returns to "+environment()->query_name()+"'s body "+NORM+BOLD+"<<>>\n"+NORM);
		 USER->add_hit_point(5+random(5));
         return 1;}
