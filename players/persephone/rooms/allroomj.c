inherit"obj/weapon";
#define tpn this_player()->query_name()
#define atn attacker->query_name()
object part;
int i;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("battleaxe");
set_alias("axe");
set_short("The Legendary Battleaxe of Bresine");
set_long(
"You see something special\n");
set_value(10);
set_weight(3);
set_class(17);
set_hit_func(this_object());
}
weapon_hit(attacker) {
i = random(100);
if(i > 97){
write("You swing with all your might and whack off one of your opponent's arms.\n");
say(tpn+" whacks off one of "+attacker->query_name()+"'s arms.\n");
attacker->heal_self(-10);
part = clone_object("players/bismarck/closed/misc/part");
part->set_part("arm");
part->set_name(atn);
part->set_owner(tpn);
move_object(part,environment(this_player()));
return 5;
}
if((i>94)&&(i<97)){
write("You swing wildly and hack off your opponents leg just below the kneecap.\n");
say(tpn+" lunges forward and hacks off "+attacker->query_name()+"'s leg in a bloody mess.\n");
attacker->heal_self(-10);
part = clone_object("players/bismarck/closed/misc/part");
part->set_part("leg");
part->set_name(atn);
part->set_owner(tpn);
move_object(part, environment(this_player()));
return 5;
}
if((i>20)&&(i<22)){
write("In an excellent show of axemanship, you whack off your opponent's nose.\n");
say(tpn+" removes "+attacker->query_name()+"'s nose with crushing blow.\n");
attacker->heal_self(-10);
part = clone_object("players/bismarck/closed/misc/part");
part->set_part("nose");
part->set_name(atn);
part->set_owner(tpn);
move_object(part, environment(this_player()));
return 5;
}
if((i>30)&&(i<33)){
write("You swing the axe around, aiming for the head, but only get some ear.\n");
say(tpn+" misses the head but manages to get a good chunk of ear.\n");
attacker->heal_self(-5);
return 5;
}
if((i>40)&&(i<43)){
write("You swing your axe and slash open your opponents gut.\n");
write(attacker->query_name()+"'s guts fall out on the ground in a bloody mess.\n");
attacker->heal_self(-10);
part = clone_object("players/bismarck/closed/misc/part");
part->set_part("guts");
part->set_name(atn);
part->set_owner(tpn);
move_object(part, environment(this_player()));
return 5;
}
if((i==69) || (i==68)){
if(random(30) > 14){
write("You remove your opponent's head with a swing of your axe. THWAK!\n");
say(tpn+" deals "+attacker->query_name()+" a deadly blow.\n");
attacker->heal_self(-100);
part = clone_object("players/bismarck/closed/misc/part");
part->set_part("head");
part->set_name(atn);
part->set_owner(tpn);
move_object(part, environment(this_player()));
}
return 5;
}
if(i == 70){
if(random(50) < 13){
write("The axe slips and you deal yourself a devastating blow!\n");
this_player()->add_hit_point(-50);
return 1;
}
return -6;
}
if (i < 14){
write("You reduce your opponent to a bloody pulp!\n");
attacker->heal_self(-6);
return 5;
}
return 3;
   }
