inherit "room/room";
object glum, money;

reset(arg)
{
   if (!present("glum")){
       glum=clone_object("players/airwoman/MONSTER/glum");
	move_object(glum, this_object());
	money = clone_object ("obj/money");
	money->set_money(1000);
       move_object(money,glum);
      }
	if(!arg) 
{
	set_light(1);
	short_desc ="room en 3 --Brobdingnags";
	long_desc = 
	"You dared eat a peach??  Somehow you have ended up on\n"+
	"the land of the huge Brobdingnags.  The grass around you\n"+
	"is so high you can see nothing now.  Everything looks like\n"+
	"a jungle...(kinda like the movie (Honey I Shrunk the Kids!)\n"+
        "Beware of Glumdalclitch!\n";
	dest_dir=({"players/airwoman/CASTLE/rmen2", "south",
		"players/airwoman/CASTLE/rmen4","north"});

}

}
