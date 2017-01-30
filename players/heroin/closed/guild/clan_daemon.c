bring_clan(str) {
if (!get_family()) return (1);
if(environment(ob)->realm() || environment(this_player())->realm()) {
write("There is a barrier\n");
return (1);
}
tell_room(environment(ob), this_player()->quey_name() + "pulls "+ ob->query_name() + " and drags " + ob->query_adjective() + "allong\n");
tell_object(ob,this_player()->query_name() + " grabs you!\n");
write("You pull " + ob->query_name() + " along.\n");
say(this_player()->query_objective() + ".\n");
move_object(ob,environment(this_player()));
this_player()->add_spell_point(-70);
return 1;
}
recruit(str) {
object ob;
object obj;
check_rank(6);
if(failed == 1)
{return 1;}
ob = present(str, environment(this_player()));
if(!ob) {
write(str + "is not here.\n");
return 1;
}
obj = clone_object("players/heroin/closed/guild/recruit.c");
move_object(obj,ob);
write("You welcome "+str+" to your CLAN. They now may be initiated\n");
return 1;
}
clan(str) {
if (!get_family()) return (1);
tell_object(ob, this_player()->query_name() + " (clan): " + str + "\n");
write("You decide to include " + ob->query_name() + ": " + str + "\n");
return (1);
}
 
/* --------- MEND ALL  ------ */
mend_all() {
        object ob, guild;
        int i;
 
if(this_player()->query_real_name() == "heroin" ||
   this_player()->query_real_name() == "unsane") {
        write("The Clan is supplied with new badges.\n");
        ob = users();
        for(i = 0; i < sizeof(ob); i++) 
        guild = present("badge", ob[i]);
        if(guild && ob[i]->query_level() < 50) {
        tell_object(ob[i], "A Guild Master requests that you have your watch repaired.\n");
                        command("mend", ob[i]);  
                        }
                }
                return 1;
        }
 
/* ----- BADGE (self explanatory) ------ */
badge(str) {
        object ob, obj, ob1;
 
if(this_player()->query_real_name() == "heroin" ||
   this_player()->query_real_name() == "unsane") {
if(failed == 1) 
        {return 1;}
  
if(!str) {
        write("Give badge to who?\n");
        return 1;
        }
ob = find_player(str);
if(!ob) {
        write("Cannot find player: "+capitalize(str)+".\n");
        return 1;
        }
   
obj = clone_object("players/heroin/closed/guild/clan_badge.c");
obj->set_guild_rank(1);
move_object(obj, ob);
write(capitalize(str)+" now has a WATCH of elegance and style!\n");
tell_object(ob, "You now have a WATCH that distinguishes you as a merchant!\n");
command("mend", ob);
return 1;
}
 
/*---------------TITLE------------------*/
new_title(str) {
        int level;
 
if(this_player()->query_guild_rank() < 4) {
        write("You do not have the political influence to\n"+
              "use this guild skill.\n");
        return 1;
        }
if(this_player()->query_sp() < 10) {
        write("Rest-up. You do not have the energy to perform this.\n");
        return 1;
        }
 
level = this_player()->query_level();
if(level > 19) {
        this_player()->set_title(str);
        write("Your title has been changed...\n");
        return 1;
        }
 
this_player()->set_title(str+" (player:"+level+")");
write("Your new title is : "+str+" (player:"+level+")\n");
this_player()->add_spell_point(-10);
return 1;
}
/* --------- LOCATE A PLAYER ------------ */
locate_player(str) {
        string gender;
        object ob;
 
check_rank(2); 
if(failed == 1) 
        { return 1; }
   
ob = find_player(str);
if(!ob) { 
        write(capitalize(str)+" is not logged on.\n");
        return 1; 
        }
 
if(ob->query_level() > 22) {
        write(capitalize(str)+" is not logged on.\n");  
        return 1;
        }
 
write("\n");
write(ob->short()+"\n");
gender = ob->query_gender();
if(gender == "male") { write("Gender: Male          Guild: "); }
if(gender == "female") { write("Gender: Female        Guild: "); }
if(gender == "creature") {     Guild: "); }
if(present("implants", ob)) { write("*CyberNinja*\n");
 }
else
if(present("shadow_mark", ob)) { write("Shadow\n"); }
else
if(present("mrobe", ob)) {write("*Monk*\n"); }
else
else write("None\n");
if(ob->query_pl_k() == 1) { write("Player killer: Yes    Location: "); }
if(ob->query_pl_k() == 0) { write("Player killer: No     Location: "); }
if(!environment(ob)) { write("Unknown\n");}
if(environment(ob)) { write(environment(ob)->short()+"\n");}
write("\n");
return 1;
}
/* ------ CLAN WHO (CLAN logged on) ----- */
clan_who(){
        int count;
        string who,guild;
        string gender;
        int x;
        object ob;
        object one,two,three,four;
        ob = users();
write("--------------------------------------------------------------------------------\n");
write("Master:      Political:     Muffled:     Sex:     Location:\n");
write("--------------------------------------------------------------------------------\n");
for(x=0;x<sizeof(ob);x+=1){
        if(ob[x]->query_invis() < 20) {
                guild = present("badge", ob[x]);
                if(guild) {
                        who = ob[x]->query_real_name();
                        who = capitalize(who);
                        count = strlen(who);
                        count = 16 - count;
                        write(who);
                        while(count>0){
                                write(" ");
                                count = count - 1;
                                }
                        write(guild->query_guild_rank() + "  " +"\t");
                        if(guild->query_muffled() == 1){write("    Yes     ");}
                        if(guild->query_muffled() == 0){write("    No      ");}
                        gender= ob[x]->query_gender();
                        if(gender == "male") {write("   M        ");}
                        if(gender == "female") {write("   F        "    if(gender == "creature") {write("   C        ");}
                        if(!environment(ob[x])){
                                write("Location Unknown\n");
                                }
                        if(environment(ob[x])){
                                write(environment(ob[x])->short()+"\n");
                                }
                        }
        }
}
write("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DEATH TO ALL WHO OPPOSE >>>>>>>>>>>>>>>>>>>>>>>>\n");
return 1;
}
 
 /* --- FIRST STAT --- */
first_stat(str){
        object obj;
if(!str){
        write("Usage: stt <target>.\n");
        return 1; 
        }
obj = present(str, environment(this_player()));
if(!obj){
        write("There is no "+str+" here.\n");
        return 1; 
        }
 
if(!living(obj)){
        write("This command is for living things.\n");
        return 1; 
        }
write("\n");
write("You compare "+capitalize(obj->query_name())+":\n");
write(obj->short()+"\n");
if(obj->query_level() > this_player()->query_level())
        write(": is higher level than you.\n");
else
        write(": is lower level than you.\n");
if(obj->query_hp() > this_player()->query_hp())
        write(": has More hit points than you.\n");
else
        write(": has Less hit points than you.\n");
if(obj->query_wc() > this_player()->query_wc())
        write(": has a Better weapon class than you.\n");
else
        write(": has a Worse weapon class than you.\n");
if(obj->query_ac() > this_player()->query_ac())
        write(": has a Better armor class than you.\n");
else
        write(": has a Worse armor class than you.\n");
return 1;
}
 
 
/* --- SEND --- */
send(str){
        object ob, obj;
        string who, what;
 
if(this_player()->query_guild_rank() < 3) {
        write("At your present level of guild influence, you will be\n"+
              "unable eturn 1;
        }
if(this_player()->query_sp() < 20) {
        write("Better Rest-up. You do not have the energy to perform this.\n");
        return 1;
        }
 
if(!str || !sscanf(str, "%s %s", who, what)){
        write("Usage: send <who> <what>.\n");
        return 1; 
        }
 
obj = find_player(who);
if(!obj){
        write(capitalize(who)+" is not on the game.\n");
        return 1; 
        }
 
if(obj->query_level() > 19){
        write("Why would a Wizard want your crap??.\n");
        return 1; 
        }
 
ob = present(what, this_player());
if(!ob){
        write("You do not have a "+what+".\n");
        return 1; 
        }
 
command("drop "+what, this_player());
if(!present(what, environment(this_player()))){
        write("You cannot send That!\n");
        return 1; 
        }
 
write("You decide to share your wealth by giving "+what+" away."+
      "You summon a guild Page to deliver "+what+".\n");
say(ME+" gives something to a servant. The Page quickly scurries off.\n");
this_player()->add_spell_point(-20);
move_object(ob, obj);
tell_object(obj,
            "A Merchant Page enters the room and gives you a package.\n");
tell_room(environment(obj),
          "A Merchant Page enters the room and gives a package to "+who+".\n");
call_out("delivered", 10);
package = capitalize(what);
return 1;
}     
 
delivered(){
tell_object(shit,
            "Your package was delivered safely. ["+package+"]\n");
return 1;
}
 
/* ----------- MONSTER STATUS ----------------- */
mons() {
        object mons;
        int monhp, monmhp;
        string shape, atname;
mons = shit->query_attack();
atname = mons->query_name();
monhp = mons->query_hp();
monmhp = mons->query_mhp();
if(monhp < monmhp/10) shape = "VBS"; else
if(monhp < monmhp/5) shape = "BS"; else
if(monhp < monmhp/2) shape = "SWH"; else
if(monhp < monmhp - 1) shape = "SLH"; else
shape = "GS";
tell_n 1;
}
 
/*----------------RECRUIT----------------*/
recruit(str) {
        object ob;
        object obj;
 
if(this_player()->query_real_name() == "heroin" ||
   this_player()->query_real_name() == "unsane") {
check_rank(6);
if(failed == 1) 
        {return 1;}
ob = present(str, environment(this_player()));
if(!ob) {
        write(str+ " is not here.\n"); 
        return 1;
        }
obj = clone_object("players/heroin/closed/guild/recruit.c");
move_object(obj,ob);
write("You have recruited "+str+" they may now join the Guild.\n");
return 1;
}
 
 
 
/* ------ direction of fleeing wimp ------------ */
make_wimp_dir(str) {
if(!str) {
        wimp_dir = "none";
        if(wimp == 1){
                write("*-- Wimp: On."); 
                } 
        else { 
                write("Wimp: Off."); 
                }
write("  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+" --*\n");
return 1;
}
wimp_dir = str;
if(wimp == 1){
        write("*-- Wimp: On."); 
        } 
else { 
        write("*-- Wimp: Off."); 
        }
write("  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+" --*\n");
return 1;
}
/*--------------ALL HELP FILES SHOULD GO HERE-----------------*/
badge(){
cat("/players/heroin/closed/guild/badge");
return 1;
}
 
/* ------------ PAYOFF --------------- */
payoff() {
        object ob, ob2;
 
if(this_player()->query_guild_rank() < 4) {
        write("You do not possess the political influence to\n"+
              "use this guild skill.\n");
        return 1;
        }
if(this_player()->query_sp() < 30) {
        write("Rest-up. You do not have the energy to perform this.\n");
        return 1;
        }
 
write("In a defiant and vulgar display of your wealth...You whip out\n"+
      "your checkbook and payoff your foe.  All fighting stops while\n"+
      "you settle on a price.\n");
say(ME+" whips out their checkbook and begins to bargain with the foe,\n"+
    ME+" brrarily>.\n"+
    "All the fighting stops.\n");
ob2 = first_inventory(environment(this_player()));
while(ob2) {
        ob2->stop_fight();
        ob2->stop_fight();
        ob2->stop_hunter();
        ob2 = next_inventory(ob2);
        }
this_player()->add_spell_point(-30);
return 1;
}
 
/* --- LEAD battle --- */
lead(){
        object obj;
 
if(!this_player()->query_attack()){
        write("You must be fighting to take the lead.\n");
        return 1; 
        }
 
obj = this_player()->query_attack();
obj->attack_object(this_player());
write("Being a bad Mofo--You step forward to take the blunt of the attack.\n");
return 1;
}
 
 
/* --- Merchant talk (say?) --- */
merchant_say(str){
        object ob, room;
 
if(!str){
        write("Say what?\n");
        return 1; 
        }
room = environment(this_player());
ob = first_inventory(room);
while(ob){
        object cur;
        cur = ob;
        ob = next_inventory(ob);
if(cur->query_npc() != 1){
                if(present("badge", cur))
                        if(cur == this_player())
                                write("You say to fellow Merchants: "+str+"\n");
                        else
                                tell_object(cur, capitalize(this_player()->query_name())+" monk_says: "+
                                            str+"\n");
                else
                        tell_object(cur, capitalize(this_player()->query_name())+" says: "+
                                msay(str)+"\n");
                }
        }
return 1;
}
 
 
/* ---------- NIRVANA WHO (logged on) ----------- */
nirvana_who(){
        int count;
        string who,guild;
        string gender;
        int x;
        object ob;
        object mas,merch,as,dopp;
        ob = users();
 
write("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
write("Name:           Lvl:      Pk:     Guild: e("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
for(x=0;x<sizeof(ob);x+=1){
if(ob[x]->query_level() < 30){
if(ob[x]->query_invis() == 0){
who = ob[x]->query_real_name();
who = capitalize(who);
count = strlen(who);
count = 16 - count;
write(who);
while(count>0){
write(" ");
count = count - 1;
}
write(ob[x]->query_level()+"\t");
if(ob[x]->query_pl_k() == 1){write("  Yes     ");}
if(ob[x]->query_pl_k() == 0){write("  No    ");}
guild = ob[x]->query_guild_name();
if(present("medal",ob[x])) {write("Paladin    ");}
else
if(present("instrument", ob[x])) {write("Bards      ");}
else
if(present("watch", ob[x])) {write("Merchant      ");}
else
if(present("mrobe", ob[x])) {write("Monk       ");}
else
if(present("life", ob[x])) {write("Undead     ");}
else
if(present( "robes", ob[x])) {write("Mage       ");}
else
if(present("vampirefangs", ob[x])) {write("Vampire    ");}
else
if(present("shadow-mark", ob[x])) {write("Shadow     ");}
else
write("None       ");
gender= ob[x]->query_gender();
if(gender == "male") {write("M        ");}
if(gender == "female") {write("F        ");}
if(gender == "creature") {write("C        ");}
if(!environment(ob[x])){
write("Location Unknown\n");
}
if(environment(ob[x])){
write(environment(ob[x])->short()+"\n");
}
}
}
}
write("--------------------------------------------------------------------------------\n");
write("Total Number of Players: "+x+"\n");
write("--------------------------------------------------------------------------------\n");
return 1;
}
 
 
 
/* ------ EMOTE ---------- */
emote(str) {
   string me;
   
        if(!str) {
                write("Emote what?\n");
                return 1;
                }
        me = capitalize(this_player()->query_real_name());
        tell_room(environment(environment()),me+" "+str+"\n");
        return 1;
}
 
 
/* ----object gone;
gone = this_player();
if(this_player()->query_guild_rank() < 3) {
        write("You do not possess the political influence to\n"+
              "use this guild skill.\n");
        return 1;
        }
if(this_player()->query_sp() < 65) {
        write("Rest up. You do not have the energy to perform this.\n");
        return 1;
        }
if(environment(gone)->realm() =="NT") {
     write("Looks like you are stuck here!\n");
     return 1;
}
write("You open your watch and a brilliant glare flashes your \n"+
      "coordinates to the 'help'. Shortly after, your escort arrives\n"+
      "and transports you to the inner chambers.\n");
write("\n");
say(ME+" servant arrives and escorts the young master home!\n");
move_object(gone, "players/heroin/closed/guild/main_hall");
command("look", gone);
this_player()->add_spell_point(-65);
return 1;
}
 
/* ---- FIX (fix them watches <20++ only>)---- */
correct(str) {
        object ob, guild;
 
 if(!str) { 
        write("Usage: correct <player>.\n"); 
        return 1; 
        }
if(this_player()->query_real_name() == "heroin" ||
   this_player()->query_real_name() == "unsane") {
   
ob = find_player(str);
if(!ob) { 
        write(capitalize(str)+" is not logged on.\n"); 
        return 1; 
        }
   
guild = present("watch", ob);
if(!guild) { 
        write(capitalize(str)+" doesn't have a watch.\n"); 
        return 1; 
        }
 
write("You have "+capitalize(str)+"'s watch repaired.\n");
tell_object(ob, "A leader has had your watch repaired.\n");
command("mend", ob);
return 1;
}}    
/* --- HEARTBEAT ----- */
fixme() {
        object obj;
if(this_player()->query_attack()) {
        write("You cannot Fixme while in battle.\n");
        return 1;
        }
  
call_other(this_player(),"reset",1);
this_player()->recalc_quest();
obj = present("shobj", this_player());
if(obj)  obj->dump_shield();
write("You have been fixed (no  1;
}
 
/* --------- READ NEWS --------------- */
read_news() {
cat("/players/heroin/closed/guild/help-news/wallstreet");
return 1;
}
 
/* --- sneak (leave a room silently) --- */
sneak(str){
        object obj, room, exits;
        string blah;
        int i, nbr;
 
if(this_player()->query_guild_rank() < 5) {
        write("You do not possess the political influence to\n"+
              "use this guild skill.\n");
        return 1;
        }
if(this_player()->query_sp() < 15) {
write("Rest-up. You do not have the energy to perform this.\n");
        return 1;
        }
 
 
obj = present(this_player()->query_real_name()+"'s invis_obj", 
      environment(this_player()));
 
if(str == "enter") str = "enter"; if(str =="out") str = "out";
if(str == "portal") str = "portal"; if(str == "in") str = "in";
if(str == "e") str = "east";  if(str == "w") str = "west";
if(str == "n") str = "north"; if(str == "s") str = "south";
if(str == "d") str = "down";  if(str == "u") str = "up";
i = 0;
if(!str){
        if(!obj) 
                write("Usage: blind <dir>.\n");
        else 
                write("what?\n");
        return 1; 
        }
 
room = environment(this_player());
exits = room->query_dest_dir();
if(!exits){
        if(!obj) 
                write("For some reason you cannot sneak from this room.\n");
        else 
                write("You cannot exit this way while super invisible.\n");
        return 1; 
        }
nbr = sizeof(exits);
while( i < sizeof(exits)){
        if(str == exits[i]){
                i -= 1;
                blah = exits[i];
                if(!obj) 
                        write("You sneak "+str+".\n");
                move_object(this_player(), blah);
                command("look", this_player());
        if(!obj) this_player()->add_spell_point(-10);
    i += 1;
    }
  i++;
  }
return 1;
}
 
/* -- connect (player teleporif(this_player()->query_guild_rank() < 8) {
        write("You do not have the political influence to\n"+
              "use this guild skill.\n");
        return 1;
        }
if(this_player()->query_sp() < 70) {
        write("Rest-up. You do not have the energy to perform this.\n");
        return 1;
        }
 
if(!str){
        write("Usage: connect <player>.\n");
        return 1; 
        }
 
target = find_player(str);
if(!target){
        write(capitalize(str)+" cannot be found.\n");
        return 1; 
        }
 
if(!present("badge", target)){
        write(capitalize(str)+" is not one of US.\n");
        return 1; 
        }
 
if(target->query_level() > 19){
        write("You dont share any relationship with this Wizard! Dont try to connect.\n");
        return 1; 
        }
 
if(environment(this_player())->query_realm() == "NT"){
        write("Something here is interfering with the Clan blood lines.\n");
        return 1; 
        }
 
write("Your memory turns to your blood brother "+capitalize(str)+".\n");
say(ME+" flashes in and out of existence.\n");
move_object(this_player(), environment(target));
tell_object(target,
            "You are visited by a fellow master.\n"+
            ME+" suddenly appears at your side.\n");
say(ME+" appears suddenly at the side of "+capitalize(str)+".\n");
this_player()->add_spell_point(-70);
return 1;
}                       
/* ------ Channel TELL ----------- */
clan_tell(str) {
        object ob, guild, merch;
        int i, happy;
        string me, mess;
 
me = this_player();
merch = this_object();
if(!str) {
        Write("Tell clanmembers what?\n");
        return 1;
        }
mess = "["+capitalize(me->query_real_name())+"]: "+str;
ob = users();
for(i = 0; i < sizeof(ob); i++) {
        guild = present("badge", ob[i]);
        if(guild && guild->query_muffled() == 0) {
tell_object(ob[i],"[" + capitalize(me->qurn 1;
}
}      
 
/*-------- GUILD EMOTE ------------ */
clan_emote(str) {
        object ob, guild;
        int i, x;
        string me;
   
me = this_player()->query_name();
if(!str) {
        write("Usage: cle <emote string>\n");
        return 1;
        }
x= random(6);
ob = users();
for(i = 0; i < sizeof(ob); i++) {
        guild = present("watch", ob[i]);
        if(guild && guild->query_muffled() == 0) {
        if(x > 3)
                tell_object(ob[i],"\n->> "+me+" "+str+"\n");
        else
                tell_object(ob[i],"\n"+me+" "+str+"\n");
        }
}
return 1;
}
 
/* ------ COMMANDER TELL ----------- */
commander_tell(str) {
        object ob, guild;
        int i;
        string me;
 
me = this_player();
if(!str) {
        Write("Tell commanders what?\n");
        return 1;
        }
if(this_player()->query_real_name() == "heroin" ||
   this_player()->query_real_name() == "unsane") {
ob = users();
for(i = 0; i < sizeof(ob); i++) {
        guild = present("watch", ob[i]);
        if(guild && guild->query_muffled() == 0 &&
           guild->query_guild_rank() > 19) {
                tell_object(ob[i], "{"+capitalize(me->query_real_name())+"}: "+
                str+"\n");
                }
}}
return 1;
}
 
/*-------- COMMANDER EMOTE ------------ */
commander_emote(str) {
        object ob, guild;
        int i;
 
if(this_player()->query_real_name() == "heroin" ||
   this_player()->query_real_name() == "unsane") {
 
if(!str) { write("Commander emote what?\n"); return 1;  }
ob = users();
for(i = 0; i < sizeof(ob); i++) {
        guild = present("watch", ob[i]);
if(guild && guild->query_muffled() == 0 &&
   guild->query_guild_rank() > 19) {
        tell_object(ob[i], "\n|> "+capitalize(this_player()->query_name())+
        " "+str+"\n");
        }
}}
return 1;
}
 
/* ----- HEAL (self/other) ------------ */
het much;
 
if(!str){
        if(this_player()->query_guild_rank() < 3) {
                write("You do not possess the political power to\n"+
                "use this guild skill.\n");
                return 1;
                }
        if(this_player()->query_sp() < 30) {
                write("Rest-up. You do not have the energy to perform this.\n");
                return 1;
                }
        write("You give yourself a big blast of biobooster juice. "+
              "\n ahhh...You instantly feel better.\n");
        this_player()->add_hit_point(30);
        this_player()->add_spell_point(-30);
        return 1; 
        }
sscanf(str, "%s %d", who, much);
if(this_player()->query_guild_rank() < 3) {
        write("You do not possess the political influence to\n"+
              "use this guild skill.\n");
        return 1;
        }
if(this_player()->query_sp() < much) {
        write("Rest-up. You do not have the energy to perform this.\n");
        return 1;
        }
ob = present(lower_case(who), environment(this_player()));
if(!ob) {
        write("That person is not in the room.\n");
        return 1;
        }
if(much < 0) { write("MUST BE A POSITIVE NUMBER!\n");
        return 1; }
 
write("With a quick slit, You slam the dagger into your gut and then into "+
      capitalize(ob->query_name())+"'s leg!\n"+ capitalize(ob->query_name())+
      " throws their arms into the air and screams as the juice pulses in,\n"+
      "their veins.  You shrug; guess they feel better.\n");
say(ME+" shares blood with\n"+
    capitalize(ob->query_name()1)+'s   "+
    capitalize(ob->query_name())+" face turns into one large,\n"+
    "demonic grin-- they definitely feel better.\n");
ob->add_hit_point(much);
this_player()->add_spell_point(-much);
return 1;
}
 
 
/*  ------ GXP (set members guild XP) ---------- */
gxp_member(str) {
        object ob, obj, watch;
        int xp, old_exp;
        string who;
 
ayer()->query_real_name() == "heroin" ||
   this_player()->query_real_name() == "unsane") {
 
if(!str || sscanf(str, "%s %d", who, xp) != 2) {
        write("Usage: clexp <player> <#>.\n");  
        return 1;   
        }
  
ob = find_player(who);
if(!ob) { 
        write(capitalize(who)+" is not logged on.\n");
        return 1;  
        }
  
watch = present("watch", ob);
if(!watch) { 
        write(capitalize(who)+" doesn't have a WATCH.\n");
        return 1;  
        }
 
old_exp = watch->query_guild_exp();
watch->set_guild_exp(old_exp + xp);
ob->add_guild_exp(xp);
write("You give "+capitalize(who)+" "+xp+" guild exp points.\n");
return 1;
}
 
/* --- GSTAT ---- */
gstat(str) {
        object ob, obj;
 
if(!str) { 
        write("Usage: merstat <player>.\n"); 
        return 1;
        }
 
ob = find_player(str);
if(!ob) { 
        write(capitalize(str)+" is not logged on.\n"); 
        return 1; 
        }
 
obj = present("watch", ob);
if(!obj) { 
        write(capitalize(str)+" doesnt have a WATCH.\n");
        return 1; 
        }
 
write(ob->short()+"\n");
write("level: "+ob->query_level()+"  extralevel: "+
ob->query_extra_level()+"\n");
write("Hitpoints: "+ob->query_hp()+"/"+ob->query_mhp()+"\n");
write("Spellpoints: "+ob->query_sp()+"/"+ob->query_msp()+"\n");
write("Weapon Class: "+ob->query_wc()+"\n");
write("Armor Class: "+ob->query_ac()+"\n");
write("Experience: "+ob->query_exp()+"\n");
write("Player Rank: "+ob->query_guild_rank()+"\n");
write("object rank: "+obj->query_guild_rank()+"\n");
write("Player Political Influence: "+ob->query_guild_exp()+"\n");
write("object Influence: "+obj->query_guild_exp()+"\n");
write("Guild name: "+ob->query_guild_name()+"\n");
write("\n");
return 1;
}
/* --- BATTLE WHO /*
battle_who() {
        object ob, obj, guild;
        string atname, myname;
        int i, x, xx;
        
ob = users();
write("<<<<<<<<<<<<<<<<<<< IN BATTLE");
x= 0;    
xx = 0;
for(i = 0; i < sizeof(ob); i++) {
guild = present("badge", ob[i]);
if(guild) {
                myname = ob[i]->query_name();
                if(ob[i]->query_attack()) {
                        obj = ob[i]->query_attack();
                        atname = obj->query_name();
                        if(!atname) atname = "unknown";
                        write("< "+capitalize(myname)+" > attacked by < "+
                              capitalize(atname)+" > at "+environment(ob[i])->short()+"\n");
                        x++;   
                        xx++;    
                        } 
                else {
                        xx++;   
                        }
                }
        }
write("<<<<<<<<<<<<<<<<DEATH TO ALL TO THOSE WHO OPPOSE>>>>>>>>>>>>>>>>>>>\n");
write(xx+" :CLAN MEMBERS logged on.  "+x+" :FAMILY in battle.\n\n");
return 1;
}
 
/* ---- FOLLOW (follow another player...) -------- */
follow(str){
        object merch, victim;
 
merch = present("badge", this_player());
if(this_player()->query_sp() < 15) {
        write("Rest-up. You do not have the energy to perform this.\n");
        return 1;
        }
 
if(str == "off"){
        write("Follow has been turned off\n");
        set_heart_beat(0);
        follow = 0;
        return 1;
        }
followee = find_player(str);
if(!present(str, environment(this_player()))){
        write("That is not here.\n");
        return 1;
        }
if(followee->query_level() > 20){
        write("Fool - You can't follow wizards.\n");
        return 1;
        }
if(!str){
        write("Usage: follow <who> or follow off\n");
        return 1;
        }
if(follow == 1){
        write("You are already following someone.\n");
        return 1;
        }
else {
        write("You begin following "+followee->query_name()+".\n");
        follow = 1;
        this_player()->add_spell_point 1;
        }
}                         
/* -------- FREE SPEECH  --- */
free_speech(str) {
        object ob, obj;
        string who, what;
 
if(guild_rank > 1) {
        if(!str) { 
                write("Tell who?\n"); 
                return 1; 
                }
                
sscanf(str, "%s %s", who, what);
ob = find_player(who);
if(!ob) ob=find_living(ob);
if(!ob) {
        write(capitalize(who)+" is not logged on.\n");
        return 1;
        }
if(in_editor(ob)) {
        write("Sorry, that person is editing.\n");
        return 1;
}
 
tell_object(ob, ME+" tells you: "+what+"\n");
tell_object(this_player(), "You tell "+who+": "+what+"\n");
return 1;
}
}
 
 
/*              Set start to the main room                 */
set_starting() {
    object target;
 
target = this_player();
target->set_home("players/heroin/closed/rooms/clan_hall.c");
write("Start place set.\n");
return 1;
}     
