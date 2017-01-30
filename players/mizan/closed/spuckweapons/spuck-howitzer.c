
id(str) {
    return str == "howitzer";
}

short() {
    return "A Super Spuckball howitzer [0]";
}

long() {
    if (this_player()) say((this_player()->query_name()) + " gazes reverently at the Super Spuckball howitzer.\n");
    write("If there was a time that words could fail to convey proper emotions,\n"+
          "This is definitely one of those times. Drifting before you is a weapon\n"+
          "capable of wreaking a truly stupid amount of senseless death and\n"+
          "destruction. You sense its immense mass as you touch it, and a shiver\n"+
          "rockets up your spine as you stare down the barrel, which you could\n"+
          "easily drive a small imported car into.\n"+
          "A good estimate of the mass of this thing would put it in the 80000\n"+
          "kilogram range, not including the funky tracks it rides on, and beefy\n"+
          "support staunchions to buffer the recoil of the blast.\n");
}

init() {
    add_action("load","load");
    add_action("shape","shape");
    add_action("shoot","shoot");
    add_action("shoot","fire");
}

load(str) {
    if (!str || str != "howitzer") return 0;
    if (present("spuckballs", this_player())) {
        write("It would take one HECK of a spuckball to fill the breech\n"+
              "of this thing. No, the ones you have just won't cut it.\n");
        return 1;
    }
    write("You don't have the proper ammo.\n");
    return 1;
}

shape(str) {
    if (!str || str == "barrel") return 0;
    write("The barrel gives a little, but then absolutely refuses to budge.\n");
    return 1;
}

shoot(str) {
    if (!str || str != "howitzer") return 0;
    write("It is not loaded.\n");
    return 1;
}

