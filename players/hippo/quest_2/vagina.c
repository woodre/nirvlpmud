inherit "room/room";
reset(arg){
set_light(0);
short_desc="WOW, WHAT IS THIS??";
/*
long_desc="WOW, WHAT IS THIS??? .\n"+
   "Things taste quite acidly in here. You wander whether you\n"+
   "arrived in a female body maybe?\n";
*/
long_desc=format("WOW, WHAT IS THIS??? \nThings taste quite acidly in here. "+
"you wonder whether you arrived in a female bodey maybe?"+
"and this is for testing the format "+
"command.\n");
dest_dir=
({
   "/players/hippo/quest_2/uterus.c","north",
});
}
