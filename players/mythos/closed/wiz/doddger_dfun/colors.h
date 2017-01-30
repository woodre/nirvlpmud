/*
** Color and Text Effects
**
** The following DEFINEs can be added to a normal text string
** to modify it into a blazing, neon, technicolor piece of
** coolness.  Just include this file, and modify your dull,
** boring string, by adding a line like this:
**
**   your_string = [STYLE]+[COLOR]+your_string+BACKSTR;
**
** Dodger
**
*/

#include "/players/boltar/things/esc.h"
#define BACKSTR esc+"[40m"
/* COLORS */
#define RED esc+"[31m"+BACKSTR
#define GREEN esc+"[32m"+BACKSTR
#define YELLOW esc+"[33m"+BACKSTR
#define BLUE esc+"[34m"+BACKSTR
#define PURPLE esc+"[35m"+BACKSTR
#define CYAN esc+"[36m"+BACKSTR
#define WHITE esc+"[37m"+BACKSTR
/* STYLES */
#define NONE esc+"[0m"
#define BOLD esc+"[1m"
#define BLINK esc+"[5m";
#define UNDERLINE esc+"[4m"
/* RETURN TO NORMAL */
#define NORMAL NONE+WHITE+BACKSTR
