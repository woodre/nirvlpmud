#include "/players/mythos/closed/ansi.h"
mixed nulled;
object leave;
inherit "players/mythos/dmon/mon";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("amara");
  set_alias("defender");
  set_race("avatar");
  set_short("Amara- Defender of the Sands");
  set_long("Before you stands a woman wearing a blood red robe.\n"+
           "She stands with a haughty air and calmly looks you over.\n"+
           "She then whispers: Be gone, intruder upon the Sacred Sands.\n"+
           "                   Else feel the wrath of a Defender!\n");
  set_level(25);
  set_hp(1200);
  set_al(0);
  move_object(clone_object("/players/mythos/dwep/defender.c"),this_object());
  init_command("wield blade");
  leave = clone_object("/obj/money.c");
  leave->set_money(3000 + random(2000));
  move_object(leave,this_object());
  set_wc(50);
  set_ac(21);
  set_heal(5,15);
  set_aggressive(1);
  set_gender("female");
  set_chat_chance(20);
  set_a_chat_chance(2);
  load_chat("Amara chants quietly.\n");
  load_chat("Sand blows around.\n");
  load_a_chat("Amara lashes out with her blade!\n");   
  load_a_chat("Sand blows everywhere.\n");
  set_chance(20);
  set_spell_dam(500);
  set_spell_mess1("Amara shouts and the wind blasts into her enemy!\n");
  set_spell_mess2("Amara shouts and a great wind blows sand everywhere!\n"+
                  "The sand strikes you and cuts into you.\n"); 
  set_mult(2);
  nulled = ({});
}

query_prevent_shadow() { return 1; }

hit_player(dam,zap) {
int damm;
object weps;
  damm = dam;
  weps = 0;
  if(previous_object()->weapon_class()) weps = previous_object();
  if(weps) if(!weps->query_dwep() && !weps->query_desert_weapon())  
    damm = damm/2;
  :: hit_player(damm,zap);
}

heal_self(n) {
int h;
object weps;
  weps = 0;
  h = n;
  if(h<0) {
  if(previous_object()->weapon_class()) weps = previous_object();
  if(weps) if(!weps->query_dwep() && !weps->query_desert_weapon()) h = h/2; }
  ::heal_self(h);
} 

init() {
 if(this_player() != this_object()) add_action("nulls");add_xverb("");
}

nulls(str) {
  if(!str) return 0;
  if(member_array(str,nulled) == -1) {
    nulled += ({str});
    nulled += ({1});
  }
  else {
     if(nulled[member_array(str,nulled) + 1] > 5) {
       if(random(100) < 5+nulled[member_array(str,nulled) + 1]) { 
         write("Amara smiles at you and you find that \n"+
               "you can not do that action.\n");
       return 1; } 
     } 
       nulled[member_array(str,nulled) + 1] = 
       nulled[member_array(str,nulled) + 1] + 1;
   }
}

heart_beat() {
  ::heart_beat();
  if(query_attack()) {
    if(query_attack() == this_object()) {
      stop_fight();
    }
    set_heal(5,15);
    if(query_wc() < 40) set_wc(40);
    if(query_ac() < 17) set_ac(17);
    if(query_attack()->query_hp() < query_attack()->query_mhp()/2 &&
       hit_point > 499) {
      if(!present("enforcer",this_object())) {
        init_command("mode enforce");
      }
    }
    if(hit_point < 500 ) {
      if(!present("defender",this_object())) {
        init_command("mode defense");
      }
    }
    }
}

query_attrib(str) {
  if(str == "pie") return 50;
  if(str == "int") return 30;
  else return 20;
}