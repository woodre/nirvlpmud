inherit "/obj/treasure.c";
reset(arg) {
set_alias("paper");
set_id("flyer");
set_alias("pamphlet");
set_short("A flyer that reads 'FREE BEER!'");
set_long("Attention Everyone!  You can win free beer in the Nudie Bar!\n"+
"This is no regular beer either, It is as good as Trix's Alchohol!\n"+
"You need to seek out the Drunken Patron in Unsane's realm and play away\n"+
"<read flyer> for directions on how to get to the nudie bar!\n\n");
set_value(0);
set_weight(0);
set_read("From the church you need to go.....\ns,w,w,w,w,n,n,w,n,w until you come to the big tree\n"+
"There you will find the hangman.  I will give you a hint.  Just say any\n"+
"sentance with the word hang in it and he will hang you up.  Then tell\n"+
"the insect where you wanna go by saying any sentance with the word bar in\n"+
"it!  If you have any questions, mail Unsane.\n");
}
