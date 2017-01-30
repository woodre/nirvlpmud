inherit "players/randalar/guild/armor";

drop() { return 1; }

query_auto_load() { return "players/randalar/guild/guild_cloak:"; }

reset(arg) {
if(arg) return;
::reset(0);
set_name("guild_cloak");
set_value(0);
set_weight(0);
set_ac(2);
set_arm_light(1);
set_alias("cloak");
set_type("other");
set_short("The Elementalists' Cloak");
set_long("This is an Elementalists' Cloak.\n"+
         "To see what you can do, type 'info'.\n");
}

init() {
    ::init();
    add_action("plague", "plague");
    add_action("telepathic", "et");
/*  add_action("quit", "quit"); */
    add_action("ew", "ew");
    add_action("info", "info");
    add_action("info2", "info2");
    add_action("info3", "info3");
    add_action("decorpse", "decorpse");
    add_action("createbag", "createbag");
    add_action("guild", "guild");
    add_action("scan", "scan");
    add_action("power", "power");
    add_action("mud_slide", "mudslide");
    add_action("earthquake", "earthquake");
    add_action("swallow", "swallow");
    add_action("flame", "flame");
    add_action("pillar", "pillar");
    add_action("firestone", "fire");
    add_action("summon", "summon");
    add_action("whirlpool", "whirlpool");
    add_action("flood", "flood");
    add_action("lightning", "lightning");
    add_action("tornado", "tornado");
    add_action("blizzard", "blizzard");
    add_action("hurricane", "hurricane");
    add_action("cure", "cure");
}

plague(str) {
    object ob;
    if(this_player()->query_level() >= 20) {
        if(!str) {
            write("Who do you want the spell cast upon?\n");
            return 1;
        }
        if(this_player()->query_spell_points() < 170) {
            write("You don't have enough spell points.\n");
            return 1;
        }
    ob = present(lower_case(str), environment(this_player()));
    if (!ob) return 0;
    write("You cast the plague upon " + str + ".\n");
    say(this_player()->query_name()+" casts a Black Plague.\n");
    ob->hit_player(random(100)+100);
    this_player()->restore_spell_points(-170);
    return 1;
    }   else   {
    write("You aren't high enough level to cast this spell.\n");
    return 1;
    }
}

ew() {
    object list;
    int i;
    list = users();
    for (i = 0; i < sizeof(list); i++) {
        string sh;
        sh = list[i]->short();
        if (in_editor(list[i]))
           continue;
        if (list[i]->query_guild() != "elementalist")
           continue;
        if (sh && query_idle(list[i]) >= 120)
           sh += " (idle)";
        if (sh)
           write(sh + " (" + list[i]->query_level() + ")\n");
    }
    return 1;
}

telepathic(str) {
    int i;
    object who;
    if (!str) return 0;
    for (i=sizeof(users())-1; i >= 0; i--) {
        who = users()[i];
        if (who->query_guild() == "elementalist")
        tell_object(who, this_player()->query_name()+" => "+str+"\n");
    }
    return 1;
}

info() {
    cat("/open/randalar/info");
    return 1;
}

info2() {
    cat("/open/randalar/info2");
    return 1;
}

info3() {
    cat("/open/randalar/info3");
    return 1;
}

createbag() {
    object ob;
    if (this_player()->query_level() >= 5) {
        if (this_player()->query_spell_points() < 30) {
            write("You don't have enough spell points.\n");
            return 1;
        }
        if (present("guild_bag", this_player())) {
            write("You have already created a bag.\n");
            return 1;
        }
        ob = clone_object("players/randalar/guild/bag");
        move_object(ob, this_player());
        this_player()->restore_spell_points(-30);
    write("You create a bag.\n");
    say(this_player()->query_name()+" creates a bag from the elements.\n");
    return 1;
    }   else   {
        write("You are not high enough level to perform this spell.\n");
    }
}

quit() {
    command("save", this_player());
    write("Saving "); write(this_player()->query_name()); write(".\n");
    say(this_player()->query_name()+" left the game.\n");
    cat("/EXIT");
    destruct(this_player());
    return 1;
}

decorpse() {
    object ob;
    ob = present("corpse", environment(this_player()));
    if (!ob) write("There is no corpse here.\n");
    destruct(ob);
    write("You use the power of the elements to destroy a corpse.\n");
    say(this_player()->query_name()+" uses the power of the elements and destroys a corpse.\n");
    return 1;
}

guild() {
    if (this_player()->query_spell_points() < 0) {
        write("You do not have enough spell points.\n");
        return 1;
    }
    say(this_player()->query_name()+" makes a magical gesture, and vanishes!\n");
    write("You make a gesture and feel yourself moved.\n");
    tell_room("players/randalar/guild/adv_guild", this_player()->query_name()+" suddenly appears before you!\n");
    move_object(this_player(), "players/randalar/guild/adv_guild");
    this_player()->restore_spell_points(-30);
    return 1;
}

scan(str) {
    object ob;
    if (this_player()->query_spell_points() < 5) {
        write("You don't have enough spell points.\n");
        return 1;
    }
    if (!str) {
        write("Scan who?\n");
        return 1;
    }
    ob = present(lower_case(str), environment(this_player()));
    if (this_player()->query_level() >= 2) {
        say(this_player()->query_name()+" chants a spell and scans the alignment of " + str + ".\n");
        if (ob->query_alignment() < -50) {
            write(capitalize(str)+" is of an evil alignment.\n");
            return 1;
        }
        if (ob->query_alignment() > 50) {
            write(capitalize(str)+" is of a good alignment.\n");
            return 1;
        }
        if (ob->query_alignment() > -50 && ob->query_alignment() < 50) {
            write(capitalize(str)+" is of a neutral alignment.\n");
            return 1;
        }
        this_player()->restore_spell_points(-5);
        return 1;
    }   else   {
        write("You are not high enough level.\n");
        return 1;
    }
}

power(str) {
    object ob;
    object obj, obje;
    object objec;
    if (this_player()->query_spell_points() < 5) {
        write("You do not have enough spell points.\n");
        return 1;
    }
    ob = present(lower_case(str), environment(this_player()));
    if (!ob) return 0;
    obje = ob->query_hp();
    obj = ob->query_max_hp();
    this_player()->restore_spell_points(-5);
        say(this_player()->query_name()+" concentrates on " + capitalize(str) + ", determining how much power it has left.\n");
        objec = 100*obje/obj;
        write(capitalize(str) + " has " + objec + "% of its hitpoints remaining.\n");
        return 1;
}

mud_slide(str) {
    object ob;
    if (this_player()->query_spell_points() < 5) {
        write("You don't have enough spell points.\n");
        return 1;
    }
    if (!str) {
        write("At who?\n");
        return 1;
    }
    ob = present(lower_case(str), environment(this_player()));
    ob->hit_player(random(5)+5);
    this_player()->restore_spell_points(-5);
    write("You create a mudslide.\n");
    say(this_player()->query_name() + " creates a mudslide which wipes " + capitalize(ob->query_name()) + " off its feet.\n");
    return 1;
}

cure(str) {
    object ob;
    if (this_player()->query_level() >= 11) {
        if (this_player()->query_spell_points() < 100) {
            write("You don't have enough spell points.\n");
            return 1;
        }
        if (!str) {
            write("Cure who?\n");
            return 1;
        }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        if (ob == this_player()) {
            this_player()->restore_spell_points(-1100);
            ob->heal_self(1000);
            return 1;
        }
        ob->heal_self(1000);
        this_player()->restore_spell_points(-100);
        return 1;
    }  else  {
    write("You are not high enough level.\n");
    return 1;
    }
}

earthquake(str) {
    object ob;
    if (this_player()->query_level() >= 3) {
        if (!str) return 0;
        if (this_player()->query_spell_points() < 10) {
            write("You don't have enough spell points.\n");
            return 1;
        }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) {
            write("That person is not here.\n");
            return 1;
        }
        write("The ground rumbles under " + capitalize(str) + "'s feet.\n");
        say("The ground rumbles uunder " + capitalize(str) + "'s feet, a result of " + this_player()->query_name() + "'s spell.\n");
        ob->hit_player(random(10) + 10);
        this_player()->restore_spell_points(-10);
        return 1;
    } else  {
    write("You are not high enough level for this spell.\n");
    return 1;
    }
}

swallow(str) {
    object ob;
    if (this_player()->query_level() >= 5) {
        if (!str) return 0;
        if (this_player()->query_spell_points() < 15) {
            write("You don't have enough spell points.\n");
            return 1;
        }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        write("You cause the earth to swallow " + capitalize(str) + ".\n");
        say(this_player()->query_name() + " causes the earth to swallow " + capitalize(str) + ".\n");
        ob->hit_player(random(20) + 20);
        this_player()->restore_spell_points(-15);
        return 1;
    } else {
        write("You are not high enough level for that spell.\n");
        return 1;
    }
}

flame(str) {
    object ob;
    if (this_player()->query_level() >= 6) {
        if (!str) return 0;
        if (this_player()->query_spell_points() < 20) {
            write("You do not have enough spell points for this spell.\n");
            return 1;
        }
        ob = present(lower_case(str), environment(this_player()));
        write("You cast flames at " + capitalize(str) + ".\n");
        say(this_player()->query_name() + " throws flames at " + capitalize(str) + ".\n");
        ob->hit_player(random(30) + 30);
        this_player()->restore_spell_points(-20);
        return 1;
        } else {
        write("You are not high enough level.\n");
        return 1;
    }
}

pillar(str) {
    object ob;
    if (this_player()->query_level() >= 8) {
        if (!str) {
            write("At whom?\n");
            return 1;
        }
        if (this_player()->query_spell_points() < 25) {
            write("You do not have enough spell points.\n");
            return 1;
        }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        write("You envelop " + capitalize(str) + " in a pillar of flame.\n");
        say(this_player()->query_name() + " envelops " + capitalize(str) + " in a pillar of flame.\n");
        ob->hit_player(random(40) + 40);
        this_player()->restore_spell_points(-25);
        return 1;
    } else {
        write("You are not high enough level for that spell.\n");
        return 1;
    }
}

firestone(str) {
    object ob;
    if (this_player()->query_level() >= 10) {
        if (!str) return 0;
        if (this_player()->query_spell_points() < 30) {
            write("You do not have enough spell points.\n");
            return 1;
        }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        write("You cast a rain of firestones upon " + capitalize(str) + ".\n");
        say(this_player()->query_name() + " casts a rain of firestones upon " + capitalize(str) + ".\n");
        ob->hit_player(random(45) + 45);
        this_player()->restore_spell_points(-30);
        return 1;
    } else {
        write("You are not high enough level for this spell.\n");
        return 1;
    }
}

/* summon() { */

whirlpool(str) {
    object ob;
    if (this_player()->query_level() >= 13) {
        if (this_player()->query_spell_points() < 45) {
            write("You don't have enough spell points.\n");
            return 1;
        }
        if (!str) { write("At who?\n"); return 1; }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        write("You send " + capitalize(str) + " into a whirlpool.\n");
        say(this_player()->query_name() + " sends " + capitalize(str) + " into a whirlpool.\n");
        ob->hit_player(random(45) + 50);
        this_player()->restore_spell_points(-45);
        return 1;
    } else {
        write("You are not high enough for this spell.\n");
        return 1;
    }
}

flood(str) {
    object ob;
    if (this_player()->query_level() >= 15) {
        if (!str) {
            write("At who?\n");
            return 1;
        }
        if (this_player()->query_spell_points() < 50) {
            write("You don't have enough spell points.\n");
            return 1;
        }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        write("You wipe away " + capitalize(str) + " in a flood.\n");
        say(this_player()->query_name() + " wipes away " + capitalize(str) + " in a flood.\n");
        ob->hit_player(random(50)+50);
        this_player()->restore_spell_points(-50);
        return 1;
    } else {
        write("You are not high enough level for this spell.\n");
        return 1;
    }
}

lightning(str) {
    object ob;
    if (this_player()->query_level() >= 16) {
        if (!str) {
            write("At whom?\n");
            return 1;
        }
        if (this_player()->query_spell_points() < 55) {
            write("You don't have enough spell points.\n");
            return 1;
        }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        write("Lightning bolts shoot out of your fingers at " + capitalize(str) + ".\n");
        say("Lightning bolts shoot out of " + this_player()->query_name() + "'s fingers, striking " + capitalize(str) + " hard.\n");
        ob->hit_player(random(55)+55);
        this_player()->restore_spell_points(-55);
        return 1;
    } else {
        write("You are not high enough level.\n");
        return 1;
    }
}

tornado(str) {
    object ob;
    if (this_player()->query_level() >= 17) {
        if (this_player()->query_spell_points() < 60) {
            write("You do not have enough spell points.\n");
            return 1;
        }
        if (!str) { write("At who?\n"); return 1; }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        write("You send a tornado at " + capitalize(str) + ".\n");
        say(this_player()->query_name() + " sends a tornado at " + capitalize(str) + ".\n");
        ob->hit_player(random(60) + 55);
        this_player()->restore_spell_points(-60);
        return 1;
    } else {
        write("You are not high enough level for this spell.\n");
        return 1;
    }
}

blizzard(str) {
    object ob;
    if (this_player()->query_level() >= 18) {
        if (this_player()->query_spell_points() < 70) {
            write("You do not have enough spell points.\n");
            return 1;
        }
        if (!str) { write("At who?\n"); return 1; }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        write("You send " + capitalize(str) + " into a blizzard.\n");
        say(this_player()->query_name() + " sends " + capitalize(str) + " into a blizzard.\n");
        ob->hit_player(random(65) + 65);
        this_player()->restore_spell_points(-70);
        return 1;
    } else {
        write("You are not high enough level for this spell.\n");
        return 1;
    }
}

hurricane(str) {
    object ob;
    if (this_player()->query_level() >= 19) {
        if (this_player()->query_spell_points() < 80) {
            write("You don't have enough spell points.\n");
            return 1;
        }
        if (!str) { write("At who?\n"); return 1; }
        ob = present(lower_case(str), environment(this_player()));
        if (!ob) return 0;
        write("You sweep " + capitalize(str) + " up in a hurricane.\n");
        say(this_player()->query_name() + " sweeps " + capitalize(str) + " up in a hurricane.\n");
        ob->hit_player(random(70)+70);
        this_player()->restore_spell_points(-80);
        return 1;
    } else {
        write("You aren't high enough level for this spell.\n");
        return 1;
    }
}
