weapon_hit() {
    if (call_other(environment(this_player()), "realm")=="enterprise") {
        write("You flip as you see an arch of electricty come from\n");
        write("the tip of your whip!!!\n");
        return 9;
    }
}
