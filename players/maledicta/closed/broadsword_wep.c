
#include "/players/maledicta/ansi.h"

inherit "players/maledicta/weapon/weapon.c";
#define USER environment()
#define TP this_player()
#define POS query_possessive()
#define OBJ query_objective()
#define PRO query_pronoun()

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("broadsword");
set_alt_name("warrior_strike_bonus");
set_alias("broadsword of balance");
set_short("The Broadsword of Balance");
set_long(
"  This is the famed Broadsword of Balance. It is made of some unknown\n"+
"magical material and looks quite deadly. There are some inscriptions\n"+
"along the blade.  This broadsword was made especially for the mortal\n"+
"Tyr.\n");
set_hit_func(this_object());
set_type("sword");  
set_class(18);
set_weight(3);
set_value(2000);
set_two_handed_wep(1);
set_no_break(1);
/*
 add_special_fun("/players/maledicta/weapon/powers/cleansing.c");
*/
message_hit = ({
  HIR+"hacked"+NORM," into a bloody, squirming mess on the floor",
  RED+"sliced"+NORM, " with a critical strike",
  RED+"diced"+NORM, " into tiny, pathetic little pieces",
  HIW+"pierced"+NORM, " deeply, causing great pain",
  HIW+"chopped"+NORM, " with a mad surgeon's grace",
  "slapped", " viciously with the flat of the blade",
  "cut", " lightly across the chest"
  });
  }


weapon_hit(ob){
int lev, xlev, hp, sp, mhp, msp, num;
  object me, att;
  me = USER;
  lev = me->query_level();
  xlev = me->query_extra_level();
  hp = me->query_hp();
  sp = me->query_sp();
  mhp = me->query_mhp();
  msp = me->query_msp();
  att = ob;
  if(lev < 10) return 0;
  if(!random(10)) {  /* 10% chance of balance */
  if(hp > (sp + 2) && !(hp > msp)) {
    num = hp - sp;
    num = num / 2;
    me->add_hit_point(-num);
    me->add_spell_point(num);
    write(
    HIG+"The Broadswor"+NORM+GRN+"d of Balance glows"+HIW+"...\n\n"+
    HIW+"        < < <  "+HIG+" M  A  G  I  C "+HIW+"  > > >\n\n"+
    HIG+"    You feel pow"+NORM+GRN+"er infuse your body!"+NORM+"\n"); }
  if(sp > (hp + 2) && !(sp > mhp)) {
    num = sp - hp;
    num = num / 2;
    me->add_hit_point(num);
    me->add_spell_point(-num);
    write(
    HIR+"The Broadswor"+NORM+RED+"d of Balance glows"+HIW+"...\n\n"+
    HIW+"        < < <  "+HIR+" M  I  G  H  T "+HIW+"  > > >\n\n"+
    HIR+"    You feel pow"+NORM+RED+"er infuse your body!"+NORM+"\n"); }
  }
  if(random(100) < 30){
     write(
  HIB+"You draw on the power of "+HIW+"L"+HIB+"aw"+HIW+"...\n\n"+
      "         - "+HIB+"S  L  I  C  E"+HIW+" -\n\n"+
      "   O"+HIB+"rder is imposed upon "+att->query_name()+"!\n"+NORM);
  return 7;
  }
  if(random(100) < xlev) return 4;

  else return;
  }   
     
get(){ 
if(this_player())
if(this_player()->query_real_name() != "tyr" && TP->query_level() < 20){
write("You are unable to grasp such a powerful artifact!\n");
return 0;
}
return 1;
}

