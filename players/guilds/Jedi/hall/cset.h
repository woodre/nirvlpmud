set_hall_path(string sh)
{
   hall_path = sh;
   save_me();
   update_everyone();
}

set_clan_owner(string sh)
{
   owner = sh;
   save_me();
   update_everyone();
}

set_abilities(string *sh)
{
   abilities = sh;
   save_me();
   update_everyone();
}

add_ability(string sh)
{
   if(!abilities) abilities = ({ });
   if(member(abilities,sh) == -1)
      {
      abilities += ({ sh });
      save_me();
      update_everyone();
   }
}

remove_ability(string sh)
{
   if(!abilities) abilities = ({ });
   abilities -= ({ sh });
   save_me();
   update_everyone();
}

set_clan_leaders(string *sh)
{
   owner = sh;
   save_me();
   update_everyone();
}

add_clan_leader(string sh)
{
   if(!leaders) leaders = ({ });
   if(member(leaders,sh) == -1)
      {
      leaders += ({ sh });
      save_me();
      update_everyone();
   }
}

remove_clan_leader(string sh)
{
   if(!leaders) leaders = ({ });
   leaders -= ({ sh });
   save_me();
   update_everyone();
}

set_clan_short(string sh)
{
   sh = (string)call_other(TOP_DIR + "funcs","modify_spell_message",sh, this_player());
   clan_short = sh;
   set_short(clan_short);
   save_me();
   update_everyone();
}

set_clan_long(string sh)
{
   clan_long = (string)call_other(TOP_DIR + "funcs","modify_spell_message",sh, this_player()) + "\nType 'clan_help' for commands.\n";
   set_long(clan_long);
   save_me();
   update_everyone();
}

set_object_name(string sh)
{
   object_name = sh;
   set_alias(sh);
   save_me();
   update_everyone();
}

set_join_type(int sh)
{
   join_type = sh;
   save_me();
   update_everyone();
}

set_chan_history(string *sh) { chan_history = sh; }

add_chan_history(sh)
{
   restore_me();
   if(!chan_history) chan_history = ({ });
   chan_history += ({ "[" + ctime() + "] " + sh });
   while(sizeof(chan_history) > 20) chan_history -= ({ chan_history[0] });
   save_me();
   update_everyone();
}

set_private_coffer(pc) { private_coffer = pc; save_me(); update_everyone();}
set_public_coffer(pc) { public_coffer = pc; save_me(); update_everyone(); }
add_private_coffer(pc) { private_coffer += pc; save_me(); update_everyone(); }
add_public_coffer(pc) { public_coffer += pc; save_me(); update_everyone(); }
set_spell_alias(sa) { spell_alias = sa; save_me(); update_everyone(); }
set_spell_delay(sd) { spell_delay = sd; save_me(); update_everyone(); }
set_spell_mess_me(sm) { spell_mess_me = sm; save_me(); update_everyone(); }
set_spell_mess_room(sm) { spell_mess_room = sm; save_me(); update_everyone(); }
set_spell_mess_them(sm) { spell_mess_them = sm; save_me(); update_everyone(); }
set_spell_id(si) { spell_id = si; save_me(); update_everyone(); }
set_spell_cost(sc) { spell_cost = sc; save_me(); update_everyone(); }
set_last_spell_time(ls) { last_spell_time = ls; save_me(); update_everyone(); }
set_damage_type(dt) { damage_type = dt; save_me(); update_everyone(); }
