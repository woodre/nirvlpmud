inherit "obj/monster";
object master,enemy;
int follow;
string myname,mastername;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("dog");
   set_alias("dog");
   set_race("undead");
   set_level(5);
   set_hp(75);
   set_al(300);
   set_wc(10);
   set_ac(5);
   set_aggressive(0);
   set_can_kill(1);
   call_out("dog_beat",1);
}
init()
{ ::init();
  add_action("set_newname","dogname");
  add_action("help","dog_help");
  add_action("atk","bite");
  add_action("stop","dstop");
  add_action("toggle_follow","dogfo");
  add_action("dogemote","dte");
  add_action("release","release");
  add_action("dogfix","dogfix");
}
descr()
{  if(myname) return myname;
   else return query_master_name()+"'s death dog";
}
set_newname(arg)
 { if(this_player()!=master) return ;
   if(!arg) { write("What do u want your dog's name to be?\n"); return 1; }
   myname=capitalize(arg);
   write("Your dog's name is now: '"+myname+"'.\n");
   set_name(arg);
   set_short(myname+", "+query_master_name()+"'s death dog");
   return 1;
 }
toggle_follow()
 { 
 if(this_player()!=master) return 0;
 if(follow) { tell_object(master,"Your death dog stops following you.\n");
                follow=0; }
   else       { tell_object(master,"Your death dog starts following you.\n");
                follow=1; }
   return 1;
 }
set_master(arg)
 { master=arg;
   mastername=master->query_real_name();
   set_short(query_master_name()+"'s death dog");
   set_alt_name("dog_"+mastername);
   return 1;
 }
long()
{
        if(this_player()==master)
         write("This is your death dog. A bulky undead dog faithful to you till its death.\n"+
               "Type 'dog_help' for the commands menu.\n"+
               "Your dog has got "+hit_point+" hps on "+max_hp+".\n");
        else
         write("This is "+query_master_name()+"'s death dog, a huge undead dog that looks "+
               "menaceously at you.\n");
	return 1;
}
query_master_name() { return capitalize(mastername); }
dog_beat() 
{
    int c;
    hit_point+=2;
    if(hit_point>=max_hp)
        hit_point=max_hp;
    if(!master)
      { object next;
        next=find_living(lower_case(query_master_name()));
        if(next) master=next;
        else
        {
         peace();
        }
      }
    if(follow) 
     { object morph;
       morph=find_living("morph_"+lower_case(master->query_name()));
      if(morph) {
       if(environment(this_object())!=environment(morph))
         { say(descr()+" leaves the room following "+
           capitalize(call_other(morph,"query_name"))+".\n");
           move_object(this_object(),environment(morph));
           say(descr()+" enters the room following "+
           capitalize(call_other(morph,"query_name"))+".\n"); 
         }
       }
      else {   
       if(environment(this_object())!=environment(master))
         { say(descr()+" leaves the room following "+
           query_master_name()+".\n");
           move_object(this_object(),environment(master));
           say(descr()+" enters the room following "+
           query_master_name()+".\n"); 
         }
        }
     }
    call_out("dog_beat",3);
}

atk(arg)
{ 
 if(this_player()!=master) return 0;
 if(!arg) { tell_object(master,"Your death dog peers at you, what do u want it to kill?\n"); return 1; }
 enemy=present(arg,environment());
 if(!enemy) { tell_object(master,"Your death dog can't find anything like that to kill.\n"); return 1; } 
 if(!call_other(enemy,"query_npc"))
   { tell_object(master,"Your death dog  can't kill "+arg+", it's not a monster!\n");
     return 1; }
 if(enemy==this_object())
   { tell_object(master,"Your death dog runs in circles chasing its own tail for a while then gives up.\n");
     say(descr()+" runs in circles chasing its own tail for a while then gives up.\n",master);
     return 1;
   }
 tell_object(environment(),descr()+" attacks "+call_other(enemy,"query_name")+".\n");
 this_object()->attack_object(enemy);
 return 1;
}
stop()
{ 
 if(this_player()!=master) return 0;
 if(!query_attack()) { tell_object(master,"Your death dog isn't attacking anyone.\n"); return 1; }
                call_other(enemy,"stop_hunting_mode");
                call_other(enemy,"stop_fight");
                enemy->attack_object();
                enemy->attacked_by();
                call_other(enemy,"stop_hunting_mode");
                call_other(enemy,"stop_fight");
                enemy->attack_object();
                enemy->attacked_by();
                call_other(this_object(),"stop_hunting_mode");
                call_other(this_object(),"stop_fight");
                this_object()->attack_object();
                this_object()->attacked_by();
                call_other(this_object(),"stop_hunting_mode");
                call_other(this_object(),"stop_fight");
                this_object()->attack_object();
                this_object()->attacked_by();
 tell_object(master,"Your death dog calms down and stops its fight with "+call_other(enemy,"query_name")+".\n");
 return 1;
}
help()
{ 
   if(this_player()==master)
     { cat("/players/trix/closed/guild/helpdog");
       return 1;
     }
   return ;
}
dogemote(arg)
{ 
   if(this_player()!=master) return ;
   if(!arg) { tell_object(master,"What do you want your pet zombie to emote?\n"); return 1; }
   say(descr()+" "+arg+"\n");
   return 1;
}
release(arg)
{
   if(this_player()!=master) return ;
   say(query_master_name()+" whistles loudly and his death dog comes back in the shadows where\n"+
            "it belongs.\n"); 
   destruct(this_object());
   return 1;
}

dogfix()
{  tell_object(master,"You whistle at your death dog that immediately worships at your feet.\n");
   say(query_master_name()+" whistles at their death dog that immediately worships at their feet.\n"); 
   remove_call_out("dog_beat");
   dog_beat();
   return 1;
}

query_guild_name() { return "undead"; }
is_pet() { return 1; }
