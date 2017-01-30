#define LOGPATH "/players/feldegast/log/"
#define OWNER "feldegast"
#include "/players/feldegast/defines.h"
inherit "/obj/monster";

  string log_file;
  string invited;
  object owner;
  object follow;
  int snooping;
  int invis;
  int muffled;

reset(arg) {
  ::reset(arg);

  if(!present("staff")) {
    move_object(clone_object("/players/feldegast/arena/melee/ceremonial_staff"),this_object());
  }
  if(!present("feldstaff")) {
    move_object(clone_object("/players/feldegast/closed/nifty_st"),this_object());
  }
  if(!present("sword",this_object())) {
    object it;
    it=clone_object("/obj/weapon");
    it->set_wc(20);
    it->set_name("broadsword");
    it->set_short(BOLD+BLK+"Greyheart"+NORM+" the Broadsword");
    it->set_weight(100);
    move_object(it,this_object());
  }

  if(arg) return;
  set_name("Seth Darkeyes");
  set_alt_name("seth");
  set_short(BOLD+"Seth Darkeyes"+NORM+", the Master of Ceremonies");
  set_long(
"Seth Darkeyes is a tall man, perhaps in his mid-thirties, with\n"+
"sharply handsome features and an immaculate appearance.  His eyes,\n"+
"despite his name are a remarkable shade of cobalt blue.  He wears a\n"+
"midnight black mantle over his broad shoulders and a scabbard hangs\n"+
"from his belt.  Seth Darkeyes is a legendary sorceror whose very\n"+
"name has been known to strike fear into the hearts of the bravest\n"+
"mortal.  It is for this reason, that the legendary Lord of the Night\n"+
"has been invited to serve as Master of Ceremonies for this tourney.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(20);
  set_wc(30);
  set_ac(9);
  set_hp(500);
  snooping=0;
  set_al(-1500);
  set_heal(50,1);
  enable_commands();

  set_a_chat_chance(5);
  load_a_chat(name+" slashes viciously with his blade.\n");
  load_a_chat(name+" gracefully swirls his cloak about his body.\n");

}

catch_tell(str) {
  out_put("~"+str);
}
set_owner(ob) {
  owner=ob;
}

set_snooping() {
  snooping=!snooping;
  write("Squawk "+(snooping?"on":"off")+"\n");
}
heart_beat() {
  ::heart_beat();
  if(!owner) destruct(this_object());
  if(attacker_ob && !random(7)) {
    tell_object(attacker_ob,name+" raises his hands and "+CYN+"electricity"+NORM+" arcs from\n"+
                "him to you, lashing you with pain.\n");
    tell_room(environment(this_object()),name+" lashes "+attacker_ob->query_name()+" with bolts of "+CYN+"electricity"+NORM+".\n");
    attacker_ob->hit_player(60);
  }
}

go_invis() {
  invis=!invis;
}

short() {
  if(invis) return 0;
  else return short_desc;
}
query_invis() {
  return invis;
}
init() {
  add_action("snoop");add_xverb("");
}
snoop(str) {
  if(snooping) {
    out_put("~"+TPN+"~"+str+"\n");
  }
}
set_follow(ob) {
  if(!ob) follow=0;
  follow=ob;
  call_out("follow",3);
}
follow() {
  if(!follow) return;
  if(follow && !present(follow,environment())) {
    move_object(this_object(),environment(follow));
    out_put("~"+environment()->short()+"\n");
  }
  call_out("follow",3);
}

set_muffle(int x) {
  muffled=!muffled;
  write("You "+(muffled?"ignore":"listen to")+" the gamemaster.\n");
}
set_file(str) {
  if(!str) log_file=0;
  else log_file=str;
}
out_put(str) {
  if(!owner) destruct(this_object());
  if(log_file) {
    write_file(LOGPATH+log_file,str);
  }
  if(!muffled) {
    tell_object(owner,str);
  }
}
