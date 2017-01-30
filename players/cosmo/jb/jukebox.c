#include "/players/cosmo/closed/ansi.h"
#include "/players/cosmo/jb/jsongs.h"
#include "/players/cosmo/jb/jtitles.h"
#define BANNER "~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~"
#define ROM tell_room(environment(),
#define CAPNAME capitalize(player->query_name())

status check;   /* Used to stop a song that is in progress. */
int x;          /* global array counter */
object player;  /* global for this_player */
string *bands;  /* a subset of CDs containing only bands */
string band;    /* Name of selected band -- obtained from bands */

id(str) {
    return str == "jukebox";
}

reset(arg) {
string temp, temp2;
string *CDs;
int n;
  if(arg) return;
  CDs = ARTISTS;
  n = 1;
  while (CDs[n] != "END")  {
    sscanf(CDs[n], "%s -- %s", temp, temp2);
    if(!bands) bands = ({ temp });
    bands += ({ temp });
    n++;  }
}

long() {
  write(HIR+"\n"+BANNER+NORM+"\nYou may:\n"+
       "<list> all available CD titles\n"+
       "<list location> of all existing Jukeboxes\n"+
       "<list #> the songs on CD <#>\n"+
       "<select # letter> a particular song for the room's\n"+
       "                  listening pleasure\n"+
       "<stop> the playing of the current song\n"+
       "<request> that a particular CD be added to the jukebox\n\n"+
       "NOTE: The cost of playing a song is 25 coins, and the\n"+
       "      cost of stopping a song is 100 coins.\n"+
       "WARNING: Some songs may contain explicit material.\n"+
       HIR+BANNER+NORM+"\n");
}

short() {return(HIR+"A CD jukebox"+NORM); }
drop() {return 1;}
get() {return 0;}


init() {
  add_action("list","list");
  add_action("select","select");
  add_action("stop","stop");
  add_action("request","request");
}

list (str) {
int num, n;
string *titles, *CDs;
  CDs = ARTISTS;
  n = 1;
  if(!str) {
    write(HIR+"\n"+BANNER+NORM+"\n");
    write("Number   Artist -- Title\n");
    while (CDs[n] != "END")  {
      if(n>9) { write("  "+n+".    "+CDs[n]+"\n"); }
      if(n<10) { write("  "+n+".     "+CDs[n]+"\n"); }
      n++;  }
    write(HIR+BANNER+NORM+"\n");
    write("Use <list location> to see where other jukeboxes exist.\n");
    write(HIR+BANNER+NORM+"\n");
  return 1;  }
  if(str=="location") {
    write(HIR+"\n"+BANNER+NORM+"\n");
    write("Location        Directions from the church\n");
    write("--------------  --------------------------------\n");
    write("The local pub   s,2e,n,e\n");
    write("Rose's Bar      s,5e,s,enter portal,5n\n");
    write("\nPlease note that different jukeboxes contain different songs.\n");
    write(HIR+BANNER+NORM+"\n");
  return 1;  }
  sscanf(str, "%d",num);
  switch(num) {
    case 1: titles = CD1; break;
    case 2: titles = CD2; break;
    case 3: titles = CD3; break;
    case 4: titles = CD4; break;
    case 5: titles = CD5; break;
    case 6: titles = CD6; break;
    case 7: titles = CD7; break;
    case 8: titles = CD8; break;
    case 9: titles = CD9; break;
    case 10: titles = CD10; break;
    case 11: titles = CD11; break;
    case 12: titles = CD12; break;
    case 13: titles = CD13; break;
    case 14: titles = CD14; break;
    case 15: titles = CD15; break;
    default:
      write("That is not a valid selection.  Please select again.\n");
      return 1;
    break;
  }
  write(HIR+"\n"+BANNER+NORM+"\n");
  write(HIY+titles[0]+NORM+"\n");
  n = 1;
  while(titles[n] != "END") {
    write(titles[n]+"\n");
    n++;
  }
  write(HIR+BANNER+NORM+"\n");
return 1;  }

select (str) {
string *lyrics;
string letter;
int num;
  if(!str || sscanf(str, "%d %s",num,letter) != 2) {
    write("Usage: select <CD number> <song letter>\n");
  return 1; }
  if(this_player()->query_money() < 25) {
    write("Show me the money! <You have less than 25 coins.>\n"); 
  return 1; }
  switch(num) {
    case 1:
      switch(letter) {
        case "a": lyrics = song1a; break;
        case "b": lyrics = song1b; break;
        case "c": lyrics = song1c; break;
        case "d": lyrics = song1d; break;
        case "e": lyrics = song1e; break;
        case "f": lyrics = song1f; break;
        case "g": lyrics = song1g; break;
        case "h": lyrics = song1h; break;
        case "i": lyrics = song1i; break;
        case "j": lyrics = song1j; break;
        case "k": lyrics = song1k; break;
        case "l": lyrics = song1l; break;
        case "m": lyrics = song1m; break;
        case "n": lyrics = song1n; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 2:
      switch(letter) {
        case "a": lyrics = song2a; break;
        case "b": lyrics = song2b; break;
        case "c": lyrics = song2c; break;
        case "d": lyrics = song2d; break;
        case "e": lyrics = song2e; break;
        case "f": lyrics = song2f; break;
        case "g": lyrics = song2g; break;
        case "h": lyrics = song2h; break;
        case "i": lyrics = song2i; break;
        case "j": lyrics = song2j; break;
        case "k": lyrics = song2k; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 3:
      switch(letter) {
        case "a": lyrics = song3a; break;
        case "b": lyrics = song3b; break;
        case "c": lyrics = song3c; break;
        case "d": lyrics = song3d; break;
        case "e": lyrics = song3e; break;
        case "f": lyrics = song3f; break;
        case "g": lyrics = song3g; break;
        case "h": lyrics = song3h; break;
        case "i": lyrics = song3i; break;
        case "j": lyrics = song3j; break;
        case "k": lyrics = song3k; break;
        case "l": lyrics = song3l; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 4:
      switch(letter) {
        case "a": lyrics = song4a; break;
        case "b": lyrics = song4b; break;
        case "c": lyrics = song4c; break;
        case "d": lyrics = song4d; break;
        case "e": lyrics = song4e; break;
        case "f": lyrics = song4f; break;
        case "g": lyrics = song4g; break;
        case "h": lyrics = song4h; break;
        case "i": lyrics = song4i; break;
        case "j": lyrics = song4j; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 5:
      switch(letter) {
        case "a": lyrics = song5a; break;
        case "b": lyrics = song5b; break;
        case "c": lyrics = song5c; break;
        case "d": lyrics = song5d; break;
        case "e": lyrics = song5e; break;
        case "f": lyrics = song5f; break;
        case "g": lyrics = song5g; break;
        case "h": lyrics = song5h; break;
        case "i": lyrics = song5i; break;
        case "j": lyrics = song5j; break;
        case "k": lyrics = song5k; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 6:
      switch(letter) {
        case "a": lyrics = song6a; break;
        case "b": lyrics = song6b; break;
        case "c": lyrics = song6c; break;
        case "d": lyrics = song6d; break;
        case "e": lyrics = song6e; break;
        case "f": lyrics = song6f; break;
        case "g": lyrics = song6g; break;
        case "h": lyrics = song6h; break;
        case "i": lyrics = song6i; break;
        case "j": lyrics = song6j; break;
        case "k": lyrics = song6k; break;
        case "l": lyrics = song6l; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 7:
      switch(letter) {
        case "a": lyrics = song7a; break;
        case "b": lyrics = song7b; break;
        case "c": lyrics = song7c; break;
        case "d": lyrics = song7d; break;
        case "e": lyrics = song7e;
          write("That song is currently unavailable.  Please select again.\n");
          return 1;
        break;
        case "f": lyrics = song7f; break;
        case "g": lyrics = song7g; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 8:
      switch(letter) {
        case "a": lyrics = song8a; break;
        case "b": lyrics = song8b; break;
        case "c": lyrics = song8c; break;
        case "d": lyrics = song8d; break;
        case "e": lyrics = song8e; break;
        case "f": lyrics = song8f; break;
        case "g": lyrics = song8g; break;
        case "h": lyrics = song8h; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 9:
      switch(letter) {
        case "a": lyrics = song9a; break;
        case "b": lyrics = song9b; break;
        case "c": lyrics = song9c; break;
        case "d": lyrics = song9d; break;
        case "e": lyrics = song9e; break;
        case "f": lyrics = song9f; break;
        case "g": lyrics = song9g; break;
        case "h": lyrics = song9h; break;
        case "i": lyrics = song9i; break;
        case "j": lyrics = song9j; break;
        case "k": lyrics = song9k; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 10:
      switch(letter) {
        case "a": lyrics = song10a; break;
        case "b": lyrics = song10b; break;
        case "c": lyrics = song10c; break;
        case "d": lyrics = song10d; break;
        case "e": lyrics = song10e; break;
        case "f": lyrics = song10f; break;
        case "g": lyrics = song10g; break;
        case "h": lyrics = song10h; break;
        case "i": lyrics = song10i; break;
        case "j": lyrics = song10j; break;
        case "k": lyrics = song10k; break;
        case "l": lyrics = song10l; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 11:
      switch(letter) {
        case "a": lyrics = song11a; break;
        case "b": lyrics = song11b; break;
        case "c": lyrics = song11c; break;
        case "d": lyrics = song11d; break;
        case "e": lyrics = song11e; break;
        case "f": lyrics = song11f; break;
        case "g": lyrics = song11g; break;
        case "h": lyrics = song11h; break;
        case "i": lyrics = song11i; break;
        case "j": lyrics = song11j; break;
        case "k": lyrics = song11k; break;
        case "l": lyrics = song11l; break;
        case "m": lyrics = song11m; break;
        case "n": lyrics = song11n; break;
        case "o": lyrics = song11o; break;
        case "p": lyrics = song11p; break;
        case "z": lyrics = song11z; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 12:
      switch(letter) {
        case "a": lyrics = song12a; break;
        case "b": lyrics = song12b; break;
        case "c": lyrics = song12c; break;
        case "d": lyrics = song12d; break;
        case "e": lyrics = song12e; break;
        case "f": lyrics = song12f; break;
        case "g": lyrics = song12g; break;
        case "h": lyrics = song12h; break;
        case "i": lyrics = song12i; break;
        case "j": lyrics = song12j; break;
        case "k": lyrics = song12k; break;
        case "l": lyrics = song12l; break;
        case "m": lyrics = song12m; break;
        case "n": lyrics = song12n; break;
        case "o": lyrics = song12o; break;
        case "p": lyrics = song12p; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 13:
      switch(letter) {
        case "a": lyrics = song13a; break;
        case "b": lyrics = song13b; break;
        case "c": lyrics = song13c; break;
        case "d": lyrics = song13d; break;
        case "e": lyrics = song13e; break;
        case "f": lyrics = song13f; break;
        case "g": lyrics = song13g; break;
        case "h": lyrics = song13h; break;
        case "i": lyrics = song13i; break;
        case "j": lyrics = song13j; break;
        case "k": lyrics = song13k; break;
        case "l": lyrics = song13l; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 14:
      switch(letter) {
        case "a": lyrics = song14a; break;
        case "b": lyrics = song14b; break;
        case "c": lyrics = song14c; break;
        case "d": lyrics = song14d; break;
        case "e": lyrics = song14e; break;
        case "f": lyrics = song14f; break;
        case "g": lyrics = song14g; break;
        case "h": lyrics = song14h; break;
        case "i": lyrics = song14i; break;
        case "j": lyrics = song14j; break;
        case "k": lyrics = song14k; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    case 15:
      switch(letter) {
        case "a": lyrics = song15a; break;
        case "b": lyrics = song15b; break;
        case "c": lyrics = song15c; break;
        case "d": lyrics = song15d; break;
        case "e": lyrics = song15e; break;
        case "f": lyrics = song15f; break;
        case "g": lyrics = song15g; break;
        case "h": lyrics = song15h; break;
        case "i": lyrics = song15i; break;
        case "j": lyrics = song15j; break;
        case "k": lyrics = song15k; break;
        case "l": lyrics = song15l; break;
        case "m": lyrics = song15m; break;
        case "n": lyrics = song15n; break;
        case "o": lyrics = song15o; break;
        case "p": lyrics = song15p; break;
        case "q": lyrics = song15q; break;
        case "r": lyrics = song15r; break;
        case "s": lyrics = song15s; break;
        default:
          write("That is not a valid selection.  Please select again.\n");
          return 1;
        break;
      }
    break;
    default:
      write("That is not a valid selection.  Please select again.\n");
      return 1;
    break;
  }
  write("You pay the 25 coin fee to play the song.\n");
  this_player()->add_money(-25);
  band = bands[num];
  player = this_player();
  call_out("singer",1,lyrics);
  write_file("/players/cosmo/jb/PLAY.LOG", this_player()->query_name()+
       " played "+lyrics[0]+" by "+band+"\n   at "+ctime(time())+"\n");
return 1;  }

stop () {
  if(this_player()->query_money() < 100) {
    write("Show me the money! <You have less than 100 coins.>\n"); 
  return 1; }
  if (x==0) {
    tell_object(this_player(),"There isn't a song currently playing.\n");
    return 1;
  }
  check = 1;
  player = this_player();
return 1;  }

singer(string *lyrics) {
  if (x!=0) {
    tell_object(player,"\nThere is already a song in progress.  Please "
       +"wait\nfor it to finish before selecting another song.\n\n");
    player->add_money(25);
  return 1;  }
  ROM "\n"+CAPNAME+" puts 25 coins in the jukebox and selects a song.\n");
  ROM "Lights flash, horns blare, and the jukebox comes to life.\n");
  ROM "The following song has been selected:\n");
  ROM HIR+BANNER+NORM+"\n");
  ROM HIB+"     "+lyrics[0]+" by "+band+NORM+"\n");
  ROM HIR+BANNER+NORM+"\n");
  x=2;
  call_out("lines",8,lyrics);
return 1;  }

lines(string *lyrics) {
string verb;
  if (check) {
    tell_object(player,"You pay the 100 coin fee to stop the song.\n");
    player->add_money(-100);
    ROM HIG+"  S C R E E E E C H  ! ! ! ! !"+NORM+"\n"+CAPNAME+
            " has stopped the song!\n");
    x = 0;
    check = 0;
    return 1;
  }
  if (extract(lyrics[1], (strlen(lyrics[1])-1)) == "s") {
     verb = " sing: ";  }
  else { verb = " sings: ";  }
  if (lyrics[1] == "Garth Brooks")
    { verb = " sings: ";  }
  if (lyrics[x] != "END")  {
    ROM HIY+lyrics[1]+verb+NORM+lyrics[x]+"\n");
    x++;
    call_out("lines",2,lyrics);
    return 1;
  }
  x = 0;
  ROM HIR+BANNER+NORM+"\n");
  ROM band+" walk off the virtual stage as they finish their song.\n");
return 1;  }

request(str) {
  if(!str) {
    write("Usage: request <artist> <title>\n");
  return 1; }
  write_file("/players/cosmo/jb/REQUEST.LOG", this_player()->query_name()+
             " requested "+str+" at "+ctime(time())+"\n");
  write("Your request has been made and will be considered\n"+
        "by the "+HIY+"Jukebox Wizard"+NORM+" for inclusion.\n");
  return 1;
}
