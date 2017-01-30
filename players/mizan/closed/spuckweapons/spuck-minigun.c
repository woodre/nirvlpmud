#define MASTER_R "/players/mizan/closed/SpuckweaponDM.c"
#define AMMOTYPE "spuckballs"
inherit "obj/weapon";

int pleva;
int total_damage;

reset(arg) {
    ::reset(arg);
    pleva=1;
    set_name("Spuckball Minigun");
    set_alias("minigun");
    set_class(17);
    set_weight(6);
    set_value(0);
    set_hit_func(this_object());
}

init() {
    ::init();
    add_action("load","load");
    add_action("adjust_dial","shape");
}

short() {
    string doh;
    int ammo;
    object ob;
    ob=present(AMMOTYPE, this_object());
    if (ob) {
        ammo=ob->query_ammo();
    }
    doh = "A Super Spuckball minigun [" + ammo + "]";
    if (wielded) doh = doh + " (wielded)";
    if (this_player() && this_player()->query_level() > 39) doh = doh + " <Total damage inflicted: [" + total_damage + "]>";
    return doh;
}

long() {
    if (this_player()) say(capitalize(this_player()->query_name()) + " gazes reverently at the Super Spuckball minigun.\n");
    write("Cleanly made of pliable, dark blue Spuckstuff, this weapon sits somewhere in\n"+
          "power between the single-fire Spuckball Blaster and the universally feared\n"+
          "Super Spuckball Flexgun.\n\n"+
          "Like its bigger sibling it has a variable-shaped barrel but its smaller, so\n"+
          "that you can fit your fist in it instead of your face. Still delightfully evil.\n");
    write("\nIt appears that you can 'shape' the barrel of this weapon.\n");
    if (pleva == 4) {
        write("The barrel is flat, like a vacuum cleaner nozzle.\n");
    }
    if (pleva == 2) write("The barrel seems to be fully opened up.\n");
    if (pleva == 1) write("The barrel opening seems to be somewhat smaller than usual.\n");
}

load(str) {
    object ammo,all_in_ob;
    int round_weight;
    int rounds2;
    if (!str || str != "minigun") return 0;
    all_in_ob = all_inventory(this_object());
    if (sizeof(all_in_ob) > 18) {
        write("There is no room for more Spuckballs.\n");
        return 1;
    }
    ammo=present(AMMOTYPE, this_player());
    if (!ammo) {
        write("You don't have any Spuckball tubes.\n");
        return 1;
    }
    move_object(ammo, this_object());
    round_weight=ammo->query_weight();
    this_player()->add_weight(-round_weight);
    rounds2=ammo->query_ammo();
    if (!rounds2 || rounds2 > 99990) {
        destruct(ammo);
        write("The Spuckball minigun rejects the crappy ammo.\n");
    }
    write("You pour some Spuckballs into the minigun.\n");
    write("There are [" + rounds() + "] rounds remaining.\n");
    say(capitalize(this_player()->query_name()) + " pours some Spuckballs into a Super Spuckball Minigun.\n");
    return 1;
}

weapon_hit(attacker) {
    object clip;
    int ammo;
    clip=present(AMMOTYPE,this_object());
    if (clip) {
        if (rounds() < (pleva * 2)) {
            write("There are not enough Spuckballs to make the minigun work properly!\n"+
                  "It begins to chuggle and convulse violently.\n");
            return -10;
        }
        if (pleva > 1) tell_room(environment(this_player()), "* * FWOP! * *\n");
        if (pleva == 2 || pleva == 1) tell_room(environment(this_player()), capitalize(attacker->query_name()) + " is pelted with rounds by a Spuckball minigun.\n");
        if (pleva == 4) {
            tell_room(environment(this_player()), "The flattened barrel of the minigun speads Spuckball goo everywhere.\n");
            say(capitalize(attacker->query_name())+" is peppered with a spray of high-velocity gunk.\n");
        }
        clip->lose_ammo(pleva * 2);
        if (pleva == 4) area_checked_hit();
        if (pleva == 2) checked_hit(40);
        if (pleva == 1) checked_hit(20);
        if (!rounds()) {
            destruct(clip);
            write("You've shot the last of your Spuckballs!\n");
            return 1;
        }
        if (1==random(16) && pleva > 1 && this_player()->query_level() < 20) {
            write("The recoil of the blast knocks you off your feet!\n");
            say((this_player()->query_name())+ " is buffeted clear across the room from the recoil.\n");
            this_player()->run_away();
            return 1;
        }
        return 1;
    }
    write("Your minigun is out of Spuckballs!\n");
    return -15;
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
        MASTER_R->reg_minigun_hit(a_dam);
    }
}

area_checked_hit(arg) {
    object foo;
    int dam_divisor,dam_charges;
    dam_divisor = count_livings();
    if (dam_divisor > 2) dam_divisor = dam_divisor - 1;
    dam_charges = 200 / dam_divisor;
    foo=first_inventory(environment(this_player()));
    while (foo) {
        object foo2;
        foo2=foo;
        foo=next_inventory(foo);
        if (living(foo2)) {
            if (foo2->query_npc()) {
                int foo_hp,foo_damage;
                foo_hp=foo2->query_hp();
                foo_damage=random(dam_charges);
                if (foo_hp < foo_damage || foo_hp == foo_damage) foo_damage = foo_hp - 1;
                tell_room(environment(this_player()),
                          capitalize(foo2->query_name()) + " is showered by nubs of molten Spuckballs!\n");
                /* CHECK FOR FIGHT TOO */
                foo2->attack_object(this_player());
                foo2->hit_player(foo_damage);
                total_damage = total_damage + foo_damage;
                MASTER_R->reg_minigun_hit(foo_damage);
            } else {
                tell_room(environment(this_player()),
                          capitalize(foo2->query_name()) + " escapes harm for some reason.\n");
            }
        }
    }
    return 1;
}

count_livings() {
    object moo;
    int mmmrugs,whees;
    moo=first_inventory(environment(this_player()));
    while (moo) {
        object squish;
        squish = moo;
        moo = next_inventory(moo);
        if (living(squish)) whees = whees + 1;
    }
    return whees;
}

adjust_dial(str) {
    int temp_pleva;
    if (str != "barrel" || !str) return 0;
    if (environment(this_object()) != this_player()) {
        write("You have to get the Spuckball minigun first.\n");
        return 1;
    }
    say(capitalize(this_player()->query_name()) + " shapes the barrel on a Super Spuckball minigun.\n");
    write("You shape the barrel, and it seems to move and flex by itself.\n");
    if (pleva == 4) {
        write("The barrel of the Spuckball minigun narrows and shrinks to half its size.\n"+
              "You can barely stick a golf ball nside it.\n");
        say("The barrel of the weapon shrinks and narrows into a purposeful gaze.\n");
        temp_pleva = 1;
    }
    if (pleva == 2) {
        write("The barrel of the Spuckball minigun seems to flatten out and expand.\n"+
              "It's scope and spread of its attack seems much wider too.\n");
        say("The barrel fans out and spreads. It looks pretty fearsome.\n");
        temp_pleva = 4;
    }
    if (pleva == 1) {
        write("The barrel of the Spuckball minigun expands biggly.\n"+
              "You can almost fit your head in it now.\n");
        say("The barrel keeps expanding until it is as big as your fist. Wow!\n");
        temp_pleva = 2;
    }
    pleva = temp_pleva;
    return 1;
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

