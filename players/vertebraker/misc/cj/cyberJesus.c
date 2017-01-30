#include <ansi.h>

inherit "/obj/monster";

int lives;

void reset(status x){
  ::reset(x);
  if(x) return;
  
  lives = 3;
  
  set_name(HIK+"CyberJesus"+NORM);
  set_alias("jesus");
  set_alt_name("cyberjesus");
  set_short(HIK+"CyberJesus"+NORM+" the Mechanical Messiah (neutral)");
  
  set_long("\
His tanned face has been scarred, revealing the innards of his\n\
clockwork mechanical workings. His eyes glow crimson with the\n\
fire of ancient knowledge. Long brown tufts of hair flay from\n\
his head, hanging just below his scraggly man beard. Stigmata\n\
on his wrists constantly ooze a green battery fluid. CyberJesus\n\
has risen again.\n");

  set_race("cyborg");
  set_gender("male");

  set_chat_chance(20);
  load_chat(query_name()+" scoffs.\n");
  load_chat(query_name()+" closes his eyes.\n");
  load_chat(query_name()+" clatters and clanks.\n");
  load_chat(query_name()+" shouts: \"dIE dEMonN!\"\n");
  load_chat(query_name()+" shouts: \"DrInK my FluiDs and BE saVeD!\"\n");
  load_chat(query_name()+" shouts: \"eaT mY MaNFleS?H!\"\n");
  load_chat(query_name()+" shouts: \"i AM goD anD HUmaN NoThing.\n");
  load_chat(query_name()+" rattles.\n");
  load_chat(query_name()+" shouts: \"CrUCifyICaTION a HuAMN PUnSIHMENT!\n");
  load_chat(query_name()+" buzzes and whirrs.\n");
  load_chat(query_name()+" flails.\n");
  
  set_level(23);
  set_wc(40);
  set_ac(21);
  set_hp(800);
  set_hp_bonus(3600);
  set_dead_ob(this_object());
  add_spell("missile",
        query_name()+" closes his eyes.\n"+
        RED+"\t\t-----|------------\n"+NORM+
        "A cross-shaped rocket shoots from his face!\n",
        query_name()+" closes his eyes.\n"+
        RED+"\t\t-----|------------\n"+NORM+
        "A cross-shaped rocket shoots from his face, at #TN#!\n",
        33,"0d1+200","other|laser");
}

void heart_beat(){
  ::heart_beat();
  
/* Replaced with add_spell - illarion 8.14.2009
  if(attacker_ob && present(attacker_ob,environment(this_object()))) {
    if(!random(3)) {
      tell_room(environment(),
        query_name()+" closes his eyes.\n"+
        RED+"\t\t-----|------------\n"+NORM+
        "A cross-shaped rocket shoots from his face!\n");
      attacker_ob->hit_player(200, "other|laser");
    }
  }
*/
  if(hit_point < 200 && lives > 0) {
    lives --;
    heal_self(1200);
    tell_room(environment(),
       query_name()+" closes his eyes.\n"+
       GRN+"Electronic energy pulses through "+NORM+query_name()+NORM+GRN+"!\n"+NORM);
  }
}

status monster_died(){
  tell_room(environment(),"\n\t\
As CyberJesus collapses to the ground, its mechanical body explodes!\n\n");
  move_object(clone_object("/players/vertebraker/misc/cj/cj_face"), environment());
  destruct(present("corpse", environment()));
 if(attacker_ob)
  write_file("/players/vertebraker/log/CyberJesus", ctime()+" killed by "+attacker_ob->query_real_name()+"\n");
  return 0;
}