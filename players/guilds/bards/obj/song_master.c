#include "/players/guilds/bards/def.h"
#define SONG_DIR "/players/guilds/bards/songs/"

string *existing_songs;

get_existing_songs() {
  string *temp_filenames,temp;
  int x;
  temp_filenames=get_dir(SONG_DIR+"*");
  existing_songs=({});
  for(x=0;x<sizeof(temp_filenames);x++)
    if(sscanf(temp_filenames[x],"%s.song",temp))
      existing_songs+=({temp});
}
song_list() {
  int x;
  if(!existing_songs)
    get_existing_songs();
  for(x=0;x<sizeof(existing_songs);x++) {
    write(pad(existing_songs[x],15));
    if((x+1)%5 == 0)
      write("\n");
  }
  write("\n");
  return 1;
}

bard_song_sing(str)
{
	int song, number;

	if (!str) {
		song_list();
		return 1;
	}
  
  if(!existing_songs)
    get_existing_songs();
    
  if( member_array(str,existing_songs)!=-1 ) {
    object song_object;
    song_object=present("bard_song_object",TP);
    if(song_object) {
      write("You're already singing.  Finish that or stop singing first.\n");
      return 1;
    }
    song_object=clone_object(OBJ+"song_object");
    move_object(song_object,TP);
    song_object->start_singing(str);
    return 1;
  }

  FAIL("There is no song by that name...  yet.  To add a song, post it in\n"+
       "the songs room, then ask a GC to record it.\n");
}
