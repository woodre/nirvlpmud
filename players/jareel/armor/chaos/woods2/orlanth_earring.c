#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())
int nrgy;
string x;


string *Armor_pieces;
  
     reset(arg) {
       ::reset(arg);

     set_name("orlanth earring");
     set_ac(0);
     set_value(5000);
     set_weight(1);
     set_type("earring");
     set_short(HIB+"Earring"+NORM+BLU+" of the raging "+HIB+"Storm"+NORM);
     set_long(
       "                      "+HIG+"Set of the Wind"+NORM+"\n"+
       "A swirling blue and white crystal encrusted in a soft silver metel.\n"+
       "winged cap.  The cap looks frail and not very sturdy.  The power\n"+
       "from the helm radiates over your soul.\n");
     call_out("generate", 40);
  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "orlanth_bracelet", "orlanth_amulet", "orlanth_earring" });
     }

status id(string arg) { return ( ::id(arg) || arg == "orlanth_earring" || arg == "earring" || arg == "storm helm" || arg == "helmet of the raging storm"); }

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
    return (HIB+"Earring "+NORM+BLU+"of the raging "+NORM+HIB+"Storm"+NORM+BOLD+" ("+NORM+HIG+"Set of the Wind"+NORM+BOLD+")"+NORM+" (worn)"+NORM);      

  if ((status)this_object()->query_worn())
    return(HIB+"Earring"+NORM+BLU+" of the raging "+NORM+HIB+"Storm"+NORM+NORM+" (worn)");

  return HIB+"Earring "+NORM+BLU+"of the raging "+HIB+"Storm"+NORM+NORM;
}

generate(){
     if(!worn) return 0;
       if(worn && worn_by && random(3)){
         if(worn_by->query_hurt()){
           worn_by->heal_self(random(3)+1);
            tell_object(worn_by,
             "You feel arcs of energy run up your arm .\n");
      }
     }  
     if( find_call_out("generate") < 0 )
       call_out("generate", 40);
     }

wear(str) {
     while(remove_call_out("regen_sp") != -1);
       if(!id(str) || environment() != this_player()) return 0;
         ::wear(str);
           if(worn) call_out("generate", 40);
     return 1;
     }

remove(string str) {
     if(!id(str) || environment() != this_player() || !worn) return 0;
       ::remove(str);
         while(remove_call_out("generate") != -1);
     return 1;
     }


