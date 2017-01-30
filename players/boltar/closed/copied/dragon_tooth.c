int i, level, nastiness;
string name;
object nasty,player,room;

id(str) {
    return (str == "dragon tooth" || str == "tooth");
}

reset() {nastiness=15;}

init () {
    add_action("drop"); add_verb("drop");
}
    
short() {
    return "A dragon's tooth";
}

long() {
    write("The tooth of a dragon.\n");
}

get() { return 1; }

drop(str) {
    player = this_player();
    room = environment(player);
    name = call_other(player,"query_name",0);
    if (id(str)) {
        say(name + " accidentally summons a demon.\n");
        tell_room(room, "A demon appears in a blast of fire!\n");
        nasty = clone_object("obj/monster");
        call_other(nasty, "set_name", "demon");
        call_other(nasty, "set_alias", "demon");
        call_other(nasty, "set_level",10+random(6));
        call_other(nasty, "set_al", -400);
        call_other(nasty, "set_short", "A summoned demon is here");
        call_other(nasty, "set_wc",15);
        call_other(nasty, "set_ac",random(nastiness/2));
        call_other(nasty, "set_aggressive", 1);
	call_other(nasty, "set_can_kill", 1);
        call_other(nasty, "set_chance",random(30));
        call_other(nasty, "set_spell_mess1", "The demon throws fire.");
        call_other(nasty, "set_spell_mess2", "The demon throws fire at you.");
        call_other(nasty, "set_spell_dam",10+random(20));
        move_object(nasty, room);
        call_other(nasty, "attack_object", player);
	destruct(this_object());
        return 1;
	}
    return 1;
}

query_auto_load() {
    return("players/vayde/dragon_tooth:");
}

