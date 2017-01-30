/*I have finally coded something all by my damn self.. it's rather*/
/*pathetic.. but one has to start somewhere... <smile>            */
/*Paulasx (Paula Sexton) July 28, 1993                            */
id(str) { return str=="staff"; }
short() { write("Paula's staff of information, since the 'stat' command sucks.\n"); }
long() { write("A long slender staff of knowledge.  It is really rather worthless.\n"); }
drop() { return 1; }
get() {return 1;}
init() {
add_action("info","info");
}
info(str) {
object ob;
if(!str) return;
ob = find_living(str);
if(!ob){
write("STAFF:  Who in the hell are you talking about?!?\n");
return 1; }
write("Player: "+ob->query_real_name()+" "+ob->query_title()+"\n");
write("Level: "+ob->query_level()+"     Extra Level: "+ob->query_extra_level()+"     Gender: "+ob->query_gender()+"\n");
write ( "HP: "+ob->query_hp()+ "/"+ob->query_mhp()+"  ");
write("SP :"+ob->query_sp()+"/"+ob->query_msp()+"\n");
write("Gold: "+ob->query_money()+"\n");
write("Guild Name: "+ob->query_guild_name()+"\nGuild Exp: "+ob->query_guild_exp()+"\n");
write("Guild Rank: "+ob->query_guild_rank()+"\nAlignment: "+ob->query_alignment()+"\n\n");
write("Sta: "+ob->query_attrib("sta")+"  Str: "+ob->query_attrib("str")+"  Int: "+ob->query_attrib("int")+"  Mag: "+ob->query_attrib("mag")+"  Pie: "+ob->query_attrib("pie"));
write("  Wil: "+ob->query_attrib("wil")+"  Ste: "+ob->query_attrib("ste")+"  Luc: "+ob->query_attrib("luc")+"\n");
write("Armor Class: "+ob->query_ac()+"  Weapon Class: "+ob->query_wc()+"  Weight: "+ob->query_weight()+"\n");
write("Intoxicated: "+ob->query_intoxination()+"  Quest Points: "+ob->query_quest_point()+"  Age: "+ob->query_age()/43000+" days  \n\n");
write("Quests: "+ob->query_quests()+"\n\n");
return 1;
}
