#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=0;
     spell_level=0;
     casting_time=1;
     duration=0;
     spell_cost=0;
     id_name="name";
     spell_name="name";
     spell_desc="";
     properties=({ });
     spell_type="";
}

int cast_spell(object *targ, string arg1, string arg2) {
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
