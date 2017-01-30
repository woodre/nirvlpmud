inherit "room/room";
object bud1, flash, beer;

reset(arg){
   if(!arg){
        set_light(1);
        short_desc="if...then...else";
        long_desc=
        "The streets are clean.  The weather is beautiful.\n"+
        "Can u ask for anything more?  How about a Bud Light?\n";
         dest_dir = ({"players/airwoman/CASTLE/rm1n", "south"});
}
}
init() {
  add_action("bud");  add_xverb("");
  add_action("light"); add_xverb("");
::init();
}

bud(str) {
    string a, b;
    object bud1;
       if (sscanf(str, "%sbud%s", a, b)==2 ||
            sscanf(str, "%sBud%s", a, b)==2 ||
            sscanf(str, "%sBUD%s", a, b)==2)
        {
	if (sscanf(str, "%sbud light%s", a, b)==2 ||
	sscanf(str, "%sbud lite%s", a, b)==2)
        {move_object(clone_object("/players/airwoman/beer"), this_player());
        say("A bud light flies to "+ this_player()->query_name()+"\n");
        write("A bud light flies to your hand\n");
        }
        else {
        if (!present("bud", this_object())) {
          move_object(clone_object("/players/airwoman/bud"), this_object());
          tell_room(this_object(), "Bud appears in a flash!\n");
        }
return;
        }
return;

}
return;
}
light(str) {
	string a, b;
        if (sscanf(str, "%sbud light%s", a, b)==2 ||
	sscanf(str, "%sbud lite%s", a, b)==2)
	{return;}
        else
	{
	if(sscanf(str, "%slight%s", a, b)==2 ||
        sscanf(str, "%slite%s", a, b)==2)
	{
	move_object(clone_object("/players/airwoman/flash"), this_player());
        say("A flash light flies to "+this_player()->query_name()+"'s hand."+"\n"); 
	write("A flash light flies to your hand\n");
 }
  }
}
