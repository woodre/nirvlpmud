#include "/players/fakir/color.h"
inherit "/obj/monster";
int ack,qq,q,kkk;
object envir;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("trolloc");
  set_alias("captain");
  set_race("creature");
  set_short("Trolloc Captain");
  set_long(
"A creature of the Dark One, created during the war of the shadow.\n"+
"Huge in stature, vicious in the extreme, he is a twisted blend of\n"+
"animal and human stock, and he kills for the sheer pleasure of\n"+
"killing.  Sly, deceitful and treacherous, he can be trusted\n"+
"only by those he fears. This one is especially large and fierce.\n");
  set_level(18);
  set_hp(450);
  set_al(-800);
  set_wc(26);
  set_ac(15);
  set_dead_ob(this_object());
  set_chat_chance(15);
  load_chat("The trolloc captain waits for your next move.\n");
  load_chat("The captain says: 'I can wait as long as you can.  You begin to bore me.'\n");
  load_chat("The captain sneers: 'No guts no glory.  Lets have at it, your steel against mine!'\n");
  set_a_chat_chance(15);
  load_a_chat("The trolloc sidesteps and bites your shoulder.\n");
  load_a_chat("The captains blade whistles past your left ear.\n");
  load_a_chat("Trolloc Captain rasps: 'You fight like a northlander woman!'\n");
  set_chance(10);
  set_spell_dam(20);
  set_spell_mess1("The trolloc snorts and coughs blood in your face.\n");
  set_spell_mess2("The trolloc snorts and coughs blood in your face. \n");
  add_money(3000);
}

heart_beat() {
  ::heart_beat();
  if(!environment()) return;
  if(!query_attack()) {
    if(!random(10)) {
      envir = 0;
      ack = allocate(10);
      qq = 0;
      kkk = 0;
      envir = all_inventory(environment(this_object()));
      for(q=0;q<sizeof(envir);q++) { 
        if(envir[q]->is_player()) {
          ack[qq] = envir[q];
          qq++; }
        }
      q = 0;
      while(q<sizeof(ack) && !kkk) {
        if(ack[q] && !random(5)) {
        attack_object(ack[q]);
        kkk = 1;
        }
      q++; } 
      }
    } 
  else if(query_attack() && query_attack() == this_object()) { heal_self(100000); }
  }

monster_died() {
  tell_room(environment(this_object()),
  YELLOW+"The trolloc captain doubles over in pain and draws his last breath."+OFF+" \n");
  return 0; }
