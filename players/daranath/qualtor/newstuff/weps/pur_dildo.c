#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()
#define SEX tp->query_possessive()

inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("dildo");
  set_alias("purple");
  set_short("An enormous "+MAG+"purple dildo"+NORM);
   set_long("A large double headed purple dildo, this item has brought pleasure\n"+
            "to countless women in need. However, in your hands, it becomes a\n"+
            "deadly weapon, able to bring down armies. Just make sure you \n"+
            "clean it afterwards...\n"+
            "type: "+MAG+"dildo_power"+NORM+" for a list of commands this weapon gives you.\n");

  set_class(16);
  set_weight(1);
  set_value(1750);
  set_hit_func(this_object());
}

query_save_flag() { return 0; }

weapon_hit(attacker){
  if(tp->query_attrib("wil") > random(35)) {
   write("You smash you foe over the head with your "+MAG+"dildo"+NORM+"\n");
  return 9; }
   return;
}

init() {
  ::init();
  add_action("dildo_power","dildo_power");
  add_action("emotes","pdtwirl");
  add_action("emotes","pdspin");
  add_action("emotes","pdlick1");
  add_action("emotes","pdlick2");
  add_action("emotes","pdsuck1");
}

dildo_power() {
write(MAG+"()()()()()()()()()()()()()()"+HIW+"DILDO POWERS"+NORM+MAG+"()()()()()()()()()()()()()()"+NORM+"\n");
  write("EMOTES:  you must put pd in front of emote to use (ex: pdlick1)\n"+
        "  lick1, lick2, spin, suck1, twirl\n");
write(MAG+"()()()()()()()()()()()()()()"+HIW+"DILDO POWERS"+NORM+MAG+"()()()()()()()()()()()()()()"+NORM+"\n");
return 1; }


emotes() {
string msg,msg2;
msg = msg2 = 0;
  if(query_verb() == "pdspin") { 
    msg = "You spin the "+MAG+"dildo"+NORM+" around in your hand.";
    msg2 = tpn+" spins a large "+MAG+"purple dildo"+NORM+" around in "+SEX+" hand.";
  }
  if(query_verb() == "pdtwirl") {
    msg = "You twirl the "+MAG+"dildo"+NORM+" over your head.";
    msg2 = tpn+" twirls a "+MAG+"purple dildo"+NORM+" over "+SEX+" head.";
  }
  if(query_verb() == "pdlick1") {
    msg = "You lick the head of the dildo seductively.";
     msg2 = tpn+" slowly licks the head of the "+MAG+"purple dildo"+NORM+" and sighs softly.";
  }
  if(query_verb() == "pdsuck1") {
  msg = "You slide your lips around the head of the "+MAG+"purple dildo"+NORM+" and begin to suck it.";
  msg2 = tpn+" slides "+SEX+" lips around the head of the "+MAG+"purple dildo"+NORM+" and slowly begins to suck it.";
}
  if(query_verb() == "pdlick2") {
    msg = "You lick the length of the "+MAG+"dildo"+NORM+" seductivly.";
    msg2 = tpn+" slowly licks the length of the "+MAG+"purple dildo"+NORM+" and grins wickedly.";
  }
  write(msg+"\n");
  say(msg2+"\n");
return 1; }

