#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/monster";
int X;
int Y;
int Z;
int G;
string SIZE;
string WHAT;
string NAME;
string RACE;
object gold;
object ob;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Y = (random(5));
  Z = (random(10));
  X = (Y+16);

  if(X == 16) SIZE = " brass";
  if(X == 17) SIZE = " bronze";
  if(X == 18) SIZE = " iron";
  if(X == 19) SIZE = " steel";
  if(X == 20) SIZE = " mithril";
  if(X == 21) SIZE = " gromril";
  if(X == 22) SIZE = " runic";

  if(Z == 0) WHAT = "golem";
  if(Z == 1) WHAT = "crusher";
  if(Z == 2) WHAT = "binder";
  if(Z == 3) WHAT = "clockwork";
  if(Z == 4) WHAT = "mechanical";
  if(Z == 5) WHAT = "animation";
  if(Z == 6) WHAT = "atomaton";
  if(Z == 7) WHAT = "grinder";
  if(Z == 8) WHAT = "pulverizer";
  if(Z == 9) WHAT = "hewer";

  if(Z == 0) RACE = "construct";
  if(Z == 1) RACE = "construct";
  if(Z == 2) RACE = "construct";
  if(Z == 3) RACE = "construct";
  if(Z == 4) RACE = "construct";
  if(Z == 5) RACE = "construct";
  if(Z == 6) RACE = "construct";
  if(Z == 7) RACE = "construct";
  if(Z == 8) RACE = "construct";
  if(Z == 9) RACE = "construct";

  if(Z == 0){ golem(); }
  if(Z == 1){ crusher(); }
  if(Z == 2){ binder(); }
  if(Z == 3){ clockwork(); }
  if(Z == 4){ mechanical(); }
  if(Z == 5){ animation(); }
  if(Z == 6){ atomaton(); }
  if(Z == 7){ grinder(); }
  if(Z == 8){ pulverizer(); }
  if(Z == 9){ hewer(); }

  if(Y == 0) G = (random(600)+1090);
  if(Y == 1) G = (random(600)+1250);
  if(Y == 2) G = (random(600)+1500);
  if(Y == 3) G = (random(1000)+2000);
  if(Y == 4) G = (random(1000)+3000);

  set_name(WHAT);
  set_short(YEL+"A"+SIZE+" "+WHAT+""+NORM);
  set_alias("RACE");
  set_race("RACE");
  set_hp(450+(Y*25));
  set_level(X);
  set_al(0);
  set_wc(X+4);
  set_ac(22+(Y*2));
  set_aggressive(1);

  set_dead_ob(TO);

  gold=clone_object("obj/money");
  gold->set_money(G);
  move_object(gold,this_object());

}

  id(str) {
  return (str == WHAT || str == RACE || str == "smon"); 
}

golem(){
    set_long("\
A creation of master dwarven artisans for various purposes around a hold.\n\
Though normally needing constant minding, this one seems to lack any sort \n\
of command or guidence.\n");    
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The golem blankly stares ahead.\n");
  load_chat("A grinding sound emits from the golem's joints.\n");
  load_a_chat("The golem pounds away with heavy fists.\n");
}
crusher(){
    set_long("\
The crusher is a melding of a rock crusher and a golem.  Originally they\n\
were created to assist in the quarries and mines, then were used in sieges\n\
and other destructive missions.\n");    
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The crusher smashes his hammer fists together.\n");
  load_chat("The crushes smashes its fists violently together.\n");
  load_a_chat("The crusher pulverises its enemy with its fists.\n");
}
binder(){
    set_long("\
The binder was created for smiths and miners to aid in binding timbers\n\
and metal plates.  They are simple minded and tend to follow orders or\n\
instructions to the letter.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The binder slowly looks about.\n");
  load_chat("The binder creaks and groans.\n");
  load_a_chat("The binder pummels its foe.\n");
}
clockwork(){
    set_long("\
Clockworks are intricately crafted with multiple parts that animate and\n\
give it locomotion.  Normally crafted as a child's play-thing, some are\n\
more advanced and thus used as defense for the dwarves.\n");    
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The clockwork clicks and whirrs.\n");
  load_chat("You hear a 'tick-tock' sound comming from the clockwork.\n");
  load_a_chat("The clockwork slashes with a sharpened appendage.\n");
}
mechanical(){
    set_long("\
Mechanicals were a dwarven attemmpt to bridge the gap between the engineers\n\
guild and the crafters guild.  Vaguely looking like a great mass of cogs and\n\
pistons with a crude metallic face.  \n");    
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The smell of lubricant wafts through the air.\n");
  load_chat("The mechanical hisses and shifts.\n");
  load_a_chat("The mechanical emites some scalding hot steam.\n");
}
animation(){
    set_long("\
A menagerie of mismatched parts discarded from other engineer projects.  At\n\
first it looks ramshackle and unstable, but with some sort of unknown magic\n\
it retains it's form and continues to move about.\n");    
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The animation clinks and rattles its parts.\n");
  load_chat("A groan of parts squeal together.\n");
  load_a_chat("The animation peppers the area with shrapnel.\n");
}
atomaton(){
    set_long("\
An atomaton is a better built form of the animation golem.  Though it still \n\
retains animating magics it also seems more sleak and and well coordinated then\n\
it's less advanced cousin.\n");     
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The atomaton stands ready before you.\n");
  load_chat("The atomaton shuffles about with a casual gait.\n");
  load_a_chat("The atomaton crushes its foe in a bear hug.\n");
}
grinder(){
    set_long("\
Grinders are a 'brother' to the crusher class golem.  They appear similiar to the\n\
other crusher, yet posses a more sleek appearence.\n");    
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The grinder looks for things to grind.\n");
  load_chat("The grinder shuffles aimlessly.\n");
  load_a_chat("The grinder grinds.\n");
}
pulverizer(){
    set_long("\
The pulverizer is the ultimate class of golem no matter what alloy type was used in\n\
it's crafting.  Though some would think the best would look the part, the dwarves who\n\
crafted them gave them a less superior appearence to throw off would be attackers.\n");    
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The pulverizer looks about.\n");
  load_chat("The pulverizer searchers for somethign to smash.\n");
  load_a_chat("The pulverizer lets loose with rapid hammer blows.\n");
}
hewer(){
    set_long("\
The hewer is solely designed to kill.  It's arms bristle with multiple axes\n\
of many types used for throwing or hacking apart it's enemies. \n");  
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The hewer swings it's bladed arms about.\n");
  load_chat("Axes click in preparation for battle.\n");
  load_a_chat("The hewer chops wildly at its foe.\n");
}
