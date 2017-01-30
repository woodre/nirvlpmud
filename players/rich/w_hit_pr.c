weapon_hit() {
    if (call_other(environment(this_player()), "realm")=="enterprise") {
        write("You smile as you hear the whine of the rifle as\n");
        write("its beam vaporizes various parts of your opponents body!!!\n");
        return 10;
    }
}
