inherit "obj/treasure";

reset(arg) {
 if(arg) return;
set_short("A Bible(autographed by Jesus)");
set_alias("bible");
set_long("Looking at this Bible you are awed at the autograph of Jesus.\n" +
"Looking closer you see what it says: This is the best restaurant\n" +
"I ever ate at.\n");
   set_weight(1);
    set_value(5000);
}
 id(str) { return str == "bible" || str == "gary"; }

