/*  Yes this is a pretty scary piece of armor....
 *  The curse of this is this: any spirits in the room
 *  Will attack the carrier of this armor <also demons>
 *  the heal works rnd twice and the attack only rnd 4 times
 *  then the armor is dested.
 *  is found on /players/mythos/closed/guild/forest/mon/jinro.c
 *  take a look before judging, he is really tough
 *                                    - mythos
 */

#include "/players/mythos/closed/ansi.h"
#define ep environment(this_object())
#define tp this_player()
#define att tp->query_attack()
#define eep environment(ep)
#define tpn tp->query_real_name()
#define tpe environment(tp)

int num_heal, num_lash;

inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("tunic");
  set_short("Torn Tunic");
  set_alias("tunic");
  set_type("armor");
  set_long("This is a close fitting tunic worn by the jinro.\n"+
           "Strange powers are in this piece of clothing....\n"+
           "type 'tunic_list'\n");
  set_ac(4);
  set_weight(2);
  set_value(10000);
  num_heal = 1 + random(2);
  num_lash = 1 + random(4);
  set_heart_beat(1);
}
query_save_flag() { return 1;}

init() {
  ::init();
  add_action("tunic_list","tunic_list");
  add_action("stroke","stroke");
  add_action("lash","lash");
}

tunic_list() {
  write("Powers that exist within the tunic:\n"+
        "  lash -  an attack\n"+
        "  stroke - healing\n");
return 1;}

heart_beat() {
object sur;
int n;
if(!ep) return;
if(!eep) return;
  if(living(ep)) 
    if(!(ep->id("jinro"))) {
      sur = all_inventory(eep);
      for(n=0;n<sizeof(sur);n++) {
        if(sur[n]) if(sur[n]->id())
        if(sur[n]->id("spirit") || sur[n]->id("demon") || sur[n]->id("daemon")) {
           if(!sur[n]->query_attack()) sur[n]->attack_object(ep);
		   else if(sur[n]->query_attack() && (sur[n]->query_attack()) != ep) 
             sur[n]->attack_object(ep);
             
           }
        }
     }
}

stroke() {
  if(living(ep)) {
    write("You stroke the tunic.  You feel better.\n");
    say(capitalize(tpn)+" suddenly looks much better!\n");
    num_heal = num_heal - 1;
    tp->heal_self(1000);
    if(num_heal < 1) {
    write("The tunic disappears!\n");
    if(worn) 
    command("remove tunic", this_player());
    destruct(this_object());
    } }
return 1;}

lash(str) {
object lashed;
  if(!str) { 
    if(att) { lashed = att; }
    else {
      write("What do you wish to lash out at?\n");
      return 1;}
  }
  if(str) { 
    lashed = present(str,tpe);
    if(!lashed) { write("That is not here!\n"); return 1;}
    if(!living(lashed) || lashed->is_player()) {
      write("You can not lash at that!\n"); return 1;}
  }
  write("You raise a hand .....\n");
  say(capitalize(tpn)+" raises a hand...\n");
  tell_room(tpe,HIB+"\n\n\t\t *  *   *  F  L  A  S  H  *   *  *\n\n\n"+NORM);
  tell_room(tpe,lashed->short()+" screams in agony!\n");
  lashed->heal_self(-1-random(30));
  lashed->attack_object(tp);
  tp->add_spell_point(-random(30));
  num_lash = num_lash - 1;
  if(num_lash < 1) {
    write("The tunic flickers and is gone...\n");
    if(worn)
    command("remove tunic", this_player());
    destruct(this_object());
    }
return 1;}
