#define MASTER_R "/players/mizan/closed/SpuckweaponDM.c"
#define AMMOTYPE "spuckballs"
inherit "obj/weapon";
int total_damage;

reset(arg) {
    ::reset(arg);
    set_name("Spuckball rifle");
    set_alias("rifle");
    set_class(14);
    set_weight(2);
    set_value(5000);
    set_hit_func(this_object());
}

init() {
    ::init();
    add_action("load","load");
}

short() {
    string doh;
    int ammo;
    object ob;
    ob=present(AMMOTYPE, this_object());
    if (ob) {
        ammo=ob->query_ammo();
    }
    doh = "A Spuckball rifle [" + ammo + "]";
    if (wielded) doh = doh + " (wielded)";
    if (this_player() && this_player()->query_level() > 39) doh = doh + " <Total damage inflicted: [" + total_damage + "]>";
    return doh;
}

long() {
    write("Your first reaction to this weapon is that of laughter. It is\n"+
          "composed of a semi-transparent squishy material that bends and\n"+
          "gives if you pinch it. However, facts are facts, and the fact is\n"+
          "that the Spuck line of weapons are most feared by many individuals.\n");
}

load(str) {
    object ammo,all_in_ob;
    int rounds2;

    if (!str || str != "rifle") return 0;
    all_in_ob = all_inventory(this_object());
    if (sizeof(all_in_ob) > 2) {
        write("There is no room for more Spuckballs.\n");
        return 1;
    }
    ammo=present(AMMOTYPE, this_player());
    if (!ammo) {
        write("You don't have any Spuckball tubes.\n");
        return 1;
    }
    move_object(ammo, this_object());
    this_player()->add_weight(-1);
    rounds2=ammo->query_ammo();
    if (!rounds2 || rounds2 > 99990) {
        destruct(ammo);
        write("Your Spuckball rifle rejects the crappy ammo.\n");
    }
    write("You pour some Spuckballs into the rifle.\n");
    write("There are [" + rounds() + "] rounds remaining.\n");
    say(capitalize(this_player()->query_name()) + " pours some Spuckballs into a Spuckball rifle.\n");
    return 1;
}

weapon_hit(attacker) {
    object clip;
    int ammo;
    clip=present(AMMOTYPE,this_object());
    if (clip) {
        if (rounds() < 2) {
            write("There are not enough Spuckballs to make the rifle work properly!\n");
            return -14;
        }
        write("You let the rifle rip and watch as "+capitalize(attacker->query_name())+" is pelted by spuckballs.\n");
        say(capitalize(this_player()->query_name())+" shoots "+capitalize(attacker->query_name())+" with a Spuckball rifle.\n");
        clip->lose_ammo(2);
        checked_hit(6);
        if (!rounds()) {
            destruct(clip);
            write("You've shot your last Spuckball!\n");
            return 1;
        }
        return 1;
    }
    write("Your rifle is out of Spuckballs!\n");
    return -14;
}

rounds() {
    object rc;
    int i;
    rc=present(AMMOTYPE, this_object());
    i=rc->query_ammo();
    return i;
}

checked_hit(arg) {
    int a_hp,a_dam;
    object a_attack;
    a_attack=this_player()->query_attack();
    if (a_attack) {
        a_hp=a_attack->query_hp();
        a_dam=random(arg);
        if (!a_attack->query_npc() && a_dam > 49) a_dam = 50;
        if (a_hp < a_dam || a_hp == a_dam) a_dam = a_hp - 1;
        a_attack->hit_player(a_dam);
        total_damage = total_damage + a_dam;
        MASTER_R->reg_rifle_hit(a_dam);
    }
}

can_put_and_get() {
    return 1;
}
