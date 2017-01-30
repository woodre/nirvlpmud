/* 10/16/05 Earwax: Changed do_special() pk portion.  It was dumb. */
/* -- AC 4, Weight 1.  Specials only against evil alignments.
 * There's a special vs mobs, and one vs players. 
 * 12/07/05 Earwax: changed it so it doesn't transfer infuse.
*/
inherit "obj/armor";
#include "/players/jaraxle/define.h"
reset(arg){
   if(arg) return;
   ::reset();
   set_name("eagle armor");
   set_alias("eagle");
  set_short(HIY+"Ea"+HIW+"g"+HIY+"le"+NORM+YEL+" Armor"+NORM);
   set_long("A thick piece of leather armor with mithril\n"+
      "chain in the shape of an eagles head adorning\n"+
      "the front, offering superior protection.\n");
   set_ac(4);
  set_params("magical",2,0,0);
  set_params("other|air",0,15,0);
  set_params("other|earth",0,-15,0);
  /* params added by ill may 2005 */
   set_type("armor");
   set_weight(2);
   set_light(2);
   set_value(4000);
}

do_special(owner) {
   object att;
   if(!owner || !owner->query_attack()) return 1;
   if(!owner->is_player()) return 1;
   att = owner->query_attack();
  /* Earwax - changed this to only have specials trigger against -align */
  if (att->query_alignment() > 299) return -2;
  if (att->query_alignment() > -299) return 0;
   if(att->query_wc() > 17 && owner->query_alignment() > 200 &&
         random(owner->query_attrib("pie")) > random(30)) {
     tell_object(owner, "Your "+HIY+"Ea"+HIW+"g"+HIY+"le Armor"+NORM+" absorbs some of the blow!\n");
      owner->add_hit_point(2); return 1; }

/* PK special */
if(att->query_spell_dam() && !att->is_npc() && (att->query_attack()==owner)) {
tell_object(owner, 
"Your armor vibrates as it absorbs part of your opponents spell!\n");

/* The next one was already here.  I changed the 2nd one since it
 * made no sense.  It was penalizing having a higher piety - Earwax
 * Mine: % chance equal to piety/100 of triggering 50% add_hp()
 * averages out to 1/6 per round if piety is 30.  Less if it isn't.
owner->add_hit_point(att->query_spell_dam()/3);
  owner->add_hit_point(random(att->query_spell_dam() / (1 + (int)owner->query_attrib("pie") / 10)));
tell_room(environment(owner), HIR+"HP ADDED: "+HIB+(att->query_spell_dam()/2)+NORM+"\n");
*/
    if (owner->query_attrib("pie") >= random(100)) {
      tell_object(owner, "Your "+HIY+"Ea"+HIW+"g"+HIY+"le Armor"+NORM+" vibrates as it absorbs some of the blow!\n");
      say(owner->query_name()+"'s "+HIY+"Ea"+HIW+"g"+HIY+"le Armor"+NORM+" vibrates as it absorbs an attack!\n",  owner);
      owner->add_hit_point((att->query_spell_dam() / 2));
    }     
  }
   return 0; }
