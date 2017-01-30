#define MAX_MEMBERS 7
#define LOG_FILE 0
static object owner_ob;
static object leader_ob;
static object members;
static int leader;
static int nrofmembers;
static int member_nr;
static int follow;
static int toggle;
static int tot_exp, tot_share;
static int contract;
static int contract_sum;
static string clan_name;
static string filepath;
inherit "obj/treasure";
string family;
object ob,ob2;
int weight;
reset(arg)
{
if(arg) return;
name="The Clan badge";
}
query_auto_load() {return("/players/heroin/closed/guild/clan_badge:" +family+ " ;"); }
id(str) {return (str =="clan" ||str == "badge");}
short() { if (family) {return name +" (" + capitalize(family) + ")"; } else { return name; } }
long() 
{
write("This is the symbol that displays your clan membership.\n");
write("All who share your symbol are part of your clan. \n");
write("For information on your clan type <claninfo>\n");
}
init_arg(str)
{
sscanf(str,"%s;",family);
}
init()
{
add_action("set_leader","leadme");
add_action("tell_leader", "tlead");
add_action("help_files","help_files");
add_action("recruit","recruit");
add_action("clan","clan");
add_action("clan_who","clwho");
add_action("donate","donate");
add_action("clan_info","claninfo");
if (family) {
ob = find_player(family);
if (ob) {
clan(this_player()->query_name() + "is among us!");
} else {
write ("Your Clan badge dulls: " + capitalize(family) + " is not among us.\n");
}
}
}
set_leader(ob) { leader=0; leader_ob=ob; }
query_leader() { return leader_ob; }
get() {return 1; }
leadername() {
if(leader) return name();
return leader_ob->name();
}
tell_leader(str) {
if(leader) tell_object(owner(),str);
else tell_object(leader_ob->owner(),str);
}
name() {return capitalize(owner_ob->query_real_name()); }
owner() { return owner_ob;}
drop() {
if (query_verb()=="drop") {
write("You should take this to your clan leader; You dishonor your clan.\n");
return 1;
if(leader) 
write("You CANNOT just drop your clan!!!!!!\n");
return 1;
}
}
query_value() {return 0; }
query_weight() { return (0); }
get_family() {
if (family) {
ob = find_player(family);
if (ob) return (1);
write(capitalize(family) + " is not on the game at this time.\n");
} else {
write("You are not part of this clan\n");
}
return;
}
clan_info(){
cat("/players/heroin/closed/guild/claninfo");
return 1;
}
recruit(str) {
object ob;
object obj;
/*
check_rank(6);
if(failed == 1)
{return 1;}
*/
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
local_set_clan(str) { family = str;}
emerg_help(str) {
if(!get_family()) return(1);
tell_object(ob,this_player()->query_name()+ "needs your assistance\n");
write("You yell out the clan howl: " +family+" Help me!!\n");
return(1);
}
check() {
int hp,sp,money,xp;
x
int maxhp,maxsp;
if(!get_family()) {
	write(family +" is not among us.\n");
return 1;
}
hp = ob->query_hp();
sp = ob->query_spell_point();
money = ob->query_money();
xp = ob->query_exp();
maxhp = ob->query_mhp();
maxsp = ob->query_msp();
write("family+ : ");
write("	HP:["+hp+"/"+maxhp+"]");
write("	SP:["+sp+"/"+maxsp+"]");
write("	MONEY: "+money+"       ");
write("    XP: "+xp+"\n");
return 1;
}
heal(str) {
int amt;
int sp;
sp = this_player()->quet_spell_point();
sscanf(str,"%d",amt);
if(amt < 0) {
write("UMMM, TRY AGAIN.\n");
return 1;
}
if (amt >sp) {
write ("You better rest first.\n");
return 1;
}
if(!get_family()) {
write(family+ "is not among us.\n");
return 1;
}
this_player()->add_spell_point(-amt);
ob->add_hit_point(amt);
write("You share your health with "+family+" by "+str+" points.\n");
tell_object(ob,this_player()->query_real_name()+ " has shared "+str+" of their health with you.\n");
return 1;
}
transfer(str) {
object test;
if(!present(str,this_player())) {
write("UHH, sorry but you must first have a "+str+".\n");
return 1;
}
test = present(str,this_player());
if(test->query_drop() == 1) {
write("You cant get rid of that.\n");
return 1;
}
write ("You share your wealth by giving "+str+" to "+family+".\n");
this_player()->add_spell_point(-20);
tell_object(ob,this_player()->query_real_name() + "gives you a "+str+".\n");
move_object(test,ob);
return 1;
}
bring_family(str) {
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
