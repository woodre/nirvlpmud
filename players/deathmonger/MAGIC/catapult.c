object target, ammo;
int armed;
reset(arg) {
if (arg) return;
armed = 0;
}

id(str) { return str == "catapult"; }
short() { return "A huge catapult"; }
long() { write("You can arm, aim and fire the catapult.\n"+
"Simply 'arm with <object you wish to launch>'\n"+
"       'aim <person at whom you wish to aim>'\n"+
"       'fire'\n"+
"You may also 'disarm' the catapult\n");
}
init() {
add_action("disarm","disarm");
add_action("arm","arm");
add_action("aim","aim");
add_action("fire","fire");
}

arm(arg) {
string str;
if(!sscanf(arg,"with %s",str) == 1) {
write("You need to follow the arm command with the object you are loading.\n");
return 1;
}
ammo = present(str, this_player());
if (!ammo) ammo = present(str, environment(this_player()));
if (!ammo) { write("You don't have that on you.\n"); 
return 1;
}
move_object(ammo, this_object());
armed = 1;
say(this_player()->query_name()+" loads the catapult with "+str+"\n");
write("Ok.\n");
return 1;
}

disarm() {
say(this_player()->query_name() + " disarms the catapult\n");
write("You disarm the catapult.\n");
move_object(ammo, this_player());
armed = 0;
return 1;
}

aim(str) {
if (!str) {
write("Follow the aim command with the person at whom you want to aim.\n");
return 1;
}
target = find_player(str);
if (!target) {
write("Cannot find that target.\n");
write("Make sure you use the command like this: aim <player>\n");
return 1;
}
if(target->query_level() > 100){
    write("A mystical force aims the cannon away from the wizard.\n");
    return 1;
}
say("Catapult is aimed at "+str+"\n");
write("Ok.\n");
return 1;
}

fire() {
object ob;
int i;
if(!target) { write("Not aimed at anyone.\n");
return 1;
}
if(!ammo) {write("Nothing loaded into the catapult.\n");
return 1;
}
shout("You see a catapult-launched "+ammo->short()+" fly across\n"+
     "the MUD only to smash "+target->query_name()+" into the ground!\n");
move_object(ammo, environment(target));
armed = 0;
return 1;
}

