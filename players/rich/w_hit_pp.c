weapon_hit() {
    if (call_other(environment(this_player()), "realm")=="enterprise") {
        write("You laugh as you hear the whine of the pistol as\n");
        write("its beam tears into your opponent!!!!\n");
        return 8;
    }
}
