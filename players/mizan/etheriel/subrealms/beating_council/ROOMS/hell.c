inherit "/room/room.c";
object hydra;
int i;

void reset(int arg) 
{
   if(!hydra)
   {
      /* kludgey but works :) */
      i = 0;
      
      for(i = 0; i < 4; i++)
      {
         hydra = clone_object("/players/mizan/etheriel/subrealms/beating_council/beasties/hydra.c");
         move_object(hydra, this_object());
      }
      
   }

   if(arg) return;
   set_light(0);
   
   short_desc = "The Caverns Of Stupidity";

   long_desc =
   "    This is a dark passage within the aptly named Caverns of Stupidity.\n"+
   "  There is an overpowering stench of corpses and sulphur here. The crunchy\n"+
   "  feeling under your feet is nothing other than decomposed and dried flaky\n"+
   "  bits of bone and flesh. You really should get the hell out of here!\n";
   
  items = ({

    "walls",
    "The wall appears to be covered in pig vomit and dried blood.",

    "floor",
    "The floor is sort of soft and crunchy. It is composed almost entirely of corpses.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/beating_council/entrance.c", "leave",
  });


}

realm() { return "NT"; }