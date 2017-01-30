#define user environment(this_object())
#define att user->query_attack()
#define ahp att->query_hp()
int amt, DAM, readied;
reset() {
        call_out("hb",2);
}
id(str) { return str == "slayer" || str == "sword"; }
short() {
        if(readied == 1) { return "Slayer Sword (readied)"; }
        if(readied == 0) { return "Slayer Sword"; }
}
        long() {
        write("The first thing you noticed about the sword is the magnificant\n"+
        "craftmanship.  Its maker was very skilled at shaping the unkown\n"+
        "material it is made out of.  It is pure black, seeming to absorb\n"+
        "any light that touches the shinny surface.  Perhaps that is where\n"+
        "its great powers lie.  There is an inscription on the side that might\n"+
        "be worth reading.  Your sword has "+amt+" power left.\n");
        }
init() {
        add_action("destroy_attack","destroy_attack");
        add_action("final_death_stab","final_death_stab");
        add_action("slayer","slayer");
        add_action("read","read");
}
hb() {
        if(amt < 0) {
        tell_object(user, "Your slayer stops glowing and fades away.\n");
        remove_call_out("hb");
        destruct(this_object());
        return 1;
        }
        if(att && ahp < 50) {
        command("final_death_stab", user);
        }
	     if(att && readied == 1) {
        command("destroy_attack", user);
        }
call_out("hb", 2);
}
read(str) {
        if(str == "inscription") {
	     write("Although the darkness of the sword makes it hard to read, you can make out:\n");
        write("The power of this sword is limited.  You should ready the\n"+
        "sword for battle with the command 'slayer ready'.  To save on its\n"+
        "magic powers, use the command 'slayer unready'.\n");
        return 1; }
}
slayer(str) {
        if(str == "ready") {
        if(readied == 1) {
        write("Your Slayer Sword is already prepared for battle.\n");
        return 1; }
        write("You ready you Slayer Sword for battle.\n");
	     say(capitalize(user->query_real_name())+" readies "+user->query_possessive()+" Slayer Sword.\n");
        readied = 1;
        return 1; }
        if(str == "unready") {
        if(readied == 0) {
        write("Your Slayer Sword is not readied.\n");
        return 1; }
        write("You unready your Slayer Sword.\n");
        readied = 0;
        return 1; }
}
destroy_attack() {
        object attacker;
        int x, damage;
        string attname, username;
        x = random(100);
        username = capitalize(user->query_real_name());
        attacker=(this_player()->query_attack());
        attname = capitalize(attacker->query_real_name());
        if(!this_player()->query_attack()){
        return 1;
}
        if(x <= 10) {
        write("You slice "+attname+" in the arm with the Slayer.\n");
        say(username+" slices "+attname+" in the arm with the Slayer.\n");
        damage = (random(10));
        attacker->hit_player(damage);
        amt = amt - damage;
        return 1;
        }
        if(x > 10 && x <= 20) {
        write("You cut open "+attname+"'s guts with the Slayer.\n");
        say(username+" cuts open "+attname+"'s guts with the Slayer.\n");
        damage = (random(12));
        attacker->hit_player(damage);
        amt = amt - damage;
        return 1;
}
        if(x > 20 && x <=40) {
        write("You slice "+attname+" across the leg with the Slayer.\n");
        say(username+" slices "+attname+" in the leg with the Slayer.\n");
        damage = (random(15));
        attacker->hit_player(damage);
        amt = amt - damage;
        return 1; }
        if(x > 40 && x <= 60) {
        write("You slice "+attname+" across the chest with the Slayer.\n");
        say(username+" slices "+attname+" across the chest with the Slayer.\n");
        damage = (random(20));
        attacker->hit_player(damage);
        amt = amt - damage;
        return 1; }
        if(x >60 && x < 92) {
        write("You cut "+attname+" across the face with the Slayer.\n");
        say(username+" cuts "+attname+" across the face with the Slayer.\n");
        attacker->hit_player(random(20));
        return 1; }
        write("Your Slayer makes a huge gash in "+attname+"'s throat.\n");
        say(username+"'s Slayer makes a huge gash in "+attname+"'s throat.\n");
        damage = (random(25));
        attacker->hit_player(damage);
        amt = amt - damage;
        return 1;
}
final_death_stab() {
        if(!user->query_attack()) return;
        write("You plung the Slayer into "+user->query_attack()->query_real_name()+"'s heart causing the killing blow.\n");
        say(capitalize(this_player()->query_real_name())+" screams as "+this_player()->query_possessive()+" plunges the Slayer Sword into "+capitalize(user->query_attack()->query_real_name())+"'s heart causing its death.\n");
        amt = amt - ahp;
        user->query_attack()->hit_player(100);
        return 1;
}
get() { return 1; }
drop() { return 0; }
query_save_flag() { return 1; }
set_amt(AMT) { amt = AMT; }

