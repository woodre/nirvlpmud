/* Modified for speed and cleaned up by Rumplemintz 10/4/2013 */
   
inherit "room/room";

#include "/players/eurale/VAMPIRES/RMS/check.h"
#include "/players/eurale/defs.h"

void reset(int arg) {
   if(arg)
      return;
   set_light(0);
   short_desc = "Vampire Title Room";
   long_desc =
   "This " + BOLD + "circular black room" + NORM + " has a " + HIR +
   "pentagram" + NORM + " etched into the shiny\n"+
   "floor.  A narrow, curved doorway leads north into the Vampire\n"+
   "Guild board room.  A small, curved plaque is attached to the wall\n"+
   "reflecting what little light there is.\n";
   
   items = ({
         "floor", "Polished black onyx with a red pentagram",
         "pentagram", "A eerie, blazing symbol that emanates from the floor",
         "plaque", "A polished black plaque with fire red letters you can read",
         "doorway", "A narrow doorway that silhouettes a bat with extended \n"+
         "wings... about to take flight",
         });
   dest_dir = ({
         "players/eurale/VAMPIRES/RMS/boardroom", "north",
         "players/eurale/VAMPIRES/RMS/foyer.c", "down",
         });
}

string realm() { return "NT"; }

void init() {
   ::init();
   add_action("down", "down");
   add_action("fix_titles", "fix_title");
   add_action("show_titles", "show_titles");
   add_action("read", "read");
}

int down() {
   if (!present("efangs", this_player())) {
      write("A strange force prevents you from going down.\n");
      return 1;
   }
   this_player()->move_player("down#players/eurale/VAMPIRES/RMS/foyer.c");
   return 1;
}

int fix_titles(string arg) {
    int level;
    int xlevel;
    int tmp;
   /* Removed all 'abbreviation' defs and changed code to use switch()
   for speed -- Rumplemintz */
   
   string str;
   
   write("You silently whisper your request.... the room becomes very\n"+
      "still and quiet..... a coldness, unlike anything you've ever\n"+
      "felt, creeps into the room and brushes across your exposed\n"+
      "skin..... you shiver with goose-bumps... and then the warmth\n"+
      "returns....\n\n");
   say(this_player()->query_name() + "'s lips turn blue and " +
      this_player()->query_pronoun() + " shivers violently...\n");
   
   if(!arg) 
   {
     /* Special titles for special people within the family */
     if ((string)this_player()->query_real_name() == "eurale") {
        this_player()->set_pretitle(GRY + "~o~" + NORM);
        this_player()->set_title("the " + HIR + "S" + GRY + "upreme " + HIR +
           "N" + GRY + "osferatu" + NORM);
        return 1;
     }
     if ((string)this_player()->query_real_name() == "solitare") {
        this_player()->set_title(HIK + "the Black Guardian" + NORM);
        this_player()->add_alignment(-1500);
        return 1;
     }
     if ((string)this_player()->query_real_name() == "night") {
        this_player()->set_title(HIR + "of the Living Dead" + NORM);
        this_player()->add_alignment(-1500);
        return 1;
     }
     if ((string)this_player()->query_real_name() == "euboy") {
        this_player()->set_title("the " + GRY + "Tester of the " + HIR + "Fangs" +
           NORM);
        return 1;
     }
     if ((string)this_player()->query_real_name() == "bone") {
        this_player()->set_pretitle(HIR + "D" + GRY + "ead " + HIR + "M" + GRY +
           "an " + HIR + "W" + GRY + "alking..." + NORM);
        this_player()->set_title("the " + HIR + "L" + NORM + BOLD + "egendary "+
           HIR + "L" + NORM + BOLD + "ord of " + HIR + "D" +
           NORM + BOLD + "arkness" + NORM);
        this_player()->set_al_title("Blackhearted");
        return 1;
     }
     if ((string)this_player()->query_real_name() == "nosferatu") {
        this_player()->set_pretitle(GRY+"C"+HIR+"ount"+NORM);
        this_player()->set_title("the "+GRY+"V"+HIR+"ampire "+GRY+"U"+HIR+
           "nderlord"+NORM);
        this_player()->set_al_title("Undead");
        this_player()->add_alignment(-1500);
        return 1;
     }
   }
   
   level = (int)this_player()->query_level();
   xlevel = (int)this_player()->query_extra_level();
   if(arg) {
      if(sscanf(arg, "+%d", tmp) == 1 &&  tmp > 0 && tmp < xlevel)
      {
         xlevel = tmp;
      }  else if(sscanf(arg, "%d", tmp) == 1 && tmp > 0 && tmp < level && tmp < 20)
      {
         xlevel = 0;
         level = tmp;
      }
   }
   /* New switch code for extra level */
   switch(xlevel) {
      case 100:
      str = "the " + HIR + "V" + GRY + "ampire " + HIR + "P" + GRY +
      "ure" + HIR + "blood" + NORM;
      break;
      case 96..99:
      if ((string)this_player()->query_gender() == "female")
         str = "the " + HIR + "V" + GRY + "ampire " + HIR + "B" + GRY +
      "aroness" + NORM;
      else
         str = "the " + HIR + "V" + GRY + "ampire " + HIR + "B" + GRY +
      "aron" + NORM;
      break;
      case 21..95:
      if ((string)this_player()->query_gender() == "female")
         str = "the " + HIR + "V" + GRY + "ampire " + HIR + "G" + GRY +
      "randmistress" + NORM;
      else
         str = "the " + HIR + "V" + GRY + "ampire " + HIR + "G" + GRY +
      "randmaster" + NORM;
      break;
      case 20:
      str = "the " + GRY + "Nocturnal " +HIR+ "Soul " + GRY + "Hunter" + NORM;
      break;
      case 19:
      if ((string)this_player()->query_gender() == "female")
         str = "the " + GRY + "Dominatrix of Shadows" + NORM;
      else
         str = "the " + GRY + "Dominator of Shadows" + NORM;
      break;
      case 18:
      str = RED + "the " +HIR+ "Hellhound " + RED + "of " + BOLD + "Darkness" +
      NORM;
      break;
      case 17:
      if ((string)this_player()->query_gender() == "female")
         str = GRY + "the Lady of " + HIR + "S" + GRY + "orcery" + NORM;
      else
         str = GRY + "the Lord of " + HIR + "S" + GRY + "orcery" + NORM;
      break;
      case 16:
      str = "the " + HIR + "Adept" + NORM + " of " + GRY + "Stormy Skies" +
      NORM;
      break;
      case 15:
      str = "the " + HIM + "Despiser " + NORM + "of " + HIY + "Sunrise" + NORM;
      break;
      case 14:
      if ((string)this_player()->query_gender() == "female")
         str = "the " + BOLD + "Princess of Darkness" + NORM;
      else
         str = "the " + BOLD + "Prince of Darkness" + NORM;
      break;
      case 13:
      str = "the " + BOLD + "Dark" + GRY + " Shapechanger" + NORM;
      break;
      case 12:
      if ((string)this_player()->query_gender() == "female")
         str = "the " + HIM + "High Priestess" + NORM + " of " + BOLD +
      "Shadows" + NORM;
      else
         str = "the " + HIM + "High Priest" + NORM + " of " + BOLD + "Shadows " +
      NORM;
      break;
      case 11:
      if ((string)this_player()->query_gender() == "female")
         str = "the " + GRY + "Mistress" + NORM + " of " + GRY +
      "Dark Elements" + NORM;
      else
         str = "the " + GRY + "Master" + NORM + " of " + GRY + "Dark Elements" +
      NORM;
      break;
      case 10:
      if ((string)this_player()->query_gender() == "female")
         str = "the " + HIB + "Living Dead" + NORM + " High Lady";
      else
         str = "the " + HIB + "Living Dead" + NORM + " High Lord";
      break;
      case 9:
      str = "the " + HIY + "Mind" + HIC + " Magician" + NORM;
      break;
      case 8:
      str = "the " + RED + "Commander" + NORM + " of " + BOLD + "Darkness" +
      NORM;
      break;
      case 7:
      if ((string)this_player()->query_gender() == "female")
         str = "the " + HIM + "Baroness of Blood" + NORM;
      else
         str = "the " + HIM + "Baron of Blood" + NORM;
      break;
      case 6:
      if ((string)this_player()->query_gender() == "female")
         str = "the " + GRY + "Mistress" + NORM + " of the " + GRY + "Night" +
      NORM;
      else
         str = "the " + GRY + "Master" + NORM + " of the " + GRY + "Night" +
      NORM;
      break;
      case 5:
      str = "the " + HIM + "fanged" + HIR + " Assassin" + NORM;
      break;
      case 4:
      str = "the " + GRY + "Adept" + NORM + " of " + HIM + "Night" + HIR +
      "mares" + NORM;
      break;
      case 3:
      str = "the " + GRY + "Soldier " + NORM + "of " + HIM + "Bloodlust" +
      NORM;
      break;
      case 2:
      str = "the " + HIB + "Guardian" + NORM + " of the " + BOLD +
      "Dark Cult" + NORM;
      case 1:
      str = "the " + GRY + "Adept" + RED + " of " + BOLD + "Shadows" + NORM;
      break;
      default:
      /* Now we switch to switch on levels, because xlevel is 0 */
      switch(level) {
         case 19:
         if ((string)this_player()->query_gender() == "male")
            str = "the " + HIB + "Master" + NORM + " of " + HIR +
         "Blood-letting" + NORM;
         else
            str = "the " + HIB + "Mistress" + NORM + " of " + HIR +
         "Blood-letting" + NORM;
         break;
         case 18:
         str = "the " + CYN + "Collector" + NORM + " of " + CYN +
         "Wayward Souls" + NORM;
         break;
         case 17:
         str = "the " + RED + "Seeker of New " + HIR + "Blood" + NORM;
         break;
         case 16:
         str = "the " + BLU + "Disciple of " + CYN + "Illusion" + NORM;
         break;
         case 15:
         str = "the " + MAG + "Cold Wind" + NORM + " Apprentice";
         break;
         case 14:
         str = "the " + YEL + "Seeker" + NORM + " of the " + BLU +
         "Storm" + NORM;
         break;
         case 13:
         str = "the " + HIG + "Child " + NORM + "of the Shadows";
         break;
         case 12:
         str = "the " + MAG + "Follower of the " + NORM + "Dark " + MAG +
         "Path" + NORM;
         case 11:
         str = "the Apprentice of " + CYN + "Lost Souls" + NORM;
         break;
         case 10:
         str = "of the " + MAG + "Living Dead" + NORM;
         break;
         case 9:
         str = "the " + YEL + "Walker" + NORM + " of Dark Mists";
         break;
         case 8:
         str = "the Initiate of " + CYN + "Moonless" + NORM + " Nights";
         break;
         case 7:
         str = "the " + RED + "Disciple of Blood" + NORM;
         break;
         case 6:
         str = "the Pallid Creature of Night";
         break;
         case 5:
         str = "the Companion of Darkness";
         break;
         default:
         str = "the Seeker of Eternal Life";
         break;
         }
   }
   /* Now we set the title to the predefined string str */
   this_player()->set_title(str);
   return 1;
}

int show_titles(string str) {
   if (!str) {
      write(
         "  Level           Title\n"+
         "____________________________________________________________\n"+
         "    4           the Seeker of Eternal Life\n"+
         "    5           the Companion of Darkness\n"+
         "    6           the pallid Night Creature\n"+
         "    7           the Disciple of Blood\n"+
         "    8           the Initiate of moonless nights\n"+
         "    9           the Walker of the Dark Mists\n"+
         "   10           of the Living Dead\n"+
         "   11           the Apprentice of Lost Souls\n"+
         "   12           the follower of the Dark Path\n"+
         "   13           the Child of Shadows\n"+
         "   14           the Seeker of the Storm\n"+
         "   15           the Cold Wind Apprentice\n"+
         "   16           the Disciple of Illusion\n"+
         "   17           the Seeker of New Blood\n"+
         "   18           the Collector of Wayward Souls\n"+
         "   19           the Master/Mistress of Bloodletting\n\n"
       );
   } else if (str == "+") {
      write(
         "  Level           Title\n"+
         "____________________________________________________________\n"+
         "  + 1           the Adept of Shadows\n"+
         "  + 2           the Guardian of the Dark Cult\n"+
         "  + 3           the Soldier of Bloodlust\n"+
         "  + 4           the Adept of Nightmares\n"+
         "  + 5           the fanged Assassin\n"+
         "  + 6           the Master/Mistress of the Night\n"+
         "  + 7           the Baron/Baroness of Blood\n"+
         "  + 8           the Commander of Darkness\n"+
         "  + 9           the Mind Magician\n"+
         "  +10           the Living Dead High Lord/High Lady\n"+
         "  +11           the Master/Mistress of Dark Elements\n"+
         "  +12           the High Priest/High Priestess of Shadows\n"+
         "  +13           the Dark Shapechanger\n"+
         "  +14           the Prince/Princess of Darkness\n"+
         "  +15           the Despiser of Sunrise\n"+
         "  +16           the Adept of Elements\n"+
         "  +17           the Lord of Sorcery\n"+
         "  +18           the Hellhound of Darkness\n"+
         "  +19           the Dominator of Dark Shadows\n"+
         "  +20           the Nocturnal Soul Hunter\n"+
         "  +21           the Vampire Grandmaster/Grandmistress\n");
   } else if (str == "++") {
      write(
         "  Level           Title\n"+
         "____________________________________________________________\n"+         
         "  +96           the Vampire Baron/Baroness\n"+
         "  +100          the Vampire Pureblood\n\n"
       );
   }
  return 1;
}

int read(string str) {
   if (!str || str != "plaque") {
      write("A voice whispers, 'Read what?'\n");
      return 1;
   }
   write(RED + "Vampire Title Room\n\n"+
      "  This magical room will allow members of the vampire family to do\n"+
      "  the following things:\n\n"+
      "   See normal level vampire titles: "+HIR+"show_titles"+NORM+RED+"\n"+
      "   See extra level vampire titles: "+HIR+"show_titles +"+NORM+RED+"\n"+
      "   See more extra level vampire titles: "+HIR+"show_titles ++"+NORM+RED+"\n"+
      "   Get an appropriate title: "+HIR+"fix_title"+NORM+RED+"\n"+
      "   Get an appropriate title: "+HIR+"fix_title #"+NORM+RED+"\n"+
      "      (# is be a level or +level you have previously earned\n"+
      "\nThe vampire titles have evolved over time and should be proudly\n"+
      "displayed by anyone in the Vampire Guild.\n" + NORM + "\n");
   return 1;
}
