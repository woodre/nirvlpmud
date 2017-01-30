#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Gnoll shaman tent";
 long_desc =
 "  Upon entering the tent you are hit with strange smells from\n"+
 "everywhere.  The tent is cleaner than the ground outside, but\n"+
 "it is still extremely messy compared to any other dwellings.\n";
 if(!present("gnoll"))
    move_object(clone_object("/players/catacomb/barbtribe/gnollshaman.c"),
    this_object());
 items = ({
   "tent",
   "The tent is lined with several different containers",
   "ground",
   "The ground is amazingly clean, with containers around the edge of the tent",
   "containers",
   "Various containers line the outside of the tent with strange fumes emitting from them"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/gnollvil3.c","north",
   "/players/catacomb/barbtribe/brooms/gnollvil2.c","east"
   });
 
}
init(){
  ::init();
      add_action("smellem","smell");  
  }

smellem(str)
{
  write("The containers have a strange smell coming from them.\n");
  say(TPN+" smells the air.\n");
  return 1;  
}