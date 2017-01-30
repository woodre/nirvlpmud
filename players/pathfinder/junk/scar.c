#define SAVE_PATH "players/dragnar/kills/"
#define user environment(this_object())
#define att user->query_attack()
#define attname att->query_real_name()
#define meme this_player()->query_real_name()+"dragon"
#define ahp att->query_hp()
#define ENVTO environment(this_object())
#define RN user->query_real_name()
static int muffled;
static string checker;
int pkills,pdeaths;
id(str) { return str == "scar" || str =="bloodscar"; }
query_auto_load() {
   return "/players/dragnar/closed/scar.c:"; }
short() {
   return "Blood scar of Mortal Kombat";
}
long() {
   write("This is the scar you recieved when you became a champion of Mortal\n"+
      "Kombat.  The scar means you are worthy of the powers it possesses.  Type\n"+
      "infoscar to see what the scar enables you to do.\n");
}
set_pdeaths(ob) { pdeaths=ob; }
set_pkills(ks) { pkills=ks; }
set_muffled(mf) { muffled=mf; }
hb() {
   if(present("bloodscar 2", user)){
      tell_object(user, "Resetting scar...\n");
      destruct(this_object());
   }
   if(att) {
      checker=att->query_real_name();
   }
   if(present("ghost of "+checker+"", environment(user))){
      object ob;
      command("ddeeaatthhmmee", find_player(checker));
      ob=clone_object("players/dragnar/deathme.c");
      move_object(ob, find_player(checker));
      pkills=pkills+1;
      tell_object(user, "You have killed "+checker+" and gain one kill!\n");
      command("tell_scar",user);
      command("save_me",user);
      command("new_scar", user);
   }
   call_out("hb",2);
}
init() {
   restore_me();
   call_out("hb",2);
	add_action("heal_scar","heal_scar");
	add_action("give_scar","give_scar");
   add_action("punt","punt");
   add_action("deathmatch","deathmatch");
   add_action("help","help");
   add_action("new_scar","new_scar");
   add_action("infoscar","infoscar");
   add_action("angel_tell","bdt");
   add_action("angel_tell_silence","bts");
   add_action("angel_emote","bbe");
   add_action("angel_who","blood");
   add_action("restore_me","restore_me");
   add_action("save_me","save_me");
   add_action("stats","stats");
   add_action("ddeeaatthhmmee","ddeeaatthhmmee");
   add_action("tell_scar","tell_scar");
}
infoscar() {
   write("\n");
   write("================================================================================\n");
   write("	SPELL			FUNCTION			COST\n");
   write("================================================================================\n");
   write("bdt			Blood tell to members			None\n");
   write("blood			See other members on			None\n");
   write("bbe			Blood emote to members			None\n");
   write("bts\t\t\tBlood tell silence\t\t\tNone\n");
   write("deathmatch <playername>\tChallenge a member to fight\t\tNone\n");
   write("stats\t\t\tSee the stats of members\t\tNone\n");
   write("new_scar\t\tGet a new scar\t\t\t\tNone\n");
   write("restore_me\t\tRestore your kill stats\t\t\tNone\n");
   write("save_me\t\t\tSave your kill stats\t\t\tNone\n");
   write("help scar\t\tInformation on stats\t\t\tNone\n");
	write("heal_scar\t\tGet rid of your scar\t\t\tNome\n");
   write("===============================================================================\n");
   return 1;
}
drop() { return 1; }
get() { return 1; }
query_value() {return 0; }
angel_emote(str) {
   int i;
   object people, sex;
   
   if(!str) {
      write("Guild emote what?\n");
      return 1;
   }
   people = users();
   for(i = 0; i<sizeof(people); i++) {
      sex=(present("bloodscar",people[i]));
      if(sex && sex->query_muffled() < 1) {
         tell_object(people[i], "\n<>: "+capitalize(this_player()->query_real_name())+" "+str+"\n");
       }
   }
   return 1;
}


angel_tell_silence(str) {
   if(!str) {
      write("Useage: ats <on/off>\n");
      return 1;
   }
   if(str == "on") {
      if(muffled == 1) {
         write("You already are muffled.\n");
         return 1;
      } else
         muffled = 1;
      write("You are now muffled.\n");
      return 1;
   }
   if(str == "off") {
      if(muffled == 0) {
         write(" You were not muffled.\n");
         return 1;
      } else
         muffled=0;
      write("You are now on the blood channel.\n");
      return 1;
   }
}


stats() {
   object list,scar;
   int i;
   list=users();
   write("\n================================================================================\n");
   write("NAME:\t\tRANK:\tLEVEL:\tEX_LEV:\tKILLS:\tDEATHS:\n");
   write("================================================================================\n");
   for(i=0; i < sizeof(list); i++) {
      scar=present("bloodscar",list[i]);
      if(scar) {
         write(capitalize(list[i]->query_real_name()));
         if(strlen(list[i]->query_real_name()) > 7)
            write("\t"); else write("\t\t");
         if(list[i]->query_real_name() =="dragnar")
            write("200\t");
         if(list[i]->query_level() > 19 && list[i]->query_real_name() !="dragnar")
            write("100\t");
         if(list[i]->query_level() < 20)
            write(list[i]->query_level()+list[i]->query_extra_level()+scar->query_pkills()+"\t");
         write(list[i]->query_level()+"\t");
         write(list[i]->query_extra_level()+"\t");
         write(scar->query_pkills()+"\t");
         write(scar->query_pdeaths()+"\n");
       }
   }
   write("================================================================================\n");
   return 1;
}
angel_who() {
   object list, guild;
   int i,level;
   string muffles;
   
   list = users();
   write("\n");
   write("================================================================================\n");
   write("NAME:\t\tRANK:\tMUFFS:  LOCATION\n");
   write("================================================================================\n");
   for(i=0; i < sizeof(list); i++) {
      guild = present("bloodscar",list[i]);
      if(guild) {
         write(capitalize(list[i]->query_real_name()));
         if(strlen(list[i]->query_real_name())>7)
            write("\t"); else write("\t\t");
         if(list[i]->query_real_name() =="dragnar")
            write("200\t");
         if(list[i]->query_real_name() !="dragnar" && list[i]->query_level() > 19)
            write("100\t");
         if(list[i]->query_level() < 20)
            write(list[i]->query_level()+list[i]->query_extra_level()+guild->query_pkills()+"\t");
         if(guild->query_muffled() > 0) write("Yes\t");
         else write("No\t");
         if(!environment(list[i])) write("Logging in");
         else write(environment(list[i])->short());
         write("\n");
       }
   }
   write("================================================================================\n");
   return 1;
}
angel_tell(str) {
   object ob, guild, angel;
   int i;
   string me;
   
   me = this_player();
   angel = this_object();
   if(!str) {
      Write("Tell blood brothers what?\n");
      return 1;
   }
   ob = users();
   for(i = 0; i < sizeof(ob); i++) {
      guild = present("bloodscar", ob[i]);
      if(guild && guild->query_muffled() < 1) {
         tell_object(ob[i], "<<" + me->query_name() +">>: "+str+"\n");
       }
   }
   return 1;
}
new_scar() {
   object scar;
   scar=clone_object("/players/dragnar/closed/scar.c");
   move_object(scar, environment(this_object()));
   tell_object(environment(this_object()), "Resetting your scar...\n");
   destruct(this_object());
   return 1;
}
query_muffled() { return muffled; }
query_pkills() { return pkills; }
query_pdeaths() { return pdeaths; }
save_me() {
   string file;
   file = SAVE_PATH + RN;
   if(!save_object(file)) {
      tell_object(user, "Error in saving kill stats!\n");
      return 1;
   } else {
      tell_object(user, "Saving guild stats.\n");
      return 1;
   }
}

restore_me() {
	object player;
	player=find_player(user->query_real_name());
   if(!user) {
	return 0;
   }
   tell_object(player, "Restoring kill stats...\n");
   restore_object(SAVE_PATH + RN);
   return 1;
}
tell_scar() {
   object list,scar;
   int i;
   list=users();
   for(i =0; i < sizeof(list); ++i) {
      scar=present("bloodscar",list[i]);
      if(scar) {
         tell_object(list[i], "<<Angel of Death>>:"+capitalize(user->query_real_name())+" has killed "+capitalize(checker)+".\n");
         return 1;
       }
   }
}
ddeeaatthhmmee() {
   if(!present("deathme", user)) {
      pdeaths = pdeaths + 1;
      command("save_me", user);
      return 1;
   }
}
help(str) {
   if(str=="scar") {
      write("\t\t\t\tKILLS\n"+
         "You can gain a kill whenever you kill another player.  This can\n"+
         "be done by killing someone while pking, in a pk area, or by\n"+
         "challenging another champion to a fight.  To challenge another\n"+
         "champion, type deathmatch <playername>.  They have to agree to the fight\n"+
         "and have the option of turning you down.  When in a fight, you\n"+
         "are moved to the arena where you will fight to the death.  This\n"+
         "isn't as bad as it seems however, because you will lose no exps for\n"+
         "being killed.  You only have to type 'pray' in the arena to get your\n"+
         "exps back.  You will lose one stat however, this is the price you\n"+
         "have to pay.\n"+
         "\t\t\t\tDeaths\n"+
         "You will get a death when you are killed by a player.  If you get\n"+
         "killed by someone without the scar, you will not gain a death\n"+
         "since Boltar has removed the shadow command and I'm not able to do\n"+
         "so.  However, I hope that anyone that has interest in pk will\n"+
         "have a scar.\n"+
         "\t\t\t\tRank\n"+
         "The idea of rank is fairly simple.  It adds your level, your extra\n"+
         "level and your amount of kills together.  Rank is a way that players\n"+
         "can put themselves above other champions.  Being a high ranking\n"+
         "champion is a great feat; only only the best will be of high ranks\n"+
         "amoung you.  May the glory of victory be on your side...\n");
      return 1;
   }
}
deathmatch(str){
   object ob,fightob;
   if(!str) {
      write("Who do you wish to fight?\n");
      return 1;
   }
   if(!present(str, environment(this_player()))) {
      write(capitalize(str)+" is not here.\n");
      return 1;
   }
   if(!find_player(str)) {
      write("You can only fight players.\n");
      return 1;
   }
   if(!present("bloodscar", find_player(str))) {
      write("You can only fight Champions.\n");
      return 1;
   }
   fightob=clone_object("/players/dragnar/fightob.c");
   move_object(fightob, find_player(str));
   fightob->set_owner(user);
   write("You have asked "+capitalize(str)+" to fight to the death!\n");
   tell_object(find_player(str), capitalize(this_player()->query_real_name())+" wishes to fight you to the death.\n"+
      "If you wish to fight them type 'accept fight'.  If you don't want to\n"+
      "fight them type 'decline fight'.\n");
   return 1;
}
punt(str) {
   int x;
   object room;
   if(user->query_level() > 20){
      x = random(70)+30;
   }
   if(user->query_level() < 20){
      x = random(65);
   }
   room=environment(user);
   if(!str) {
      write("Who do you want to punt?\n");
      return 1;
   }
   if(!present(str, environment(user))){
      write(capitalize(str)+" isn't here!\n");
      return 1;
   }
   if(!find_living(str)){
      write("Don't do that, you might hurt yourself.\n");
      return 1;
   }
   write("You punted "+capitalize(str)+" " +x+" yards.\n");
   if(x < 30){
      write("What a squib!\n");
   }
   if(x >=30 && x < 50) {
      write("A decent kick.\n");
   }
   if(x >= 50) {
      write("Damn, you booted "+capitalize(str)+"'s ass!\n");
   }
   say(capitalize(user->query_real_name())+" punts "+capitalize(str)+".\n");
   say("A "+x+" yard kick.");
   if(x > 0 && x < 30){
      say("  What a squib!\n");
      return 1;
   }
   if(x >= 30 && x < 50){
      say("  A decent kick.\n");
      return 1;
   }
   if(x >= 50){
      say("  You better sign this man!\n");
      return 1;
   }
}
give_scar(str){
	object who,scar;
	if(this_player()->query_real_name() != "konya"){
	write("You are NOT allowed to do that.\n");
	return 1;
	}
	who=find_player(str);
	if(!who){
	write("I could not find "+capitalize(str)+" Konya.\n");
	return 1;
	}
	scar=clone_object("/players/dragnar/closed/scar.c");
	move_object(scar, who);
	write("Ok, done Konya.\n");
	return 1;
}
heal_scar(){
	write("You mumble some magic words and your scar slowly fades away.\n");
	destruct(this_object());
	return 1;
}
