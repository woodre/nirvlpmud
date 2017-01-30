#include <ansi.h>

inherit "/obj/monster";

string size;

void reset(int arg)
{
  
  ::reset(arg);
  if(arg) return;
  
  set_dead_ob(this_object());
  
  set_race("alma");
  set_gender(random(2) ? "male" : "female");
  
  set_armor_params("other|ice", 0, 50, "ice_defense");
  
  set_message_hit(({
   HIR+"GOUGED"+NORM, "'s torso open",
   HIK+"slammed"+NORM, " to the ground, carving and slashing",
   RED+"splattered"+NORM+" the wall with","'s blood",
   "sliced", " with a strong swipe",
   "slashed", " solidly",
   "nicked", "",
   "grazed", "",
   }));
  
  switch(random(9)) {
    case 0..1:
      size = "baby";
      set_long("\
A small, furry alma. Like humans, the babies are *usually*\n\
the only almas that crawl. The babies are lighter grey in\n\
color than the adults. Its tiny black hands and feet are\n\
rounded at the points, devoid of claws. Its small green\n\
eyes look at you with bemusement and wonder.\n");
      set_level(14);
      set_hp(210);
      set_ac(11);
      set_wc(18);
      set_short("A baby alma");
      set_message_hit(({
        "annihilated", " with a swift flurry of blows",
        "crushed", " relentlessly",
        "bashed", " on the noggin", 
        "struck", " hard",
        "punched", "",
        "slapped", "",
        "kicked", " gently",
      }));
      break;
    case 2..3:
      size = "juvenile";
      set_long("\
A juvenile alma, these are notorious for being particularly\n\
aggressive to intruders. The juvenile alma is fearless, and\n\
while it may not be the strongest of the almas, it makes up\n\
for its physicality with tenacity. The juvenile almas are thin\n\
with black fur with spots of grey.\n");
      set_level(18);
      set_hp(400);
      set_ac(15);
      set_wc(26);
      set_wc_bonus(26);
      set_aggressive(1);
      set_short("A juvenile "+HIK+"alma"+NORM);
      break;
    case 4..7:
      size = "adult";
      set_long("\
The adult alma are protective of their other alma; with strong\n\
arms and rippling muscles, they are easily capable of handling\n\
any intruders to the family's den. Their fur is sheer black,\n\
with tufts of brown on their back. Peering at you with curiosity,\n\
the adult alma mimics some of your actions while keeping a casual\n\
distance. You begin wondering whether these adult alma are some\n\
sort of missing link to humanity.\n");
      set_level(21);
      set_wc(34);
      set_wc_bonus(34);
      set_ac(19);
      set_hp(600);
      set_short("An "+YEL+"adult"+NORM+" "+HIK+"alma"+NORM);
      break;
    case 8:
      size = "elder";
      set_short("An "+HIW+"elder alma"+NORM);
      set_long("\
The elderly alma are quite rare in alma society. They are sheer\n\
white, with only a few graying strands left on their body. Their\n\
talons are much longer than the other almas, thickened bone and\n\
sharpened cartilage. They are quiet and meek, but if attacked\n\
are known as the most ferocious of all the almas.\n");
      set_level(21);
      set_wc(50);
      set_wc_bonus(50);
      set_ac(19);
      set_hp(600);
      break;
  }
  if(!sscanf(short(), "An %s", name))
    sscanf(short(), "A %s", name);
  set_name(name);
  set_alias(size+" alma");
  set_alt_name(size);
  
  set_chat_chance(5);
  load_chat(short()+" picks at something.\n");
  load_chat(short()+" ruffles through "+possessive(this_object())+" hair.\n");
  load_chat(short()+" shuffles around.\n");
  load_chat(short()+" smiles broadly.\n");
  load_chat(short()+" holds "+possessive(this_object())+" arms up and shakes wildly.\n");
  load_chat(short()+" looks at you.\n");
  load_chat(short()+" chitters a few words, then abruptly stops.\n");
  load_chat(short()+" looks bewildered.\n");
  load_chat(short()+" lays down on the ground.\n");
  load_chat(short()+" stares up in the sky.\n");
  load_chat(short()+" picks up some dirt, then lets it fall out of "+
    possessive(this_object())+" hands.\n");
  load_chat(short()+" digs at something in the ground.\n");
  load_chat(short()+" approaches the bars of the cage, then stops and stares out them.\n");
  load_chat(short()+" appears to be singing some sort of alma song.\n");
  load_chat(short()+" warbles a few sounds.\n");
  load_chat(short()+" stands upon "+possessive(this_object())+" four-toed feet \
and puffs out "+possessive(this_object())+" chest.\n");
}

int ice_defense()
{
  tell_room(environment(),
    "The "+short()+" resists the "+HIC+"cold"+NORM+"!\n");
  return 0;
}

string query_alma_size(){
  return size;
}

void heart_beat(){
  
  ::heart_beat();
  
  if(attacker_ob){
    object ob, oc;
    
    ob = first_inventory(environment());
    while(ob){
      oc = next_inventory(ob);
      if(ob != this_object() && !ob->query_attack() &&
       (string)ob->query_alma_size() == "adult"){
        tell_room(environment(),
          (string)ob->short()+" roars in anger!\n");
        ob->attack_object(attacker_ob);
      }
      ob = oc;
    }
  }
  
  if(attacker_ob && (size == "adult" || size == "elder")){
    already_fight = 0;
    attack();
  }
}

status monster_died() {
  object obj;
  obj = clone_object("/players/x/realms/zoo/obj/alma_fur");
  obj->set_size(size);
  move_object(obj, environment(this_object()));
  tell_room(environment(), "\n\
The dead alma leaves its precious fur behind.\n");
  return 0;
} 
