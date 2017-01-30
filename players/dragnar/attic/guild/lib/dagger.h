#include "/players/dragnar/guild/defs/def.h"
dagger(str) {
        int dmg;
        object ob, obj;
	     dmg=(random(60) + 5);
	     if(!str && !att) {
		write("Who do you want to throw a dagger at?\n");
        return 1;
        }
	     if(!str && att) { str = att->query_real_name(); }
        ob=present(str, environment(this_player()));
        if(!ob) {
        write(capitalize(str)+ "is not here.\n");
        return 1;
                }
        if(find_player(str)) {
	write("Shardak does not allow you to use your powers against players.\n");
        return 1; }
        if(!living(ob)) {
	write("Only a foolish warrior would try to kill something that is not alive.\n");
        return 1;
                }
	if(usp < 10) {
	write("You do not have enough spell points to sacrifice!\n");
        return 1;
	}
	write("Your magical dagger stabs "+ob->query_real_name()+" in the chest.\n");
	say(capname+" stabs "+capitalize(ob->query_real_name())+" in the chest with a magical dagger.\n");
	this_player()->spell_object(ob, "dagger", dmg, 0);
	this_player()->add_spell_point(-10);
	if(ob && !ob->query_attack()) { ob->attacked_by(this_player()); }
                return 1;
}
