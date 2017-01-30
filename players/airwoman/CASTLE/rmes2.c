#include "room.h"
object alex;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset (){
if (!present("alex")){
       alex=clone_object("players/airwoman/MONSTER/alex");
	move_object(alex, this_object());
	}

}

TWO_EXIT("players/airwoman/CASTLE/rmes1.c", "north",
	"players/airwoman/CASTLE/rmes3.c", "south",
	"room east south 2",
        "The streets are gloomy as you walk by.\n"+
        "It is night when the hoodlums roam the streets.\n", 1)
