/*
 * This monster's primary purpose is to provide a way for players
 * to find out if a weapon or armor has any non-physical components
 * to it.
 *
 */
 
#include "/players/illarion/dfns.h"
inherit "obj/monster";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("martin");
  set_short("Martin, the pessimistic scholar");
  set_alt_name("scholar");
  set_gender("male");
  set_race("human");
  
  set_level(1);
  set_hp(1000);
  
  set_long("\
Martin is a fairly tall man, with slightly thinning hair, a thin,\n\
cleanshaven face, and a sour look that evidently never goes away.\n\
His clothing is of fine material and fancy cut, but worn and even\n\
threadbare in some places.\n\
He has come to Ryllian to try to earn back his lost fortune, by\n\
selling access to his immense knowledge of weapons and armor.  If\n\
you\'re interested in using his services, you should <ask> him\n\
what they are.\n");

  set_chat_chance(2);
  load_chat("Martin grumbles under his breath.\n");

  load_chat("Martin says, \"Don't you try to tell me there's good in the world.\"\n");
/*
  load chat("Martin says, \"Man is bound to live either in convulsions of misery\n"+
"or in the lethargy of boredom.  Don't ask me to rescue anyone from\n"+
"the convulsions of misery.\n");
*/

}

init() {
  ::init();
  add_action("cmd_ask","ask");
  add_action("cmd_cost","cost");
  add_action("cmd_identify","identify");
}

status cmd_ask() {
  write("Martin says, to you:\n"+
"\"I am a scholar.  I have tremendous knowledge of weapons and armor.\n"+
"For a price consummate with the value of an item, I can give you\n"+
"a general idea of its quality, and sometimes I can even tell when\n"+
"it has some kind of unusual property.\n\n"+
"For my services, just ask me to <identify> an item.  You might want\n"+
"to check the <cost> first, though, as I do charge quite a lot for\n"+
"more valuable items.\"\n");
  say("Martin tells "+NAME(TP)+" about his services.\n");
  return 1;
}

status get_ob_type(object ob) {
  if(ob->is_armor())
    return 1;
  if(ob->weapon_class())
    return 2;
  return 0;
}

int get_ob_cost(object ob) {
  int cost;
  return 300;
/* Use the formula below if and when he gives more info

  cost=(int)ob->query_value();
  if(cost < 1000)
    cost=1000;
  else if(cost < 10000)
    cost=cost+ (cost-10000)/1000;
  return cost;
  */
}

status cmd_cost(string str) {
  object ob;
  if(!str) {
    write("Martin rolls his eyes.  \"What item to you want to know the identify cost for?\"\n");
    return 1;
  }
  
  if(!(ob=present(str,TP))) {
    write("Martin sighs.  \"You don't have that.\"\n");
    return 1;
  }
  if(!get_ob_type(ob)) {
    write("Martin says, \"Weapons and armor only, please.\"\nHe sighs.\n");
    return 1;
  }
  write("Martin says, \"It will cost you "+get_ob_cost(ob)+" coins for my opinion of that item.\n"+
        "Before you ask, no I don't take credit, and no, I won't give you a discount.\"\n");
  return 1;
}

show_ob_info(object ob,int ob_type) {
  mixed *params;
  int s,iterate,x;
  string message;
  string cat,subcat;

  params=ob->query_params();
  if(ob_type==1)
    iterate=4;
  else
    iterate=3;
  s=sizeof(params);
  message="";
  for(x=0;x<s;x+=iterate) {
    if(params[x]=="physical" || params[x]=="magical")
      message+=params[x]+", ";
    else if(sscanf(params[x],"%s|%s",cat,subcat)==2)
      message+=subcat+", ";
  }
  write("Martin says, \"Your item has influence in the following areas:\n" +
#ifndef __LDMUD__ /* Rumplemintz */
        message[0..-3] +
#else
        message[0..<3] +
#endif
        "\n");
  write("You want to know any more, you just go ask a Bard.\n");
  write("If you can find one.\"\n");
}
  
status cmd_identify(string str) {
  object ob;
  int type;
  int cost;
  if(!str) {
    write("Martin says, \"Yes, I can identify items.  But you need to specify the item\n"+
          "You want me to identify.\"\n");
    return 1;
  }
  if(!(ob=present(str,TP))) {
    write("Martin says, \"Look, I'm not a patient man.  Go get that item and bring it here\n"+
          "and I _might_ still be willing to identify it.\"\n");
    return 1;
  }
  if(!(type=get_ob_type(ob))) {
    write("Martin rolls his eyes.  \"Weapons and armor only.\"\n");
    return 1;
  } 
  if((cost=get_ob_cost(ob)) > TP->query_money()) {
    write("Martin sneers at you.  \"Sorry, no credit and no discounts.  Come back when you\n"+
          "can afford the cost of my services.\"\n");
    return 1;
  }
  TP->add_money(-cost);
  write("Martin takes your money, and counts it.  Twice.\n");
  write("He then makes a mystic symbol and it vanishes in a puff of smoke.\n");
  write("He almost looks cheerful as he studies your item.\n");
  show_ob_info(ob,type);
  write("Martin smiles humorlessly.  \"Thanks for your custom, and your money.\"\n");
  write("He raises his voice and says, \"Next item!\"\n");
  say("Martin says, \"Next item!\"\n");
  return 1;
}
