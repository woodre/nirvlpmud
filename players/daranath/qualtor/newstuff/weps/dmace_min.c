#define tp this_player()->query_name()
#define POSS this_player()->query_possessive()
#define ATT attacker->query_name()
#include <ansi.h>
int w;

inherit "obj/weapon.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("distruption mace");
set_alias("mace");
set_alt_name("minor");
set_short(WHT+"Mace of Disruption "+NORM+"<"+BOLD+BLK+"minor"+NORM+">");
set_long("Forged by the best craftsmen and blessed by Qual'tors HighPriest,\n"+
         "this weapon was specifically designed to battle the evils that\n"+
         "plague Ghost Ward. The Mace of Distruption sheds a soft light\n"+
         "throughout the area.\n");
set_class(17);
set_weight(2);
set_light(1);
set_value(3500);
set_hit_func(this_object());
}

weapon_hit(attacker){
 if(call_other(this_player(),"query_attrib","pie") > random (80)) {
  say("The "+WHT+"Mace of Disruption"+NORM+" glows with a holy light.\n");
  write("\nYour Mace of Disruption glows with a "+WHT+"soft light"+NORM+".\n");

  if(call_other(attacker,"id","undead") ||
     call_other(attacker,"id","spirit"))    {

  write("The light from the "+WHT+"Mace of Disruption"+NORM+" flares brightly.\n"+
        ATT+" screams loudly as the "+HIW+"Holy Light"+NORM+" tears into its undead form.\n");
  say("The light from the mace "+HIW+"BURNS"+NORM+" into "+ATT+"'s form.\n");
  attacker->heal_self(-(random(20)+5));
       }
  tell_room(environment(this_player()),
  ATT+" staggers from the force of the mace.\n\n");
  return 8;
  }
    return;
return;
}

query_save_flag()  { return 0; }

