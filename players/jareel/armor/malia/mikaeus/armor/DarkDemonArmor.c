#include "/players/jareel/define.h"
inherit "/obj/armor.c";

#define SETNAME HIG+"Set of the Underworld"+NORM
#define FULLSETNAME HIG+"Full Set of the Underworld"+NORM

object ob;
string *Armor_pieces;
string soulbinder;

void
reset(int arg) {
    ::reset(arg);
    if (arg) return;

  set_ac(1);
  set_res(10);
  set_value(100);
  set_weight(2);
  set_type("armor");
  set_name("plate of the underworld");
  set_alias("plate");
  set_short(HIK+"Plate of "+HIK+"Evil"+NORM+" ["+RED+"Demon Fire"+NORM+HIK+"] ["+SETNAME+"]"); 
  set_long(
    "Plate Armor forged in the demon fire forge of the Malia blacksmith Mikaeus, the Umhallowed.\n"+
    "A palpable clinging evil seeps out of the magical platemail.  The encircling evil sweeps out\n"+
	"of the dark armor and empowers the plate with magical energy.\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "PlateOfTheUnderworld", "BraceletOfDarkness", "MiscOfDarkness", "GuardOfDarkNess" });
     }

status id(string arg) { return ( ::id(arg) || arg == "PlateOfTheUnderworld" || arg == "plate of the unswerworld"); }

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
    return (HIK+"Plate of "+HIK+"Evil"+NORM+" ["+RED+"Demon Fire"+NORM+HIK+"] ["+FULLSETNAME+"]"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Plate of "+HIK+"Evil"+NORM+" ["+RED+"Demon Fire"+NORM+HIK+"] ["+SETNAME+"]"+NORM+" (worn)"+NORM);

  return HIK+" Plate of "+HIK+"Evil"+NORM+" ["+RED+"Demon Fire"+NORM+HIK+"] ["+SETNAME+"]"+NORM+""+NORM+NORM;
}


do_special(owner) {
  int i;
  if (random(1000) > 200) /* It only hits 20% of the time */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }

    set_params("magical",0,10,0);
    set_params("other|evil",5,0,"powerupneck");
}
  
    powerupneck(){
	    int i;
          i = random(4);
        if(i==1){	
         tell_room(environment(USER),
           HIK+"D A R K N E S S "+NORM+"engulfs "+environment()->query_name()+"'s body "+NORM+BOLD+" you feel empowered as the "+HIK+"D A R K N E S S"+NORM+" flows within you!!!@!\n"+NORM);
		 USER->add_hit_point(1+random(5));
         return 1;}
         return 1;} 
		 
void start(object ob) 
{
  call_out("corrupt_wearer", 10, ob);   
}

int corrupt_wearer(object ob) 
{
  if(!ob || !((status)this_object()->query_worn()))
    return 1;  
    
  if((int)ob->query_alignment() > -1000) 
  {
    call_other(ob, "add_alignment", -100);
    if(!random(4)) 
    {
      tell_object(ob,
        HIK+"You feel a deep seeded evil "+HIR+"C"+NORM+RED+"o"+HIR+""+NORM+RED+""+HIR+"U"+NORM+RED+"p"+HIR+"T"+HIK+" the very core of your soul\n"+NORM);
      tell_room(environment(ob),
        (string)ob->query_name()+"'s armor eats at the surrounding light absorbing any warmth.\n", ({ ob }));
    }
  }
  
  call_out("corrupt_wearer", 60+random(120), ob);
  return 1;        
  
}

void stop(object ob) 
{
  while(remove_call_out("corrupt_wearer") != -1);  
}

int do_black_special(object owner) 
{
  if(!owner) return 0;
  if((int)owner->query_attrib("luc") > random(200)) 
  {
    tell_object(owner,
      HIK+"A  D A R K  B L A C K  F I E L D  E N V E L O P S  Y O U! ! !\n"+NORM);
    tell_room(environment(owner),
      "A black field of energy surrounds "+
      (string)owner->query_name()+".\n", ({ owner }));
    return 2;
  }
}

int do_evil_special(object owner) 
{
  if(!owner) return 0;
  if((int)owner->query_attrib("luc") > random(80)) 
  {
    tell_object(owner,
      HIK+"Tendrils of dark demonic energy lash out from your armor.\n"+NORM);
    tell_room(environment(owner),
      "Tendrils of dark demonic energy lash out from "+
      (string)owner->query_name()+"'s armor.\n", ({ owner }));
    return 0510;  
	}
}

