#define user environment(this_object())
#define att user->query_attack()
int amt;
id(str) { return str == "wand" || str == "wand of acid"; }
short() {
        return "Wand of Acid ["+amt+"]"; 
        }
long() {
        write("A wand of acid created within the depths of hell.\n"+
        "You can 'cast wand' to fire acid at your foe and cause them\n"+
        "great amounts of pain. You can also 'recharge <amt>' if your\n"+
        "wand runs out of acid.  You wand currently has "+amt+" acid left.\n");
        }
init() {
        add_action("cast","cast");
        add_action("recharge","recharge");
}
cast(str) {
        int DMG;
        if(str == "wand") {
        if(!att) {
        write("You are not attacking anything.\n");
        return 1; }
        if(!att->query_npc()) {
        write("Your wand of acid does not effect players.\n");
        return 1; }
        DMG = random(50);
        if(amt < DMG) {
        write("Your wand does not have "+DMG+" acid left.\n");
        return 1; }
        amt = amt - DMG;
        write(capitalize(att->query_real_name())+" is burned by a steam of acid!\n");
	     say(capitalize(user->query_real_name())+" fires a stream of acid from "+user->query_possessive()+" wand.\n"+
	     ""+capitalize(att->query_real_name())+" is burned by the acid!\n");
	     att->hit_player(DMG);
        return 1; 
	}
}
recharge(str) {
        int coinage;
        if(!str) {
        write("How much do you want to recharge your wand?\n");
        return 1; }
	     if(!sscanf(str, "%d", coinage)) {
	     write("You must specify an amount of coins you want to use.\n");
	     return 1; }
	     sscanf(str, "%d", coinage);
        if(this_player()->query_money() < coinage) {
        write("You don't have enough gold coins to sacrifice.\n");
        return 1; }
        if(coinage < 1) {
        write("Shardak forbids you to dishonor him by cheating.\n");
        return 1; }
        write("You recharge your wand with "+coinage/10+" extra acid.\n");
        say(capitalize(user->query_real_name())+" recharges a Wand of Acid.\n");
        this_player()->add_money(-coinage);
	     amt = amt + (coinage/10);
        return 1;
}
                
get() { return 1; }
drop() { return 0; }
query_save_flag() { return 1; }
set_amt(COIN) { amt = COIN; }

