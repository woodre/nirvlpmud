/*
        skills()

        Show the guild member an in depth listing of his/her
        current skills and stats.
*/
skills() {
int temp;
int nlvl;


if(this_player()->query_level() < 21) {
temp = call_other("room/adv_guild","get_next_exp",this_player()->query_level());
nlvl = temp - this_player()->query_exp();
}
write("\n");
if(this_player()->query_level() < 21) {
        write("Experience to next level: "+nlvl+"\n");
}
write("Total Skill Points: "+query_total()+"\n\n");
write("*(%%%%|===========================> <===========================|%%%%)*\n");
write("   Skills Acquired in the Service of Death\n\n");
write("*(%%%%|===========================> <===========================|%%%%)*\n");
return 1;
}

