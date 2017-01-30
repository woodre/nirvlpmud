inherit "room/room";
reset(arg){
set_light(1);
short_desc="Hmm.. a penis?";
long_desc="You recognize this thing as a penis. It looks quite\n"+
   "big, and....\n"+
   "IT'S ERECTED!\n";
dest_dir=
({
   "/players/hippo/quest_2/prostate.c","back",
});
}
init ()
{   add_action("questing","questing");
   add_action("search","search");
}
questing()
{   move_object(this_player(),"/players/hippo/quest_2/vagina.c");
    command("look",this_player());
return 1;
}
search()
{   write ("The quest_story, and type 'questing' to continue\n");
return 1;
}
