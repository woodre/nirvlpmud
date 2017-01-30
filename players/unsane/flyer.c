inherit "/obj/treasure.c";
reset(arg) {
set_alias("beautiful flyer");
set_id("flyer");
set_alias("paper");
set_short("A beautiful flyer");
set_long("This is a flyer announcing the opening of Unsane's realm!\n"+
"If you want directions or hints you should read it.\n");
set_value(0);
set_weight(0);
set_read("From the church you need to go.....\ns,w,w,w,w,n,n,w,n,w until you come to the big tree\n"+
"There you will find the hangman.  I will give you a hint.  Just say any\n"+
"sentance with the word hang in it and he will hang you up.  Then you are on\n"+
"your own.  But, reading the sign in the entrance couldn't hurt.\n");
}
