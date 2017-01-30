inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("guardian demon");
    set_alias("demon");
set_alt_name("guardian");
    set_race("demon");
    set_short("Guardian Demon");
    set_long("\
This is the guardian demon of the abyss.  You must kill him to leave\n\
this place, or find another way out.\n");
    set_level(22);
    set_hp(600);
    set_al(-1000);
    set_wc(34);
    set_ac(19);
    set_chance(60);
    set_spell_dam(10+random(30));
    set_spell_mess1("The Guardian demon casts a fireball.");
    set_spell_mess2("The Guardian demon casts a fireball at you.");

    add_money(3000 + random(20));
/*
    move_object(clone_object("/players/scathe/closed/rod3"), this_object());
*/
}

void heart_beat() {
    int dam;
    object attacker, room;
    string aname;

    ::heart_beat();
    room = environment();
    if(!room) return;
    attacker = (object) this_object()->query_attack();

    if (attacker && living(attacker) && present(attacker, room)) {
        aname = (string) attacker->query_name();

        if (!attacker->query_ghost()) {
            if (1 == random(5)) {
                tell_room(room, "Guardian demon smashed " + aname +
                                " with a bone crushing sound.\n");
                attacker->hit_player(20 + random(10));
            }
            else {
                tell_room(room, "Guardian demon missed " + aname + ".\n");
            }
        }
        if (attacker && !attacker->query_ghost()) {
            if (1 == random(5)) {
                tell_room(room, "Guardian demon smashed " + aname +
                                " with a bone crushing sound.\n");
                attacker->hit_player(20 + random(10));
            }
            else {
                tell_room(room, "Guardian demon missed " + aname + ".\n");
            }
        }
        if (attacker && !attacker->query_ghost()) {
            if (1 == random(5)) {
                tell_room(room, "Guardian demon smashed " + aname +
                                " with a bone crushing sound.\n");
                attacker->hit_player(20 + random(10));
            }
            else {
                tell_room(room, "Guardian demon missed " + aname + ".\n");
            }
        }
        if (attacker && !attacker->query_ghost()) {
            if (1 == random(5)) {
                tell_room(room, "Guardian demon smashed " + aname +
                                " with a bone crushing sound.\n");
                attacker->hit_player(20 + random(10));
            }
            else {
                tell_room(room, "Guardian demon missed " + aname + ".\n");
            }
        }
        if (attacker && !attacker->query_ghost()) {
            if (1 == random(5)) {
                tell_room(room, "Guardian demon smashed " + aname +
                                " with a bone crushing sound.\n");
                attacker->hit_player(20 + random(10));
            }
            else {
                tell_room(room, "Guardian demon missed " + aname + ".\n");
            }
        }
    }
}
