/* 2011-06-18 - increased WC, AC, and HP as the katana has been powered up some */
inherit "players/illarion/high/mon/imm_mon";
#include "/players/illarion/dfns.h"


void reset(int arg) {
  if(arg) return;
  ::reset(arg);
  
  if(!present("scar",this_object())) move_object(clone_object("/players/dragnar/MKScar/scar"),this_object());
  set_name("Duncan MacLeod");
  set_alias("duncan");
  set_race("immortal");
  set_gender("male");
  set_immortal(1);
  set_weapon_path(HOBJ+"dkatana_new");
  set_attacks(4);
  set_x_attack_chance(85);
  set_grab_bag(1);
  set_grab_chance(20);
  set_use_heals(1);
  set_use_heals_health(80);
  set_healing_factor(5);
  add_emote("healing_factor","","Electricity crackles around one of $MN$'s wounds.  "+
    "The wound shrinks away and vanishes!");
  set_level(21);
  set_al(700);
  set_wc(50);
  set_ac(30);
  /* 4/27/2000- changed hps from 100k to 10k - Illarion */
  /* 7/11/2009  reduced hp again */
  set_hp(5000);
  set_dodge_chance(33);
  add_emote("dodge","$MN$ ducks and rolls away from your attack.","$MN$ ducks and rolls away from $TN$'s attack.");
  set_counter_chance(20);
  add_emote("counter","$MN$ returns your attack with one of $MP$ own!","$MN$ returns $TN$'s attack with one of $MP$ own.");
  set_short("A dangerous looking, dark-haired man");
  set_long(
"A shiver runs down your spine as you examine this man.  There is something\n"+
"in his stance and expression that makes you feel young and helpless, even\n"+
"when he looks friendly.  He wears his dark hair long, and pulled back into\n"+
"a ponytail, and has the musculature of an accomplished martial artist...\n"+
"or a master swordsman.\n");
  add_chat_response("hello","The man nods absently.");
  add_chat_response("name",
    "The man says, \"Duncan Maccleod of the Clan Maccleod.\"\n");
  add_chat_response("immortal",
    "The man says, \"I don't know what you mean.\"\n");
  add_chat_response("fight",
    "The man says, \"Look, I don't want to fight you.\"\n");
}
long() {
  ::long();
  if(TP)  call_out("look_greet",0,TP);
}
look_greet(object ob) {
  if(ob && environment(this_object()))
    if(present(ob,environment(this_object()))) {
      tell_object(ob,"The man stares back at you, sizing you up.\n");
      tell_room(environment(this_object()),
        "The man sizes up "+ob->query_name()+".\n",({ob,this_object()}));
    }
}
id(str) { return ::id(str) || str == "man"; }
monster_died() {
  object *ppl,*obs,ob;
  int n,p,size,size2;
  string tmp;
  ppl=all_inventory(environment(this_object()));
  ppl-=this_object();
  ob=present("corpse",environment(this_object()));
  ppl-=ob;
           /* legality log */
  size=sizeof(ppl);
  write_file("/players/illarion/high/mon/WDLOG","Duncan killed "+
    ctime(time())+" by "+this_player()->short()+"\n");
  for(n=0;n<size;n++) {
    write_file("/players/illarion/high/mon/WDLOG","Name: "+
      ppl[n]->query_name()+" Level: "+ppl[n]->query_level()+"\n"+
      "Inventory:\n");
    obs=all_inventory(ppl[n]);
    size2=sizeof(obs);
    for(p=0;p<size2;p++)
      write_file("/players/illarion/high/mon/WDLOG",file_name(obs[p])+"\n");
  }
            /* vanity log */
  write_file("/players/illarion/high/mon/DLOG","Time: "+ctime(time())+"\n");
  write_file("/players/illarion/high/mon/DLOG","Killing blow struck by:\n"+
    this_player()->short()+" ("+capitalize(TPRN)+")\n");
  ppl-=TP;  
  size=sizeof(ppl);
  if(size) {
    write_file("/players/illarion/high/mon/DLOG","Others present:\n");
    for(n=0;n<size;n++)
     if(ppl[n])
      if((tmp=ppl[n]->short()))
       if((tmp=ppl[n]->query_real_name()))
        write_file("/players/illarion/high/mon/DLOG",tmp+" ("+capitalize(ppl[n]->query_real_name())+")\n");
  }
  return ::monster_died();
}
attack_object(ob) {
  if(ob == this_object()) {
    write("Duncan laughs at your pathetic attempts to cloud his mind,\n"+
          "shaking them off like mere cobwebs.\n");
    return;
  }
  ::attack_object(ob);
}
attacked_by(ob) {
  if(ob==this_object()) {
    tell_room(environment(),"Duncan refuses to fight himself.\n");
    stop_fight();
    return;
  }
  return ::attacked_by(ob);
}
catch_tell(str) {
  ::catch_tell(str);
  "/players/beck/MortalKombat/MKQuestNPC.c"->catch_tell(str,this_object());
}
