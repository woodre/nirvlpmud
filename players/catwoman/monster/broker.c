/* reset(arg) fixed by Vertebraker [5.29.01] */


inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_hp(180);
   set_name("broker");
   set_alias("broker");
   set_short("A Item Broker");
   set_wc(16);
   set_ac(9);
   set_al(142);
   set_long("This is Rich, the Item Broker.\nAsk him to Judge <item1> <item2>.\n");
   set_level(12);
   set_chat_chance(40);
   load_chat("Rich looks around briefly.\n");
   load_chat("Rich says:  So have you seen the weapon out on the island?\n");
   load_chat("Rich says:  Hard to believe they allow that powerfull weapons out there!\n");
   load_chat("Rich sighs.\n");
   ::reset(0);
}

/*break*/
init(){
add_action("judge","judge");
}
judge(z) {
int a,b;
string as,bs,str;
object oa,ob;
if (!z || sscanf(z," %s",str)!=2) str = z;
if (!str || sscanf(str,"%s %s",as,bs)!=2 ) {
write("Judge what against what?\n");
return 1;
}
oa=present(as,this_player());
ob=present(bs,this_player());
if (!oa) {
write("Couldn't find "+as+"\n");
return 1;
}
if (!ob) {
write("Couldn't find "+bs+"\n");
return 1;
}
a = oa->weapon_class();
b = ob->weapon_class();
if (a && b) {
if (a==b) 
write("  Rich says: They are of equal value.\n");
else if (a<b) 
write("  Rich says: "+bs+" is better.\n");
else 
write("  Rich says: "+as+" is better.\n");
return 1;
}
a = oa->armour_class();
b = ob->armour_class();
 
if (a && b) {
if (a==b) 
write("  Rich says: They are of equal value.\n");
else if (a<b) 
write("  Rich says: "+bs+" is better.\n");
else 
write("  Rich says: "+as+" is better.\n");
return 1;
}
a = oa->query_value();
b = ob->query_value();
if (a && b) {
if (a==b) 
write("  Rich says: They are of equal value.\n");
else if (a<b) 
write("  Rich says: "+bs+" is better.\n");
else 
write("  Rich says: "+as+" is better.\n");
return 1;
}
write("  Rich says: I'm confused. I think you are comparing different types of\n");
write("of objects. Either that, or valueless ones.\n");
return 1;
}
