#include <ansi.h>

inherit "/obj/monster";

object tumtum;

void reset(int x){
  ::reset(x);
  if(x) return;
  set_name("seagull");
  set_short("A seagull (flying)");
  set_long("\
 The seagull is puffy and annoying.\n\
 tweet tweet.\n");
  set_race("bird");
  set_gender(random(2) ? "male" : "female"); /* could be m or f */
  set_hp(150);
  set_wc(14);
  set_ac(8);
  set_level(10);
  set_chance(33); /* 33% chance per round */
  set_spell_mess2("\
Diving low, the seagull delivers its payload onto your head.\n\
\t\t\t*"+HIW+"splat"+NORM+"*\n");
  set_spell_mess1("\
Diving low, the seagull delivers its payload onto its target.\n\
\t\t\t*"+HIW+"splat"+NORM+"*\n");
  set_spell_dam(10); /* random(10) dam when it goes off */
  /* sample chats when not in combat */
  set_chat_chance(5);
  load_chat("The seagull tweets.\n");
  load_chat("The seagull chirps.\n");
  /* sample chats when in combat */
  set_a_chat_chance(5);
  load_chat("The seagull tweets angrily!\n");
  load_chat("The seagull pecks menacingly!\n");
  /* replaces boring hit, hit very hard, etc. */
  set_message_hit(({
    HIR+"RAVAGES"+NORM, " with a hefty PECK",   /* massacre */
    RED+"beak-smashes"+NORM+" through", ", causing "+ /* smash */
      RED+"blood"+NORM+" to fly",
    HIK+"slams"+NORM+" its jagged beak into", "", /* hit vh */
    "cuts deeply into", " with a swift peck", "", /* hit h */
    "whacks", " with its beak", /* hit */
    "kicks", " with a tiny claw", /* tickled */
    "flutters on", "'s head", /* grazed */
   }));
   /* clone our tum tum */
   tumtum = clone_object("/open/verte/sd/seagull_stomach");
   move_object(tumtum, this_object());
   /* marks the mob to execute monster_died()
      [see below] when it dies */
   set_dead_ob(this_object());
 }
 
void heart_beat(){
  object e;
  ::heart_beat();
  /* if this is a root copy, turn off hb and return .. prevents errors */
  if(!(e=environment())) {
    set_heart_beat(0);
    return;
  }
  /* 10% chance if not in combat */
  if(!attacker_ob && random(10)){
    object *objs, *plays;
    int    s;
    /* filter through the environment and if we find a player,
       add them to an array */
    plays=({});
    objs = all_inventory(e);
    s = sizeof(objs);
    while(s--) {
      if(objs[s]->is_player()){
        plays += ({ objs[s] });
      }
    }
    /* if no players, return */
    if(!(s=sizeof(plays))) {
      return;
    }
    else { /* if we have players */
      object guy, *stuff, *heals, heal;
      string room_msg, play_msg, player_name, heal_name;
      guy = plays[random(s)]; /* pick a player at random */
      /* go thru his whole inv, counting bags */
      stuff = deep_inventory(guy);
      s = sizeof(stuff);
      heals = ({});
      while(s--){
        /* if it is a heal, add it to an array */
        if(stuff[s]->is_heal()){
          heals += ({stuff[s]});
        }
      }
      /* if no heals in array, return */
      if(!(s = sizeof(heals))) {
        return;
      }
      /* otherwise pick a heal at random */
      heal = heals[random(s)];
      /* next two lines are just for easier msgs */
      heal_name = (string)heal->short();
      player_name = (string)guy->query_name();
      
      move_object(heal,tumtum);
      room_msg = "\nA seagull flies up to "+player_name
                +" and nabs "+possessive(guy)+" "
                +heal_name+"!\n\n";
      play_msg = "\nA seagull flies up to you and nabs"
                +" your "+heal_name+"!\n\n";
      tell_room(e, format_colour(room_msg,65), ({ guy }));
      tell_object(guy, format_colour(play_msg,65));
    }
  }
}

/* called upon death */
status monster_died(){
  object *heals;
  int    s, luck;
  /* check everything in our stomach */
  heals = all_inventory(tumtum);
  s = sizeof(heals);
  
  /* meanwhile drop our last bomb */
  tell_room(environment(), "\
 The seagull releases one last poo before\
 it falls to the earth, dead.\n");
  
  if(!attacker_ob) { /* there should always be one */
    luck = random(40);
  }
  else {
    luck = (int)attacker_ob->query_attrib("luc");
  }

  /* if we are unlucky, the heals may be destructed
    .. seagull has eaten them */ 
  while(s--){
    if(luck < random(40)){
      destruct(heals[s]);
    }
  }
  
  /* recalc heals to find how many are left */
  heals = all_inventory(tumtum);
  /* if we still have heals, move them to env */
  if(s = sizeof(heals)) {
    tell_room(environment(),"\
The seagull's innards spill out.\n");
    while(s--){
      move_object(heals[s], environment());
    }
  }
  
  destruct(tumtum);
  return 0;
}
