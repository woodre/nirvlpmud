inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
object *all;
int a,sa,b,c,d,e;

reset(arg) {
  ::reset(arg);
   if (!arg) {

  set_name(BOLD+BLK+"primordial ooze"+NORM);
  set_alias("ooze");
  set_short(BOLD+BLK+"A black primordial ooze"+NORM);
  set_long(
    "What rests before you is a strange black ooze.  It is spread out\n"+
    "across much of the floor of the cavern with a heaving bulge about\n"+
    "four feet tall in the center which is hard to see in the darkness.\n"+
    "Toxic fumes are slowly escaping from the creature as tiny bubbles\n"+
    "of gas slowly collect and then pop, throwing tiny amounts of ooze\n"+
    "up against the walls of the cavern.  It is very difficult to guage\n"+
    "the difficulty or the intelligence of this primordial ooze.\n");
  set_race("ooze");
  set_level(26);
  set_ac(23+random(4));
  set_wc(54+random(5));
  set_wc_bonus(96);
  set_hp(1000);
  set_heal(5,1);
  set_gender("creature");
  set_chat_chance(4);
  load_chat("The ooze shifts in the dirt...\n");
  load_chat("The ooze bubbles slowly...\n");
  load_chat("The ooze seems to shift back and forth...\n");
  load_chat("You notice fumes rising from the ooze...\n");
  set_chance(20);
  set_spell_dam(65);
  set_spell_mess1("Toxic fumes burn your nose...\n");
  set_spell_mess2(GRN+"Toxic ooze burns your skin!\n"+NORM);
 	set_dead_ob(this_object());
  b = hit_point;
  e = 0;
}  }

void init(){
  ::init();
  add_action("north", "north");
}

north(){ 
  if(random(3)){
    write("You slip on the slippery floor as you try to leave.\n");
    tell_room(environment(), this_player()->query_name()+" slips as "+
      this_player()->query_pronoun()+" tries to leave.\n",
      ({ this_player() }));
    return 1;
  }
}

monster_died(){
  object cash;
  write_file("/players/zeus/log/bigmon",
  ctime(time())+" - "+AO->QN+" [L "+AO->query_level()+
  "+"+AO->query_extra_level()+"] killed Ooze.\n");
  cash = clone_object("/obj/money.c");
  cash -> set_money(8000+random(6000));
  tell_room(environment(), 
    "You notice some coins among the ooze as the slime\n"+
    "slowly seeps down into the cracks of the cavern.\n");
  move_object(cash, environment());
  move_object(clone_object("/players/zeus/realm/OBJ/oozeball.c"),
    environment());
}

heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if((c = (b - hit_point)) > 35+random(13))
  {
    if(c > 110)
    {
      hit_point += (c - 110);
      c = 110;
      tell_room(environment(), BOLD+BLK+
        "The ooze absorbs some of the damage.\n"+NORM);
    }
    if(!random(2))
    {
    tell_room(environment(), GRN+
      "A poisonous gas seeps from the ooze, filling the cavern.\n"+NORM+
      BOLD+BLK+"             You choke on the toxic fumes!\n"+NORM);
    }
    else
      tell_room(environment(), GRN+"The fumes burn your lungs!\n"+NORM);
    all = all_inventory(environment());
    sa = sizeof(all);
    for(a = 0; a < sa; a++)
    {
      if(all[a] && (all[a]->is_player() || all[a]->is_npc()) && 
        all[a] != this_object() && all[a]->query_attack() == this_object() &&
        present(all[a], environment())){
        if(all[a]->is_player())
          all[a]->hit_player((c), "other|poison");
        else
          all[a]->hit_player(c);
        d += c;
      }
    }
  }
  else if(d > 140+random(260))
  {
    d = 0;
    tell_room(environment(), 
      BOLD+BLK+"\nA large bubble slowly forms in the ooze...\n"+NORM+
      "                - POP -\n"+GRN+
      "   Toxic ooze splatters everywhere!\n\n"+NORM);
    all = all_inventory(environment());
    sa = sizeof(all);
    for(a = 0; a < sa; a++)
    {
      if(all[a] && (all[a]->is_player() || all[a]->is_npc()) && 
        all[a] != this_object() && all[a]->query_attack() == this_object() &&
        present(all[a], environment()))
        if(all[a]->is_player())
          all[a]->hit_player(100, "other|poison");
        else
          all[a]->hit_player(100);
    }
  }
  else if(c && c < 1+random(20))
  {
    e++;
    if(e > 5)
    {
      e = 0;
      if(attacker_ob && present(attacker_ob, environment()) &&
        attacker_ob->query_attack() == this_object())
      {
        tell_room(environment(),
          "The air of the cavern becomes "+
          "wavy as you gaze into the darkness.\n"+
          "Suddenly your nose and lungs begin "+
          "to burn with searing pain!\n");
        attacker_ob->hit_player(50, "other|poison");
      }
      if(alt_attacker_ob && present(alt_attacker_ob, environment()) &&
        alt_attacker_ob != attacker_ob &&
        alt_attacker_ob->query_attack() == this_object())
        if(alt_attacker_ob->is_player())
          alt_attacker_ob->hit_player(50, "other|poison");
        else
          alt_attacker_ob->hit_player(50);
    }
  }
  b = hit_point;
}

