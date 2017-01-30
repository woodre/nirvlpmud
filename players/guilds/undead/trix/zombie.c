inherit "obj/monster";
object master,enemy;
int follow,carry,cause,prevwc;
string myname,mastername;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("zombie");
   set_race("undead");
   set_level(5);
   set_hp(75);
   set_al(300);
   set_wc(9);
   set_ac(5);
   set_aggressive(0);
set_can_kill(1);
   cause=0;
   prevwc=0;
   call_out("zom_beat",1);
}
init()
{ ::init();
  add_action("help","help");
  add_action("pickup","pickup");
  add_action("ddrop","ddrop");
  add_action("gimme","gimme");
  add_action("atk","atk");
  add_action("stop","stk");
  add_action("toggle_follow","zomfo");
  add_action("zemote","zemote");
  add_action("midpeace","peace");
  add_action("zomfix","zomfix");
  add_action("use","use");
}
set_myname(arg)
 { myname=arg;
   set_short("The zombie of "+myname);
   return 1;
 }
toggle_follow()
 { 
 if(this_player()!=master) return 0;
 if(follow) { tell_object(master,"Your pet zombie stops following you.\n");
                follow=0; }
   else       { tell_object(master,"Your pet zombie starts following you.\n");
                follow=1; }
   return 1;
 }
set_master(arg)
 { master=arg;
   mastername=master->query_real_name();
   set_alias("zombie_"+mastername);
   return 1;
 }
long()
{
	write("This is the zombie of "+myname+". Brought back to life by "+
              capitalize(call_other(master,"query_name"))+".\n"+
              "Type 'help zombie' for the commands menu.\n"+
	      "Your pet zombie has got "+hit_point+" hps on "+max_hp+".\n");
	return 1;
}
query_master_name() { return capitalize(mastername); }
zom_beat() 
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
        {cause=1;
         peace();
        }
      }
    if(follow) 
     { object morph;
       morph=find_living("morph_"+lower_case(master->query_name()));
      if(morph) {
       if(environment(this_object())!=environment(morph))
         { say(short()+" leaves the room following "+
           capitalize(call_other(morph,"query_name"))+".\n");
           move_object(this_object(),environment(morph));
           say(short()+" enters the room following "+
           capitalize(call_other(morph,"query_name"))+".\n"); 
         }
       }
      else {   
       if(environment(this_object())!=environment(master))
         { say(short()+" leaves the room following "+
           query_master_name()+".\n");
           move_object(this_object(),environment(master));
           say(short()+" enters the room following "+
           query_master_name()+".\n"); 
         }
        }
     }
    call_out("zom_beat",3);
}

add_carry(arg) { carry=carry+arg; }
query_carry() { return carry; }
maxcarry() { return 20; }


pickup(arg)
{object stuff; 
 if(this_player()!=master) return 0;
 if(!arg) { tell_object(master,"Your pet zombie looks around for something to pick up.\n"); return 1; }
 stuff=present(arg,environment());
 if(!stuff)
 { tell_object(master,"Your pet zombie looks for "+arg+" to pick up but can't find it.\n"); return 1;}
 if(arg=="ghost") { tell_object(master,"Forget it!\n"); return 1;}
     if (arg == "all") {
        get_all(environment());
        return 1;
    }
 if(stuff->query_npc())
	{ write("Your pet zombie can't take that!\n");
	  return 1;
	}
 if(call_other(stuff,"query_weight")+query_carry()>maxcarry()) { 
 tell_object(master,"Your pet zombie can't carry that much.\n"); return 1; } 
 move_object(stuff,this_object());
 tell_room(environment(),"Zombie of "+myname+" picks up "+arg+".\n");
 add_carry(call_other(stuff,"query_weight"));
 return 1;
}

ddrop(arg)
{object stuff; 
 if(this_player()!=master) return 0;
 if(!arg) { tell_object(master,"Your pet zombie peers at you quizzically, drop what?!?\n"); return 1; }
 stuff=present(arg,this_object());
 if(!stuff)
 { tell_object(master,"Your pet zombie can't find "+arg+" to drop.\n"); return 1;}
 if(stuff->weapon_class()) stuff->drop(1);
 move_object(stuff,environment()); 
 weapon_class=prevwc;
 tell_room(environment(),"Zombie of "+myname+" drops "+arg+".\n");
 add_carry(-call_other(stuff,"query_weight")); 
 return 1;
}

gimme(arg)
{ object stuff;
  int weight;
 if(this_player()!=master) return 0;
 if(!arg) { tell_object(master,"What do you want your pet zombie to give you?\n"); return 1; }
 stuff=present(arg,this_object());
 if(!stuff)
 { tell_object(master,"Your pet zombie has no "+arg+" to give you.\n"); return 1;}
  weight=stuff->query_weight();
  if(master->add_weight(weight))
  { tell_object(master,"Your pet zombie gives "+arg+" to you.\n");
    if(stuff->weapon_class()) stuff->drop(1);
    move_object(stuff,master);
    weapon_class=prevwc;
    add_weight(-weight);
  } 
 else tell_object(master,"You can't carry that much.\n");
 return 1;
}
atk(arg)
{ 
 if(this_player()!=master) return 0;
 if(!arg) { tell_object(master,"Your pet zombie peers at you, what do u want him to kill?\n"); return 1; }
 enemy=present(arg,environment());
 if(!enemy) { tell_object(master,"Your pet zombie can't find anything like that to kill.\n"); return 1; } 
 if(!call_other(enemy,"query_npc"))
   { tell_object(master,"Your pet zombie can't kill "+arg+", it's not a monster!\n");
     return 1; }
 if(enemy==this_object())
   { tell_object(master,"Your pet zombie goes 'tsk, tsk, tsk' at you, can't attack itself.\n");
     return 1;
   }
 tell_object(environment(),short()+" attacks "+call_other(enemy,"query_name")+".\n");
 this_object()->attack_object(enemy);
 return 1;
}

stop()
{ 
 if(this_player()!=master) return 0;
 if(!query_attack()) { tell_object(master,"Your pet zombie isn't attacking anyone.\n"); return 1; }
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
 tell_object(master,"Your pet zombie calms down and stops its fight with "+call_other(enemy,"query_name")+".\n");
 return 1;
}
help(arg)
{ 
   if(this_player()==master&&arg=="zombie")
     { cat("/players/trix/closed/guild/helpzombie");
       return 1;
     }
   return ;
}
zemote(arg)
{ 
   if(this_player()!=master) return ;
   if(!arg) { tell_object(master,"What do you want your pet zombie to emote?\n"); return 1; }
   say(short()+" "+arg+"\n");
   return 1;
}
use(arg)
{   if(this_player()!=master) return ;   
       if(!arg) { tell_object(master,"What do you want your pet zombie to wield?\n");
       return 1; }
       if(!prevwc) prevwc=weapon_class;
       command("wield "+arg,this_object());
       return 1;
}

midpeace()
{
   if(this_player()!=master) return ;
   else peace();
   return 1;
}
peace(arg)
{
   if(cause) say(short()+"'s master left and it immediately crumbles to dust while a cold wind spreads "+
                  "what remains in the air.\n");
   else say(query_master_name()+" releases his pet zombie that immediately crumbles to dust while a cold wind "+
            "spreads what remains in the air.\n"); 
   destruct(this_object());
   return 1;
}

zomfix()
{  tell_object(master,"You stare at your pet zombie and looking in its glazed eyes you know that it'll\n"+
		       "obey and follow you undoubtedly from now on.\n");
   say(query_master_name()+" looks deep into their pet zombie's eyes that returns a look full of\n"+
			   "obedience.\n",master); 
   remove_call_out("zom_beat");
   zom_beat();
   return 1;
}

query_guild_name() { return "undead"; }
is_pet() { return 1; }
