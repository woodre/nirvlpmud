#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("spear");
  set_alias("gungnir");
  set_short("Gungnir: the legendary spear of Wodan");
  set_long("A long shafted spear that vibrates with power. Runes\n"+
           "cover its length and glow with a red ember light. The\n"+
           "iron tip is blackened and razor sharp. Its wood has a\n"+
           "burnt finish and is heavy and wrist thick. This is a\n"+
           "spear of might.\n");
  set_class(17);
  set_type("polearm");
  set_weight(2);
  set_value(10000);
  set_hit_func(this_object());
}

query_save_flag() { return 0; }

weapon_hit(attacker){
  if(tp->query_attrib("wil") > random(50)) {
    write("You gouge your foe with the power of GUNGNIR!!!!\n");
  return 7; }
   return;
}

init() {
  ::init();
  add_action("read_runes","read");
  add_action("spear_lore","spear_lore");
  add_action("emotes","snarl");
  add_action("emotes","bsnarl");
  add_action("emotes","howl");
  add_action("emotes","blust");
  add_action("trophy","behead");
  add_action("berzerk","berzerk");
}

read_runes(str) {
  if(!str) { write("read what?\n"); return 1;}
  if(str != "runes") { write("read what?\n"); return 1;}
write("Type spear_lore for the functions of GUNGNIR!!!!\n");
return 1;
}

spear_lore() {
  write("~~~~~~~~~~~~~~~~~~~Spear Lore~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  write("EMOTES:\n"+
        "  snarl   bsnarl   howl   blust\n");
  write("POWERS:\n"+
        "  berzerk  behead\n");
  write("~~~~~~~~~~~~~~~~~~~Spear Lore~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
return 1; }


emotes() {
string msg,msg2;
msg = msg2 = 0;
  if(query_verb() == "snarl") { 
    msg = "You snarl viciously.";
    msg2 = tpn+" snarls viciously.";
  }
  if(query_verb() == "bsnarl") {
    msg = "You explode with a bloodthirsty snarl.";
    msg2 = tpn+" explodes with a bloodthirsty snarl.";
  }
  if(query_verb() == "howl") {
    msg = "You throw back your head and howl.";
    msg2 = tpn+" throws back "+tp->query_possessive()+" head and howls wildly.";
  }
  if(query_verb() == "blust") {
    msg = "You shake mightily as the Bloodlust overcomes you.";
    msg2 = tpn+" shakes mightily as the Bloodlust overcomes "+tp->query_objective()+".";
  }
  write(msg+"\n");
  say(msg2+"\n");
return 1; }

trophy(str) {
string name;
object ob,head;
  if(!str) { write("Behead what?\n"); return 1; }
  if(str != "corpse") { write("You can't do that.\n"); return 1;}
  ob = present("corpse",environment(tp));
  if(!ob) { write("There is no corpse here.\n"); return 1; }
  if(sscanf(ob->short(),"corpse of %s",name)) {
    head = clone_object("/players/daranath/closed/stuff/head.c");
    head->set_name(name);
    move_object(head,environment(tp));
    destruct(ob);
    write("You brutally take another trophy for your collection.\n");
    say(tpn+" brutally rips the head from the corpse!\n");
  } else {
  write("The corpse is too decayed to take a proper trophy.\n");
  }
return 1; }
  
berzerk(str) {
object targ;
  if(!str) { write("Berzerk what?\n"); return 1; }
  targ = present(str,environment(tp));
  if(!targ) { write("There is nothing to unleash your fury upon.\n"); return 1;}
  if(!living(targ)) { write("You must be mad!!!!\n"); return 1; }
  if(targ->is_pet()) {
    write("Tsk tsk, now be nice.\n"); return 1; }
  if(!this_player()->valid_attack(targ))
    return 1;
  if(tp->query_sp() < 20) { write("You do not have enough power.\n"); return 1; }
  tell_room(environment(tp),
        tpn+" bellows as the berzerk rage takes "+
        "hold and brutally beats "+capitalize(str)+"!\n");
  targ->attack_object(tp);
  tp->add_spell_point(-20);
return 1; }
