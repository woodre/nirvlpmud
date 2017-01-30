#define MASTER_R "/players/mizan/closed/SpuckweaponDM.c"
#define AMMOTYPE "spuckballs"
inherit "obj/weapon";

int total_damage;

reset(arg) {
    ::reset(arg);
    set_name("Spuckball cannon");
    set_alias("cannon");
    set_class(20);
    set_weight(4);
    set_value(21000);
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
    doh = "A Spuckball cannon [" + ammo + "]";
    if (wielded) doh = doh + " (wielded)";
    if (this_player() && this_player()->query_level() > 39) doh = doh + " <Total damage inflicted: [" + total_damage + "]>";
    return doh;
}

long() {
    write("This is a rather comical looking thing. You are able to squeeze\n"+
          "it, and bend it, but it has a barrel with a diameter the size\n"+
          "of your closed fist. That fact gives you the chills.\n");
}

load(str) {
    object ammo,all_in_ob;
    int rounds2;
    if (!str || str != "cannon") return 0;
    all_in_ob = all_inventory(this_object());
    if (sizeof(all_in_ob) > 7) {
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
        write("Your Spuckball cannon rejects the crappy ammo.\n");
    }
    write("You pour some Spuckballs into the cannon.\n");
    write("There are [" + rounds() + "] rounds remaining.\n");
    say(capitalize(this_player()->query_name()) + " pours some Spuckballs into a Spuckball cannon.\n");
    return 1;
}

weapon_hit(attacker) {
    object clip;
    int ammo;
    /* next line added by verte */
    if (!attacker) return;
    clip=present(AMMOTYPE,this_object());
    if (clip) {
        if (rounds() < 6) {
            write("There are not enough Spuckballs to make the cannon work properly!\n");
            return -17;
        }
        write("You hear a 'THWOP!' and a Spuckball blasts "+capitalize(attacker->query_name())+" squarely where it counts.\n");
        /* next line added by verte */
        if (this_player())
            say(capitalize(this_player()->query_name())+" blasts "+capitalize(attacker->query_name())+" with a spuckball cannon.\n");
        clip->lose_ammo(6);
        checked_hit(26);
        if (!rounds()) {
            destruct(clip);
            write("You've shot your last Spuckball!\n");
            return 1;
        }
        return 1;
    }
    write("Your cannon is out of Spuckballs!\n");
    return -18;
}

rounds() {
    object rc;
    int i;
    rc=present(AMMOTYPE, this_object());
    i=rc->query_ammo();
    return i;
}

can_put_and_get() {
    return 1;
}

query_save_flag() {
    return 1;
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
        MASTER_R->reg_cannon_hit(a_dam);
    }
}

