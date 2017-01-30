int pulled;
int thrown;
short() {
        return "A heavy nuclear handgrenade (lethal)";
}
long() {
        write("A heavy nuclear handgrenade, intended for seriously harming\n");
        write("one's foe. It does have its setbacks, though, so be warned.\n");
        write("Usage: 'pull pin', then 'throw handgrenade'. Do this quickly\n");
        write("or the grenade will blow up in your hands.\n");
        return 1;
}
id(str) { return str == "heavy handgrenade" || str == "handgrenade" 
                || str == "nuclear handgrenade";
}
get() {
        return 1;
}
drop() { return 0; }
init() {
        add_action("pull", "pull");
        add_action("throw", "throw");
}
pull(st) {
        if(st != "pin") return 0;
        if(!this_player()->query_attack()) {
                write("You must be fighting to use this object.\n");
                return 1;
        }
        pulled = 1;
        say(this_player()->query_name() + " pulls the pin on a nuke!!\n");
        write("You pull the pin on the nuclear handgrenade. Throw it!!!\n");
        call_out("nuke_me", 10, !thrown);
        return 1;
}
nuke_me() {
        int it;
        if(thrown) return 0;
        it = this_player()->query_hit_point() - 5;
        write("You didn't throw the grenade in time!!!!\n");
        say(this_player()->query_name() + " didn't throw the grenade!!!\n");
        write("As you stare at the grenade, you realize your time is now...\n");
        this_player()->reduce_hit_point(it);
        write("At the last moment, the Gods save you from certain death...\n");        
        say(this_player()->query_name() + "'s soul is expelled.\n");
        write("Your soul is expelled.\n");
        destruct(this_player());
        return 1;
}
throw(st) {     
        string short_str; 
        string long_str;
        object suit, who_obj;
        int i;
        if(!pulled) {
		write("You haven't pulled the pin yet!\n");
		return 1;
        }
        i = this_player()->query_hit_point() - 5;
        suit = present("radiation suit", this_player());
	if(st != "handgrenade" && st != "grenade") return 0;
        write("You throw the handgrenade in time! It hits its foe with a deadly\n");
        write("force!\n");
        if(!suit || call_other(suit, "query_rad_protected") != 1) {
                write("You are not protected from radiation!!!\n");
                this_player()->reduce_hit_point(i);
        } else {
                write("The radiation strikes through your suit!\n");
                this_player()->reduce_hit_point(-i/2);
        }
        who_obj = this_player()->query_attack();
        long_str = who_obj->long();
        write(long_str);
        short_str = who_obj->short();
        who_obj->set_short(short_str + " (mutating)");
        who_obj->set_long(long_str);
        i = 30 + random(40);
        who_obj->reduce_hit_point(i);
        say(this_player()->query_name() + " hits his foe with a nuke!\n");
        write("Your foe crumples to the ground in pain. You notice that\n");
        write("he is mutating because of the radiation.\n");
        destruct(this_object());
        return 1;        
}
