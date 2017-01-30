
#define ok return 1
#define call call_other
#define you this_player()
#define act add_action
#include "color.h"
int can_drop;

short() {
     return "The staff of wizardry";
}

long() {
     write("It is an intricately carved staff of oak.\n"+
           "It hums with power.\n");
     if(call(you, "query_level")>39 ||
        call(you, "query_real_name")=="womble")
          write("\n(Type 'staff' for a list of commands.)\n"); 
}

id(str) {
     return str=="staff" || str=="staff of wizardry" || str=="temp"; }

get() { ok; }

drop() {
     if(can_drop) 
          return 0;
     write("You can't.\n");
     ok;
}
set_can_drop(d) { can_drop=d; }

query_value() { return 10000; }

query_weight() { return 0; }

query_auto_load() {
     if((this_player()->query_real_name()=="womble") ||
        (this_player()->query_real_name()=="bastion")) {
          return("players/bastion/closed/staff:"); }
}

init() {
  if(call(you, "query_level")>20 || call(you, "query_real_name")=="damian") {
     act("echo"), add_xverb("$");
     act("echoall"), add_xverb("@");
     act("echo_at", "atp");
     act("bring", "bring");
     act("send", "send");
     act("silent_goto", "to");
     act("pocket", "pocket");
     act("identify", "id");
     act("true_inv", "inv");
     act("patch", "patch");
     act("heal", "heal");
     act("call_reset", "rset");
     act("meteor_swarm", "meteor");
     act("trash", "trash");
     act("sober", "sober");
     act("give_cash", "cash");
     act("force", "force");
     act("make", "make");
     act("retitle", "retitle");
     act("frog", "frog");
     act("defrog", "defrog");
     act("resurrect", "raise");
     act("invis_tell", "itell");
     act("invis_shout", "ishout");
     act("paralyze", "par");
     act("unparalyze", "unpar");
     act("bug", "bug");
     act("unparalyze", "debug");
     act("hey", "hey");
     act("zot", "zot");
     act("klone", "klone");
     act("power_get", "get!");
     act("power_get", "take!");
     act("power_put", "put!");
     act("test_func", "test");
     act("command_list", "staff"); }
}

echo(str) {
     if(!str) {
          write ("Echo what?\n");
          ok; }
     say(str + "\n");
     write("You echo: " + str + "\n");
     ok;
}

echoall(str) {
     if(!str) {
          write("Echoall what?\n");
          ok; }
     shout(str + "\n");
     write("You echoall: " + str + "\n");
     ok;
}

echo_at(str) {
     object ob;
     string who, what;
     if(!str || sscanf(str, "%s %s", who, what)!=2) {
          write("Echo to whom what?\n");
          ok; }
     ob=find_living(who);
     if(!ob) 
          ob=find_anyone(who);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     tell_object(ob, what + "\n");
     write("You echo at " + capitalize(who) + ": " + what + "\n");
     ok;
}

bring(str) {
     object ob, old_room;
     string who;
     ob=find_living(str);
     if(!ob)
          ob=find_anyone(str);
     if(!ob) {
          write("Summon whom?\n");
          ok; }
     who=call(ob, "query_name");
     old_room=environment(ob);
     say(who + " materializes.\n");
     move_object(ob, environment(you));
     tell_room(old_room, who + " disappears in a flash of red light!\n");
     tell_object(ob, "You suddenly find yourself elsewhere.\n");
     write("You summon " + who + ".\n");
     ok;
}

send(str) {
     object ob, ob2, old_room;
     string who, where;
     if(!str || sscanf(str, "%s %s", who, where)!=2) {
          write("Send whom where?\n");
          ok; }
     ob=find_living(who);
     if(!ob)
          ob=find_anyone(who);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     who=call(ob, "query_name");
     old_room=environment(ob);
     if(!find_living(where)) {
          tell_room(where, who + " materializes.\n");
          move_object(ob, where);
          tell_room(old_room, who + " disappears in a flash of red light!\n");
          tell_object(ob, "You suddenly find yourself elsewhere.\n");
          write("Done.\n"); 
          ok; }
     ob2=environment(find_living(where));
     tell_room(ob2, who + "materializes.\n");
     move_object(ob, ob2);
     tell_room(old_room, who + " disappears in a flash of red light!\n");
     tell_object(ob, "You suddenly find yourself elsewhere.\n");
     write("Done.\n");
     ok;
}

silent_goto(str) {
     object ob2, old_room;
     if(!str) {
          write("Go to where?\n");
          ok; }
     if(!find_living(str) && !find_anyone(str)) {
          move_object(you, str);
          call(you, "look");
          ok; }
     ob2=environment(find_living(str));
     if(!ob2)
          ob2=environment(find_anyone(str));
     move_object(you, ob2);
     call(you, "look");
     ok;
}

pocket(str) {
     object ob;
     if(!str) {
          write("Enter who's inventory?\n");
          ok; }
     ob=find_living(str);
     if(!ob)
          ob=find_anyone(str);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     move_object(you, ob);
     write("You climb into " + call(ob, "query_real_name") + "'s pocket.\n");
     ok;
}

identify(str) {
     object ob;
     string what;
     if(!str) {
          write("Identify what?\n");
          ok; }
     if(present(str, you))
          ob=present(str, you);
     else if(present(str, environment(you)))
          ob=present(str, environment(you));
     else if(find_living(str))
          ob=find_living(str);
     else if(str=="me")
          ob=you;
     else if(find_anyone(str))
          ob=find_anyone(str);
     else
          ob=find_object(str);
     if(!ob) {
          write("No such object found.\n");
          ok; }
     write(call(ob, "short") + "\n");
     write(ob); write("\n");
     what=call(ob, "query_name");
     if(what) { write("Name:     \t\t" + what + "\n"); }
     what=call(ob, "query_alias");
     if(what) { write("Alias:    \t\t" + what + "\n"); }
     what=call(ob, "query_info");
     if(what) { write("Magical ID:\t\t" + what + "\n"); }
     what=call(ob, "query_alias");
     if(what) { write("Alias:\t\t" + what + "\n"); }
     what=call(ob, "query_race");
     if(what) { write("Race:\t\t" + what + "\n"); }
     what=call(ob, "query_hp");
     if(what) { write("Hit points:\t\t" + what + "\n"); }
     what=call(ob, "query_type");
     if(what) { write("Type:     \t\t" + what + "\n"); }
     what=call(ob, "weapon_class");
     if(what) { write("Weapon class:\t\t" + what + "\n"); }
     what=call(ob, "query_wc");
     if(what) { write("Weapon class:\t\t" + what + "\n"); }
     what=call(ob, "query_ac");
     if(what) { write("Armor class:\t\t" + what + "\n"); }
     what=call(ob, "armor_class");
     if(what) { write("Armor class:\t\t" + what + "\n"); }
     what=call(ob, "query_weight");
     if(what) { write("Weight:   \t\t" + what + "\n"); }
     what=call(ob, "query_value");
     if(what) { write("Value:    \t\t" + what + "\n"); }
     what=call(ob, "query_level");
     if(what) { write("Level:    \t\t" + what + "\n"); }
     what=call(ob, "query_exp");
     if(what) { write("Experience:\t\t" + what + "\n"); }
     what=call(ob, "query_guild_exp");
     if(what) { write("Guild exp.:\t\t" + what + "\n"); }
     what=call(ob, "query_alignment");
     if(what) { write("Alignment:\t\t" + what + "\n"); }
     what=call(ob, "query_money");
     if(what) { write("Money:    \t\t" + what + "\n"); }
     what=call(ob, "query_charges");
     if(what) { write("Charges:\t\t" + what + "\n"); }
     what=creator(ob);
     if(what) { write("Creator:\t\t" + what + "\n"); }
     ok;
}

true_inv(str) {
     object ob, next_ob;
     int i;
     if(!str) {
         write("Get what object's inventory?\n");
         ok; }
     if(present(str, environment(you)))
          ob=present(str, environment(you));
     else if(find_living(str))
          ob=find_living(str);
     else if(str=="here")
          ob=environment(you);
     else if(str=="me")
          ob=you;
     else if(find_anyone(str))
          ob=find_anyone(str);
     else
          ob=find_object(str);
     if(!ob) {
          write("No such object found.\n");
          ok; }
     write(call(ob, "short") + "\n");
     write(ob); write("\n");
     ob=first_inventory(ob);
     i=0;
     while(ob) {
          write(i + ": "); write(ob);
          write("  " + call(ob, "short") + "\n");
          i+=1;
          ob=next_inventory(ob); }
     ok;
}

patch(str) {
     object ob;
     string name, with, what;
     int iwhat;
     if(!str) {
          write("Patch what with what?\n");
          ok; }
     if(sscanf(str, "%s %s %d", name, with, what)==3)
          iwhat=1;
     else if(sscanf(str, "%s %s %s", name, with, what)!=3) {
          if(sscanf(str, "%s %s", name, with)==2)
               iwhat=0;
          else {
               write("Patch what with what?\n"); 
               ok; } }
     if(present(name, you))
          ob=present(name, you);
     else if(name=="me")
          ob=you;
     else if(name=="here")
          ob=environment(you);
     else if(present(name, environment(you)))
          ob=present(name, environment(you));
     else if(find_anyone(name))
          ob=find_anyone(name);
     else
          ob=find_living(name);
     if(!ob)
          return("No such object found.\n");
     write("Got: "); write(call(ob, with, what)); write("\n");
     ok;
}

heal(str) {
     object ob;
     ob=find_living(str);
     if(!str || !ob) {
          write("Heal whom?\n");
          ok; }
     ob->heal_self(10000);
     tell_object(ob, call(you, "query_name") + " has healed you.\n");
     write("You heal " + call(ob, "query_real_name") + ".\n");
     ok;
}

call_reset(str) {
     object ob;
     if(!str)
          ob=environment(you);
     else
          ob=find_object(str);
     if(!ob) {
          write("Reset what?\n");
          ok; }
     ob->reset(1);
     write("You reset: "); write(ob); write("\n");
     ok;
}

meteor_swarm(str) {
     object ob;
     string who;
     if(!str) {
          ob=(call(you, "query_attack"));
          if(!ob) {
               write("Cast meteor swarm at whom?\n");
               ok; } }
     else {
          ob=present(str, environment(you));
          if(!ob) {
               write("No such person or monster found.\n"); 
               ok; } }
     write("You cast a meteor swarm.\n");
     ob->attacked_by(you);
     say(call(you, "query_name") + " releases a ball of fire from the top of his staff.\nThe flame splits into four globes of fire which grow and explode, englulfing\n" + call(ob, "query_name")  + ".\n");
     you->attack_object(ob);
     ob->heal_self(-10000);
     ok;
}

trash(str) {
     object ob;
     if(!str) {
          write("Trash whom?\n");
          ok; }
     ob=find_living(str);
     if(!ob)
          ob=find_anyone(str);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     ob->drink_alcohol(10000);
     tell_object(ob, "You suddenly feel VERY drunk.\n");
     write("You trash " + capitalize(str) + ".\n");
     ok;
}

sober(str) {
     object ob;
     if(!str) {
          write("Sober whom?\n");
          ok; }
     ob=find_living(str);
     if(!ob)
          ob=find_anyone(str);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     ob->drink_alcohol(-10000);
     write("You sober " + capitalize(str) + ".\n");
     ok;
}

give_cash(str) {
     object ob;
     string who, amt;
     if(!str || sscanf(str, "%s %d", who, amt)!=2) {
          write("Give whom how much?\n");
          ok; }
     ob=find_living(who);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     ob->add_money(amt);
     if(amt<0)
          tell_object(ob, "You have been robbed!\n");
     else
          tell_object(ob, "You have been given a gift.\n");
     write("You give " + capitalize(who) + " " + amt + " coins.\n");
     ok;
}

retitle(str) {
     object ob;
     string who, what;
     if(!str || sscanf(str, "%s %s", who, what)!=2) {
          write("Retitle whom as what?\n");
          ok; }
     ob=find_living(who);
     if(!ob)
          ob=find_anyone(who);
     if(!ob) {
          write("No such person found.\n");
          ok; }
     ob->set_title(what);
     write("You changed " + capitalize(who) + "'s title to " + what + ".\n");
     ok;
}

frog(str) {
     object ob;
     if(!str) {
          write("Frog whom?\n");
          ok; }
     ob=find_living(str);
     if(!ob)
          ob=find_anyone(str);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     ob->frog_curse(1);
     ok;
}

defrog(str) {
     object ob;
     if(!str) {
          write("Defrog whom?\n");
          ok; }
     ob=find_living(str);
     if(!ob)
          ob=find_anyone(str);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     ob->frog_curse(0);
     ok;
}

force(str) {
     object ob;
     string who, what;
     if(!str || sscanf(str, "%s %s", who, what)!=2) {
          write("Make who do what?\n");
          ok; }
     ob=find_living(who);
     if(!ob)
          ob=find_anyone(who);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     ob->force_us(what);
     write("You force " + call(ob,"query_real_name") + " to " + what +".\n");
     ok;
}

make(str) {
     object ob;
     string who, what;
     if(!str || sscanf(str, "%s %s", who, what)!=2) {
          write("Make who do what?\n");
          ok; }
     ob=find_living(who);
     if(!ob)
          ob=find_anyone(who);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     command(what, ob);
     write("You command " + capitalize(who) + " to " + what + ".\n");
     ok;
}

resurrect(str) {
     object ob;
     int exp;
     if(!str) {
          write("Resurrect whom?\n");
          ok; }
     ob=find_living("ghost of " + str);
     if(!ob) {
          write("No such ghost found.\n");
          ok; }
     tell_object(ob, "You feel a warmth spread from the center of your body\n"+
          "as you take on more solid form.\n");
     tell_room(environment(ob), capitalize(str)+" appears first as a "+
          "faint image, then gradually\ntakes on more substance.\n");
     call(ob, "remove_ghost");
     exp=(call(ob,"query_exp"))/3;
     ob->add_exp(exp);
     write("You resurrect " + capitalize(str) + ".\n");
     ok;
}

invis_tell(str) {
     object ob;
     string who, what;
     if(!str || sscanf(str, "%s %s", who, what)!=2) {
          write("Tell whom what?\n");
          ok; }
     ob=find_living(who);
     if(!ob)
          ob=find_anyone(who);
     if(!ob) {
          write("No such person or monster found.\n");
          ok; }
     write("You tell " + capitalize(who) + ": " + what + "\n");
     tell_object(ob, "Someone tells you: " + what + "\n");
     ok;
}

invis_shout(str) {
     if(!str) {
          write("Shout what?\n");
          ok; }
     shout("Someone shouts: " + str + "\n");
     write("You shout: " + str + "\n");
     ok;
}

bug(str) {
     object ob, bug;
     string name;
     if(!str) {
          write("Bug what?\n");
          ok; }
     if(present(str)) 
          ob=present(str);
     else if(present(str, environment(you)))
          ob=present(str, environment(you));
     else if(str=="here")
          ob=environment(you);
     else if(find_living(str))
          ob=find_living(str);
     else if(find_anyone(str))
          ob=find_anyone(str);
     else
          ob=find_object(str);
     if(!ob) {
          write("No such object found.\n");
          ok; }
     bug=clone_object("players/bastion/closed/bg");
     bug->set_who(you);
     name=ob->query_real_name();
     bug->set_player(name);
     move_object(bug, ob);
     write("You bug " + capitalize(str) + ".\n");
     ok; 
}

paralyze(str) {
     object ob, dem;
     string name;
     if(!str) {
          write("Paralyze whom?\n");
          ok; }
     if(present(str))
          ob=present(str);
     else if(present(str, environment(you)))
          ob=present(str, environment(you));
     else if(find_anyone(str))
          ob=find_anyone(str);
     else
          ob=find_object(str);
     if(!ob) {
          write("No such person found.\n");
          ok; }
     dem=clone_object("players/bastion/closed/demon");
     dem->set_who(you);
     name=ob->query_real_name();
     dem->set_player(name);
     move_object(dem, ob);
     write("You paralyze " + capitalize(str) + ".\n");
     ok;
}

unparalyze(str) {
     object ob, bg;
     if(!str) {
          write("Unparalyze whom?\n");
          return 1; }
     if(present(str))
          ob=present(str);
     else if(present(str, environment(you)))
          ob=present(str, environment(you));
     else if(find_living(str))
          ob=find_living(str);
     else if(find_anyone(str))
          ob=find_anyone(str);
     else
          ob=find_object(str);
     if(!ob) {
          write("No such person or monster found.\n");
          return 1; }
     bg=present("bg", ob);
     if(bg->id("demon")) {
          write("You unparalyze " + capitalize(str) + ".\n");
          tell_object(ob, "The feeling returns to your numbed body.\n"); }
     else {
          write("You debug " + ob->query_real_name() + ".\n"); }
     destruct(bg);
     return 1;
}

command_list() {
     return call("/closed/wiz_soul", "more", "/players/bastion/staff.doc");
}

hey(){
     object ob;
      int i;
     ob = users();
     for(i=0;i<sizeof(ob);i++){
     if(ob[i]->query_level() >= 40){
       if(ob[i]->query_invis()){
      write(ob[i]->query_real_name()+" (invis)    "+file_name(environment(ob[i]))+
      "\n");
       }
      else
       write(ob[i]->query_real_name()+"   "+file_name(environment(ob[i]))+"\n");
     }
}
return 1;
}

zot(str) {
     object ob;
     if(!str) {
          write("Destruct what?\n");
          return 1; }
     if(present(str, this_player())) 
          ob=present(str, this_player());
     else if(present(str, environment(this_player())))
          ob=present(str, environment(this_player()));
     else if(find_living(str))
          ob=find_living(str);
     else if(find_anyone(str))
          ob=find_anyone(str);
     else
          ob=find_object(str);
     if(!ob) {
          write("No such object found.\n");
          ok; }
     write("Destruct: "); write(ob); write("\n");
     destruct(ob);
     ok;
}

klone(str) {
     object ob;
     if(!str) {
          write("Clone what object?\n");
          ok; }
     ob=clone_object(str);
     if(!ob) {
          write("Bad file name.\n");
          ok; }
     move_object(ob, this_player());
     write("Done.\n");
     ok;
}

power_get(str) {
     string item, cont;
     object itemob, contob;
     if(!str) {
          write("Get what?\n");
          ok; }
     if(str=="all") {
          get_all(environment(you));
          ok; }
     if(sscanf(str, "%s from %s", item, cont)!=2) {
          pick_item(str);
          ok; }
     contob=present(lower_case(cont));
     if(!contob)
          contob=present(lower_case(cont), environment(you));
     if(!contob) {
          write("There is no " + cont + " here.\n");
          ok; }
     if(item=="all") {
          get_all(contob);
          ok; }
     itemob=present(item, contob);
     if(itemob) {
          int weight;
          weight=itemob->query_weight();
          contob->add_weight(-weight);
          move_object(itemob, you);
          write("Ok.\n");
          if(you->query_invis() > 40) ok;
          say(you->query_name() + " takes " + item + " from " + cont + ".\n");
          ok; }
     write("There is no " + item + " in the " + cont + ".\n");
     ok;
}

static pick_item(obj) {
     object ob;
     int w;
     obj=lower_case(obj);
     ob=present(obj, environment(you));
     if(!ob) {
          write("That is not here.\n");
          ok; }
     if(environment(ob)==you) {
          write("You already have it!\n");
          ok; }
     w=ob->query_weight();
     environment(ob)->add_weight(-w);
     move_object(ob, you);
     write("Ok.\n");
     if(you->query_invis() > 40) ok;
     say(you->query_name() + " takes " + obj + ".\n");
     ok;
}

static get_all(from) {
     object ob, next_ob;
     ob=first_inventory(from);
     while(ob) {
          string item;
          int w;
          next_ob=next_inventory(ob);
          item=ob->short();
          if(!ob->id("soul")) {
               w=ob->query_weight();
               write(item + ": Ok.\n");
               from->add_weight(-w);
               move_object(ob, you);
               if(you->query_invis() <=41) 
                    say(you->query_name() + " takes: " + item + ".\n");
          }
          ob=next_ob; }
     ok;
}

power_put(str) {
     int weight;
     string item, cont;
     object itemob, contob;
     if((!str) || (sscanf(str, "%s in %s", item, cont)!=2)) {
          write("Put what?\n");
          ok; }
     cont=lower_case(cont);
     contob=present(cont, you);
     if(!contob) 
          contob=present(cont, environment(you));
     if(!contob) {
          write("There is no " + cont + " here!\n");
          ok; }
     item=lower_case(item);
     itemob=present(item, you);
     if(!itemob) {
          write("You have no " + item + ".\n");
          ok; }
     if(itemob==contob) return 0;
     weight=itemob->query_weight();
     environment(itemob)->add_weight(-weight);
     move_object(itemob, contob);
     write("Ok.\n");
     if(you->query_invis() > 40) ok;
     say(you->query_name() + " puts the " + item + " in the " + cont + ".\n");
     ok;
}

find_anyone(who) {
     object ob;
     int x;
     ob=users();
     for(x=0; x < sizeof(ob); x++) {
          if(ob[x]->query_real_name()==who)
               return ob[x];
     }
}

test_func ( str ) {
   object ob;
   ob = present("instrument", this_player());
   ob->set_bard_level(str);
   return 1;
}
