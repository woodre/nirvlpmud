#define TPN this_player()->query_name()
inherit "room/room";
int mofo;

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The Durkor caverns";
 long_desc =(
 "  The area is filled with spider webs.  The webs make movement\n"+
 "around the area very limited.  Several different cocoons are\n"+
 "hanging from the many webs.  Each of the cocoons is a victim of\n"+
 "the vicious spiders that are inhabited here.  The victims have \n"+
 "all felt the spiders' venomous bites.  The only way that is open\n"+
 "for travel is east.\n");

 items = ({
   "webs",
   "The webs are very thick making movement limited", 
   "web",
   "The webs are very thick making movement limited", 
   "coccoons",
   "Food for the spiders", 
   "coccoon",
   "Food for the spiders", 
   "victims",
   "Fallen heroes who met their unfortunate end",
   "victim",
   "Fallen heroes waiting to be food for the spiders of this area", 
   });

 dest_dir = ({
   "/players/catacomb/Cavern/rooms/lvl1_5.c","east", 
   });

 if (!present("spider"))
 {   
    mofo = 1;
    while (mofo != 3)
    {
      move_object(clone_object("/players/catacomb/Cavern/mobs/spider.c"),
	 this_object());
      mofo++;
    }
 }

}
