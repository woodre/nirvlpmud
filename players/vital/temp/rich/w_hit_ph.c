weapon_hit() {
    if (call_other(environment(this_player()), "realm")=="enterprise") {
        write("You cry out with glee as you hear the whine of the phaser as\n");
        write("its beam slams into your opponent!!!\n");
        return 11;
    }
}
