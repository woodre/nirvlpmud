id(str) { return str == "scroll" || str == "scroll of healing"; }

short() {
   return "Scroll of Healing";
}

long() {
   write("An ancient spell of healing. It tells of wonderous effects, but\n");
   write("also warns of possible defects. To activate the spell, type:\n");
   write("'read healing scroll'\n");
}

read(str) {
   if(str == "healing scroll") {
     if(random(100) = 100) {
       write("You feel a wrenching in your gut as the spell malfunctions.\n");
       call_other(this_player(),"raise_stanima",-1);
       return 1;
     }
