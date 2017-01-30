inherit "obj/armor";
#define CAP capitalize
#define RN this_player()->query_name()
#define POS this_player()->query_possessive()
int pos,count1,count2,flag;
reset(arg){
set_name("armor");
set_alias("bio-booster armor");
set_short("The Guyver Bio-Booster Armor");
set_value(0);
set_weight(1);
set_heart_beat(1);
set_ac(3);
set_type("armor");
set_long("This is the armor of Guyver-1, a deadly fighting machine.  You notice that \n"+
"it has rotating cannons and moveable armor plates covering its surface.\n"+
"You, as controller of the armor can rotate these plates and cannons to give\n"+
"you more flexibility in combat.  Type help armor4 for more help.\n");
}
init(){
::init();
add_action("help","help");
add_action("pos","pos");
pos = 1;
}
remove(str){
if (str=="armor"||str=="bio-booster armor"){
write("You hastily try to remove your cybernetic part and get a dose of \n"+
"biological feedback.\n");
if(this_player()->query_hp()>20) this_player()->hit_player(10);
}}
help(str){
if (str=="armor4"){
write("The Guyver Bio-booster armor can be telekinetically controlled by its \n"+
"wearer to respond to different battle situations.  It currently supports\n"+
"three postions of cannons and armor. \n"+
"Position 1:  Standard position (type pos 1)\n"+
"Position 2:  Assault position (type pos 2)\n"+
"Position 3:  Speed position (type pos 3)\n"+
"Position 4:  Blocking position (type 4)\n"+
"Each of the positions give a temporay boost in combat, followed by a brief\n"+
"decline.\nTo see what postion you are currently in type pos with no argument.\n");
}
}
pos(str){
int ac,wc;
ac = this_player()->query_ac();
wc = this_player()->query_wc();
if (flag || pos != 1){write("You must regain more power first.\n"); return 1;}
if (!str){write("You are currently in position "+pos+".\n");return 1;}
if (str=="1" || str=="one"){
if (pos==1){write("You are already set in standard mode\n");return 1;}
write("You telekinetically command your armor to assume Standard Position.\n");
say("There is a whirring sound and a scaping of metal as "+CAP(RN)+"'s armor changes to suit "+POS+" needs.\n");
pos = 1;
return 1;}
if (str=="2" || str=="two"){
if (pos==2){write("You are already in assault mode.\n"); return 1;}
write("You telekinetically command your armor to assume Assault Position.\n");
say("The massive cannons on "+CAP(RN)+"'s armor swivel to face forwards.\nYou become very afraid.\n");
pos = 2;
this_player()->set_wc(wc+2);
return 1;}
if (str=="3" || str=="three"){
if (pos==3){write("You are already in speed mode.\n"); return 1;}
write("You telekinetically command your armor to assume the Speed Position.\n");
say("The armoured plate and cannons on "+CAP(RN)+"'s armor space themselves out for speed.\n");
pos = 3;
this_player()->set_wc(wc++);
this_player()->set_ac(ac++);
return 1;}
if (str=="4" || str =="four"){
if (pos==4){write("You are already in Blocking Position.\n"); return 1;}
write("You telekinetically command your armor to assume Blocking Position.\n");
say("The armoured plates and cannons on "+CAP(RN)+"'s armor move to provide maximum protection.\n");
pos = 4;
this_player()->set_ac(ac+2);
return 1;}
write("You need to choose a postition between 1 and 4.\n");
return 1;}
heart_beat(i){
i++;

if (pos != 1) count1++;
write(count1);
if (count1>100){write("You exhaust your armors power supply.\nYou return to standard mode.\n");
pos = 1;
flag = 1;}
if (flag) count2++;
if (count2>100){write("Your armor has regained enough power to work again.\n");
flag = 0;}
}
