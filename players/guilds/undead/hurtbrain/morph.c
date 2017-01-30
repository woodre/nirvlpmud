inherit "obj/monster";

object here;
string com_str;

reset(arg){
   ::reset(arg);
   if(arg) return;
	set_race("undead");
	set_hp(100);
        set_long("This is a morph of an undead.\n") ;
	set_ac(10000);
	set_al(0);
	set_wc(0);
	set_level(1);
	enable_commands();
	here=this_object();
	call_out("fol",5);
        set_heart_beat(1);
}

query_npc()  {
	return 0;
	}

query_pl_k()  {
	return 0;
	}

attack_object(obj)  {
	return 1;
	}

attacked_by(obj)  {
	return 1;
	}

set_com(str)  { com_str=str; return 1; }

fol()  {
	object who;
        object sph;
        if(!present(here->query_info(),here))
                {
                who=find_living(here->query_info());
                if(!who)  {
                        move_object(first_inventory(here),environment(here));
                        destruct(here);
                        return 1;
                        }
                if(!query_interactive(who)) {
                        move_object(who,environment(here));
                        sph=first_inventory(here);
                        move_object(sph,environment(here));
                        destruct(here);
                        destruct(sph);
                        return 1;
                        }
		move_object(here,environment(who));
		move_object(who,here);
		}
	call_out("fol",5);
	return 1;
	}

set_say(str)  {
	if(str)  say(here->query_name()+str+"\n");
	return 1;
	}

catch_tell(str)  {
if(!find_living(here->query_info())) { destruct(here);  }
        if(str=="What?\n") {
	command("new_command",find_living(find_living(here->query_info())->query_info()));
        command(com_str,find_living(find_living(here->query_info())->query_info()));
        command("new_command2",find_living(find_living(here->query_info())->query_info()));
	}
	else   tell_object(find_living(find_living(here->query_info())->query_info()),str);
	return 1;
	}

heart_beat() {
  ::heart_beat();
  set_ac(10000);  /* so that it can not be used in combat */
  set_wc(0);
}