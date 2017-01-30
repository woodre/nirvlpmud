#include "/players/jaryn/closed/define.h"
#define ROOT "/players/jaryn/areas/maztica/"
#define EBOA GRN+"Emerald Tree Boa"+NORM
#define WSNAKE HIR+"Wi"+HIY+"ng"+HIB+"ed "+NORM+GRN+"Serpent"+NORM
inherit "obj/monster.c";
int snake_likes_jello;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_race("snake");
set_dead_ob(this_object());

switch(random(10)+1) {
  case 1..5:
    snaketype1();
    break;
  case 6..10:
    snaketype2();
    break;
  default:
    snaketype1();
    break;
  }
}

snaketype1() {
  snake_likes_jello=1;
  set_name("snake");
  set_alias("boa");
  set_short(GRN+"Emerald Tree Boa"+NORM);
  set_long(
    "  The emerald tree boa is a deep green snake with white bands along its body.\n"+
    "It lives in the trees of the jungle dropping on its prey to constrict around\n"+
    "it and squeeze it to death. It has long fangs on its upper and lower jaw that\n"+
    "it uses to attach itself then swallow its meal. This species can grow to be\n"+
    "eight to ten feet in length.\n"
  );
  set_level(17);
  set_hp(250+random(200));  /* 350 Average */
  set_al(100-random(201));
  set_wc(20+random(11));    /* 25 Average */
  set_wc_bonus(13);        /* check snake_is_dead1 under heartbeat for calculations */
  set_ac(10+random(7));    /* 13 Average */
  set_aggressive(1);
  set_chat_chance(5);
    load_chat("The "+EBOA+" tastes the air with its forked tongue.\n");
    load_chat("The "+EBOA+" eyes you for its next meal.\n");
  set_a_chat_chance(5);
    load_a_chat("The "+EBOA+" lunges with its fanged maw.\n");
    load_a_chat("Sensing death, the "+EBOA+" squeezes harder.\n");
  set_chance(25);
  set_spell_dam(20+random(11)); /* 25 Average */
  set_spell_mess1(
    "\nWith a quick strike, the "+EBOA+" sinks its fangs home.\n\n"
  );
  set_spell_mess2(
    "\nWith a quick strike, the "+EBOA+" sinks its fangs into you.\n\n"
  );
}

snaketype2() {
  snake_likes_jello=2;
  set_name("snake");
  set_alias("serpent");
  set_alt_name("winged serpent");
  set_short(HIR+"Wi"+HIY+"ng"+HIB+"ed "+NORM+GRN+"Serpent"+NORM);
  set_long(
    "  Winged serpents, sometimes called spark snakes, are colorful reptiles that\n"+
    "dwell in forests and jungles. They are supported by swift, gossamer wings, of\n"+
    "bright color plumage as to resemble reptilian hummingbirds. Due to the speed\n"+
    "with which its wings beat, the serpent is able to build up an electric charge.\n"+
    "This is the reason they are known as spark snakes.\n"
  );
  set_level(18);
  set_hp(300+random(201));  /* 400 Average */
  set_al(100-random(201));
  set_wc(25+random(6));    /* 27 Average */
  set_wc_bonus(17);        /* Check snake_is_angry2 under heartbeat for calculations */
  set_ac(10+random(7));    /* 13 Average */
  set_heal(3,1);
  set_aggressive(0);
  set_chat_chance(5);
    load_chat("The "+WSNAKE+" flits around your head.\n");
    load_chat("The "+WSNAKE+" emits a small "+HIC+"spark"+NORM+".\n");
  set_a_chat_chance(5);
    load_a_chat("With an impossible quickness, the "+WSNAKE+" dodges an attack.\n");
  set_chance(50);
  set_spell_dam(25+random(16)); /* 32.5 Average */
  set_spell_mess1(
    "\nDarting quickly toward its attacker, the "+WSNAKE+" spits acid at thier face!\n\n"
  );
  set_spell_mess2(
    "\nDarting quickly toward its you, the "+WSNAKE+" spits acid at your face!\n\n"
  );
}

heart_beat() {
  ::heart_beat();
  if(snake_likes_jello == 1) { /* 12.5/(100/100) = 12.5*1.00 = 13 wc_bonus */
    if((attacker_ob) && (attacker_ob->query_ghost())) return;
    if(!present(attacker_ob, environment())) return;
    tell_room(ENVTO, "\nThe "+EBOA+" hisses as it\n"+
                     "          tightens it coils about "+AQN+"         \n"+
                     ""+GRN+"         ((("+BLU+" SQUEEZING"+GRN+" )))"+NORM+"\n"+
                     "                         with immense pressure!\n",  ({ attacker_ob }));
    tell_object(attacker_ob, "\nThe "+EBOA+" hisses as it\n"+
                             "          tightens it coils about you           \n"+
                             ""+GRN+"         ((("+BLU+" SQUEEZING"+GRN+" )))"+NORM+"\n"+
                             "                         with immense pressure!\n");
    attacker_ob->hit_player(10+random(6));
  }
  if(snake_likes_jello == 2) {
    int ws;
    if(attacker_ob) {
      ws = random(11);
      switch(ws) {
        case 0..4: FANGS_WSNAKE(); break; /*  20/(100/40) = 8*1.00 = 8 wc_bonus */
        case 5..6: SPARK_WSNAKE(); break; /* 37.7/(100/20) = 7.54*1.25 = 9 wc_bonus */
        case 7..10: return 0; break;
      }
    }
  }
}

FANGS_WSNAKE() {
  if((attacker_ob) && (attacker_ob->query_ghost())) return;
  if(!present(attacker_ob, environment())) return;
  tell_room(ENVTO, "\nThe "+WSNAKE+" whisks toward "+AQN+"   \n"+
                   "        baring its "+HIW+"fangs"+NORM+", \n"+
                   "\n"+WSNAKE+" sinks them into "+AQN+"'s throat!\n", ({ attacker_ob }));
  tell_object(attacker_ob, "\nThe "+WSNAKE+" whisks toward you   \n"+
                           "        baring its "+HIW+"fangs"+NORM+", the \n"+
                           "\n"+WSNAKE+" sinks them into your throat!\n");
  attacker_ob->hit_player(15+random(11));
}

SPARK_WSNAKE() {
  if((attacker_ob) && (attacker_ob->query_ghost())) return;
  if(!present(attacker_ob, environment())) return;
  tell_room(ENVTO, "\nThe "+WSNAKE+" hovers overhead beating its wings furiously.\n"+
                   "      The "+WSNAKE+" begins to hum with "+HIY+"electricity"+NORM+"! \n"+
                   "\n\nWith a slight hiss, the "+WSNAKE+" emits a bolt of \n"+
                   "         "+HIY+"  \ \ \ LIGHTNING \ \ \ "+NORM+"      \n"+
                   "                                   at "+AQN+"!\n", ({ attacker_ob }));
  tell_object(attacker_ob, "\nThe "+WSNAKE+" hovers overhead beating its wingsfuriously.\n"+
                    "      The "+WSNAKE+" begins to hum with "+HIY+"electricity"+NORM+"!\n"+
                     "\n\nWith a slight hiss, the "+WSNAKE+" emits a bolt of \n"+
                     "         "+HIY+"  \ \ \ LIGHTNING \ \ \ "+NORM+"        \n"+
                     "                                   at you!\n");
  attacker_ob->hit_player(25+random(26), "other|electric");
}

monster_died() {
  if(snake_likes_jello == 1) {
    tell_room(ENVTO, "The "+EBOA+" loosens its coils and\n"+
                     "                      collapses in a round heap.\n");
    MOCO(ROOT+"OBJ/eboa_corpse.c"), ENVTO);
          return 1;
  }

    if(snake_likes_jello == 2) {
      tell_room(ENVTO, "The "+WSNAKE+"'s wings stop beating as it\n"+
                     "                      collapses with a light 'THUD'.\n");
    MOCO(ROOT+"OBJ/wsnake_corpse.c"), ENVTO);
    
      return 1;
  } 
}
