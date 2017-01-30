/*                  INCLUDES and DEFINITIONS                            */
#include "/players/heroin/closed/guild/merch_say.c"
#include "/players/heroin/closed/guild/defs.h"
#define ME capitalize(this_player()->query_name())
#define IT capitalize(obj->query_name())
#define LVLAC this_player()->set_ac
inherit "obj/treasure";
 
int failed;
 
/* borrow (pick pocket) */
borrow (str) {
string what,who;
object per, it;
notify_fail("Usage is: \n borrow <item) from <who>\n");
if(!str) return 0;
sscanf(str,"%sfrom %s", what,who);
if(!what ||!who) return 0;
per = find(who);
if(!per) return 0;
it = present(what,per);
if(!it) {
notify_fail(capitalize(who)+" doesn't have a "+what+".\n");
return 0;
}
move_object(it,this_player());
per->add_weight(-it->query_weight());
this_player()->add_weight(it->query_weight());
write(capitalize(what)+" was borrowed from "+capitalize(who)+".\n");
return 1;
}
 
/* ------ MEND (get new guild object) -------- */
 
register() {
        object ob, new_watch;
        int rank, exp, sh, muffled, stam, loan, wat, wmp, myac;
        string wir;
 
        new_watch = clone_object("players/heroin/closed/guild/watch_2");
        rank = this_player()->query_guild_rank();
        exp = this_player()->query_guild_exp();
        wat = this_object()->query_wimp_at();
        wmp = this_object()->query_wimp();
        wir = this_object()->query_wimp_dir();
        muffled = this_object()->query_muffled();
        new_watch->set_muffled(muffled);
        new_watch->set_guild_rank(rank);
        new_watch->set_wimp(wmp);
        new_watch->set_wimp_at(wat);
        new_watch->set_wimp_dir(wir);
        new_watch->set_guild_exp(exp);
        new_watch->setum_how_often(how_often);
        move_object(new_watch, this_player());
        if(stunwho)
                stunwho->set_wc(stunwc);
        myac = this_player()->query_ac();
        this_player()->set_player_killing(0);
        this_player()->add_ac(-myac);
        if(this_player()->query_guild_rank() < 4)
                this_player()->add_ac(4);
        if(this_player()->query_guild_rank() > 4 &&
           this_player()->query_guild_rank() < 9)
                this_player()->add_ac(7);
        if(this_player()->query_guild_rank() > 8)
                this_player()->add_ac(10);
        if(present("shield_obj", this_player())){
                sh = present("shield_obj", this_player())->query_shields();
                this_player()->add_ac(sh * 2);       }
        destruct(this_object());
        if(color == 1)
write( "Your new watch has that barely worn look to it now.\n");
        else
write("Your watch has that 'barely worn' look to it now.\n");
        this_player()->set_guild_name("merchant");
 
return 1;
}
 
 
/* ------ NEW SCORE (show score) --------- */
rank() {
        command("sc",this_player());
        write("\n");
        write("Guild Rank: "+this_player()->query_guild_rank());
        write("          Guild Experience: "+
        this_player()->query_guild_exp()+"\n");
        if(muffled == 1) {
                write("Merchant Channel: Muffled     ");
        } else
                write("Merchant Channel: Open        ");
write("Health Moniter: "+hpmon+" <"+how_often+">\n");
        write("Armor Class: "+this_player()->query_ac()+" ");
        if(present("shield_obj", this_player()))
                write("<"+present("shield_obj", this_player())->query_shields()+">");
        else
                write("<0>");      write("\n");
        write("Location: "+
        environment(this_player())->short() + "\n");
        write("Current Time: "+ctime()+"\n");
        write("\n\n");
   return 1;
}
 
 
/* ----------------- FIRST STAT COMMAND ---------- */
stat_monster(str) {
        object ob;
        int ac, nhp, wc, hp, percent;
        int maxhp,maxhp2;
  
if(this_player()->query_guild_rank() < 3) {
        write("You must attain a higher level in the guild before\n"+
              "using this skill.\n");
        return 1;
        }
if(this_player()->query_sp() < 20) {
        write("You do not have the energy to perform this.\n");
        return 1;
        }
 
if(!str) {
        write("Usage: stat <target>.\n");
        return 1;
        }
   
ob = present(str, environment(this_player()));
if(!ob) {
        write("There is not a "+str+" here.\n");
        return 1;
        }
       
ac = ob->query_ac();
wc = ob->query_wc();
hp = ob->query_mhp();
nhp = ob->query_hp();
write("\n");
write(ob->short()+" : \n");
if(ac < 3) {
        write("Armor Class: Poor.\n"); 
        }
if(ac > 2 && ac < 7) {
        write("Armor Class: Average.\n"); 
        }
if(ac > 6 && ac < 11) {
        write("Armor Class: Good.\n"); 
        }
if(ac > 10 && ac < 20) {
        write("Armor Class: Excellent.\n"); 
        }
if(ac > 19) {
        write("Armor Class: Godly.\n"); 
        }
if(wc < 5) {
        write("Weapon Class: Poor.\n"); 
        }
if(wc > 6 && wc < 15) {
        write("Weapon Class: Average.\n"); 
        }
if(wc > 14 && wc < 20) {
        write("Weapon Class: Good.\n"); 
        }
if(wc > 19 && wc < 30) {
        write("Weapon Class: Excellent.\n"); 
        }
if(wc > 29) {
        write("Weapon Class: Godly.\n"); 
        }
if(hp < 200) {
        write("Full Health: Weak.\n"); 
        }
if(hp > 199 && hp < 300) {
        write("Full Health: Average.\n"); 
        }
if(hp > 299 && hp < 400) {
        write("Full Health: Good.\n"); 
        }
if(hp > 499 && hp < 600) {
        write("Full Health: Excellent.\n"); 
        }  
if(hp > 599) {
        write("Full Health: Godly.\n"); 
        }
maxhp = ob->query_hp();
maxhp2 = ob->query_mhp();
write("Current Health: "+(maxhp*100/maxhp2)+"%\n");
write("\n");
this_player()->add_spell_point(-20);
return 1;
}
 
/* ------ CAST LIGHT ---------- */
cast_light(str) {
if(str == "light") {
if(guild_rank < 2) {
        write("You do not have the political influence to have\n"+
              "learned this guild ability.\n");
        return 1;
        }
if(this_player()->query_sp() < 0) {
        write("Rest-up. You do not have enough energy to use this ability.\n");
        return 1;
        }
this_player()->add_spell_point(-5);
if(set_light(1) >= 1) {
        write("You let the light on your watch to light up the room\n"+
              "with a golden glow.\n");
        say(ME+" opens up their watch covering the room in a golden glow.\n");
        return 1;
        }
write("Your watch light glows but alas, it\n"+
      "still remains to dark to see.\n");
return 1;
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
 
 
/* -------- CONSIDER ------------ */
consider(str) {
        object target;
        int strength, power;
        string rating;
 
if(this_player()->query_guild_rank() < 7) {
        write("You must attain a higher level in the guild before\n"+
              "using this skill.\n");
        return 1;
        }
if(this_player()->query_sp() < 30) {
        write("You do not have the energy to perform this.\n");
        return 1;
        }
 
target = present(str, environment(this_player()));
if(!target){
        write("No "+str+" here.\n");
        return 1;
        }
 
if(!living(target)){
       write(capitalize(str)+" is not a living thing.\n");
       return 1;
        }
 
write(capitalize(target->query_name())+"\n");
write("Level: "+target->query_level()+"\n");
write("Hit points: "+target->query_hp()+"\n");
write("WC: "+target->query_wc()+"\n");
write("AC: "+target->query_ac() +"\n");
write("% Health: "+(target->query_hp() *100/target->query_mhp()) +"\n");
if(target->query_interactive())
if(target->query_pl_k())
        write("This player has his player killing set! (Yeah!)\n");
if(target->query_interactive() && !target->query_pl_k())
        write("This player does not have his player killing set.\n");
if(present("medal", target))
        write("Member of Paladin guild\n");
if(present("fangs", target))
        write("Member of Vampire guild\n");
if(present("watch", target))
        write("A fellow master (DEVIOUS)\n");
if(present("symbol", target))
        write("Member of the Clerics guild\n");
if(present("black robes", target)) 
        write(" Member of the Mage guild\n");
this_player()->add_spell_point(-50);
return 1;
}
/*              Set start to the main room                 */
set_starting() {
    object target;
 
target = this_player();
target->set_home("players/heroin/closed/guild/main_hall.c");
write("Start place set.\n");
return 1;
}
  /* ------- CASH (This is the Only Direct Damage spell..) ----- */
cash(str){
        object obj;
        int damage;
 
if(this_player()->query_guild_rank() < 5) {
        write("You do not have the wealth or influence to be throwing around\n"+
              "money! Using this skill is a priveledge you do not have.\n");
        return 1;
        }
 
if(!this_player()->query_attack()){
        write("You must be fighting to use this spell.\n");
        return 1; 
        }
 
if(!str && !this_player()->query_attack()){
        write("Usage: cash <target>.\n");
        return 1; 
        }
 
if(!str && this_player()->query_attack())
        obj = this_player()->query_attack();
else
        obj = present(str, environment(this_player()));
 
if(!obj){
        write("That is not here.\n");
        return 1; 
        }
 
if(obj->query_npc() != 1){
        write("You cannot use this spell on a player. Would be nice huh?\n");
        return 1; 
        }
 
if(this_player()->query_money() < 500){
        write("You are to poor to use this spell.\n");
        return 1; 
        }
 
say(ME+" pulls out a booby-trapped purse. The purse explodes and \n"+
    "the coins are violently flung into the unsuspecting "+IT+"!\n");
write("You carefully pull out a booby-trapped purse. You light the purse\n"+
      "and watch in hateful splendor as the symbols of your greed stick\n"+
      "into the flesh of your enemy. \n");
damage = random(50);
if(damage > obj->query_hp())
damage = obj->query_hp();
obj->hit_player(damage);
this_player()->add_money(-(400 + random(200)));
return 1;
}
 
 
/* --------- MEND ALL  ------ */
mend_all() {
        object ob, guild;
        int i;
 
if(this_player()->query_real_name() == "heroin" ||
   this_player()->query_real_name() == "unsane") {
        write("The Guild is supplied with new watches.\n");
        ob = users();
        for(i = 0; i < sizeof(ob); i++) 
        guild = present("watch", ob[i]);
        if(guild && ob[i]->query_level() < 50) {
        tell_object(ob[i], "A Guild Master requests that you have your watch repaired.\n");
                        command("mend", ob[i]);  
                        }
                }
                return 1;
        }
 
/* ----- WATCH (self explanatory) ------ */
watch(str) {
        object ob, obj, ob1;
 
check_rank(20);
if(failed == 1) 
        {return 1;}
  
if(!str) {
        write("Give watch to who?\n");
        return 1;
        }
ob = find_player(str);
if(!ob) {
        write("Cannot find player: "+capitalize(str)+".\n");
        return 1;
        }
   
obj = clone_object("players/heroin/closed/guild/watch_2.c");
obj->set_guild_rank(1);
move_object(obj, ob);
write(capitalize(str)+" now has a WATCH of elegance and style!\n");
tell_object(ob, "You now have a WATCH that distinguishes you as a merchant!\n");
command("mend", ob);
return 1;
}
 
/* ------- GUILD TITLE (set guild title) ----- */
guild_title() {
        string title;
        object me;
 
if(guild_rank == 1) { title = "the Merchant Page"; }
if(guild_rank == 2) { title = "the Novice Apprentice"; }
if(guild_rank == 3) { title = "the Apprentice"; }
if(guild_rank == 3) { title = "the Merchant (Kinda Greedy)"; }
if(guild_rank == 4) { title = "the Master Merchant (Local)"; }
if(guild_rank == 5) { title = "the Master Merchant (Regional)"; }
if(guild_rank > 5) { title = "the Master Merchant <<<GLOBAL>>>"; }
 
this_player()->set_title(title);
write("Your guild title has now been set.\n");
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
if(gender == "creature") { write("Gender: Creature      Guild: "); }
if(present("watch", ob)) { write("Merchant\n"); }
else
if(present("vampirefangs", ob)) { write("Vampire\n");
 }
else
if(present("seal", ob)) { write("Mason\n"); }
else
if(present("shadow_mark", ob)) { write("Shadow\n"); }
else
if(present("mrobe", ob)) {write("Monk\n"); }
else
if(present("license", ob)) { write("Assassin\n"); }
else write("None\n");
if(ob->query_pl_k() == 1) { write("Player killer: Yes    Location: "); }
if(ob->query_pl_k() == 0) { write("Player killer: No     Location: "); }
if(!environment(ob)) { write("Unknown\n");}
if(environment(ob)) { write(environment(ob)->short()+"\n");}
write("\n");
return 1;
}
/* ------ Guild WHO (guild members logged on) ----- */
merch_who(){
        int count;
        string who,guild;
        string gender;
        int x;
        object ob;
        object mas,monk,as,dopp;
        ob = users();
write("--------------------------------------------------------------------------------\n");
write("Master:       Political Influence:     Muffled:     Sex:     Location:\n");
write("--------------------------------------------------------------------------------\n");
for(x=0;x<sizeof(ob);x+=1){
        if(ob[x]->query_invis() < 20) {
                guild = present("watch", ob[x]);
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
                        if(gender == "female") {write("   F        ");}
                        if(gender == "creature") {write("   C        ");}
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
return 1;
}
 
 
/* ------ PROMOTE (RESTRICTED!) ----- */
promote_member(str) {
        object ob, obj;
        string who;
        int level, old_rank, old_exp, old_rank1, xp;
   
sscanf(str, "%s %d", who, level);
obj = find_player(who);
ob = present("watch", obj);
ob->set_guild_rank(level);
old_rank1 = obj->query_guild_rank();
obj->add_guild_rank(-old_rank1);
obj->add_guild_rank(level);
tell_object(obj, "You now have political influence of: "+level+".\n");
write("You pull some strings and raise "+capitalize(who)+" to political influence:  "+level+".\n");
old_exp = obj->query_guild_exp();
obj->add_guild_exp(-old_exp);
if(level == 1) { xp = 1; }
if(level == 2) { xp = 25000; }
if(level == 3) { xp = 75000; }
if(level == 4) { xp = 175000; }
if(level == 5) { xp = 475000; }
if(level == 6) { xp = 1000000; }
if(level == 7) { xp = 1700000; }
if(level == 8) { xp = 2500000; }
if(level == 9) { xp = 3600000; }
if(level > 9) {  xp = 5500000; }
obj->add_guild_exp(xp);
ob->set_guild_exp(xp);
write_file("/players/heroin/closed/guild/PROMOS",
capitalize(this_player()->query_real_name())+" PROMOTED "+
capitalize(who)+" to LEVEL "+level+" on "+ctime()+".\n");
return 1;
} /* --- FIRST STAT --- */
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
              "unable to find ANY guild Pages to run your errands.\n");
        return 1;
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
tell_object(shit, "  [ATT:"+shape+"]\n");
return 1;
}
 
/*----------------RECRUIT----------------*/
recruit(str) {
        object ob;
        object obj;
 
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
 
 
 
/* --------- MAKE WIMP (on or off) ----------- */
make_wimp(str) {
if(!str) { 
        write("Usage: wimp <on/off>.\n"); 
        return 1; 
        }
if(str == "on") {
        wimp = 1;
        write("*-- Wimp: On.  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+
              " --*\n");
        return 1;
        }
 
if(str == "off") {
        wimp = 0;
        write("*-- Wimp: Off.  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+
              " --*\n");
        return 1;
        }
 
write("Usage: wimp <on/off>.\n");
return 1;
}
 
/* --- MAKE WHIMPY NUMBER --------- */
make_wimp_at(str) {
        int num;
 
if(!str) {
        wimp_at = 10;
        if(wimp == 1){
                write("*-- Wimp: On."); 
                } 
        else { 
                write("*-- Wimp: Off."); 
                }
        write("  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+" --*\n");
        return 1;
        }
        
sscanf(str, "%d", num);
if(num < 1) {
write("You must select a number greater than 1.\n");
         return 1; 
         }
 
if(num > 99) {
         write("What are you a total pansy? Who recruited you?\n");
         write("You must select a number between 1 and 99.\n");
         return 1; 
         }
wimp_at = 100 / num;
if(wimp == 1){
         write("*-- Wimp: On."); 
         } 
else { 
        write("*-- Wimp: Off."); 
        }
write("  Wimp At: "+wimp_at+"%  Wimp Dir: "+wimp_dir+" --*\n");
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
/*---------------GC-----------------*/
gc(){
cat("/players/heroin/closed/guild/gc");
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
    ME+" brings order to the room  <Temporarily>.\n"+
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
 
 
/* --- GOLD CORPSE (turn corpse into some coins) --- */
gold(str){
        object ob, obj;
        int x;
 
if(this_player()->query_guild_rank() < 4) {
        write("Your greed is greater than your skill. You must gain more influence\n"+
              "to use this skill.\n");
        return 1;
        }
if(this_player()->query_sp() < 10) {
        write("Rest-up. You do not have the energy to perform this.\n");
        return 1;
        }
 
if(!str){
        write("Usage: gold corpse.\n");
        return 1; 
        }
 
obj = present("corpse", environment(this_player()));
if(!obj){
        write("There is no corpse here.\n");
        return 1; 
        }
 
x = obj->heal_value();
x=30+random(x);
if(x>50) 
        x=50;
this_player()->add_money(x);
write("You quickly extract all valuable elements from your foe's corpse.\n");
say(ME+" mutilates the poor corpse for a few measly coins.\n");
destruct(obj);
this_player()->add_spell_point(-10);
return 1;
}
 
/* --- Checkbook --- */
checkbk(str){
        object ob;
 
if(!present("check book", this_player())){
        ob = clone_object("players/heroin/closed/guild/checkbk.c");
        move_object(ob, this_player());
        write("You whip out your statement of credit (checkbook).\n");
        command("checkbk "+str, this_player());
        return 1; 
        }
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
                if(present("watch", cur))
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
 
/*---------QUICK SCORE-------------*/
mon() {
        int hp,sp,money;
        int intox;
        int xp;
xp = this_player()->query_exp();
intox = this_player()->query_intoxination();
hp = this_player()->query_hp();
sp = this_player()->query_sp();
money = this_player()->query_money();
write("HP: "+hp+"   SP: "+sp+"   XP: "+xp+"   MONEY: "+money+"  INTOX: "+intox+"/"+min+"\n");
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
 
write("--------------------------------------------------------------------------------\n");
write("Name:           Lvl:      Pk:     Guild:     Sex:     Location:\n");
write("--------------------------------------------------------------------------------\n");
for(x=0;x<sizeof(ob);x+=1){
if(ob[x]->query_level() < 1000000){
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
if(ob[x]->query_pl_k() == 0){write("  No      ");}
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
if(present("black robes", ob[x])) {write("Mage       ");}
else
if(present("vampirefangs", ob[x])) {write("Vampire    ");}
else
if(present("shadow-mark", ob[x])) {write("Shadow     ");}
else
if(present("badge", ob[x])) {write("Dopple     ");}
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
 
 
/* -------- auction (remote sell) --------------- */
xsell(str) {
        string item;
        object itemob;
        int val;
 
if(!str || sscanf(str, "%s", item) != 1) {
        write("Useage:  tithe <item>\n");
        return 1;
        }
itemob = present(item, this_player());
if(!itemob) {
        write("You do not have a "+item+".\n");
        return 1;
        }
call_other(this_player(),"add_spell_point", -10);
val = call_other(itemob, "query_value");
if(val > 0) {
        if(val > 1000) {
                val = 1000 + random(600);
                }
        call_other(this_player(),"add_money", val);
        destruct(itemob);
        write("You quickly sell "+item+" to the first unfortunate being\n"+
              " that happens past you.  Upon settling on a 'fair' price\n"+
              "the stranger hands you a small stack of coins. You made\n"+
              "about "+val+" in coins.\n");
        say(ME+" auctions off a "+item+" to a passerby.  The man haggles over\n"+
            "the price and then hands ME+ some coins. What a con artist!\n");
        return 1;
        }
write("You cant find anyone to buy such a worthless item.\n"+
      "Save your breath..dont bother trying.\n");
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
 
 
/* ------ ESCAPE (take me back to guild) ----- */
escape(){
object gone;
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
}
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
write("You have been fixed (no guarantees).\n");
return 1;
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
 
/* -- connect (player teleport) -- */
connect(str){
        object target;
 
if(this_player()->query_guild_rank() < 8) {
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
 
if(!present("watch", target)){
        write(capitalize(str)+" is not one of US.\n");
        return 1; 
        }
 
if(target->query_level() > 19){
        write("You dont share any relationship with this Wizard! Dont try to connect.\n");
        return 1; 
        }
 
if(environment(this_player())->query_realm() == "NT"){
        write("Something here is interfering with the watch frequency\n");
        return 1; 
        }
 
write("You wind up your watch and connect with "+capitalize(str)+".\n");
say(ME+" flashes in and out of existence.\n");
move_object(this_player(), environment(target));
tell_object(target,
            "You are visited by a fellow master.\n"+
            ME+" suddenly appears at your side.\n");
say(ME+" appears suddenly at the side of "+capitalize(str)+".\n");
this_player()->add_spell_point(-70);
return 1;
}                       
/* ------ GUILD TELL ----------- */
merchant_tell(str) {
        object ob, guild, merch;
        int i, happy;
        string me, mess;
 
me = this_player();
merch = this_object();
if(!str) {
        Write("Tell guildmembers what?\n");
        return 1;
        }
mess = "["+capitalize(me->query_real_name())+"]: "+str;
ob = users();
for(i = 0; i < sizeof(ob); i++) {
        guild = present("watch", ob[i]);
        if(guild && guild->query_muffled() == 0) {
tell_object(ob[i],"[" + capitalize(me->query_real_name()) +"]: " +str+"\n");
}
return 1;
}
}
 
/*-------- GUILD EMOTE ------------ */
merch_emote(str) {
        object ob, guild;
        int i, x;
        string me;
   
me = this_player()->query_name();
if(!str) {
        write("Usage: me <emote string>\n");
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
ob = users();
for(i = 0; i < sizeof(ob); i++) {
        guild = present("watch", ob[i]);
        if(guild && guild->query_muffled() == 0 &&
           guild->query_guild_rank() > 19) {
                tell_object(ob[i], "{"+capitalize(me->query_real_name())+"}: "+
                str+"\n");
                }
}
return 1;
}
 
/*-------- COMMANDER EMOTE ------------ */
commander_emote(str) {
        object ob, guild;
        int i;
 
if(!str) { write("Commander emote what?\n"); return 1;  }
ob = users();
for(i = 0; i < sizeof(ob); i++) {
        guild = present("watch", ob[i]);
if(guild && guild->query_muffled() == 0 &&
   guild->query_guild_rank() > 19) {
        tell_object(ob[i], "\n|> "+capitalize(this_player()->query_name())+
        " "+str+"\n");
        }
}
return 1;
}
 
/* ----- HEAL (self/other) ------------ */
heal_spell(str) {
        string who;
        object ob;
        int much;
 
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
 
write("You slam the biobooster canister into "+
      capitalize(ob->query_name())+"'s leg!\n"+ capitalize(ob->query_name())+
      " throws their arms into the air and screams as the juice pulses in,\n"+
      "their veins.  You shrug; guess they feel better.\n");
say(ME+" slams the biobooster canister into\n"+
    capitalize(ob->query_name())+"'s leg.  "+
    capitalize(ob->query_name())+" face turns into one large,\n"+
    "demonic grin-- they definetly feel better.\n");
ob->add_hit_point(much);
this_player()->add_spell_point(-much);
return 1;
}
 
/* ----- QUIT (borrowed-set all modifiers, counters, etc Zip) -- */
quit(){
 iquit = 911;
command("quit", this_player());
return 1;
 
}
 
/*  ------ GXP (set members guild XP) ---------- */
gxp_member(str) {
        object ob, obj, watch;
        int xp, old_exp;
        string who;
 
if(!str || sscanf(str, "%s %d", who, xp) != 2) {
        write("Usage: merexp <player> <#>.\n");  
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
write("<<<<<<<<<<<<<<<<<<< IN BATTLE >>>>>>>>>>>>>>>>>>>>\n");
x= 0;    
xx = 0;
for(i = 0; i < sizeof(ob); i++) {
guild = present("watch", ob[i]);
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
write(xx+" :MERCHANTS logged on.  "+x+" :MERCHANTS in battle.\n\n");
return 1;
}
 
/* ---- FOLLOW (follow another player...) -------- */
follow(str){
        object merch, victim;
 
merch = present("watch", this_player());
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
        this_player()->add_spell_point(-15);
        set_heart_beat(1);
        return 1;
        }
}                         
