query_auto_load() { return TOP_DIR + "object.c:"; }
query_clan_short() { return clan_short; }
query_clan_long() { return clan_long; }
query_object_name() { return object_name; }
query_owner()  { return owner; }
query_leaders() { return leaders; }
query_hall_path() { return hall_path; }
int query_leader(string str) { if(member(leaders,str) != -1 || str == owner) return 1; return 0; }
query_abilities() { return abilities; }
int query_ability(string str)  { if(member(abilities,str) != -1) return 1; return 0; }
query_join_type() { return join_type; }
query_chan_history() { return chan_history; }
query_public_coffer() { return public_coffer; }
query_private_coffer() { return private_coffer; }
query_spell_alias() { return spell_alias; }
query_spell_mess_me() { return spell_mess_me; }
query_spell_mess_room() { return spell_mess_room; }
query_spell_mess_them() { return spell_mess_them; }
query_spell_id() { return spell_id; }
query_spell_cost() { return spell_cost; }
query_spell_delay() { return spell_delay; }
query_last_spell_time() { return last_spell_time; }
query_damage_type() { return damage_type; }
int spell_is_delayed()
{
  if(last_spell_time + spell_delay < time())
    return 0;
  return 1;
}
query_weight() { return 0; }
