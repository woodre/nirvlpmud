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
     set_type("earrirng");
     set_short(HIB+"Helmet"+NORM+BLU+" of the raging "+HIB+"Storm"+NORM);
     set_long(
       "                      "+HIG+"Set of the Wind"+NORM+"\n"+
       "A swirling blue and white crystal encrusted in a soft silver metel.\n"+
       "winged cap.  The cap looks frail and not very sturdy.  The power\n"+
       "from the helm radiates over your soul.\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "orlanth_amulet", "orlanth_amulet", "orlanth_earring" });
     }

status id(string arg) { return ( ::id(arg) || arg == "orlanth_earring" || arg == "earring" || arg == "storm helm" || arg == "helmet of the raging storm"); }

status check_full_set() {
  int i;

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

do_special(owner){
  if(!owner || !owner->query_attack()) return 1;
  if(!owner->is_player()) return 1;
  if(owner->query_hp() < 100 && nrgy)
  {
    tell_object(owner, 
            "special works!\n");
        tell_room(environment(owner), owner->query_name()+
                "this worked!\n", ({ owner }));
    owner->add_hit_point(50);
        nrgy -=1;
        return 2;
  }
  else if(owner->query_sp() < 50 && nrgy)
  {
    tell_object(owner, 
            "This works!\n");
        tell_room(environment(owner), owner->query_name()+
                "sps works!\n", ({ owner }));
    owner->add_spell_point(50);
        nrgy -=1;
        return 2;
  }
  return 2; 
}

