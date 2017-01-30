#define FOLLOW_SPELL 20
#define VISION_SPELL 30
#define MELT_SPELL 15
#define SEND_SPELL 10
#define SECOND_LEVEL 5000
#define THIRD_LEVEL  10000
#define FOURTH_LEVEL 20000
#define FIFTH_LEVEL 40000
#define SIXTH_LEVEL 80000
#define SEVENTH_LEVEL 160000
#define GUILD_COM 1000000
#define GUILD_CREAT 2000000
#define FOG_SPELL 30
#define LIGHTNING_SPELL 50
#define CHARM_SPELL 20
#define GLARE_SPELL 40
#define SHADOWS_SPELL 40
#define SUCK_SPELL 5
#define GLOW_SPELL 10
#define QGM_SPELL 10
#define QUARTZ_SPELL 10
#define HAND_SPELL 30
#define ANIMATE_SPELL 80
#define EVOKE_SPELL 20
#define CHILL_SPELL 40
#define WEAKEN_SPELL 40
#define FING_SPELL 100
#define KNOW_SPELL 20
#define FEIGN_SPELL 40
#define SCAN_SPELL 10
#define RAISE_SPELL 100
#define LOW_ARMOR_SPELL 40
#define LOW_WEAPON_SPELL 50
#define HIGH_ARMOR_SPELL 60
#define HIGH_WEAPON_SPELL 70
#define HORSE_SPELL 150

query_auto_load() {
   return "/players/hurtbrain/pent.c:";
}

int hide_on;
object name,this;
int flag_follow,lasthp,lastsp,mon_on;
int muffled,touch_spell;
int first;
int glow_turn,glow_flag;
object ex_att;
string inp;
int hand_on;
string morph;
int xsp, xhp;
int num_more;
me() { set_heart_beat(1); return this_player(); }
RN() { return capitalize(me()->query_real_name()); }
rn() { return me()->query_real_name(); }
query_muffle() { return muffled; }
get() { return 1; }
id(str) { return str=="life" | str=="soul-undead"; }
short() { return capitalize(environment(this_object())->query_real_name())+"'s life"; }
long() {
   write("\tThis is the 'UNDEAD' symbol.\n"+
      "Type 'com' for a list of commands.\n");
}

guild_level() { 
   int lev;
   if(!first)  
      lev=me()->query_guild_exp();
   else
      lev=environment(this_object())->query_guild_exp();
   first=1;
   if(lev < SECOND_LEVEL)
      {
      morph="Skeleton";
      lev=1;
   }
   else if(lev < THIRD_LEVEL)
      {
      morph="Zombie";
      lev=2;
   }
   else if(lev < FOURTH_LEVEL)
      {
      morph="Ghoul";
      lev=3;
   }
   else if(lev < FIFTH_LEVEL)
      {
      morph="Shadow";
      lev=4;
   }
   else if(lev < SIXTH_LEVEL)
      {
      morph="Wight";
      lev=5;
   }
   else if(lev < SEVENTH_LEVEL)
      {
      morph="Wraith";
      lev=6;
   }
   else if(lev < GUILD_COM)
      {
      morph="Spectre";
      lev=7;
   }
   else if(lev < GUILD_CREAT)
      {
      morph="Lich";
      lev=50;
   }
   else
      {
      morph="Special";
      lev=100;
   }
   return lev;
}

init() {
   if(!xsp) xsp = 0;
   else xsp = xsp;
   if(!xhp) xhp = 0;
   else xhp = xhp;
   set_heart_beat(1);
   mon_on=0;
   muffled=0;
   first=0;
   touch_spell=guild_level()*5;
   this=this_player();
   hide_on=0;
   add_action("call","call");
   add_action("low_armor","mvest");
   add_action("low_weapon","fball");
   add_action("high_armor","ffield");
   add_action("high_weapon","fwhip");
   add_action("raise","raise");
   add_action("aid","aid");
   add_action("renew","renew");
   add_action("scan","scan");
   add_action("feign","feign");
   add_action("hide","hide");
   add_action("new_command","new_command");
   add_action("new_command2","new_command2");
   add_action("quit","quit");
   add_action("communicate", "say");
#ifndef __LDMUD__
    add_action("communicate"); add_xverb("\"");
#else
    add_action("communicate", "\"", 3);
#endif

#ifndef __LDMUD__
    add_action("communicate"); add_xverb("'");
#else
    add_action("communicate", "'", 3);
#endif
   add_action("inv","i");
   add_action("turn","turn");
   add_action("fog","fog");
   add_action("lightning","lightning");
   add_action("glare","glare");
   add_action("touch","touch");
   add_action("shadows","shadows");
   add_action("charm","charm");
   add_action("set_touch","set_touch");
   add_action("utm","utm");
   add_action("mon","mon");
   add_action("follow","follow");
   add_action("vision","vision");
   add_action("emote","emote");
   add_action("melt","melt");
   add_action("send","send");
   add_action("du","du");
   add_action("ut","ut");
   add_action("ue","ue");
   add_action("com","com");
   add_action("title","title");
   add_action("qgm","qgm");
   add_action("rankme","rankme");
   add_action("suck","suck");
   add_action("glow","glow");
   add_action("quartz","quartz");
   add_action("hand","hand");
   add_action("animate","animate");
   add_action("store_spell_points","ssp");
   add_action("store_hit_points","shp");
   add_action("xpts","stored");
   add_action("get_spell_points","gsp");
   add_action("get_hit_points","ghp");
   add_action("evoke","evoke");
   add_action("chill","chill");
   add_action("weaken","weaken");
   add_action("fing","fing");
   add_action("do_compare","know");
	add_action("horse","horse");
}

set_touch(str)  {
   int num;
   if(!str)  {
      notify_fail("Usage: set_touch <number>\n");
      return 0;
   }
   if(!sscanf(str,"%d",num))
      {
      notify_fail("You have to write a number.\n");
      return 0;
   }
   if(num < 0 || num > guild_level()*5)
      {
      notify_fail("Number not in available range.\n");
      return 0;
   }
   write("Power of touch set to "+num+".\n");
   touch_spell=num;
   return 1;
}

utm()  {
   if(!muffled)  {
      write("Guild messages muffled.\n");
      muffled=1;
   }
   else  {
      write("Ear muffle off.\n");
      muffled=0;
   }
   return 1;
}

drop() {
   write("Life -- That would not be a good idea.\n");
   return 1;
}
com(str) {
   if(str)  return;
   if(!num_more)  num_more=1;
   if(num_more<5)  {
      cat("/players/hurtbrain/helpdir/pent"+num_more+".com");
      if(num_more < 4)  {
         write("More (q or Q to exit):");
         input_to("more");
      }
      else num_more=0;
      ++num_more;
      return 1;
   }
   return 1;
}
more(arg)  {
   if(arg=="q" || arg=="Q")  {
      num_more=1;     
      write("\n");
   }
   else  {
      inp=arg;
      com();
   }
   return 1;
}
ut(str) {
   object us;
   int x;
   if(!str) return;
   if(muffled)  {
      notify_fail("The channel is muffled.\n");
      return 0;
   }
   us=users();
   for(x=0;x<sizeof(us); x++) {
      if(present("soul-undead",us[x]) && !call_other(present("soul-undead",us[x]),"query_muffle"))
         tell_object(us[x],"{[ "+RN()+" ]} "+str+"\n");
   }
   return 1;
}
ue(str) {
   object us;
   int x;
   if(!str) return;
   if(muffled)  {
      notify_fail("The channel is muffled.\n");
      return 0;
   }
   us=users();
   for(x=0;x<sizeof(us);x++) {
      if(present("soul-undead",us[x]) && !call_other(present("soul-undead",us[x]),"query_muffle"))
         tell_object(us[x],"->> "+RN()+" "+str+"\n");
   }
   return 1;
}
du(str) {
   object us;
   int x;
   int lev;
   if(str) return;
   write("Name---------G.Level----Location--------------------------------------\n");
   us=users();
   for(x=0;x<sizeof(us);x++) {
      if(present("soul-undead",us[x])) {
         write(capitalize(us[x]->query_real_name()));
         if(strlen(us[x]->query_real_name())>7)
            write("\t"); else write("\t\t");
         lev=call_other(present("soul-undead",us[x]),"guild_level");
         write(lev+" ");
         if(call_other(present("soul-undead",us[x]),"query_muffle"))
            write("m");
         write("\t");
         write(environment(us[x])->short());
         write("\n");
       }
   }
   return 1;
}
turn(str) {
   if(!str) return;
   sscanf(str,"%s undead",str);
   if(!find_living(str)) {
      write("Life: I could not find '"+str+"'\n");
      return 1;
   }
   move_object(clone_object("/players/hurtbrain/pent.c"),find_living(str));
   tell_object(find_living(str),RN()+" has just given you a new life.\n");
   write("Done.\n");
   return 1;
}

follow(str)  {
   if (!str)
      if( flag_follow==1)  {
      write("Follow off.\n");
      flag_follow=0;
      return 1;
   }
   else {
      write("You are not following anyone.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < FOLLOW_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   name=present(str,environment(me()));
   if(!name)  {
      notify_fail("No "+str+" here!\n");
      return 0;
   }
   if(flag_follow==1)
      write("You are no longer following "+call_other(name,"query_name")+".\n");
   flag_follow=1;
   call_other(me(),"add_spell_point",-FOLLOW_SPELL);
   this=me();
   write("You now are following "+capitalize(str)+".\n");
   return 1;
}

heart_beat()  { 
   object att;
   int hit;
   if(flag_follow==1)  {
      if(environment(this)!=environment(name))  {
         move_object(this,environment(name));
         command("look",this);
      }
   }
   if((mon_on==1) && (lasthp!=this->query_hp() || lastsp!=this->query_sp() ))  {
      tell_object(this,
         "Hp:["+this->query_hp()+"/"+this->query_mhp()+"]  " +
         "Sp:["+this->query_sp()+"/"+this->query_msp()+"]  \n" );
      lasthp=this->query_hp();
      lastsp=this->query_sp();
   }
   if(glow_flag)  {
      --glow_turn;
      if(!glow_turn)  {
         tell_object(this,"Your body slowly stops glowing.\n");
         tell_room(environment(this),this->query_name()+" stops glowing.\n");
         glow_flag=0;
         set_light(-1);
      }
   }
   if(hand_on)  {
      att=call_other(this,"query_attack");
      if(att->query_hp()<HAND_SPELL || !att || att!=ex_att || (this->query_sp() <= 0))  {
         tell_object(this,"The magical hand disappears in a puff of smoke.\n");
         hand_on=0;
      }
      else  {
         tell_object(this,"Your hand hits "+att->query_name()+".\n");
         hit=att->hit_player(HAND_SPELL);
         call_other(this,"add_spell_point",-hit);
      }
   }
   if(find_living("sph_"+this->query_name()) && find_living("morph_"+this->query_name()) && !interactive(this))  {
      destruct(find_living("morph_"+lower_case(me()->query_name())));
      destruct(find_living("sph_"+lower_case(me()->query_name())));
      hide_on=0;
   }
}


vision(str) {
   object ob, ob_tmp, pla;
   string item;
   string it;
   int max;
   if (!str) {
      notify_fail("Who do you want to vision?\n");
      return 0;
   }
   if(call_other(me(),"query_sp") < VISION_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   pla=find_player(str);
   if(!pla)  {
      notify_fail("No "+str+" on!\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-VISION_SPELL);
   write("**********************************************************\n");
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
      notify_fail("Usage: melt <item>\n");
      return 0;
   }
   obj=present(str,me());
   if(!obj)  {
      notify_fail("What do you want to melt?\n");
      return 0;
   }
   value=obj->query_value();
   if (!value) {
      write("You can't melt worthless things!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < MELT_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
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
   object stuff1,rece1;
   if((!str) || ((sscanf(str,"%s %s",stuff,rece) !=2)))
      {   notify_fail("You fail to send.\n");
      return 0;
   }
   if(!present(stuff) || !find_living(rece))
      {   notify_fail("Stuff or receiver not present.\n");
      return 0;
   }
   if(present(stuff)->drop())  {
      notify_fail("You can't send this object.\n");
      return 0;
   }
   if(call_other(me(),"query_sp") < SEND_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   rece1=find_living(rece);
   stuff1=present(stuff);
   if(!present("soul-undead",rece1)) {
      notify_fail("You can send only to a guild mate!\n");
      return 0;
   }
   move_object(stuff1,rece1);
   tell_object(rece1,"A spirit arrives and gives you a "+stuff+" from "+RN()+".\n");
   write("You send a "+stuff+" to "+rece1->query_name()+".\n");
   call_other(me(),"add_spell_point",-SEND_SPELL);    
   return 1;
}


mon()  {
   if(mon_on)
      {
      mon_on=0;
      write("Guild monitor off.\n");
   }
   else {
      mon_on=1;
      write("Guild monitor on.\n");
      lasthp=call_other(me(),"query_hp");
      lastsp=call_other(me(),"query_sp");
      this=me();
   }
   return 1;
}


fog(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         notify_fail("Who do you want to fog?\n");
         return 0;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         notify_fail("No "+capitalize(arg)+" here.\n");
         return 0;
      }
      who=find_living(arg);
      if(!who)  {
         notify_fail("You can't attack objects.\n");
         return 0;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         notify_fail("You can't attack "+who->query_name()+".\n");
         return 0;
      }
   }
   if(call_other(me(),"query_sp") < FOG_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-FOG_SPELL);
   write("You cast a magical fog on "+who->query_name()+".\n");
   say("A black fog invades the room and starts to choke "+who->query_name()+".\n");
   who->attack_object(me());
   who->hit_player(FOG_SPELL);
   return 1;
}


lightning(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         notify_fail("Who do you want to lightning?\n");
         return 0;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         notify_fail("No "+capitalize(arg)+" here.\n");
         return 0;
      }
      who=find_living(arg);
      if(!who)  {
         notify_fail("You can't attack objects.\n");
         return 0;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         notify_fail("You can't attack "+who->query_name()+".\n");
         return 0;
      }
   }
   if(call_other(me(),"query_sp") < LIGHTNING_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-LIGHTNING_SPELL);
   write("You cast a black lightning on "+who->query_name()+".\n");
   say(RN()+" releases a black bolt of energy and "+who->query_name()+" staggers.\n");
   who->attack_object(me());
   who->hit_player(LIGHTNING_SPELL);
   return 1;
}


shadows(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         notify_fail("Who do you want to shadows?\n");
         return 0;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         notify_fail("No "+capitalize(arg)+" here.\n");
         return 0;
      }
      who=find_living(arg);
      if(!who)  {
         notify_fail("You can't attack objects.\n");
         return 0;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         notify_fail("You can't attack "+who->query_name()+".\n");
         return 0;
      }
   }
   if(call_other(me(),"query_sp") < SHADOWS_SPELL-10) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   obj=present("quartz",me());
   if(!obj)  {
      notify_fail("You need a magical quartz to shadows someone!\n");
      return 0;
   }
   destruct(obj);
   write("As you pronounce the magical words the quartz glows and crumbles away.\n");
   call_other(me(),"add_spell_point",-SHADOWS_SPELL-10);
   write("You summon the shadows from the depth of the earth.\n");
   write("The shadows attack "+who->query_name()+".\n");
   who->attack_object(me());
   who->hit_player(SHADOWS_SPELL);
   say("You see "+who->query_name()+"surrounded by "+RN()+"'s shadows.\n");
   return 1;
}


glare(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         notify_fail("Who do you want to glare?\n");
         return 0;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         notify_fail("No "+capitalize(arg)+" here.\n");
         return 0;
      }
      who=find_living(arg);
      if(!who)  {
         notify_fail("You can't attack objects.\n");
         return 0;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         notify_fail("You can't attack "+who->query_name()+".\n");
         return 0;
      }
   }
   if(call_other(me(),"query_sp") < GLARE_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-GLARE_SPELL);
   write("You gaze "+who->query_name()+" in the eyes and he starts to hit himself!\n");
   say("As "+RN()+" gazes "+who->query_name()+" the monster starts to hit himself.\n");
   who->attack_object(me());
   who->hit_player(GLARE_SPELL);
   return 1;
}


charm(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         notify_fail("Who do you want to charm?\n");
         return 0;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         notify_fail("No "+capitalize(arg)+" here.\n");
         return 0;
      }
      who=find_living(arg);
      if(!who)  {
         notify_fail("You can't attack objects.\n");
         return 0;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         notify_fail("You can't attack "+who->query_name()+".\n");
         return 0;
      }
   }
   if(call_other(me(),"query_sp") < CHARM_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-CHARM_SPELL);
   write("You charm "+who->query_name()+" and smash its head against your knee.\n");
   say(who->query_name()+" seems to be stunned.\n");
   say(RN()+" smashes "+who->query_name()+"'s head against his knee.\n");
   who->attack_object(me());
   who->hit_player(CHARM_SPELL);
   return 1;
}


touch(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         notify_fail("Who do you want to touch?\n");
         return 0;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         notify_fail("No "+capitalize(arg)+" here.\n");
         return 0;
      }
      who=find_living(arg);
      if(!who)  {
         notify_fail("You can't attack objects.\n");
         return 0;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         notify_fail("You can't attack "+who->query_name()+".\n");
         return 0;
      }
   }
   if(call_other(me(),"query_sp") < touch_spell) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-touch_spell);
   write("As you touch "+who->query_name()+", he seems to lose power.\n");
   say(RN()+" touches "+who->query_name()+" which seems to grow weaker.\n");
   who->attack_object(me());
   who->hit_player(touch_spell);
   return 1;
}


title(arg)  {
   if(!arg) {
      call_other(me(),"set_title","");
      write("Your title is now clear.\n");
      return 1;
   }
   call_other(me(),"set_title",arg);
   write("Your title is now:\n"+arg+".\n");
   return 1;
}

rankme()  {
   int lev;
   lev=guild_level();
   write(RN()+" the "+morph+".\n");
   write("Guild level: "+lev+".\n");
   write("Guild experience: "+me()->query_guild_exp()+".\n");
   write("Current morph: ");
   if(!hide_on)
      write("None.\n");
   else
      write(morph+".\n");
   write("Touch power: "+touch_spell+".\n");
   return 1;
}


suck()  {
   object corpse;
   int heal;
   corpse=present("corpse",environment(me()));
   if(!corpse)  {
      notify_fail("No corpse here.\n");
      return 0;
   }
   if(call_other(me(),"query_sp") < SUCK_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-SUCK_SPELL);
   heal=corpse->heal_value();
   me()->heal_self(heal);
   write("You suck energy from the corpse.\nThe corpse shrivels up and disappears.\n");
   say(RN()+"sucks energy from a corpse.\nThe corpse shrivels up and disappears.\n");
   destruct(corpse);
   return 1;
}


glow()  {
   glow_turn=50;
   if(call_other(me(),"query_sp") < GLOW_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-GLOW_SPELL);
   write("Your body begins to emit a soft glow enabling you to see.\n");
   say(RN()+" starts to glow.\n");
   glow_flag=1;
   this=me();
   set_light(1);
   return 1;
}

qgm(arg)  {
   int lev;
   object mate;
   string m_morph;
   mate=find_player(arg);
   if(!mate)  {
      notify_fail("No "+arg+" on.\n");
      return 0;
   }
   if(!present("soul-undead",mate)) {
      notify_fail(mate->query_name()+" is not an undead.\n");
      return 0;
   }
   if(call_other(me(),"query_sp") < QGM_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-QGM_SPELL);
   lev=mate->query_guild_exp();
   if(lev < SECOND_LEVEL)
      {
      m_morph="Skeleton";
      lev=1;
   }
   else if(lev < THIRD_LEVEL)
      {
      m_morph="Zombie";
      lev=2;
   }
   else if(lev < FOURTH_LEVEL)
      {
      m_morph="Ghoul";
      lev=3;
   }
   else if(lev < FIFTH_LEVEL)
      {
      m_morph="Shadow";
      lev=4;
   }
   else if(lev < SIXTH_LEVEL)
      {
      m_morph="Wight";
      lev=5;
   }
   else if(lev < SEVENTH_LEVEL)
      {
      m_morph="Wraith";
      lev=6;
   }
   else if(lev < GUILD_COM)
      {
      m_morph="Spectre";
      lev=7;
   }
   else if(lev < GUILD_CREAT)
      {
      m_morph="Lich";
      lev=50;
   }
   else
      {
      m_morph="Special";
      lev=100;
   }
   write(capitalize(mate->query_real_name()));
   write(" the "+m_morph+".\n");
   write("Guild level: "+lev+".\n");
   write("Guild experience: "+mate->query_guild_exp()+".\n");
   return 1;
}

quartz()  {
   object quartz;
   if(call_other(me(),"query_sp") < QUARTZ_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-QUARTZ_SPELL);      
   wrtheme("You raise your hands and a magical quartz appears in it.\n");
   say(RN()+" closes his eyes and a quartz magically appears.\n");
   quartz=clone_object("/players/hurtbrain/guild/quartz.c");
   move_object(quartz,me());
   return 1;
}


hand()  {
   object obj;
   obj=call_other(me(),"query_attack");
   if(!obj) {
      notify_fail("You are not fighting anyone.\n");
      return 0;
   }
   if(hand_on)  {
      write("The magical hand stops fighting and disappears.\n");
      hand_on=0;
      return 1;
   }
   write("A hand rises from the dead earth and clinches "+call_other(obj,"query_name")+".\n");
   write("A hand magically appears near you. The hand starts to massacre "+call_other(obj,"query_name")+".\n");
   ex_att=me()->query_attack();
   hand_on=1;
   this=me();
   return 1;
}


animate(arg)
{ object corpse;
   string name;
   object zom;
   if(arg!="dead")  {
      notify_fail("What do you want to animate?\n");
      return 0;
   }
   corpse=present("corpse",environment(this_player()));
   if(!corpse) { write("No corpse here.\n"); return 1; }
   if(this_player()->query_sp()<ANIMATE_SPELL){
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-ANIMATE_SPELL);
   sscanf(call_other(corpse,"short"),"corpse of %s",name);
   zom=clone_object("/players/trix/castle/guild/zombie");
   call_other(zom, "set_ac", 1+(17*(corpse->heal_value())/19));
   call_other(zom, "set_level",3);
   call_other(zom, "set_ep",2283);
   call_other(zom, "set_hp",50+(250*(corpse->heal_value())/19));
   call_other(zom, "set_wc",5+(25*(corpse->heal_value())/19));
   call_other(zom, "set_myname",name);
   call_other(zom, "set_info","z_"+rn());
   call_other(zom, "set_master",this_player());
   move_object(zom,environment(this_player()));
   call_other(zom,"toggle_follow");
   write("You summon a zombie from the depth of the earth.\n");
   say(RN()+" summons a zombie.\n");
   destruct(corpse);
   return 1;
}

store_spell_points(amt){
   int num;
   if(!amt){
      write("How many spell points do you want to store?\n");
      return 0;
   }
   else if(sscanf(amt,"%d",num)==1){
      if(num*2>me()->query_sp()){
         write("You don't have that many spell points!\n");
         return 1;
         }
      me()->add_spell_point(-(num*2));
      xsp = xsp+num;
      write("You store "+num+" spell points.\n");
      write("You now have "+xsp+" stored sp.\n");
      return 1;
   }
   else return 0;
}
store_hit_points(amt){
   int num;
   if(!amt){
      write("How many hit points do you want to store?\n");
      return 0;
   }
   else if(sscanf(amt,"%d",num)==1){
      if(me()->query_hp() - 50 < num*2){
         write("You wouldn't want your hit points to get too low.\n");
         return 1;
         }
      else {
         me()->add_hit_point(-(num*2));
         xhp = xhp+num;
         write("You store "+num+" hit points.\n");
         write("You now have "+xhp+" stored hp.\n");
         return 1;
         }
   }
   else return 0;
}
xpts(){
   write("XHP: "+xhp+"\tXSP: "+xsp+"\n");
   return 1;
}
get_spell_points(amt){
   int num;
   if(!amt){
      write("How many spell points do you want to get?\n");
      return 0;
   }
   else if(sscanf(amt,"%d",num)==1){
      if(num>xsp){
         write("You don't have that many spell points stored.\n");
         return 1;
         }
      else {
         xsp = xsp-num;
         me()->add_spell_point(num);
         write("You get "+num+" spell points.\n");
         return 1;
         }
   }
   else return 0;
}
get_hit_points(amt){
   int num;
   if(!amt){
      write("How many hit points do you want to get?\n");
      return 0;
   }
   else if(sscanf(amt,"%d",num)==1){
      if(num>xhp){
         write("You don't have that many hit points stored.\n");
         return 1;
         }
      else{
         xhp=xhp-num;
         me()->add_hit_point(num);
         write("You get "+num+" hit points.\n");
         return 1;
         }
   }
   else return 0;
}
query_xsp(){ return xsp; }
query_xhp(){ return xhp; }

evoke()  {
   object ppl,ppl1;
   ppl = first_inventory(environment(me()));
   write("You evoke the death upon the room!\n");
   say(RN()+" evokes the death upon the room.\n");
   while(ppl) {
      ppl1 = next_inventory(ppl);
      if(call_other(me(),"query_sp") < EVOKE_SPELL) {
         notify_fail("You don't have enough spell points.\n");
         return 0;
         }
      if(ppl!=me() && ppl->query_info()!="z_"+rn())
         if((ppl->query_npc()==1) || ((ppl->query_pl_k()==1) && (me()->query_pl_k()==1)))
         {
         call_other(ppl,"attack_object",me());
         ppl->hit_player(EVOKE_SPELL);
         call_other(me(),"add_spell_point",-EVOKE_SPELL);
         }
      ppl = ppl1;
   }
   return 1;
}


chill(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         notify_fail("Who do you want to chill?\n");
         return 0;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         notify_fail("No "+capitalize(arg)+" here.\n");
         return 0;
      }
      who=find_living(arg);
      if(!who)  {
         notify_fail("You can't attack objects.\n");
         return 0;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         notify_fail("You can't attack "+who->query_name()+".\n");
         return 0;
      }
   }
   if(call_other(me(),"query_sp") < CHILL_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-CHILL_SPELL);
   write(who->query_name()+"'s power seems to decrease.\n");
   say(RN()+" makes a gesture and "+who->query_name()+"'s power seems to decrease.\n");
   who->attack_object(me());
   call_other(who,"set_wc",who->query_wc()-1);
   return 1;
}


weaken(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         notify_fail("Who do you want to weaken?\n");
         return 0;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         notify_fail("No "+capitalize(arg)+" here.\n");
         return 0;
      }
      who=find_living(arg);
      if(!who)  {
         notify_fail("You can't attack objects.\n");
         return 0;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         notify_fail("You can't attack "+who->query_name()+".\n");
         return 0;
      }
   }
   if(call_other(me(),"query_sp") < WEAKEN_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-WEAKEN_SPELL);
   write(who->query_name()+"'s armor starts to melt.\n");
   say(RN()+" makes a gesture and "+who->query_name()+"'s armor starts to melt.\n");
   who->attack_object(me());
   call_other(who,"set_ac",who->query_ac()-1);
   return 1;
}


fing(arg)  {
   object who,obj;
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         notify_fail("Who do you want to fing?\n");
         return 0;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         notify_fail("No "+capitalize(arg)+" here.\n");
         return 0;
      }
      who=find_living(arg);
      if(!who)  {
         notify_fail("You can't attack objects.\n");
         return 0;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         notify_fail("You can't attack "+who->query_name()+".\n");
         return 0;
      }
   }
   if(call_other(me(),"query_sp") < FING_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-FING_SPELL);
   write("You point your finger and "+who->query_name()+" starts to tremble.\n");
   say(RN()+" points his finger and "+who->query_name()+" starts to tremble.\n");
   who->attack_object(me());
   who->hit_player(who->query_hp()/10);
   return 1;
}



hide () {
   object mons,sph;
   object att;
   if(find_living("sph_"+lower_case(me()->query_name())) && find_living("morph_"+lower_case(me()->query_name())))  hide_on=1;
   else hide_on=0;
   if(!hide_on)
      {
      write("You hide into your soul! Your corpse turns into a "+morph+".\n");
      say(me()->query_name()+" takes a breath and turns into a "+morph+".\n");
      mons=clone_object("/players/hurtbrain/guild/morph.c");
      sph=clone_object("/players/hurtbrain/guild/sphere.c");
      call_other(mons,"set_name",lower_case(morph));
      call_other(mons,"set_short","A "+morph);
      call_other(mons,"set_alias","morph_"+lower_case(me()->query_name()));
      call_other(mons,"set_info","sph_"+lower_case(me()->query_name()));
      call_other(sph,"set_alias","sph_"+lower_case(me()->query_name()));
      call_other(sph,"set_short","Sphere of "+me()->query_name());
      call_other(sph,"set_info",lower_case(me()->query_name()));
      move_object(sph,environment(me()));
      move_object(mons,environment(me()));
      move_object(me(),sph);
      move_object(sph,mons);
      hide_on=1;
      tell_object(me(),"HIDDEN ->> ");
      input_to("read");
   }
   else {
      command("drop a_pass",me());
      move_object(me(),environment(find_living("morph_"+lower_case(me()->query_name()))));
      destruct(find_living("morph_"+lower_case(me()->query_name())));
      destruct(find_living("sph_"+lower_case(me()->query_name())));
      hide_on=0;
      write("You are no longer hidden.\n->> ");
      say("The "+morph+" takes a breath and turns into "+me()->query_name()+".\n");
      att=first_inventory(environment(me()));
      while (att)  {
         if(call_other(att,"query_hunted")==me())
            call_other(att,"attack_object",me());
         att=next_inventory(att);
      }
   }
   return 1;
}

read(str)  {
   object ex_env,str2;
   if(str=="quit" || str=="say" || str=="i" || str=="'")
      command(str,me());
   else if(str && str!="new_command")  {
      ex_env=environment(find_living("morph_"+lower_case(me()->query_name())));
      call_other(find_living("morph_"+lower_case(me()->query_name())),"set_com",str);
      command(str,find_living("morph_"+lower_case(me()->query_name())));
      if(environment(find_living("morph_"+lower_case(me()->query_name())))!=ex_env)
         command("look",find_living("morph_"+lower_case(me()->query_name())));
   }
   tell_object(me(),"HIDDEN ->> ");
   if(str!="hide" && str!="new_command")   input_to("read");
   return 1;
}

quit()  {
   object obj;
   obj=find_living("zombie_"+lower_case(me()->query_name()));
   if(hide_on)
      command("hide",me());
   if(obj)
      command("peace str",me());
}

new_command()  {
   return 1;
}

new_command2()   {
   input_to("read");
   return 1;
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


communicate(str) {
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
         notify_fail("That is not on the MUD!\n");
         return 0;
      }
      if(enemy==this_player())                          
         {
         notify_fail("You cannot compare yourself !!\n");
         return 0;
      }
      if(me()->query_sp()<KNOW_SPELL) {
         notify_fail("You don't have enough spell points.\n");
         return 0;
      }
      call_other(me(),"add_spell_point",-KNOW_SPELL);
      enemy_name=capitalize(enemy->query_name());
      enemy_sp=enemy->query_sp();   
      enemy_hp=enemy->query_hp();   
      enemy_lv=enemy->query_level();
      enemy_ac=call_other(enemy,"query_ac",);
      enemy_wc=call_other(enemy,"query_wc",);
      pl_sp=this_player()->query_sp  ();   
      pl_hp=this_player()->query_hp();   
      pl_lv=this_player()->query_level();   
      
      pl_ac=call_other(this_player(),"query_ac",);  
      pl_wc=call_other(this_player(),"query_wc",);
      
      write("You concentrate for a moment.\n");
      write("Your eyes become red.\n");
      write("Your Undead powers allow you to know that:\n");
      say(capitalize(this_player()->query_name())+"'s eyes start to shine and become red.\n");
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
         write("Ac : You have the same armor class as "+enemy_name+".\n");
      else if(diff_ac<-5)
         write("Ac : "+enemy_name+" kicks your ass!\n"); 
      else
         write("Ac : "+enemy_name+" is stronger then you.\n");
      if (diff_wc>5) 
         write("Wc : You kick "+enemy_name+"'s ass!\n");
      else if(diff_wc>0)
         write("Wc : You are stronger then "+enemy_name+".\n");
      else if(diff_wc==0)
         write("Wc : You have the same weapon class as "+enemy_name+".\n");
      else if(diff_wc<-5)
         write("Wc : "+enemy_name+" kicks your ass!\n"); 
      else
         write("Wc : "+enemy_name+" is stronger then you.\n");
      if (diff_lv>5) 
         write("Level : You kick "+enemy_name+"'s ass!\n");
      else if(diff_lv>0)
         write("Level : You are stronger then "+enemy_name+".\n");
      else if(diff_lv==0)
         write("Level : You are the same level as "+enemy_name+".\n");
      else if(diff_lv<-5)
         write("Level : "+enemy_name+" kicks your ass!\n"); 
      else
         write("Level : "+enemy_name+" is stronger then you.\n");
      
      return 1;
   }                                             
   write("Usage: know <monster>\n");
   return 1;
}

feign()  {
   object obj;
   if(call_other(me(),"query_sp") < FEIGN_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
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
      notify_fail("What do you want to scan?\n");
      return 0;
   }
   obj=find_living(str); 
   if(!obj)  {
      notify_fail("No "+str+" on.\n");
      return 0;
   }
   if(call_other(me(),"query_sp") < SCAN_SPELL) { 
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-SCAN_SPELL); 
   write("You gaze into "+capitalize(str)+"'s eyes and see:\nHp left: "+
      call_other(obj,"query_hp",)*100/call_other(obj,"query_mhp",)+"%.\n");
   return 1; 
}
renew()  {
   object obj;
   if(hide_on)
      command("hide",me());
   write("Resetting hp and sp stored.\n");
   write("Refreshing life.\n");
   obj=clone_object("/players/hurtbrain/pent.c");
   move_object(obj,me());
   destruct(this_object());
   return 1;
}

aid(str)  {
   int points;
   string name;
   object who;
   if(!str)  {
      notify_fail("Usage : aid <player> <nn>.\n");
      return 0;
   }
   if (sscanf(str,"%s %d",name,points)!=2)  {
      notify_fail("Usage : aid <player> <nn>.\n");
      return 0;
   }
   who=find_player(name);
   if(!who)  {
      notify_fail("No "+capitalize(name)+" on.\n");
      return 0;
   }
   if(points<0 || points>me()->query_sp())  {
      notify_fail("Spell points out of range.\n");
      return 0;
   }
   call_other(who,"add_spell_point",points);
   call_other(me(),"add_spell_point",-points);
   write("You aid "+who->query_name()+", and send him "+points+" spell points.\n");
   tell_object(who,RN()+" helps you and sends you "+points+" spell points.\n");
   return 1;
}

raise(str)  {
   object who;
   if(!str)  {
      notify_fail("Who do you want to raise?\n");
      return 0;
   }
   who=find_player(str);
   if(!who || !present(who,environment(me())))  {
      notify_fail("No "+capitalize(str)+" here!\n");
      return 0;
   }
   if(!who->query_ghost())  {
      notify_fail(who->query_name()+" doesn't seem to need it.\n");
      return 0;
   }
   if(me()->query_sp() < RAISE_SPELL)  {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-RAISE_SPELL);
   if(random(101) > 50)  {
      write("Your eyes and hands start to glow...\n");
      write("The ghost of "+capitalize(str)+" trembles...\n");
      write("You try but nothing happens.\n");
      write("You fail to raise "+capitalize(str)+"!\n");
      say(RN()+"'s eyes and hands start to glow.\n");
      say(RN()+" just fail to raised "+capitalize(str)+" from the dead.\n");
      return 1;
   }
   write("Your eyes and your hands start to glow...\n");
   write("The ghost of "+capitalize(str)+" trembles...\n");
   write("The ghost begins to take the shape of "+who->query_name()+"!\n");
   write("You just raised "+capitalize(str)+"!\n");
   call_other(who, "remove_ghost", 0);
   tell_object(who,"You feel a very strong force.\n");
   tell_object(who,"You are sucked away...\n");
   tell_object(who,"You reappear in a more solid form.\n");
   say(RN()+"'s eyes and hands start to glow.\n");
   say(RN()+" just raised "+capitalize(str)+" from the dead.\n");
   return 1;
}
low_armor()  {
   object obj;
   if(call_other(me(),"query_sp") < LOW_ARMOR_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-LOW_ARMOR_SPELL);
   write("You utter some words unknown to the living and a magical vest appears.\n");
   say(RN()+" utters unknown words and a magical vest appears.\n");
   obj=clone_object("/players/hurtbrain/guild/vest");
   move_object(obj,me());
   return 1;
}

low_weapon()  {
   object obj;
   if(call_other(me(),"query_sp") < LOW_WEAPON_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-LOW_WEAPON_SPELL);
   write("You utter some words unknown to the living and a ball of fire appears.\n");
   say(RN()+" utters unknown words and creates a ball of fire.\n");
   obj=clone_object("/players/hurtbrain/guild/ball");
   move_object(obj,me());
   return 1;
}

high_armor()  {
   object obj;
   if(call_other(me(),"query_sp") < HIGH_ARMOR_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-HIGH_ARMOR_SPELL);
   write("You magically create a force field!\n");
   say(RN()+" magically creates a force field.\n");
   obj=clone_object("/players/hurtbrain/guild/field");
   move_object(obj,me());
   return 1;
}

high_weapon()  {
   object obj;
   if(call_other(me(),"query_sp") < HIGH_WEAPON_SPELL) {
      notify_fail("You don't have enough spell points.\n");
      return 0;
   }
   call_other(me(),"add_spell_point",-HIGH_WEAPON_SPELL);
   write("You utter some words unknown to the living and a firewhip appears.\n");
   say(RN()+" utters unknown words and creates a firewhip.\n");
   obj=clone_object("/players/hurtbrain/guild/whip");
   move_object(obj,me());
   return 1;
}
call()  {
   object obj;
   obj=find_living("zombie_"+lower_case(RN()));
   if(!obj)  {
      notify_fail("No zombie to call.\n");
      return 0;
   }
   tell_room(obj,"As you hear a whistle "+obj->query_name()+" shade off from your view.\n");
   move_object(obj,environment(me()));
   say(obj->query_name()+" appears near his master, "+RN()+".\n");
   write("Your zombie arrives and stands at your side.\n");
   return 1;
}
horse() {
	object horse, ob;
	if(call_other(me(),"query_sp") < HORSE_SPELL) {
	  notify_fail("You don't have enough spell points.\n");
	  return 0;
	}
	call_other(me(),"add_spell_point",-HORSE_SPELL);
	horse=clone_object("/players/dragnar/closed/horse.c");
	ob=this_player();
	move_object(horse, environment(this_player()));
	horse->set_owner(ob);
	write("Some bones emerge from the earth and assemble into a skeleton horse.\n");
	say(capitalize(ob->query_real_name())+" mumbles some unknown words and bones emerge from the ground to form a skeleton horse.\n");
}
