/*
 *  Fayawyn Hut 
 *	fayhut
 *  Cloud 2009
 */

#include "/obj/ansi.h"

inherit "room/room";
int X;
int num;


string color;
 
reset(arg) 
{
	num = random(6);
	if(num == 0) {color = HIR+"Fayawyn Hut"+NORM;}
	if(num == 1) {color = HIW+"Fayawyn Hut"+NORM;}
	if(num == 2) {color = HIY+"Fayawyn Hut"+NORM;}
	if(num == 3) {color = HIB+"Fayawyn Hut"+NORM;}
	if(num == 4) {color = HIC+"Fayawyn Hut"+NORM;}
	if(num == 5) {color = HIG+"Fayawyn Hut"+NORM;}
	
	::reset(arg);
		 
 	if(!arg)
 	{

		set_light(0);

  		short_desc= ""+color+"";
 
		long_desc=
			""+HIC+"A good inch of dust covers the inside of this hut. Empty bookshelves"+NORM+"\n" +
			""+HIC+"and a plain wooden bed are the only things that furnish this poor home."+NORM+"\n" +
			""+HIC+"A broken-out glass window gives a good view of the ground below you."+NORM+"\n";
 
		items=
		({	
  		"dust",
  			"It is probably best not to "+HIK+"stir"+NORM+" the "+HIK+"dust"+NORM+" if you are allergic",
  		"bookshelves",
  			"It could only be imagined what books these shelves have seen",
  		"bed",
  			"Just the wooden frame remains",
  		"window",
  			"The broken window on the backside of the hut shows the area below the village",
  		"ground",
  			"Gauging the distance, falling from here would probably suck a lot",
  		"books",
  			"What knowledge they could have held....",
  		"shelves",
  			"They are very dusty",
  		"frame",
  			"It is in very good shape considering the circumstances",
  
 		});

		dest_dir=
		({
 			"/players/cloud/Fayawyn/rooms/fay5.c", "out",  
		});
	}
}

init()
	{
		::init();
		add_action("stir","stir");
		
	}

	stir(string str)
	{		
		if(str == "dust")
  		{	
	  		
	  		if(X == 0)
	  		{
				tell_object(this_player(),
	  				"\n You stir the dust and a "+HIK+"Dust Bunny "+NORM+"emerges!\n\n");
				tell_room(environment(this_player()),
					"\n"+this_player()->query_name()+" stirs the dust and a "+HIK+"Dust Bunny"+NORM+" emerges!\n\n", ({ this_player() }));
          		move_object(clone_object("/players/cloud/Fayawyn/mobs/dbunny.c"),this_object());
          		++X;
          		return 1;
		    }
		    
		    else
		    {
				tell_object(this_player(),
	  				"You stir the dust, but nothing happens.\n");
				tell_room(environment(this_player()),
					"\n"+this_player()->query_name()+" stirs the dust, but nothing happens.\n", ({ this_player() }));    
				return 1;
			}
		    	
 		}
 		 
  		else
  		{
	  		write("Stir what?\n");
	  		return 1;
  		}
	}