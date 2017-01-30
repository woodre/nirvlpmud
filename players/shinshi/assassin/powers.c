#define WHONAME who->query_name()

set_disguise(ob){
   if(ob) shadow = ob;
   return 1;
}
set_disguised(i){ disguised = i; return 1;}
set_reserved(ob){
   if(ob) monshadow = ob;
   return 1;
}
set_stalkee(ob, str, i){
   if(ob){
      stalkee = ob;
      stalkee_name = str;
      stalk = i;
   }
   return 1;
}
set_ok_backstab(i){
   if(i) ok_backstab = i;
   return 1;
}
set_bug(ob){ bug = ob; return 1; }
set_roombug(ob){ roombug = ob; return 1; }

emote(str){
   if(!str){ notify_fail("Emote what?"); }
   str = extract(str, 1, strlen(str));
   say(this_player()->query_name()+" "+str+"\n");
   return 1;
}

fear(str){
   object who;
   who = present(str, environment(this_player()));
   if(!who){ notify_fail("That is not here."); }
   if(who->query_level() > 20 && who->query_wimpy()){
      this_player()->run_away();
      write("You make a scary face. "+capitalize(WHONAME)+
         " makes an even scarier one!\n");
      return 1;
   }
   if(!who){
      write("That is not here.\n");
      return 1;
   }
   if(!who->query_interactive()){
      write(capitalize(WHONAME)+" is scarier than any face you can make.\n");
      return 1;
   }
   if(!who->query_wimpy()) {
      write(capitalize(WHONAME)+" laughs at your feeble scare attempt.\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 15) {
      write("You do not have enough spell pts.\n");
      return 1;
   }
   who->run_away();
   this_player()->add_spell_point(-15);
   write("You scare "capitalize(+str+)" right out of the room.\n");
   say(this_player()->query_name()+" frightens "+capitalize(WHONAME)+
      " right out of the room.\n", who);
   tell_object(who,
      capitalize(this_player()->query_name())+" makes such a scary face"+
      " that you run out of the room in fright.\n");
   return 1;
}

communicate(str){
   say(environment(this_object())->query_name()+
      " says: "+str+"\n");
   write("You said: "+str+"\n");
   return 1;
}

backstab(str){
   object victim;
   int damage;
   if(!str){ notify_fail("Usage: backstab <who>"); }
   victim = present(str, environment(this_player()));
   if(!victim){
      write("That is not here.\n");
      return 1;
   }
   if(random(20) > this_player()->query_attrib("ste")){
      write("You clumsily fail in your attempt to backstab.\n");
      this_player()->hit_player(random(20));
      write("You stab yourself instead.\n");
      write("Guess you weren't stealthy enough.\n");
      tell_object(victim, capitalize(this_player()->query_name())+
         "tries to backstab you, but you catch it in the nick of time.\n");
      say(capitalize(this_player()->query_name())+" tried to backstab "+
         capitalize(str)+" but failed.\n");
      return 1;
   }
   if(!victim->query_npc()) {
      write(capitalize(str)+" can't be attacked by assassin backstabs.\n");
      return 1;
   }
   damage = (this_player()->query_wc() * 2)+10;
   if(this_player()->query_attack() == 0 && this_player()->query_hunted()
         == 0){
      victim->hit_player(damage);
      this_player()->attack_object(victim);
      write("You stab "+capitalize(str)+" in the back!\n");
      tell_object(victim, capitalize(this_player()->query_name())+
         " stabs you in the back!\n");
      tell_room(environment(this_player()),
         capitalize(this_player()->query_name())+ " stabs "+capitalize(str)+" in the back!\n");
      return 1;
   }
   write("You cannot get behind someone you're already fighting.\n");
   return 1;
}

cannibalize(){
   object corpse;
   int heal;
   corpse= present("corpse");
   if(!corpse){
      corpse = present("corpse", environment(this_player()));
      if(!corpse){
         write("There is no corpse here for you to eat, sorry.\n");
         return 1;
      }
   }
   heal = corpse->heal_value();
   write("You tear into the corpse, eating bones and all.\n");
   say(this_player()->query_name()+" tears into the corpse, eating bones and all.\n");
   this_player()->heal_self(heal);
   destruct(corpse);
   return 1;
}

harm(str) {
   object victim;
   if(!str){
      victim = environment(this_object())->query_attack();
      if(!victim){
         write("Usage: harm <monster>\n");
         return 1;
      }
   }
   else {
      victim = present(str, environment(this_player()));
      if(!victim){
         write("That player/creature is not here.\n");
         return 1;
      }
   }
   if(this_player()->query_spell_point() < 50){
      write("You are too weak to harm anyone.\n");
      return 1;
   }
   if(victim->query_npc() == 0) {
      write("Sorry, mud policy is no pk guild spells.\n");
      return 1;
   }
   this_player()->spell_object(victim, "harm", random(60), 30);
   
   write("You raise the Finger of Death and harm "+capitalize(str)+".\n");
   tell_object(victim, 
      this_player()->query_name()+" raises the Finger of Death against you!\n");
   tell_room(environment(this_player()),
      this_player()->query_name()+" raises the Finger of Death against "+
      capitalize(str)+"!\n");
   
   return 1;
}


bug(str){
   object who;
   if(bug){ notify_fail("You can only have one bug out at a time."); }
   if(!str){ notify_fail("Usage: bug <who>"); }
   who = find_player(str);
   if(!who){ notify_fail(capitalize(str)+" is not logged on."); }
   if(who->query_level() > 20){
      notify_fail("Wizards don't like to be spied upon."); }
   bug = clone_object(APATH+"bug");
   bug->set_owner(this_player()->query_real_name());
   move_object(bug, find_player(str));
   write("You bug "+capitalize(str)+".\n");
   return 1;
}

unbug(){
   if(!bug){
      notify_fail("You do not have a bug out."); }
   bug->bye();
   return 1;
}

roombug(str){
   object who;
   if(roombug){ notify_fail("You can only have one roombug out at a time."); }
   if(!str){ notify_fail("Usage: roombug <who>"); }
   who = find_player(str);
   if(!who && str != "here"){
      notify_fail(capitalize(str)+" is not logged on."); }
   if(who->query_level() > 20){
      notify_fail("Wizards don't like to be spied upon."); }
   roombug = clone_object(APATH+"bug");
   roombug->set_owner(this_player()->query_real_name());
   if(str != "here")
      move_object(roombug, environment(who));
   else
      move_object(roombug, environment(this_player()));
   write("You bug the room.\n");
   return 1;
}

unroombug(){
   if(!roombug){
      notify_fail("You do not have a bug out."); }
   roombug->bye();
   return 1;
}


spy(str) {
   string who;
   if(!str || sscanf(str, "%s", who) != 1) {
      write("Useage:  spy <player>\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 10) {
      write("You are too low on power.\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who)+" is not on.\n");
      return 1;
   }
   if(find_player(who)->query_invis() > 0) {
      write(capitalize(who)+" is not on.\n");
      return 1;
   }
   if(find_player(who)->query_level() > 20) {
      write("You cannot spy on wizards.\n");
      return 1;
   }
   call_other(this_player(), "add_spell_point", -10);
   write(capitalize(who)+"'s location:\n");
   write(call_other(find_player(who), "look")+"\n");
   return 1;
}

hitlist(){
   find_object(APATH+"bounty")->hitlist();
   return 1;
}

heroes(){
   find_object(APATH+"fame")->list();
   return 1;
}


pkers(){
   object list;
   int i, j;
   list = users();
   write("\n");
   write("[========================================]\n");
   write(justify("Level:", 9)+justify("Name:", 14)+justify("Guild:",10));
   write("\n");
   write("------\t "+"-----"+"         ------\n");
   for(i=0; i< sizeof(list); i++) {/* for each player */
      string name, gname;
      int lvl;
      if(!list[i]->query_pl_k()) continue;
      name = list[i]->query_name();
      lvl = list[i]->query_level();
      if(lvl > 20) lvl = "WIZ";
      if(list[i]->query_invis() > 0) { write(""); } else {
         gname = check_guild(list[i]);
         write(justify(lvl, 9)+justify(name, 14)+gname+"\n");
       }
      
   }
   write("[========================================]\n");
   return 1;
}
escape(){
   string here_realm;
   object here;
   if(this_player()->query_spell_point() < 15){
      write("You are too weak to escape!\n");
      return 1;
   }
   here=environment(this_player());
   here_realm=here->realm();
   if(here_realm == "NT") {
      write("This room is teleport protected.\nYou fail.\n");
      return 1;
   }
   this_player()->add_spell_point(-15);
   say(this_player()->query_name()+
      " throws a small black globe and a large\n"+
      "cloud as dark as night fills the area, blinding you!!!\n");
   write("You throw a smoke ball and disappear into the darkness\n");
   move_object(this_player(),
      APATH+"cenguild");
   return 1;
}

consider(str){
   object target;
   string tarname;
   int strength, power;
   string rating;
   if(!str){
      write("Usage: consider <who>\n");
      return 1;
   }
   target = present(str, environment(this_player()));
   if(!target){
      write("No "+str+" here.\n");
      return 1;
   }
   tarname = target->query_name();
   if(!living(target)){
      write(capitalize(str)+" is not a living thing.\n");
      return 1;
   }
   if(target->query_name() == this_player()->query_name()){
      write("You can't consider yourself.\n");
      return 1;
   }
   target->long();
   if(target->query_interactive())
      write("Money: "+target->query_money()+" gold coins.\n");
   if(target->query_pl_k())
      write("This player has his player killing set! (Yeah!)\n");
   if(target->query_interactive() && !target->query_pl_k())
      write("This player does not have his player killing set.\n");
   if(target->query_interactive()){
      string gname;
      gname = check_guild(target);
      if(gname == "No guild"){
         write("No guild membership.\n");
      }
      else {
         write("Member of "+gname+" guild.\n");
      }
   }
   if(target->query_ac() > this_player()->query_ac()){
      write(tarname+" has better armor than you.\n");
   }
   else { write(tarname+" does not have better armor than you.\n"); }
   if(target->query_wc() > this_player()->query_wc()){
      write(tarname+" has a better weapon than you.\n");
   }
   else { write(tarname+" does not have a better weapon than you.\n"); }
   if(target->query_hp() > this_player()->query_hp()){
      write(tarname+" can take more damage than you.\n");
   }
   else { write(tarname+" cannot tmage than you.\n"); }
   this_player()->add_spell_point(-15);
   return 1;
}

contract(str){
   object contractor, victim, contract, license;
   string who1, who2;
   me = this_player();
   
   license = present("license", this_player());
   if(license->query_guild_quest() < 2){
      write("You must be a journeyman assassin to contract for assassination.\n");
      return 1;
   }
   if(sscanf(str, "%s %s", who1, who2) == 2){
      contract = clone_object(APATH+"contract");
      contractor = find_player(who1);
      victim = find_player(who2);
      tell_object(contractor, "A demon arrives bearing a contract from a\n");
      tell_object(contractor, "certain assassin willing to take up your\n");
      tell_object(contractor, "request.  The demon gives you the contract,\n");
      tell_object(contractor, "and awaits your response.\n");
      write("A demon flies away carrying your contract to the contractor.\n");
      contract->set_victim_level(victim->query_level());
      contract->set_assassin(this_player()->query_name());
      contract->set_victim(capitalize(who2));
      contract->set_contractor(capitalize(who1));
      move_object(contract, contractor);
      return 1;
   }
}

disguise(str){
   string a, b, what;
   level = 0; name = 0;   /* needed for restore_object() */
   if(!str){ notify_fail("Usage: disguise <what>"); }
   str = lower_case(str);
   if(this_player()->query_spell_point() < 50){
      notify_fail("You do not have enough spell points."); }
   if(disguised){
      notify_fail("You are already disguised."); }
   if(sscanf(str, "%s %s", a, b)){
      write("No spaces allowed, sorry.\n");
      return 1;
   }
   restore_object("players/"+str);
   if(name){
      write("Sorry, no player emulation at this time.\n");
      return 1;
   }
   name = 0; level = 0;
   restore_object("banish/"+str);
   if(name){
      write("That name has been banished.\n"); return 1;
   }
   if(sscanf(str, "#corpse", what)){
      what = "Corpse of "+this_player()->query_cap_name();
      str = "corpse";
   }
   else what = str;
   this_player()->add_sp(-50);   
   shadow = clone_object(APATH+"shadow");
   shadow->set_name(str);
   shadow->set_cap_name(capitalize(str));
   shadow->set_short(what);
   shadow->set_long(what);
   shadow->shadow_player(this_player());
   command("refresh", this_player());
   write("You disguise yourself as "+what+".\n");
   disguised = 1;
   return 1;
}

undisguise(){
   if(!shadow) { write("You are not disguised.\n"); return 1; }
   shadow->stop_shadow();
   name = 0; level = 0;
   command("refresh", this_player());
   write("You remove your disguise.\n");
   disguised = 0;
   return 1;
}

quit(){
   if(shadow){
      write("Removing your disguise...\n");
      shadow->stop_shadow();
   }
   if(monshadow){
      write("Dismissing your monster reservation...\n");
      monshadow->remove_blocks();
   }
   if(bug){
      write("Destroying your bug...\n");
      bug->bye();
   }
   if(roombug){
      write("Terminating your roombug...\n");
      roombug->bye();
   }
}

stalk(str){
   object assassin, victim;
   if(!str){ notify_fail("Usage: stalk <who>\n"); }
   assassin = present("license", this_player());
   if(str == "off"){
      write("You are no longer stalking "+stalkee->query_name()+".\n");
      set_heart_beat(0);
      stalk = 0;
      return 1;
   }
   stalkee = find_player(str);
   if(!present(str, environment(this_player()))){
      write("That is not here.\n");
      return 1;
   }
   if(stalkee->query_level() > 20){
      write("You can't stalk wizards.\n");
      return 1;
   }
   if(!str){
      write("Stalk who?\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 15){
      write("You are too low on power to stalk.\n");
      return 1;
   }
   if(!str){
      write("Usage: stalk <who> or stalk off\n");
      return 1;
   }
   if(stalk == 1){
      write("You are already stalking someone.\n");
      return 1;
   }
   else {
      write("You begin stalking "+stalkee->query_name()+".\n");
      stalk = 1;
      this_player()->add_spell_point(-15);
      set_heart_beat(1);
      return 1;
   }
}

my_heart_beat(){
   if(stalk == 1){
      if(environment(stalkee) != environment(environment(this_object()))){
         move_object(environment(this_object()), environment(stalkee));
         tell_object(environment(this_object()),
            "You continue stalking "+stalkee->query_name()+".\n");
         command("look", environment(this_object()));
      }
      return 1;
   }
   return 1;
}

preview(str){
   object lame;
   
   if(this_player()->query_spell_point() < 5) {
      write("You do not have enough spell points for this task.\n");
      return 1;
   }
   lame = clone_object(APATH+"lame");
   move_object(lame, environment(this_player()));
   command(str, this_player());
   command("look", this_player());
   move_object(this_player(), environment(lame));
   destruct(lame);
   this_player()->add_spell_point(-5);
   return 1;
}
sneak(str) {
   object here, dest, ob;
   string here_realm, dest_realm;
   if(!str) {
      write("Usage: sneak <player>\n");
      return 1;
   }
   
   dest=environment(find_player(str));
   here=environment(this_player());
   ob=find_player(str);
   if(!ob) {
      write("That person is not playing right now.\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 75){
      write("You are too low on power.\n");
      return 1;
   }
   if(ob->query_level() > 20){
      write("You can never sneak up on a wizard.\n");
      return 1;
   }
   here_realm=here->realm();
   dest_realm=dest->realm();
   if(dest_realm == "NT" || here_realm == "NT") {
      write("Your destination or the room you are in is teleport\n");
      write("protected.\nYou fail.\n");
      return 1;
   }
   this_player()->add_spell_point(-75);
   move_object(this_player(), dest);
   write("ok\n");
   return 1;
}


verify_use(string cmd, int lev_req, int sp_req, string pres){
   return 1;
}