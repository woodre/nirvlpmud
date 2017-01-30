#define tp this_player()->query_name()
#define POSS this_player()->query_possessive()
#define ATT attacker->query_name()
#include <ansi.h>

int a, w;

inherit "obj/weapon.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("distruption mace");
set_alias("mace");
set_alt_name("minor");
set_short(WHT+"Mace of Disruption "+NORM+"<"+BOLD+BLK+"Major"+NORM+">");
set_long("Mace of disruption is a holy weapon.\n");
set_long("Out of every 100 disruption maces blessed within the city of\n"+
         "Qual'tor, legend has it that Tarkos himself intervenes and\n"+
         "imbues one with special powers. These weapons are highly sought\n"+
         "after in the war against the undead.\n");
set_class(21);
set_weight(2);
set_light(2);
set_value(10750);
set_hit_func(this_object());
}

query_save_flag() {return 1;}

weapon_hit(attacker){
 a = random(100);
 if(call_other(this_player(),"query_attrib","pie") > random (80)) {
  say("The "+WHT+"Mace of Disruption"+NORM+" glows with a holy light.\n");
  write("\nYour Mace of Disruption glows with a "+WHT+"soft light"+NORM+".\n");

  if(call_other(attacker,"id","undead") ||
     call_other(attacker,"id","spirit"))    {

if(a > 1) {
write("The light from the "+HIW+"Mace of Disruption"+NORM+" flares brightly.\n"+
  ATT+" screams loudly as the "+HIY+"Holy Light"+NORM+" tears into its undead form.\n");
  say("\n");
 say("The light from the mace "+HIW+"BURNS"+NORM+" into "+ATT+"'s form.\n");
  say("\n");
  return 8; }
/* Total 3 in 400 chance of massive damage to undead/spirit critter  */
/* For a player with a maxed out Pie score */
if(a < 3) {
  object targ;
   targ = present(attacker, environment(this_player()));
  write("The Mace fills the area with a brilliant\n\n"+
       "           "+HIW+"     |       "+NORM+"\n"+
       "       "+ HIW+"<<-- "+HIY+"HOLY LIGHT"+HIW+" -->>"+NORM+"\n"+
       "           "+HIW+"     |       "+NORM+"\n\n"+
       ATT+" turns to dust from the light.\n");
  say("\n");
  say("Light streams from the "+HIW+"Holy Mace"+NORM+" and "+HIY+"BLASTS"+NORM+" the "+ATT+"!\n");
  say("\n");
  targ->heal_self(-10000); }
  }
  }
    return;
return;
}

