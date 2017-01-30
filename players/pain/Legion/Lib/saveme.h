/*
        saveme()

        Save guild members stats and information.
*/
saveme() {
save_object(LEGION+this_player()->query_real_name());
write("Legion stats and information saved. . . .\n");
return 1;
}


