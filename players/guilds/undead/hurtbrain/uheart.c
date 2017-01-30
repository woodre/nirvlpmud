inherit "room/room"; 
#include "/players/boltar/things/esc.h"
#define COMMU_SPELL 5
#define VISION_SPELL 30
#define MELT_SPELL 15
#define SEND_SPELL 50
#define SECOND_LEVEL 5000
#define THIRD_LEVEL 15000
#define FOURTH_LEVEL 35000
#define FIFTH_LEVEL 75000
#define SIXTH_LEVEL 155000
#define SPEED_SPELL 30
#define TITLE_SPELL 10
#define DOG_SPELL 50
#define SEVENTH_LEVEL 315000
#define EIGHTH_LEVEL 635000
#define GUILD_COM 700000
#define GUILD_COM2 1000000
#define FOG_SPELL 30
#define LIGHTNING_SPELL 80
#define POSSESS_SPELL 100
#define CHARM_SPELL 35
#define GLARE_SPELL 50
#define SHADOWS_SPELL 50
#define BURN_SPELL 8
#define GLOW_SPELL 10
#define QGM_SPELL 10
#define QUARTZ_SPELL 10
#define ANIMATE_SPELL 60
#define EVOKE_SPELL 20
/* this should cost enough to limit the number of times it may cast  */
/* this command is too powerfull for only a 100 sp cost it has been raised*/
#define KNOW_SPELL 20
#define FEIGN_SPELL 60
#define SCAN_SPELL 10
#define RAISE_SPELL 100
#define LOW_ARMOR_SPELL 500
#define LOW_WEAPON_SPELL 600
#define HIGH_ARMOR_SPELL 800
#define HIGH_WEAPON_SPELL 1200
#define TOMB_SPELL 50

reset(arg) {
    if(arg) return;
    set_light(1);
    long_desc = "You entered the Undead Sancta Sanctorum, the Holiest place to the\n"+
		"Unnameable's adepts in this world. A persistent feeling, like an itch behind\n"+
		"your nape, suggests you that this is the place where all the lines of Undead\n"+
		"Power join in together. And right here the Power is strong as nowhere else. \n"+
		"You feel like worshipping the Unnameable, Father of the Undead.\n";
   short_desc = "Heart of the Darkness";
    dest_dir = ({ "/players/trix/closed/guild/guild_room.c", "up"});
    items = ({ "table", "A huge marble table where important decisions are made",
	       "sign", "The sign reads: Type 'adepts' to see the list of our breed" });
}
init()
{ 
   object obj;
   ::init();
   obj = first_inventory(this_player());
   if(!obj || !obj->is_player()) obj = this_player();
   if(!obj->is_player() || obj->query_level() > 20 || present("soul-undead",obj))
     {
	add_action("worship","worship");
	return 1;
     }
   else
    {
	write("You are not allowed in here ASSHOLE!\n");
	this_player()->move_player("with Gorgan's foot up his ass#room/church");
	this_player()->set_title("the dork");
	return 1; 
    }
}

communicate(str) {
/* 
 return;
 this is not legal -Bp  @it has to be this way or morphing would keep from talking*/
   if (!str) {
      write("Say what?\n");
      return 1;
   }
   str = format(str,60);
   if (me()->query_ghost()) {
      say(me()->short() + " says: " + str + ".\n");
      if (me()->query_brief())
         write("Ok.\n");
      else
         write("You say: " + str + "\n");
      return 1;
   }
   say(me()->query_name() + " says: " + str + "\n");
   if (me()->query_brief())
      write("Ok.\n");
   else
      write("You say: " + str + "\n");
   return 1;
}


worship(arg)
{  if(arg!="Father") write("Worship who?\n");
   else 
     { say(me()->query_name()+" worships the Unnameable, Father of every Undead. The Father is pleased.\n",me());
       write("You worship the Unnameable, and you can feel He is pleased.\n");
     }
   return 1;
}


object name,this;
object ewho;
object mate;
me() { this=this_player(); return this_player(); }
RN() { return capitalize(me()->query_real_name()); }
rn() { return me()->query_real_name(); }
rn2()  { return this_player()->query_real_name(); }
id(str) { return str=="heart"; }

pet_zone() {
  string temp;
  temp = environment(this_player())->short();
  if(temp != "Village green [n,w,e]") {
    write("You fail from this location.\n");
    return 0;
  }
  else return 1;
}

/*
uquit()
{   guild_channel_mess(RN()+" falls asleep and leaves this world.\n",me());
   me()->quit();
   return 1;
}

*/

guild_channel_mess(str,this){
   object *us,life;
   int x;
   if(this->query_invis()||this->query_level()>20)  return 0;
   us=users();
   for(x=0;x<sizeof(us);x++){
      life=present("soul-undead",us[x]);
      if(life&&!life->query_muffle()){
         tell_object(us[x],"[*UNDEAD*]: "+str+"\n");
       }
   }
   return 1;
}

set_touch(str,guildlev)  {
   int num;
   if(!str)  {
      write("Usage: set_touch <number>\n");
      return 0;
   }
   if(!sscanf(str,"%d",num))
      {
      write("You have to write a number.\n");
      return 0;
   }
   if(num < 0 || num > guildlev*5)
      {
      write("Number not in available range.\n");
      return 0;
   }
   write("Power of Touch set to "+num+".\n");
   return num;
}

utm(muffled)  {
   if(!muffled)  {
      write("Guild messages muffled.\n");
      return 1;
   }
   else  {
      write("Ear muffle off.\n");
      return 0;
   }
}

gcw() {
   object us,life;
   int x;
   int lev;
   int invis;
   write("*-----------------------------------------------------------------------------*\n");
   write("|*Undead*===*G.Level*==*Location*=============================================|\n");
   write("*-----------------------------------------------------------------------------*\n");
   us=users();
   for(x=0;x<sizeof(us);x++) {
      invis=us[x]->query_invis();
      life=present("soul-undead",us[x]);
      if(life &&life->guild_level()>=10&& invis<this_player()->query_level()){
         if(invis) { write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"); }
         write(capitalize(us[x]->query_real_name()));
         if(strlen(us[x]->query_real_name())>7)
            write("\t"); else write("\t\t");
         write(esc+"[0m");
         lev=call_other(present("soul-undead",us[x]),"guild_level");
         write(lev+" ");
         if(call_other(present("soul-undead",us[x]),"query_gmuffle"))
            write("m");
         write("\t");
         write(environment(us[x])->short());
         write("\n");
       }
   }
   return 1;
}
gcm(gmuffled)  {
   if(!gmuffled)  {
      write("Guild Leaders messages muffled.\n");
      return 1;
   }
   else  {
      write("Guild Leaders ear muffle off.\n");
      return 0;
   }
}

com1() {
   cat("/players/hurtbrain/closed/guild/helpdir/pent1.com");
   return 1;
}
com2() {
   write("Spell                                                 Cost(sp) Level\n\n");
   cat("/players/hurtbrain/closed/guild/helpdir/pent2.com");
   return 1;
}
com3() {
   write("Spell                                                 Cost(sp) Level\n\n");
   cat("/players/hurtbrain/closed/guild/helpdir/pent3.com");
   return 1;
}
com4() {
   write("Spell                                                 Cost(sp) Level\n\n");
   cat("/players/hurtbrain/closed/guild/helpdir/pent4.com");
   return 1;
}

com5() {
   write("Spell                                                 Cost(sp) Level\n\n");
   cat("/players/hurtbrain/closed/guild/helpdir/pent5.com");
   return 1;
}

comh()  {
   cat("/players/hurtbrain/closed/guild/helpdir/pent6.com");
   return 1;
}

ut(str,muffled) {
   object us;
   int x;
   if(!str) return;
   if(muffled)  {
      write("The channel is muffled.\n");
      return 1;
   }
   us=users();
   for(x=0;x<sizeof(us); x++) {
      if(present("soul-undead",us[x]) && !call_other(present("soul-undead",us[x]),"query_muffle"))
         tell_object(us[x],format("[*"+RN()+"*] "+str+"\n",75));
   }
   return 1;
}
ue(str,muffled) {
   object us;
   int x;
   if(!str) return;
   if(muffled)  {
      write("The channel is muffled.\n");
      return 1;
   }
   us=users();
   for(x=0;x<sizeof(us);x++) {
      if(present("soul-undead",us[x]) && !call_other(present("soul-undead",us[x]),"query_muffle"))
         tell_object(us[x],format("[*] "+RN()+" "+str+"\n",75));
   }
   return 1;
}
gct(str,gmuffled) {
   object us,soul;
   int x;
   if(!str) return;
   if(gmuffled)  {
      write("The channel is muffled.\n");
      return 1;
   }
   us=users();
   for(x=0;x<sizeof(us); x++) {
      soul=present("soul-undead",us[x]);
      if(soul&&call_other(soul,"guild_level")>=10 && !call_other(soul,"query_gmuffle"))
         tell_object(us[x],format("[*!"+RN()+"!*] "+str+"\n",75));
   }
   return 1;
}
gce(str,gmuffled) {
   object us,soul;
   int x;
   if(!str) return;
   if(gmuffled)  {
      write("The channel is muffled.\n");
      return 1;
   }
   us=users();
   for(x=0;x<sizeof(us);x++) {
      soul=present("soul-undead",us[x]);
      if(soul&&call_other(soul,"guild_level")>=10 && !call_other(soul,"query_gmuffle"))
         tell_object(us[x],format("[*!*] "+RN()+" "+str+"\n",75));
   }
   return 1;
}
du() {
   object us,life,aura;
   int x;
   int lev;
   int invis;
   write("*-----------------------------------------------------------------------------*\n");
   write("|*Undead*---*G.Level*--*Location*---------------------------------------------|\n");
   write("*-----------------------------------------------------------------------------*\n");
   us=users();
   for(x=0;x<sizeof(us);x++) {
      invis=us[x]->query_invis();
      life=present("soul-undead",us[x]);
      aura=present("aura-undead",us[x]);
      if((life||aura) && invis<this_player()->query_level()){
         if(invis) { write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"); }
         write(capitalize(us[x]->query_real_name()));
         if(strlen(us[x]->query_real_name())>7)
            write("\t"); else write("\t\t");
         write(esc+"[0m");
         if(life) {
            lev=life->guild_level();
            write(lev+" ");
            if(call_other(present("soul-undead",us[x]),"query_muffle"))
            write("m");
          }
         else write("\b[App]");
         write("\t");
         write(environment(us[x])->short());
         write("\n");
       }
   }
   return 1;
}

turn(str,randname) {
   object new;
   if(!str) return;
   sscanf(str,"%s undead",str);
   new = find_player(str);
   if(!new) {
      write("Life: I could not find '"+str+"'\n");
      return 1;
   }
   if(!present(new,environment(me())))  {
      write("Life: "+new->query_name()+" is not here.\n");
      return 1;
   }
     if (new -> query_level () < 3) {
      write("Life: "+new->query_name()+" is not ready to join yet.\n");
      return 1;
   }
   move_object(clone_object("/players/"+randname+"/life.c"),find_living(str));
   tell_object(find_living(str),RN()+" has just given you a new life.\n");
   new->set_guild_name("undead");
   write("You raise your powerful hands and give "+new->query_name()+" a new life!\n");
   say(RN()+" just recruited "+new->query_name()+".\n");
   command("ut "+new->query_name()+" is now an Undead!\n",new);
   return 1;
}

reject(str) {
   object new,aura;
   if(!str) return;
   sscanf(str,"%s undead",str);
   new=find_player(str);
   if(!new) {
      write("Life: I could not find '"+str+"'\n");
      return 1;
   }
   if(!present(new,environment(me())))  {
      write("Life: "+new->query_name()+" is not here.\n");
      return 1;
   }
   aura=present("aura-undead",new);
   if(!aura)  {
      write("Life: "+new->query_name()+" is not an Apprentice yet!\n");
      return 1;
   }
   say(RN()+" banishes "+new->query_name()+" from the Undead Apprenticeship.\n");
   write("You force "+new->query_name()+" to abandon the Undead Apprenticeship.\n");
   command("ut "+RN()+" rejects "+new->query_name()+" from joining the Undead!\n",me());
   destruct(aura);
   new->set_guild_name();
   return 1;
}

vision(str) {
   object ob, ob_tmp, pla;
   string item;
   string it;
   int max;
   if (!str) {
      write("Who do you want to vision?\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < VISION_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   pla=find_player(str);
   if(!pla)  {
      write("No "+str+" on!\n");
      return 1;
   }
   write("**********************************************************\n");
   call_other(me(),"add_spell_point",-VISION_SPELL);
   write(call_other(environment(pla), "short")); write("\n");
   call_other(environment(pla), "long");
   ob = first_inventory(environment(pla));
   max = 20;
   while(ob && max > 0) {
      string short_str;
      short_str = call_other(ob, "short");
      if (short_str) {
         max -= 1;
         write(short_str + ".\n");
         it = short_str;
         }
      ob = next_inventory(ob);
   }
   write("**********************************************************\n");
   return 1;
}

emote(str){
   if(!str)
      return 0;
   str = format(str,60);
   write("You emote:\n");
   say(call_other(me(), "query_name", 0) + " "+ str +"\n");
   write(call_other(me(), "query_name", 0) + " "+ str +"\n");
   return 1;
}


melt(str)  {
   object obj;
   int value,weight;
   if(!str)  {
      write("Usage: umelt <item>\n");
      return 1;
   }
   obj=present(str,me());
   if(!obj)  {
      write("What do you want to melt?\n");
      return 1;
   }
   value=obj->query_value();
   if (!value) {
      write("You can't melt worthless things!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < MELT_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   weight = call_other(obj, "query_weight", 0);
   call_other(me(), "add_weight", - weight);
   if (value > 1000)  value = 1000 + random(200);
   call_other(me(),"add_spell_point",-MELT_SPELL);
   write("As you gaze the "+str+" glows.\nThe item melts into "+value+" coins.\n");
   say("You see "+call_other(me(),"query_name")+"'s eyes glow and a "+str+" melts.\n");
   call_other(me(), "add_money", value);
   destruct(obj);
   return 1;
}

send(str)
{
   string stuff,rece;
   int stweight;
   object stuff1,rece1;
   if((!str) || ((sscanf(str,"%s %s",stuff,rece) !=2)))
      {   write("You fail to send.\n");
      return 1;
   }
   if(!present(stuff,this_player()) || !find_living(rece))
      {   write("Stuff or receiver not present.\n");
      return 1;
   }
   if( find_living(rece)->query_invis()) {
   write("Stuff or receiver not present.\n");
      return 1;
   }
   if(environment(this_player())->realm() == "NT" ||
      environment(find_living(rece))->realm() == "NT") {
        write("You or the receiver are in a restricted area.\n");
        write("You can not send.\n");
   return 1; }
   if(present(stuff,this_player())->drop())  {
      write("You can't send this object.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < SEND_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
/* Addition by -= Pain =- */
    if(call_other(me(),"query_money") < 30) {
	write("You don't have enough money!\n");
	return 1;
   }
/* End -= Pain =- additions. */
   rece1=find_living(rece);
   stuff1=present(stuff,this_player());
   stweight=stuff1->query_weight();
/*
   if(!present("soul-undead",rece1)) {
      write("You can send only to a guild mate!\n");
      return 1;
   }
*/
   if(!rece1->add_weight(stweight))
      { write("Your mate can't carry that much.\n"); return 1; }
   move_object(stuff1,rece1);
   me()->add_weight(-stweight);
   tell_object(rece1,"A spirit arrives and gives you a "+stuff+" saying it's from "+RN()+".\n");
   write("You send a "+stuff+" to "+rece1->query_name()+".\n");
   call_other(me(),"add_spell_point",-SEND_SPELL);
   call_other(me(),"add_money",-30);
   return 1;
}

fog(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to fog?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < FOG_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-FOG_SPELL);
   write("You cast a magical fog on "+who->query_name()+".\n");
   say("A black fog invades the room and starts to choke "+who->query_name()+".\n");
   me()->attack_object(who);
   who->hit_player(FOG_SPELL-random(-10));
   /* there should be some randomness here -Bp */
   return 1;
}


lightning(arg)  {
   object who,obj;
   int flagarg;
   if(!arg)  {
      flagarg=0;
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to lightning?\n");
         return 1;
      }
   }
   else  {
      flagarg=1;
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(flagarg)
      who=present(arg,environment(me()));
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < LIGHTNING_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-LIGHTNING_SPELL);
   write("You cast a black lightning on "+who->query_name()+".\n");
   say(RN()+" releases a black bolt of energy and "+who->query_name()+" staggers.\n");
   me()->attack_object(who);
   who->hit_player((LIGHTNING_SPELL*3/5)+random(LIGHTNING_SPELL*2/5));
   /* some randomness */
   return 1;
}


shadows(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to shadows?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < SHADOWS_SPELL-10) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   obj=present("quartz",me());
   if(!obj)  {
      write("You need a magical quartz to shadows someone!\n");
      return 1;
   }
   destruct(obj);
   write("As you pronounce the magical words the quartz glows and crumbles away.\n");
   call_other(me(),"add_spell_point",-SHADOWS_SPELL-10);
   write("You summon the shadows from the depth of the earth.\n");
   write("The shadows attack "+who->query_name()+".\n");
   me()->attack_object(who);
   who->hit_player(SHADOWS_SPELL-random(20));
   say("You see "+who->query_name()+" surrounded by "+RN()+"'s shadows.\n");
   return 1;
}


glare(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to glare?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < GLARE_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-GLARE_SPELL);
   write("You gaze "+who->query_name()+" in the eyes and he starts to hit himself!\n");
   say("As "+RN()+" gazes "+who->query_name()+" the monster starts to hit himself.\n");
   me()->attack_object(who);
   who->hit_player(GLARE_SPELL-random(20)); 
   return 1;
}


charm(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to charm?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < CHARM_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-CHARM_SPELL);
   write("You charm "+who->query_name()+" and smash its head against your knee.\n");
   say(who->query_name()+" seems to be stunned.\n");
   say(RN()+" smashes "+who->query_name()+"'s head against his knee.\n");
   me()->attack_object(who);
   who->hit_player(CHARM_SPELL-random(10));
   return 1;
}


touch(arg,touch_spell)  {
   object who,obj;
    int flagarg;
   if(!arg)  {
        flagarg=0;
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to touch?\n");
         return 1;
      }
   }
   else  {
        flagarg=1;
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
    if(flagarg)
        who=present(arg,environment(me()));
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < touch_spell) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-touch_spell);
   write("As you touch "+who->query_name()+", he seems to lose power.\n");
   say(RN()+" touches "+who->query_name()+" which seems to grow weaker.\n");
   me()->attack_object(who);
   who->hit_player(random(touch_spell+random(touch_spell/2)));
   /* this should be random */
   return 1;
}


title(arg)  {
   if(call_other(me(),"query_sp") < TITLE_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   if(!arg) {
      call_other(me(),"set_title","");
      write("Your title is now clear.\n");
      return 1;
   }
   if(strlen(arg)>70) {
      write("You can only set titles up to 70 characters.\n");
      return 1;
   }
   call_other(me(),"set_title",arg);
   write("Your title is now:\n"+arg+".\n");
   return 1;
}

/*
title(arg)  {
   if(arg) return;

   call_other(me(),"set_title","the Undead "+morph);
   write("Your title is now: the Undead "+morph+".\n");
   return 1;
}
*/

rankme(hide_on,morph,touch_spell,guildlev)  {
   int lev,olev,xlev,lev_exp,spexp,next_lev;
   lev=guildlev;
   write(RN()+" the "+morph+".\n");
   write("Guild level: "+lev+".\n");
   write("Guild experience: "+me()->query_guild_exp()+".\n");
   if(lev==1)
      next_lev=SECOND_LEVEL;
   else if(lev==2)
      next_lev=THIRD_LEVEL;
   else if(lev==3)
      next_lev=FOURTH_LEVEL;
   else if(lev==4)
      next_lev=FIFTH_LEVEL;
   else if(lev==5)
      next_lev=SIXTH_LEVEL;
   else if(lev==6)
      next_lev=SEVENTH_LEVEL;
   else if(lev==7)
      next_lev=EIGHTH_LEVEL;
   if(lev<=7)
      {
      olev = me()->query_level();
      if(olev>19) olev=19;
      xlev = me()->query_extra_level();
      if(xlev>19) xlev = 19;
      if(olev > 18&&xlev>0) lev_exp = call_other("/room/exlv_guild","get_next_exp",xlev-1);
      else lev_exp = call_other("/room/adv_guild","get_next_exp",olev-1);
      spexp=me()->query_exp()-lev_exp;
      next_lev-=(spexp+me()->query_guild_exp());
      write("Next guild level: "+next_lev+" gxp needed.\n");
   }
   else write("Maximum guild level.\n");
   write("Guild Whimpy: ");
   /*
   if(guild_whimpy<1)
      write("OFF.\n");
   else
      write(guild_whimpy+"%.\n");
      */
   write("Current morph: ");
   if(!hide_on)
      write("None.\n");
   else
      write(morph+".\n");
   write("Touch power: "+touch_spell+".\n");
   return 1;
}


burn()  {
   object corpse;
   int heal;
   corpse=present("corpse",environment(me()));
   if(!corpse || corpse->query_level()!=0)  {
      write("No corpse to burn here.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < BURN_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-BURN_SPELL);
   heal=corpse->heal_value();
   me()->heal_self(heal);
   write("You burn the corpse of your opponent filling yourself up with its energy.\n"+
      "The corpse turns into ash and the wind blows it away.\n");
   say(RN()+" burns a corpse and glows with its energy.\nThe corpse turns into ash and the wind blows it away.\n");
   destruct(corpse);
   return 1;
}

glow()  {
   if(call_other(me(),"query_sp") < GLOW_SPELL) {
      write("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-GLOW_SPELL);
   write("Your body begins to emit a soft glow enabling you to see.\n");
   say(RN()+" starts to glow.\n");
   command("look",me());
   return 1;
}

qgm(arg,guildlev)  {
   int lev,olev,xlev,lev_exp,spexp,next_lev,flagout;
   string m_morph;
   if(!arg) {
      write("Whose stats do u want to check?\n");
      return 1;
   }
   mate=find_player(arg);
   if(!mate)  {
      mate=clone_object("/players/trix/closed/guild/qgm");
      call_other(mate,"set_search",arg);
      move_object(mate,me());
      if(mate->query_name()=="<noone>") {
         write("No players called "+arg+".\n");
         return 1;
      }
      flagout=1;
      call_out("destqgm",1);
   }
   if(!present("soul-undead",mate)) {
      if(!flagout||flagout&&mate->query_guild_name()!="undead") {
         write(mate->query_name()+" is not an undead.\n");
         return 1;
      }
   }
   if(guildlev<10)
      {
      if(call_other(me(),"query_sp") < QGM_SPELL) {
         write("You don't have enough spell points.\n");
         return 1;
      }
      call_other(me(),"add_spell_point",-QGM_SPELL);
   }
   lev=mate->query_guild_exp();
   if(lev < SECOND_LEVEL)
      {
      m_morph="Skeleton";
      lev=1;
      next_lev=SECOND_LEVEL;
   }
   else if(lev < THIRD_LEVEL)
      {
      m_morph="Zombie";
      lev=2;
      next_lev=THIRD_LEVEL;
   }
   else if(lev < FOURTH_LEVEL)
      {
      m_morph="Ghoul";
      lev=3;
      next_lev=FOURTH_LEVEL;
   }
   else if(lev < FIFTH_LEVEL)
      {
      m_morph="Shadow";
      lev=4;
      next_lev=FIFTH_LEVEL;
   }
   else if(lev < SIXTH_LEVEL)
      {
      m_morph="Wight";
      lev=5;
      next_lev=SIXTH_LEVEL;
   }
   else if(lev < SEVENTH_LEVEL)
      {
      m_morph="Wraith";
      lev=6;
      next_lev=SEVENTH_LEVEL;
   }
   else if(lev < EIGHTH_LEVEL)
      {
      m_morph="Spectre";
      lev=7;
      next_lev=EIGHTH_LEVEL;
   }
   else if(lev < GUILD_COM)
      {
      m_morph="Lich";
      lev=8;
   }
   else if(lev < GUILD_COM2)
      {
      m_morph="Special";
      lev=10;
   }
   else
      {
      m_morph="Special";
      lev=50;
   }
   if(mate->query_real_name()=="hurtbrain" ||
         mate->query_real_name()=="trix" ||
      mate->query_real_name()=="gorgan" ) {
      m_morph="Dracolich";
      if(flagout)
         lev=mate->query_guild_rank();
      else
         lev=call_other(present("soul-undead",mate),"guild_level");
   }
   if(mate->query_real_name()=="nikki" || mate->query_real_name()=="jaraxle") {
      m_morph="Banshee";
      if(flagout)
         lev=mate->query_guild_rank();
      else
         lev=call_other(present("soul-undead",mate),"guild_level");
   }
   write(capitalize(mate->query_real_name()));
   write(" the "+m_morph+".\n");
   write("Guild level: "+lev+".\n");
   write("Guild experience: "+mate->query_guild_exp()+".\n");
   if(guildlev>=10)
      {
      if(lev<=7)
         {
         olev = mate->query_level();
         if(olev>19) olev=19;
         xlev = mate->query_extra_level();
         if(xlev>19) xlev = 19;
         if(olev > 18&&xlev>0) lev_exp = call_other("/room/exlv_guild","get_next_exp",xlev-1);
         else lev_exp = call_other("/room/adv_guild","get_next_exp",olev-1);
         spexp=mate->query_exp()-lev_exp;
         next_lev-=(spexp+mate->query_guild_exp());
         write("Next guild level: "+next_lev+" gxp needed.\n");
      }
      else write("Maximum guild level.\n");
   }
   return 1;
}

destqgm() { destruct(mate); }

quartz()  {
   object quartz;
   if(call_other(me(),"query_sp") < QUARTZ_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-QUARTZ_SPELL);
   write("You raise your hands and a magical quartz appears in it.\n");
   say(RN()+" close his eyes and a quartz magically appears.\n");
   quartz=clone_object("/players/hurtbrain/closed/guild/quartz.c");
   move_object(quartz,me());
   return 1;
}

animate(arg)
{ object corpse;
   string name;
   int animate_spell;
   object zom;
   if(arg!="dead")  {
      write("What do you want to animate?\n");
      return 1;
   }
   if(find_living("zombie_"+lower_case(me()->query_name())))  {
      write("You already have a pet zombie.\n");
      return 1;
   }
/* blt add. */
  if(!pet_zone()) return 1;
/*    */
   corpse=present("corpse",environment(me()));
   if(!corpse) { write("No corpses in this room.\n"); return 1; }
   animate_spell=30+(30*(corpse->heal_value())/19);
   if(call_other(me(),"query_sp") < animate_spell) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-animate_spell);
   sscanf(call_other(corpse,"short"),"corpse of %s",name);
   zom=clone_object("/players/trix/closed/guild/zombie");
   call_other(zom, "set_ac", 1+(4*(corpse->heal_value())/19));
   call_other(zom, "set_level",3);
   call_other(zom, "set_ep",2283);
   call_other(zom, "set_hp",50+(100*(corpse->heal_value())/19));
   call_other(zom, "set_wc",5+(10*(corpse->heal_value())/19));
   call_other(zom, "set_myname",name);
   call_other(zom, "set_info","z_"+rn());
   call_other(zom, "set_master",me());
   move_object(zom,environment(me()));
   call_other(zom,"toggle_follow");
   write("You summon a zombie from the depth of the earth.\n");
   say(RN()+" summons a zombie.\n");
   destruct(corpse);
   return 1;
}

store_spell_points(xsp){
   object corpse;
   int heal;
   if(xsp>100) {
      write("You can't store so many spell points.\n");
      return 0;
   }
   corpse=present("corpse",environment(me()));
   if(!corpse)  {
      write("This spell requires a corpse.\n");
      return 0;
   }
   heal=corpse->heal_value();
   xsp = xsp+heal;
   write("You drain the life energy from the corpse and store it in your life.\n");
   say(RN()+" drains the life energy from the corpse and store it in his life.\n");
   write("You store "+heal+" spell points.\n");
   write("You now have "+xsp+" stored sp.\n");
   destruct(corpse);
   return heal;
}
store_hit_points(xhp){
   object corpse;
   int heal;
   if(xhp>100)
      {     write("You can't store so many hit points.\n");
      return 0;
   }
   corpse=present("corpse",environment(me()));
   if(!corpse)  {
      write("This spell requires a corpse.\n");
      return 0;
   }
   heal=corpse->heal_value();
   xhp = xhp+heal;
   write("You drain the life energy from the corpse and store it in your life.\n");
   say(RN()+" drains the life energy from the corpse and store it in his life.\n");
   write("You store "+heal+" spell points.\n");
   write("You now have "+xhp+" stored sp.\n");
   destruct(corpse);
   return heal;
}

get_spell_points(amt,xsp){
   int num;
   if(!amt){
      write("How many spell points do you want to get.\n");
      return 0;
   }
   else if(sscanf(amt,"%d",num)==1){
      if(num>xsp){
         write("You haven't got that many spell points stored.\n");
         return 0;
         }
      else {
         xsp = xsp-num;
         me()->add_spell_point(num);
         write("You get "+num+" spell points.\n");
         return num;
         }
   }
   else return 0;
}

get_hit_points(amt,xhp){
   int num;
   if(!amt){
      write("How many hit points do you want to get?\n");
      return 0;
   }
   else if(sscanf(amt,"%d",num)==1){
      if(num>xhp){
         write("You don't have that many hit points stored.\n");
         return 0;
         }
      else{
         xhp=xhp-num;
         me()->add_hit_point(num);
         write("You get "+num+" hit points.\n");
         return num;
         }
   }
   else return 0;
}

evoke()  {
   object ppl,ppl1;
   ppl = first_inventory(environment(me()));
   write("You evoke the death upon the room!\n");
   say(RN()+" evokes the death upon the room.\n");
   while(ppl) {
      ppl1 = next_inventory(ppl);
      if(call_other(me(),"query_sp") < EVOKE_SPELL) {
         write("You don't have enough spell points.\n");
         return 1;
         }
      if(ppl!=me() && ppl->query_info()!="z_"+rn())
         if((ppl->query_npc()==1) && (ppl->is_pet()==0))
         {
         call_other(ppl,"attack_object",me());
         ppl->hit_player(EVOKE_SPELL-random(10));
         call_other(me(),"add_spell_point",-EVOKE_SPELL);
         }
      ppl = ppl1;
   }
   return 1;
}

 
uquit(hide_on)  {
   object obj;
   obj=find_living("zombie_"+lower_case(me()->query_name()));
   if(hide_on)
      command("hide",me());
   if(obj)
      command("peace str",me());
   obj=find_living("dog_"+lower_case(me()->query_name()));
   if(obj)
      command("release str",me());
  guild_channel_mess(RN()+" falls asleep and leaves this world.\n",me());

}



test_dark() {
   if (set_light(0) <= 0) {
      write("It is too dark.\n");
      return 1;
   }
   return 0;
}

inv() {
   object ob;
   ob = first_inventory(me());
   if (test_dark())
      return 1;
   while (ob) {
      string str;
      str = call_other(ob, "short");
      if (str) {
         write(str + ".\n");
         }
      ob = next_inventory(ob);
   }
   return 1;
}

do_compare(str)
{
   object enemy;
   string what,enemy_name;
   int enemy_sp,enemy_hp,enemy_lv,enemy_ac,enemy_wc;
   int pl_sp,pl_hp,pl_lv,pl_ac,pl_wc;
   int diff_hp,diff_sp,diff_ac,diff_wc,diff_lv;
   if(str)
      {
      enemy=find_living(str);
      if(!enemy)
         {
         write("That is not on the MUD!\n");
         return 1;
      }
      if(enemy==me())
         {
         write("You cannot compare yourself !!\n");
         return 1;
      }
      if(me()->query_sp()<KNOW_SPELL) {
         write("You don't have enough spell points.\n");
         return 1;
      }
      call_other(me(),"add_spell_point",-KNOW_SPELL);
      enemy_name=capitalize(enemy->query_name());
      enemy_sp=enemy->query_sp();
      enemy_hp=enemy->query_hp();
      enemy_lv=enemy->query_level();
      enemy_ac=call_other(enemy,"query_ac",);
      enemy_wc=call_other(enemy,"query_wc",);
      pl_sp=me()->query_sp();
      pl_hp=me()->query_hp();
      pl_lv=me()->query_level();

      pl_ac=call_other(me(),"query_ac",);
      pl_wc=call_other(me(),"query_wc",);

      write("You concentrate for a moment.\n");
      write("Your eyes become red.\n");
      write("Your Undead powers allow you to know that :\n");
      say(capitalize(me()->query_name())+"'s eyes start to shine and become red.\n");
      diff_hp=pl_hp-enemy_hp;
      diff_sp=pl_sp-enemy_sp;
      diff_ac=pl_ac-enemy_ac;
      diff_wc=pl_wc-enemy_wc;
      diff_lv=pl_lv-enemy_lv;
      if (diff_hp>100)
         write("Hp : You kick "+enemy_name+"'s ass!\n");
      else if(diff_hp>0)
         write("Hp : You are stronger then "+enemy_name+".\n");
      else if(diff_hp==0)
         write("Hp : You have as many hit points as "+enemy_name+".\n");
      else if(diff_hp<-100)
         write("Hp : "+enemy_name+" kicks your ass!\n");
      else
         write("Hp : "+enemy_name+" is stronger then you.\n");
      if (diff_sp>100)
         write("Sp : You kick "+enemy_name+"'s ass!\n");
      else if(diff_sp>0)
         write("Sp : You are stronger then "+enemy_name+".\n");
      else if(diff_sp==0)
         write("Sp : You have as many spell points as "+enemy_name+".\n");
      else if(diff_sp<-100)
         write("Sp : "+enemy_name+" kicks your ass!\n");
      else
         write("Sp : "+enemy_name+" is stronger then you.\n");
      if (diff_ac>5)
         write("Ac : You kick "+enemy_name+"'s ass!\n");
      else if(diff_ac>0)
         write("Ac : You are stronger then "+enemy_name+".\n");
      else if(diff_ac==0)
         write("Ac : You have the same armor class of "+enemy_name+".\n");
      else if(diff_ac<-5)
         write("Ac : "+enemy_name+" kicks your ass!\n");
      else
         write("Ac : "+enemy_name+" is stronger then you.\n");
      if (diff_wc>5)
         write("Wc : You kick "+enemy_name+"'s ass!\n");
      else if(diff_wc>0)
         write("Wc : You are stronger then "+enemy_name+".\n");
      else if(diff_wc==0)
         write("Wc : You have the same weapon class of "+enemy_name+".\n");
      else if(diff_wc<-5)
         write("Wc : "+enemy_name+" kicks your ass!\n");
      else
         write("Wc : "+enemy_name+" is stronger then you.\n");
      if (diff_lv>5)
         write("Level : You kick "+enemy_name+"'s ass!\n");
      else if(diff_lv>0)
         write("Level : You are stronger then "+enemy_name+".\n");
      else if(diff_lv==0)
         write("Level : You are the same level of "+enemy_name+".\n");
      else if(diff_lv<-5)
         write("Level : "+enemy_name+" kicks your ass!\n");
      else
         write("Level : "+enemy_name+" is stronger then you.\n");

      return 1;
   }
   write("Usage: compare <monster>\n");
   return 1;
}

feign()  {
   object obj;
   if(call_other(me(),"query_sp") < FEIGN_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-FEIGN_SPELL);
   obj=first_inventory(environment(me()));
   while(obj)   {
      call_other(obj,"stop_hunting_mode");
      call_other(obj,"stop_fight");
      obj->attack_object();
      obj->attacked_by();
      call_other(obj,"stop_hunting_mode");
      call_other(obj,"stop_fight");
      obj->attack_object();
      obj->attacked_by();
      obj=next_inventory(obj);
   }
   write("You simulate your death. Everyone in the room stops fighting!\n");
   say(RN()+" died.\nYou stop fighting to see what has happened!\n");
   return 1;
}

scan(str) {
   object obj;
   if(!str) {
      write("What do you want to scan?\n");
      return 1;
   }
   obj=find_living(str);
   if(!obj)  {
      write("No "+str+" on.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < SCAN_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-SCAN_SPELL);
   write("You gaze into "+capitalize(str)+"'s eyes and see: Hp left: "+
      call_other(obj,"query_hp",)*100/call_other(obj,"query_mhp",)+"%.\n");
   return 1;
}

/*
set_guild_whimpy(str)  {
   guild_whimpy=str;
   return 1;
}

query_whimpy() { return guild_whimpy; }
set_prev_touch(str)  {
   touch_spell=str;
   return 1;
}

*/
renew(randname,hide_on,touch_spell,xsp,xhp,old) {
   object obj;
   if(hide_on)
      command("hide",me());
   write("Refreshing life.\n");
   obj=clone_object("/players/"+randname+"/life.c");
   move_object(obj,me());
   obj->set_hp_stored(xhp);
   obj->set_sp_stored(xsp);
   if(xhp || xsp )  {
      write("HP stored: "+xhp+".\n");
      write("SP stored: "+xsp+".\n");
   }
   obj->set_noentrance();
   obj->set_prev_touch(touch_spell);
   write("Touch power set to "+touch_spell+".\n");
   destruct(old);
   return 1;
}

aid(str)  {
   int points;
   string name;
   object who;
   if(!str)  {
      write("Usage : aid <player> <nn>.\n");
      return 1;
   }
   if (sscanf(str,"%s %d",name,points)!=2)  {
      write("Usage : aid <player> <nn>.\n");
      return 1;
   }
   who=find_player(name);
   if(!who)  {
      write("No "+capitalize(name)+" on.\n");
      return 1;
   }
   if(points<0 || points>me()->query_sp())  {
      write("Spell points out of range.\n");
      return 1;
   }
   call_other(who,"add_spell_point",points);
   call_other(me(),"add_spell_point",-points);
   write("You aid "+who->query_name()+" and send him "+points+" spell points.\n");
   tell_object(who,RN()+" helps you and sends you "+points+" spell points.\n");
   return 1;
}

low_armor()  {
   object obj;
   if(call_other(me(),"query_money") < LOW_ARMOR_SPELL) {
      write("You don't have enough gold coins.\n");
      return 1;
   }
   call_other(me(),"add_money",-LOW_ARMOR_SPELL);
   write("You utter some words unknown to the living and a magical vest appears.\n");
   say(RN()+" utters unknown words and a magical vest appears.\n");
   obj=clone_object("/players/hurtbrain/closed/guild/vest");
   move_object(obj,me());
   return 1;
}

low_weapon()  {
   object obj;
   if(call_other(me(),"query_money") < LOW_WEAPON_SPELL) {
      write("You don't have enough gold coins.\n");
      return 1;
   }
   call_other(me(),"add_money",-LOW_WEAPON_SPELL);
   write("You utter some words unknown to the living and a ball of fire appears.\n");
   say(RN()+" utters unknown words and creates a ball of fire.\n");
   obj=clone_object("/players/hurtbrain/closed/guild/ball");
   move_object(obj,me());
   return 1;
}

high_armor()  {
   object obj;
   if(call_other(me(),"query_money") < HIGH_ARMOR_SPELL) {
      write("You don't have enough gold coins.\n");
      return 1;
   }
   call_other(me(),"add_money",-HIGH_ARMOR_SPELL);
   write("You magically create a force field!\n");
   say(RN()+" magically creates a force field.\n");
   obj=clone_object("/players/hurtbrain/closed/guild/field");
   move_object(obj,me());
   return 1;
}

high_weapon()  {
   object obj;
   if(call_other(me(),"query_money") < HIGH_WEAPON_SPELL) {
      write("You don't have enough gold coins.\n");
      return 1;
   }
   call_other(me(),"add_money",-HIGH_WEAPON_SPELL);
   write("You utter some words unknown to the living and a firewhip appears.\n");
   say(RN()+" utters unknown words and creates a firewhip.\n");
   obj=clone_object("/players/hurtbrain/closed/guild/whip");
   move_object(obj,me());
   return 1;
}

call()  {
   object obj;
   object mor;
   object env;
   obj=find_living("zombie_"+lower_case(RN()));
   if(!obj)  {
      write("No zombie to call.\n");
      return 1;
   }
   mor=find_living("morph_"+lower_case(RN()));
   if(mor) env=environment(mor);
   else env=environment(me());
   tell_room(environment(obj),"As you hear a whistle "+obj->query_name()+" shades off from your view.\n");
   move_object(obj,environment(me()));
   command("zomfo",me());
   move_object(obj,env);
   tell_room(env,obj->query_name()+" appears near his master, "+RN()+".\n");
   write("Your zombie arrives and stands at your side.\n");
   return 1;
}

promote(str)  {
   object obj;
   int lev;
   int gexp;
   if(!str)  {
      write("Who do you want to promote?.\n");
      return 1;
   }
   obj=find_player(str);
   if(!obj)  {
      write("No "+capitalize(str)+" on.\n");
      return 1;
   }
   if(!present("soul-undead",obj))  {
      write(obj->query_name()+" is not an Undead!\n");
      return 1;
   }
   gexp=obj->query_guild_exp();
   if(gexp < SECOND_LEVEL)  {
      call_other(obj,"add_guild_exp",SECOND_LEVEL-gexp);
      lev=2;
   }
   else if(gexp < THIRD_LEVEL)  {
      call_other(obj,"add_guild_exp",THIRD_LEVEL-gexp);
      lev=3;
   }
   else if(gexp < FOURTH_LEVEL)  {
      call_other(obj,"add_guild_exp",FOURTH_LEVEL-gexp);
      lev=4;
   }
   else if(gexp < FIFTH_LEVEL)  {
      call_other(obj,"add_guild_exp",FIFTH_LEVEL-gexp);
      lev=5;
   }
   else if(gexp < SIXTH_LEVEL)  {
      call_other(obj,"add_guild_exp",SIXTH_LEVEL-gexp);
      lev=6;
   }
   else if(gexp < SEVENTH_LEVEL)  {
      call_other(obj,"add_guild_exp",SEVENTH_LEVEL-gexp);
      lev=7;
   }
   else if(gexp < EIGHTH_LEVEL)  {
      call_other(obj,"add_guild_exp",EIGHTH_LEVEL-gexp);
      lev=8;
   }
   else if(gexp < GUILD_COM)  {
      call_other(obj,"add_guild_exp",GUILD_COM-gexp);
      lev=10;
   }
   else  {
      write("You can't promote to wiz's level!\n");
      return 1;
   }
   tell_object(obj,"You are promoted in the guild by "+RN()+".\n");
   write("You promoted "+obj->query_name()+" to level "+lev+".\n");
   log_file("hurtbrain.pro",RN()+" promoted "+obj->query_name()+" to level "+lev+".\n");
   return 1;
}

gdemote(str)  {
   object obj;
   int lev;
   int gexp;
   string name;
   if(!str)  {
      write("Who do you want to demote?.\n");
      return 1;
   }
   obj=find_player(str);
   if(!obj)  {
      write("No "+capitalize(str)+" on.\n");
      return 1;
   }
   if(!present("soul-undead",obj))  {
      write(obj->query_name()+" is not an Undead!\n");
      return 1;
   }
   name=obj->query_real_name();
   if(name=="hurtbrain" || name=="trix" || name=="gorgan")  {
      write("You can't demote guild wizard.\n");
      return 1;
   }
   gexp=obj->query_guild_exp();
   if(gexp < SECOND_LEVEL)  {
      write(obj->query_name()+" is already level 1.\n");
      return 1;
   }
   else if(gexp < THIRD_LEVEL)  {
      call_other(obj,"add_guild_exp",-gexp);
      lev=1;
   }
   else if(gexp < FOURTH_LEVEL)  {
      call_other(obj,"add_guild_exp",SECOND_LEVEL-gexp);
      lev=2;
   }
   else if(gexp < FIFTH_LEVEL)  {
      call_other(obj,"add_guild_exp",THIRD_LEVEL-gexp);
      lev=3;
   }
   else if(gexp < SIXTH_LEVEL)  {
      call_other(obj,"add_guild_exp",FOURTH_LEVEL-gexp);
      lev=4;
   }
   else if(gexp < SEVENTH_LEVEL)  {
      call_other(obj,"add_guild_exp",FIFTH_LEVEL-gexp);
      lev=5;
   }
   else if(gexp < EIGHTH_LEVEL)  {
      call_other(obj,"add_guild_exp",SIXTH_LEVEL-gexp);
      lev=6;
   }
   else if(gexp < GUILD_COM)  {
      call_other(obj,"add_guild_exp",SEVENTH_LEVEL-gexp);
      lev=7;
   }
   else  {
      call_other(obj,"add_guild_exp",EIGHTH_LEVEL-gexp);
      lev=8;
   }
   tell_object(obj,"You are demoted in the guild by "+RN()+".\n");
   write("You demoted "+obj->query_name()+" to level "+lev+".\n");
   log_file("hurtbrain.pro",RN()+" demoted "+obj->query_name()+" to level "+lev+".\n");
   return 1;
}

leave(hide_on)  {
   object obj;
   write("YOU ARE A TRAITOR!!!!!!!\nResetting your guild levels.\n");
   write("You lose 1/3 of your xp.\nYou feel your power decreasing.\n");
   write("You turn human again.\n");
   obj=find_living("zombie_"+lower_case(me()->query_name()));
   if(hide_on) command("hide",me());
   if(obj) command("peace str",me());
   me()->set_guild_name(0);
me()->add_exp(me()->query_guild_exp());
   me()->add_guild_exp(-me()->query_guild_exp());
   me()->add_guild_rank(-me()->query_guild_rank());
   me()->add_exp(-(me()->query_exp()/3));
   destruct(present("soul-undead",me()));
   return 1;
}

awho(str){
   object us;
   int x;
   if(str) return;
   us = users();
   write("*-----------------------------------------------------------------------------*\n");
   write("|*Name*---*Sex*Level*-*Guild*-------*Location*--------------------------------|\n");
   write("*-----------------------------------------------------------------------------*\n");
   for(x=0;x<sizeof(us);x++){
      int invis;
      invis=us[x]->query_invis();
      if(invis<this_player()->query_level()){
         if(invis) { write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"); }
         write(capitalize(us[x]->query_real_name()));
         if(strlen(us[x]->query_real_name())>7)
            write("\t"); else write("\t\t");
         write(esc+"[0m");
         write("\b\b\b\b");
         if(us[x]->query_gender()=="male")
            write("M   ");
         else
            if(us[x]->query_gender()=="female")
            write("F   ");
         else
            write("C   ");
         write(us[x]->query_level()+"\t\b");
         if(us[x]->query_guild_name())
            if(us[x]->query_guild_name()=="Black Circle Mage")
            write("BC Mage\t\t");
         else
            write(capitalize(us[x]->query_guild_name())+"\t");

         else
            write("None\t");
         if(!us[x]->query_guild_name()||strlen(us[x]->query_guild_name())<=8) write("\t");
         write("\b\b\b\b");
         if(!environment(us[x])) write("Logging in");
         else write(environment(us[x])->short());
         write("\n");}
   }
   write("*----------------------Players currently logged on: "+x);
   if(x<10) write("-");
   write("------------------------*\n");
   return 1;
}

tell(str) {
   object ob;
   string who;
   string msg;
   string it;
   if (me()->query_ghost()) {
      write("You fail.\n");
      return 1;
   }
   if (me()->query_spell_point() < 0) {
      write("You are low on power.\n");
      return 1;
   }
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
      write("Tell what?\n");
      return 1;
   }
   it = lower_case(who);
   ob = find_player(it);
   if (!ob) ob = find_living(it);
   if (!ob) {
      write("No player with that name.\n");
      return 1;
   }
   if (interactive(ob)) {
      if (ob->query_invis() ) {
         write("No player with that name.\n");
         return 1;
       }
      if (in_editor(ob)) {
         write("That person is editing. Please try again later.\n");
         return 1;
       }
   }
   if (call_other( me(), "query_invis", 0) > 0 && call_other(me(), "query_level", 0) < 999)
      {
      write( "Don't be annoying.  Become visible before you talk to someone!\n" );
      return 1;
   }
   msg = format(msg, 60);
   tell_object(ob, me()->query_name() + " tells you: " + msg + "\n");
   write("Ok.\n");
   write("You tell "+who+ " " + msg);
   if(me()->query_level() < 20)
      call_other(me(),"add_spell_points",-5);
   return 1;
}

tomb()  {
   if(environment(me())->realm()=="NT"&&me()->query_level()<20)  {
      write("This room blocks your try to escape.\n");
      return 1;
   }

   if(environment(me())->short()!="Village church")
      {
      if(call_other(me(),"query_sp") < TOMB_SPELL) {
         write("You don't have enougth spell points.\n");
         return 1;
      }
      call_other(me(),"add_spell_point",-TOMB_SPELL);
   }
   write("You enter your own soul, travelling to your guild room.\n");
   say(RN()+" disappears in a flash of light.\n");
   move_object(me(),"/players/trix/closed/guild/guild_room.c");
   write("You reached undead's guild room!\n");
   say(RN()+" appears in a flash of light.\n");
   return 1;
}
/*
set_whimpy(str)  {
   int num;
   if(!str)  {
      write("Guild Whimpy is ");
      if(guild_whimpy==-1)
         write("OFF.\n");
      else
         write("set to "+guild_whimpy+"%.\n");
      return guild_whimpy;
   }
   if(!sscanf(str,"%d",num))
      {
      write("Usage: set_whimpy <number>.\n");
      return 1;
   }
   if(num < 0 || num > 90)
      {
      write("Guild Whimpy can be set [0-90] only.\n");
      return 1;
   }
   if(num==0)
      {
      guild_whimpy=-1;
      write("You set Guild Whimpy OFF.\n");
      return guild_whimpy;
   }
   write("You set Guild Whimpy to "+num+"%.\n");
   guild_whimpy=num;
   return guild_whimpy;
}

*/
utp(str) {
   object ob;
   string who;
   string msg;
   string it;
   string msg2;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
      write("What do you want to tell?\n");
      return 1;
   }
   it = lower_case(who);
   ob = find_player(it);
   if (!ob) ob = find_living(it);
   if (!ob) {
      write("No player with that name.\n");
      return 1;
   }
   if (interactive(ob)) {
      if (ob->query_invis() >= 100) {
         write("No player with that name.\n");
         return 1;
       }

      if (in_editor(ob)) {
         write("That person is editing. Please, do not disturb.\n");
         return 1;
       }
	if(!present("soul-undead",ob))  {
   	if(call_other(me(),"query_sp") < COMMU_SPELL) {
      		write("You don't have enough spell points.\n");
     		return 1;
   		}
	call_other(me(),"add_spell_point",-COMMU_SPELL);
      }   
   }
   msg2 = format(msg, 62);
   msg = format(msg, 53);
 /*  tell_object(ob, "<*>"+me()->query_name() + "<*> " + msg2 + "\n"); */
 /*  tell_object(ob, "<*>"+me()->query_name() + "<*> "+wrap_string(msg2, 79, strlen("<*>"+me()->query_name() + "<*> " + 9))+"\n");  
  no specialized tells! - mythos <6-8-96>
  */
  tell_object(ob, me()->query_name() + " tells you: " + msg2 + "\n");
   write("Ok.\n");
   write("You tell "+who+ " " + msg);
   return 1;
}

uep(str)  {
   object ob;
   string who;
   string msg;
   string it;
   string msg2;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
      write("What do you want to emote?\n");
      return 1;
   }
   it = lower_case(who);
   ob = find_player(it);
   if (!ob) ob = find_living(it);
   if (!ob) {
      write("No player with that name.\n");
      return 1;
   }
   if (interactive(ob)) {
      if (ob->query_invis() >= 100) {
         write("No player with that name.\n");
         return 1;
       }
      if (in_editor(ob)) {
         write("That person is editing. Please, do not disturb.\n");
         return 1;
       }
        if(!present("soul-undead",ob))  {
        if(call_other(me(),"query_sp") < COMMU_SPELL) {
                write("You don't have enough spell points.\n");
                return 1;
                }
        call_other(me(),"add_spell_point",-COMMU_SPELL);
      }
   }
   msg2 += " from afar";
   msg += " from afar";
   msg2 = format(msg, 64);
   msg = format(msg, 68);
   /*
   tell_object(ob, "<***> "+me()->query_name() + " " + msg2 + "\n");
   write("You undead_emote "+who+ ":\n " +me()->query_name()+" "+ msg);
   no specialized tells! - mythos <6-8-96>
   */
   tell_object(ob, me()->query_name() + " " + msg2+"\n");
   write("Ok.\n");
   write("You emote from afar "+who+ ":\n " +me()->query_name()+" "+ msg);
   return 1;
}
trance(arg)
{int num;
   if(!arg){
      write("How many hit points do u want to heal?\n");
      return 1;
   }
   else if(sscanf(arg,"%d",num)==1){
      if(num<0) { write("You can't do it! Try with a positive number.\n");
         return 1;
         }

      if(num>me()->query_sp()){
         write("You don't have that many spell points!\n");
         return 1;
         }
      if(me()->query_mhp()-me()->query_hp()<num)
         {  write("Your hit points are not that low, try with a lower amount.\n");
         return 1;
         }
      say(capitalize(me()->query_real_name())+
         " enters a contemplative trance and suddenly looks healthier.\n",me());
      write("You enter a contemplative trance and feel suddenly better.\n");
      me()->add_spell_point(-num);
      me()->add_hit_point(num);
      return 1;
   }
}
score(hide_on,touch_spell,guildlev)
{  int lev,olev,xlev,lev_exp,spexp,next_lev;
   write("\n*============================> You are an UNDEAD <============================*");
   call_other(me(),"score");
   write("Time: "+ctime(time())+" CST\n");
   write("Touch Power: "+touch_spell);
   if(touch_spell<100)
      write("\t");
   write("\t\tMorphing: ");
   if(hide_on)
      write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mOn"+esc+"[0m.\n");
   else    write("Off.\n");
   lev=guildlev;
   if(lev==1)
      next_lev=SECOND_LEVEL;
   else if(lev==2)
      next_lev=THIRD_LEVEL;
   else if(lev==3)
      next_lev=FOURTH_LEVEL;
   else if(lev==4)
      next_lev=FIFTH_LEVEL;
   else if(lev==5)
      next_lev=SIXTH_LEVEL;
   else if(lev==6)
      next_lev=SEVENTH_LEVEL;
   else if(lev==7)
      next_lev=EIGHTH_LEVEL;
   write("Guild Level: "+guildlev+"\t\tGxp to next level: ");
   if(lev<=7)
      {
      olev = me()->query_level();
      if(olev>19) olev=19;
      xlev = me()->query_extra_level();
      if(xlev>19) xlev = 19;
      if(olev > 18&&xlev>0) lev_exp = call_other("/room/exlv_guild","get_next_exp",xlev-1);
      else lev_exp = call_other("/room/adv_guild","get_next_exp",olev-1);
      spexp=me()->query_exp()-lev_exp;
      next_lev-=(spexp+me()->query_guild_exp());
      write(next_lev+".\n");
   }
   else write("--.\n");
   write("*=============================================================================*\n");
   return 1;
}

lead()  {
   object who;
   if(!me()->query_attack())  {
      write("You are not fighting anyone!\n");
      return 1;
   }
   who=me()->query_attack();
   if(who->query_attack()==me())  {
      write("You already lead the fight!\n");
      return 1;
   }
   write("You break throught the crowd and stand between "+who->query_name(
         )+" and "+(who->query_attack())->query_name()+".\n");
   say(RN()+" leads the fight now!\n");
   who->attack_object(me());
   return 1;
}

guildfix(arg)
{ object who,life;
   if(!arg)  {
      write("Whose guild object do you want to fix?\n");
      return 1;
   }
   who=find_living(arg);
   if(!who){
      write("No "+arg+" on.\n");
      return 1;
   }
   if(who->query_guild_name()!="undead")
      {
      write(capitalize(arg)+" is not an Undead, forget about it!\n");
      return 1;
   }
   if(present("soul-undead",who))
      {
      write(capitalize(arg)+" already has a life!!!\n");
      return 1;
   }
   life=clone_object("/players/hurtbrain/life");
   move_object(life,who);
   command("renew",who);
   return 1;
}
ecnart(arg)
{int num;
   if(!arg){
      write("How many hit points do u want to swap?\n");
      return 1;
   }
   else if(sscanf(arg,"%d",num)==1){
      if(num<0) { write("You can't do it! Try with a positive number.\n");
         return 1;
         }

      if(me()->query_hp()-num<20){
         write("It's not safe to concentrate so hard!\n");
         return 1;
         }
      if(me()->query_msp()-me()->query_sp()<num)
         {  write("Your spell points are not that low, try with a lower amount.\n");
         return 1;
         }
      say(capitalize(me()->query_real_name())+
         " enters a contemplative trance and with a huge physical effort increases\n"+
         "their magical skills.\n",me());
      write("You enter a contemplative trance and feel weaker but better magically skilled.\n");
      me()->add_spell_point(num);
      me()->add_hit_point(-num);
      return 1;
   }
}
speed() {
   if(present("speedster",me())){
      write("You already have your speedster.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < SPEED_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   write("You receive a speedster from Hurtbrain.\n");
   call_other(me(),"add_spell_point",-SPEED_SPELL);
   move_object(clone_object("/players/hurtbrain/obj/newspeed.c"),me());
   return 1;
}

whistle()  {
   object obj;
   object mor;
   object env;
   obj=find_living("dog_"+lower_case(RN()));
   if(!obj)  {
      write("You have no dog to call.\n");
      return 1;
   }
   mor=find_living("morph_"+lower_case(RN()));
   if(mor) env=environment(mor);
   else env=environment(me());
   tell_room(environment(obj),"As you hear a whistle "+obj->query_name()+" trots away to its master.\n");
   move_object(obj,environment(me()));
   command("dogfo",me());
   move_object(obj,env);
   obj->set_master(me());
   tell_room(env,obj->query_name()+" appears near his master, "+RN()+".\n");
   write("Your dog trots and stops at your side.\n");
   return 1;
}

dog()
{ object dog;
   if(find_living("dog_"+lower_case(me()->query_name())))  {
      write("You already have a death dog.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < DOG_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
/* blt add. */

  if(!pet_zone()) return 1;

/*      */
   }
   call_other(me(),"add_spell_point",-DOG_SPELL);
   dog=clone_object("/players/trix/closed/guild/ddog");
   call_other(dog, "set_master",this_player());
   move_object(dog,environment(this_player()));
   call_other(dog,"toggle_follow");
   write("You whistle loudly and a huge death dog rises from the shadows.\n");
   say(RN()+" whistles loudly and a huge death dog rises from the shadows.\n");
   return 1;
}

creat_flyer()
{
   write("You clap your hands and a Undead's guild flyer appears in it.\n");
   say(RN()+" claps his hands and a flyer appears.\n");
   move_object(clone_object("/players/hurtbrain/guildflyer.c"),me());
   return 1;
}
cl_edit(guildlev) {
    if(guildlev != 25 && guildlev != 100) return 0;
    if(present("editor",me()))  {
        write("You already have one!\n");
        return 1;
        }
    move_object(clone_object("/players/hurtbrain/closed/guild/editor"),me());
    write("Ok.\n");
    return 1;
}
/* BEGINNING OF EMOTE SECTION */
find(arg) { return present(arg,environment(me())); }

check_edit(edwho)  { if(edwho->query_level()>20&&in_editor(edwho)) return 1; }

sex(arg) { return call_other(arg,"query_gender"); }

uname(arg){ return capitalize(call_other(arg,"query_real_name")); }

pos(arg) { if(sex(arg)=="male") return "his";
           else if(sex(arg)=="female") return "her";
           return "its";
         }
pro(arg) { if(sex(arg)=="male") return "he";
           else if(sex(arg)=="female") return "she";
           return "it";
         }
ogg(arg) { if(sex(arg)=="male") return "him";
           else if(sex(arg)=="female") return "her";
           return "it";
         }
prp(arg) { if(sex(arg)=="male") return "his";
           else if(sex(arg)=="female") return "hers";
           return "its";
         }

ugrin(arg) {
 write("You grin wickedly, your eyes glow with a red sick light.\n");
 say(uname(me())+" grins wickedly, "+pos(me())+" eyes glow with a red sick light.\n",me());
 return 1;
}

usmile(arg) {
 string self,aim,others;
 if(!arg) {  write("You smile an evil smile, your eyes betraying no signs of human feelings.\n");
             say(uname(me())+" smiles an evil smile, "+pos(me())+" eyes betraying no signs of human feelings.\n",me());
             return 1;
          }
 ewho=find(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; }
 self="You smile evilly at "+uname(ewho)+", your eyes betraying no signs of human feelings.\n";
 aim=uname(me())+" smiles evilly at you, "+pos(me())+" eyes betraying no signs of human feelings.\n";
 others=uname(me())+" smiles evilly at "+uname(ewho)+", "+pos(me())+" eyes betraying no signs of human feelings.\n";
 phone(self,aim,others);
 return 1;
}

uglare(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 ewho=find(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; }
 self="You glare at "+uname(ewho)+", red flashes coming out of your eyes reduced to two narrow slits.\n";
 aim=uname(me())+" glares at you, red flashes coming out of "+pos(me())+" eyes reduced to two narrow slits.\n";
 others=uname(me())+" glares at "+uname(ewho)+", red flashes coming out of "+pos(me())+" eyes reduced to two narrow slits.\n";
 phone(self,aim,others);
 return 1;
}


ugreet(arg) {
 string self,aim,others,bro;
 if(!arg) {  object us,life;
             string name;
             int x;
             write("You close your eyes and mentally greet your brothers undead.\n");
             say(uname(me())+" closes "+pos(me())+" eyes, "+pos(me())+" body relaxes as "+pro(me())+
                 " abandones it for an instant, then it quivers violently when "+pro(me())+" takes"+
                 " possession back.\n",me());
             us=users();
             name=uname(me());
             for(x=0;x<sizeof(us); x++) {
                    life=present("soul-undead",us[x]);
                    if(life&&!life->query_muffle()&&!check_edit(us[x])&&us[x]!=me())
                    {
                     tell_object(us[x],"You feel "+uname(me())+" enter your mind and greet you as an undead");
                     if(sex(us[x])=="female") tell_object(us[x]," sister.\n");
                     else tell_object(us[x]," brother.\n");
                    }
           }
             return 1;
          }
 ewho=find_living(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; }
 if(ewho->query_guild_name()!="undead")
          {  write(capitalize(arg)+" is not an Undead.\n");
             return 1;

          }
 if(check_edit(ewho))
    {  write(uname(ewho)+" is editing. Please, do not disturb.\n");
       return 1;
    }
 if(sex(ewho)=="female") bro="sister";
 else bro="brother";
 self="You close your eyes and mentally greet "+uname(ewho)+" as an Undead "+bro+".\n";
 aim="You feel "+uname(me())+" enter your mind and greet you as an undead "+bro+".\n";
 others=uname(me())+" closes "+pos(me())+", "+pos(me())+" body relaxes as "+pro(me())+
                 " abandones it for an instant, then it quivers violently when "+pos(me())+" takes"+
                 " possession back.\n";
 phone(self,aim,others);
 return 1;
}

uwater(arg) {
 write("You express your repulsion for water.\n");
  say(uname(me())+" goes \"Water?!?!?! Eeeeeeek!!!!\".\n",me());
 return 1;
}

uoblige(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 ewho=find(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; }
 self="You force "+uname(ewho)+" to bow.\n";
 aim=uname(me())+" stares at you with red glowing eyes, you feel a tremendous power pushing"+
     " down on you, forcing you to bow.\n";
 others=uname(me())+" stares at "+uname(ewho)+" with red glowing eyes, "+uname(ewho)+" is"+
        " forced to bow deeply before "+ogg(me())+".\n";
 phone(self,aim,others);
 return 1;
}

uthreaten(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 ewho=find(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; }
 self="You suddenly spring and move behind "+uname(ewho)+", staring greedily at the"+
      " back of "+pos(ewho)+" neck.\n";
 aim="You bat your eyelids and when u reopen up your eyes "+uname(me())+" is not in front"+
     " of you anymore, shivers run up and down your spine as you feel two red eyes staring"+
     " at you from behind.\n";
 others=uname(me())+" moves quickly behind "+uname(ewho)+" and stares greedily at the back of "+pos(ewho)+" neck.\n";
 phone(self,aim,others);
 return 1;
}

phone(self,aim,others)
{object ob;
write(format(self, 80));
tell_object(ewho,format(aim, 80));
 ob=first_inventory(environment(this_player()));
 while(ob) { if(ob!=ewho&&ob!=me()) tell_object(ob,others);
 ob=next_inventory(ob); }
}

/* END OF EMOTE SECTION */
uemotes(str) {
   if(str)  return;
   write("\n  @====================== Undead Special Emotes ======================@\n");
   write("  ||**|uglare      ||* |ugreet      ||  |ugrin       ||**|uoblige     |\n");
   write("  ||* |usmile      ||**|uthreaten   ||  |uwater      ||  |            |\n");
   write("  @===================================================================@\n");
   return 1;
}
apprentice(str) {
  object new,aura;
  if(!str) return;
  sscanf(str,"%s undead",str);
  new = find_player(str);
  if(!new) {
    write("Life: I could not find '"+str+"'\n");
    return 1;
  }
  if(!present(new,environment(me())))  {
        notify_fail("Life: "+new->query_name()+" is not here.\n");
        return 0;
        }
  if(present("soul-undead",new))  {
        notify_fail("Life: "+new->query_name()+" is already an Undead!\n");
        return 0;
        }
  if(present("aura-undead",new))  {
        notify_fail("Life: "+new->query_name()+" is already an Undead Apprentice!\n");
        return 0;
        }
  if((new->query_guild_name()&&lower_case(new->query_guild_name())!="none") || new->query_guild_exp())
  {
      notify_fail("Life: "+new->query_name()+" is already in another guild.\n");
      return 0;
      }
  if(new->query_level() < 3)  {
        notify_fail("Life: "+new->query_name()+" needs to be at least level 3.\n");
        return 0;
        }
  aura=clone_object("/players/trix/closed/guild/apprentice.c");
  move_object(aura,new);
  call_other(aura,"set_age",new->query_age());
  tell_object(new,RN()+" just made you an Undead Apprentice.\n");
  write("You raise your powerful hands and mark "+new->query_name()+" as an Undead Apprentice!\n");
  say(RN()+" just marked "+new->query_name()+" as an Undead Apprentice.\n",new);
  command("ut "+new->query_name()+" is now an Undead Apprentice!\n",this_player());
  return 1;
}
appfix(arg)
{ object who,aura;
    if(!arg)  {
                notify_fail("Whose apprentice aura do you want to fix?\n");
                        return 0;
                }
  who=find_living(arg);
  if(!who){
         notify_fail("No "+arg+" on.\n");
         return 0;
        }
  if(who->query_guild_name()!="[UndApp]")
   {
        write(capitalize(arg)+" is not an Undead Apprentice, forget about it!\n");
        return 1;
   }
  if(present("aura-undead",who))
   {
        write(capitalize(arg)+" already has an aura!!!\n");
        return 1;
   }
  aura=clone_object("/players/trix/closed/guild/apprentice");
  call_other(aura,"set_age",who->query_age()-7500);
  move_object(aura,who);
  command("renew",who);
  return 1;
}

possess(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to possess?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < POSSESS_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-POSSESS_SPELL);
   write("You take "+who->query_name()+"'s head in your hands and start drawing"+
   " energy from "+ogg(who)+".\n"+
       who->query_name()+" shakes like a cloth caught in a windstorm and arches "+pos(who)+" back\n"+
       "in a vain attempt to break free from your grasp.\n");
   say(RN()+" takes "+who->query_name()+"'s head in "+pos(me())+" hands and starts drawing energy from "+ogg(who)+".\n"+
       who->query_name()+" shakes like a cloth caught in a windstorm and arches "+pos(who)+" back\n"+
       "in a vain attempt to break free from "+RN()+"'s grasp.\n");
   me()->attack_object(who);
   call_other(me(),"add_hit_point",POSSESS_SPELL/2-random(POSSESS_SPELL/5));
   who->hit_player(POSSESS_SPELL/2-random(POSSESS_SPELL/5));
   return 1;
}

raise(str)  {
   object who;
   if(!str)  {
      write("Who do you want to revive?\n");
      return 1;
   }
   who=find_player(str);
   if(!who || !present(who,environment(me())))  {
      write("No "+capitalize(str)+" here!\n");
      return 1;
   }
   if(!who->query_ghost())  {
      write(who->query_name()+" doesn't seem to need it.\n");
      return 1;
   }
      if(!present("soul-undead",who)&&who->query_guild_name()!="vampire") {
	    write("You can revive only Undead or Vampires!\n");
		  return 1;        
     }                   

   if(me()->query_sp() < RAISE_SPELL)  {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-RAISE_SPELL);
   if(random(101) > 40)  {
      write("Your eyes and your hands start to glow...\n");
      write("The ghost of "+capitalize(str)+" trembles...\n");
      write("You try but nothing happen.\n");
      write("You fail to revive "+capitalize(str)+"!\n");
      say(RN()+"'s eyes and hands start to glow.\n");
      say(RN()+" just fail to revived "+capitalize(str)+" from the death.\n");
      return 1;
   }
   write("Your eyes and your hands start to glow...\n");
   write("The ghost of "+capitalize(str)+" trembles...\n");
   write("The ghost begins to take the shape of "+who->query_name()+"!\n");
   write("You just revived "+capitalize(str)+"!\n"); 
   call_other(who, "remove_ghost", 0);
   tell_object(who,"You feel a very strong force.\n");
   tell_object(who,"You are sucked away...\n");
   tell_object(who,"You reappear in a more solid form.\n");
   say(RN()+"'s eyes and hands start to glow.\n");
   say(RN()+" just revived "+capitalize(str)+" from the death.\n");
   return 1;
}


string wrap_string(string str, int width, int indent) {  
    mixed *brkarg;
    string *outstr;
    string indstr ;
    int i;
    int j;
    int k;
    int gCol;

    brkarg=explode(str,"\n");
    str=implode(brkarg,"");
    if (indent)
     indstr = ""[0..indent-1];
    else        indstr = "";
       gCol = indent;
    outstr = explode(str+" "," ");    
    i=sizeof(outstr);
    while(i<0&&outstr[i]=="") i--;
    if(i) outstr=outstr[0..i];
    else return implode(outstr," ");
    for(i=0; i<sizeof(outstr); i++) {
     if(outstr[i]!="") j = i;
     if(strlen(outstr[i])+gCol > width) {
      k = i;
      while(k<sizeof(outstr)&&outstr[k]=="")
       k++;
      if(j!=k) {
       outstr = outstr[0..j] + outstr[k..sizeof(outstr)];
       i = j+1;
      }
      if(i==sizeof(outstr)) i--;     
      gCol = strlen(indstr) + strlen(outstr[i]) + 1;
      outstr[i] = "\n"+indstr+outstr[i];
     }
     else { gCol += strlen(outstr[i]) + 1; }
    }    
    return implode(outstr," ");
   }


