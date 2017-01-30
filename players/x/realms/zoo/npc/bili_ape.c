#include <ansi.h>

inherit "/obj/monster";

string BA;

int eaten;

void reset(int arg){
  ::reset(arg);
  if(arg) return;
  BA = HIK+"bili ape"+NORM;
  set_name("bili ape");
  set_alias("ape");
  set_race("chimpanzee");
  set_short("A toughened "+BA+" (snarling)");
  set_long("\
This "+BA+" looks like a giant chimpanzee. Held in its\n\
hands are are a few strange-looking fruits, some branches and\n\
other pieces of wood. Strong, agile muscles dominate its limber\n\
physique. The "+BA+"'s black eyes stare directly\n\
into yours as it shows no fear.\n");
  set_a_chat_chance(8);
  load_a_chat("The "+BA+" growls and snarls.\n");
  load_a_chat("The "+BA+" snaps at you!\n");
  load_a_chat("The "+BA+" thrashes its limbs around.\n");
  load_a_chat("The "+BA+" stares at you.\n");
  load_a_chat("The "+BA+" hoots wildly at the sky.\n");
  set_gender("male");
  set_level(23);
  set_wc(40);
  set_ac(21);
  set_hp(800);
  set_hp_bonus(500);
  set_wc_bonus(13);
  set_armor_params("other|poison", 100, 0, 50, "poison_defense");
  set_dead_ob(this_object());
  set_message_hit(({
    HIR+"BUTCHERED"+NORM, " into pulps of meat",
    HIK+"splattered"+NORM, "'s blood all over the cage",
    RED+"gored"+NORM, ", ruthlessly tearing into flesh",
    YEL+"smashed"+NORM, "'s flesh",
    "whalloped", "",
    "punched", "",
    "kicked at", "",
  }));
}

int poison_defense(){
  tell_room(environment(),
    "The "+BA+" resists the "+GRN+"poison"+NORM+"!\n");
  return 0;
}

void heart_beat(){
  ::heart_beat();
  if(eaten < 5 && hit_point <= 200){
    tell_room(environment(),
      "\n"+BA+" puts a "+GRN+"strange"+NORM+" "+MAG+"fruit"+NORM
        +" in his mouth and takes a bite.\n");
    eaten++;
    heal_self(100);
  }
  if(!attacker_ob){
    object ob, oc;
    ob = first_inventory(environment());
    while(ob){
      oc = next_inventory(ob);
      if(ob!=this_object()){
        attack_object(ob);
      }
      ob = oc;
    }
  }
  if(attacker_ob){
    if(!random(4)){
      tell_object(attacker_ob,
        "\n\t"+BA+" hurls a sharp stick at you!\n");
        attacker_ob->hit_player(50);
    }
  }  
}

status monster_died(){
  int x;
  tell_room(environment(),
    "\n\tThe dying "+BA+" leaves behind some strange-looking fruit.\n\n");
    
  for(x=0;x<(2+random(4));x++) {
    move_object(clone_object("/players/x/realms/zoo/obj/strangler_fig"), environment());
  }
  return 0;
} 