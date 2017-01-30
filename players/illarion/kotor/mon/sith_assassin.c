#include "/players/illarion/dfns.h"

inherit IMM_MON;
status setup_stats;
status is_visible;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("assassin");
  set_alias("sith");
  set_race("human");
  set_short(0);
  set_gender(({"male","female"})[random(2)]);
  set_long(format(
     "Though "+PRO(TO)+" is garbed entirely in black, broken only by glowing "+
     "red goggles, this assassin's figure looks even darker than it should be.  "+
     "Rather than absorbing light, "+PRO(TO)+" seems to radiate darkness."));
/* base stats.  These are reshuffled the first time the target is attacked! */
  set_wc(20);
  set_ac(10);
  set_hp(200);
  set_level(10);
  add_emote("dodge",
      "The assassin jumps up and over you, avoiding your attack!\n",
      "The assassin jumps up and over #TN#, avoiding #TP# attack!\n");
  add_emote("dodge",
      "The assassin leans back, and your attack falls just barely short.\n",
      "The assassin leans back, and #TN#'s attack falls just barely short.\n");
  set_chat_chance(5);
  load_chat("There is a faint shimmer in the air.\n");
}

void make_me_stronger(object ob) {
  int lev;
  object room;
  if((room=ETO)) {
    tell_room(room,format(
        "The assassin staggers back from "+NAME(ob)+"'s attack for a moment, but then "+
        PRO(TO)+" suddenly seems stronger!\n"),({ob,TO}));
    tell_object(ob,
        "You feel a brief but intense mental connection between yourself and the assassin.\n"+
        "The connection vanishes, and you don't feel any different, but the assassin seems\n"+
        "stronger!\n");
  }
  lev=10+(int)ob->query_total_level()/5;
  if(lev>30) lev=30;
  set_wc(lev);
  set_ac(lev/2);
  set_hp(lev*20);
  set_dodge_chance(lev);
  set_counter_chance(lev/2);
  set_armor_params("other|mental",0,lev*2,0);
  set_attacks(1+lev/15);
}

id(str) {
  if(is_visible)
    return ::id(str);
  if(TP) {
    int luck,intel;
    luck=TP->query_attrib("luc");
    intel=TP->query_attrib("intel");
    if(random(luck) > 15 || random(intel) > 15 || TP->query_level() > 19)
      return str=="shimmer";
  }
}
  
long() {
  if(is_visible)
    return ::long();
  write("You can just barely make out a human-shaped shimmer in the air.  Either\n"+
     "you're seeing things, or someone is using a stealth field generator.\n");
} 

void attacked_by(object ob) {
  ::attacked_by(ob);
  if(!setup_stats && ob->is_player()) {
    setup_stats=1;
    make_me_stronger(ob);
  }
}

heart_beat() {
  if(!is_visible && attacker_ob && present(attacker_ob,ETO)) {
    is_visible=1;
    tell_room(ETO,
        "A stealth field collapses, revealing the black figure of a Sith Assassin!\n",
        ({TO}));
    set_short("A Sith assassin");
  } else if(is_visible && (!attacker_ob || !present(attacker_ob,ETO))) {
    is_visible=0;
    tell_room(ETO,
        "The assassin's body seems to shimmer, and then it vanishes!\n",
        ({TO}));
    set_short(0);
  }
  ::heart_beat();
}
