/*
	restoreme()

        Restore guild member stats and information.
*/
restoreme() {
if(restore_object(LEGION+this_player()->query_real_name())) {
        write("Your Legion stats are being restored. . . .\n");
   return 1;
}
else {
        write("Creating a Legion stat file, please hold. . . .\n");
        saveme();
   return 1;
}
}

