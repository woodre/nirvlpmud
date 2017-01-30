inherit "obj/monster";
#include "/players/illarion/dfns.h"
#define RING "/players/illarion/wedding/wring"

object spouse1,spouse2;
int busy;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("priest");
  set_alias("druid");
  set_race("human");
  set_gender("male");
  set_short("A brown-robed druid priest");
  set_long(
"Despite his average stature and build, and the simplicity of his brown,\n"+
"hooded robes, this man exudes an aura of power and authority.  Only his\n"+
"eyes seem in keeping with his aura, glittering brightly from shadowed\n"+
"sockets.  In his right hand he holds a wooden staff as plain and unadorned\n"+
"as his robes.\n");
  set_level(20);
  set_wc(1); /* he won't kill players, just remove them */
  set_ac(50); /* overridden in hit_player anyway */
  set_hp(10000); /* just in case */
  set_al(1000);
}
void init() {
  ::init();
  add_action("quick_marriage","qm");
  add_action("cmd_ask","ask");
}
long() {
  ::long();
  if(!busy) {
    busy=1;
    call_out("greet_player",1,TP);
  }
}
hit_player(int x) {
  write("A shield of blue energy absorbs the impact of your attack.\n");
  say("A shield of blue energy absorbs the impact of "+TPN+"'s attack.\n");
  return 0;
}
attack() {
  if(attacker_ob && present(attacker_ob,environment())) {
    if(attacker_ob==this_object()) {
      say("The priest shrugs off the attack on his mind.\n");
      attacker_ob=0;
      alt_attacker_ob=0;
      return;
    }
    say("The priest angrily strikes out with his staff.\n");
    tell_object(attacker_ob,
"A magical force races through you, carrying you elsewhere.\n");
    move_object(attacker_ob,"/room/church");
    tell_room(environment(),attacker_ob->query_name()+
" is blasted from the room by the power of the druid's staff.\n");
    tell_room(environment(attacker_ob),attacker_ob->query_name()+
" appears in the room looking shaken and drained.\n",({attacker_ob}));
  }
  ::attack();
}
void give_rings(object s1,object s2) {
  object r1,r2;
  string n1,n2;
  n1=(string)s1->query_real_name();
  n2=(string)s2->query_real_name();
  r1=clone_object(RING);
  r2=clone_object(RING);
  move_object(r1,s1);
  move_object(r2,s2);
  r1->set_info(n2+"@@@0@@@joins you in the realms of Nirvana@@@leaves you alone for now.");
  tell_object(s1,"A ring materializes around your finger.\n");
  tell_object(s2,"A ring materializes around your finger.\n");
  r2->set_info(n1+"@@@0@@@joins you in the realms of Nirvana@@@leaves you alone for now.");
  return;
}
int quick_marriage(string arg) {
  string sp1,sp2;
  object s1,s2;
  if(!arg) return 0;
  if(sscanf(arg,"%s %s",sp1,sp2)!=2) return 0;
  s1=present(sp1,environment());
  s2=present(sp2,environment());
  if(!(s1 && s2)) return 0;
  give_rings(s1,s2);
  return 1;
}
void greet_player(object p) {
  busy=0;
  if(!p) return;
  say(format("The priest smiles and says, \"Welcome to my temple, "
     +p->query_name()+".  Is there anything you wish to ask of me?\n"));
  return;
}
string ask_responses(string str) {
  switch(str) {
    default: return "You may ask me about my 'temple', the 'power' that "+
                    "lingers here, or about my 'marriage' ceremony, "+
                    "and probably a few other things I do not recall at "+
                    "the moment.";
    case "temple": return "It's not very impressive anymore, is it?  When "+
                    "the ancients built it, it was the only temple of its "+
                    "kind in this world, and their high priests wielded "+
                    "power the like of which I cannot imagine.";
    case "power": return "Yes, the power the ancients gave this place was "+
                    "too strong to die completely even when the temple was "+
                    "attacked and mostly destroyed by their enemies.";
    case "marriage": return "Ah, so you think you may have found your "+
                    "lifemate?  If you a certain, I can use the powers of "+
                    "this place to bind you together.";
  }
}
int cmd_ask(string str) {
  if(busy) return 0;
  if(!str) str="";
  say("The priest speaks quietly to "+TPN+".\n",TP);
  write(format("The priest quietly says to you, \""+ask_responses(str)+"\""));
  return 1;
}
