#include <ansi.h>
/* next added by Vertebraker [5.31.01] */
#define MO move_object

inherit "/obj/monster";
#define WC 35
int phase, p;
object lgolem, nmy, *arena;
string w;

reset(arg) {
  ::reset(arg);
  if (!arg) {

  arena =({
    "players/zeus/museum/arena/ar1",  "players/zeus/museum/arena/ar2",
    "players/zeus/museum/arena/ar3",  "players/zeus/museum/arena/ar4",
    "players/zeus/museum/arena/ar5",  "players/zeus/museum/arena/ar6",
    "players/zeus/museum/arena/ar7",  "players/zeus/museum/arena/ar8",
    "players/zeus/museum/arena/ar9", });

  phase = 0;
  set_name("granite golem");
  set_short(BOLD+BLK+"A Granite Golem"+NORM);
  set_race("golem");
  set_gender("creature");
  set_long(
"This is a gigantic granite golem.  Created by magic, its sole purpose\n"+
"is to serve the bidding of its master.  Its two glowing red eyes seem\n"+
"fueled by the fires of Hell.  It is an emotionless tool of destruction.\n");
  set_ac(36);
  set_wc_bonus(145); /* best judgement here */
  set_wc(WC);
  set_hp(1350);
  set_hp_bonus(80);
  set_heal(1,7);
  set_level(28);
  set_al(-600);
  set_aggressive(0);
  set_chat_chance(4);
  set_a_chat_chance(0);
  load_chat("The golem stands silently.\n");
  load_chat("The golem watches you.\n");
  load_chat("The golem looks at you.\n");
  load_chat("The golems eyes flash with fire.\n");
  load_chat("The golems eyes burn with a passion.\n");
  load_chat("The golem stands waiting.\n");
  set_chance(20);
  set_spell_dam(60);
  set_spell_mess1("The Granite Golem pounds its fists into the ground!\n");
  set_spell_mess2("The Granite Golem pounds its fists into you!\n");
  set_dead_ob(this_object());
  call_out("hunt", 20+random(10));
  }
}

id(s){ return s == "granite" || s == "golem" || s == "granite golem" ||
s == "magic golem" || s == "zeus magic granite golem"; }

query_nmy(){ return nmy; }

object summon_mini(){
  object little;
  tell_room(environment(),
    "\nA chunk of granite becomes detached and falls to the ground...\n"+
    "The chunk molds into a mini granite golem!\n\n");
	little = clone_object("/players/zeus/museum/NPC/tiny_golem.c");
	move_object(little, environment());
	return little;
}

hunt(){
  if(!environment()) return;
  if(!sscanf(file_name(environment()), 
    "players/zeus/museum/arena/%s", w)) return;
  call_out("hunt", 30);
  if(!nmy) return;
  if(!sscanf(file_name(environment(nmy)),
    "players/zeus/museum/arena/%s", w)) return;
  if(!nmy->query_ghost() && nmy->query_interactive())
  {
    if(present(nmy, environment()))
    {
      tell_room(environment(),
        "The Granite Golem pounds its fists into the ground.\n");
      this_object()->attack_object(nmy);
    }
    else {
      if(random(5))
      {
        lgolem = summon_mini();
        MO(lgolem, environment(nmy));
        tell_room(environment(nmy), 
          "\nA mini golem attacks with bloodlust!\n\n");
        lgolem->attack_object(nmy);
      }
      else {
        move_object(this_object(), environment(nmy));
        tell_room(environment(), "The Granite Golem arrives.\n"+
          "The Granite Golem sees you and attacks.\n");
        this_object()->attack_object(nmy);
      }
    } 
  }
}

int check(){
  if(!environment()) return 0;
  if(!sscanf(file_name(environment()), 
    "players/zeus/museum/arena/%s", w)) return 2;
  if(!nmy) return 0;
  if(!present(nmy, environment())) return 0;
  if(nmy->is_npc()) return 1;
  if(!nmy->query_interactive()) return 0;
  if(nmy->query_ghost()) return 0;
  return 1;
}

tremble(r,s){
  int a;
  if(check())
  {
    if(s)
      tell_room(environment(this_object()), BOLD+BLK+
        "\n\nThe Granite Golem begins to tremble!\n\n\n"+NORM);
    for(a = 0; a < r; a++)
    {
      lgolem = summon_mini();
      lgolem->attack_object(nmy);
    }
  }
}

one(){
  if(check())
  {
    tremble(5,0);
    if(nmy->is_player())
    {
      while(present(nmy, environment()))
        move_object(this_object(), arena[random(sizeof(arena))]);
    }
    phase = 1;
  }
}

two(){
  if(check())
  {
    if(random(2))
    {
      tell_room(environment(this_object()),
        "\nThe Granite Golem throws a giant boulder straight at you!\n"+
        "You are sent flying backwards by the massive blow!\n\n");
    }
    else {
      tell_room(environment(this_object()),
      "\nThe Granite Golem crushes you with fists of stone!\n"+
      RED+"Blood gushes from your body as you collapse to the ground!\n\n"+
      NORM);
    }
    nmy->hit_player(p);
    if(p < 62)
      phase = 2;
  }
}

three(){
  if(check())
  {
    weapon_class = (WC + 25);
    tell_room(environment(this_object()),
      "\nThe Granite Golem stomps violently on the ground!\n\n");
    if(phase == 2)
    {
      tremble(4,0);
      phase = 3;
    }
    else if(phase == 3)
    {
      lgolem = summon_mini();
      lgolem->attack_object(nmy);
      if(p < 32)
      {
        phase = 4;
        weapon_class = WC;
      }
    }
  }
}

four(){
  if(check())
  {
    if(random(2))
      tremble(2+random(2),1);
    if(p < 5)
      phase = 5;
  }
}

five(){
  if(check() && nmy->is_player())
  {
    tell_room(environment(this_object()), 
      "The Granite Golem falls to pieces and reforms elsewhere.\n");
    hit_point += 40;
    while(present(nmy, environment()))
     move_object(this_object(), arena[random(sizeof(arena))]);
  }
}

monster_died(){
  /*
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
  capitalize((string)TP->QRN)+" defeated Granite Golem.\n");
   "/players/zeus/museum/lounge.c"->npc1();
  tell_room(environment(),
    "The golem explodes into fragments of rock!\n"+
    "An object rests among the rubble.\n");
  move_object(clone_object("/players/zeus/museum/OBJ/gstaff.c"),
    environment(this_object()));
  */
}

void heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  nmy = attacker_ob;
  if(check() == 2)
  {
    tell_room(environment(this_object()), 
      "The Granite Golem crumbles to pieces.\n");
    destruct(this_object());
    return;
  }
  p = (hit_point * 100) / max_hp;
  if(!random(6))
  {
    lgolem = summon_mini();
    lgolem->attack_object(nmy);
  }
  if(p < 95 && phase == 0)
    one();
  else if(p < 86 && phase == 1 && random(3))
    two();
  else if(p < 50 && phase == 2)
    three();
  else if(p < 14 && phase == 4)
    four();
  else if(p <= 3 && phase == 5)
    five();
}

