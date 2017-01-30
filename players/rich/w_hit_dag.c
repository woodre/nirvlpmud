weapon_hit() {
    if (call_other(environment(this_player()), "realm")=="enterprise") {
        write("You watch as your blade splits into three prongs,\n");
        write("and slams deep into your opponent!!\n");
        return 5;
    }
}
