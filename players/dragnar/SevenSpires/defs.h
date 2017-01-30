/** Directories **/
#define SCROLLDIR "/players/dragnar/SevenSpires/scrolls"
#define OBJDIR "/players/dragnar/SevenSpires/obj"
#define MONSDIR "/players/dragnar/SevenSpires/mons"
#define LOGDIR "/players/dragnar/SevenSpires/logs"
#define FOREST "/players/dragnar/SevenSpires/rooms/forest"
#define SPIRE "/players/dragnar/SevenSpires/rooms/citadel"

/** Daemons **/
#define MAPDM "/players/dragnar/SevenSpires/daemons/mapDM"

#define DTYPES ([ "magical" :      ({ "Magic", NORM }) \
                 ,"other|fire":     ({ "Fire", HIR }) \
                 ,"other|ice":      ({ "Ice" , HIB }) \
                 ,"other|evil":     ({ "Evil" , RED }) \
                 ,"other|good":     ({ "Good" , HIW }) \
                 ,"other|light":    ({ "Light" , HIY }) \
                 ,"other|dark":     ({ "Dark" , HIK }) \
                 ,"other|poison":   ({ "Poison" , HIG }) \
                 ,"other|electric": ({ "Electric" , YEL }) \
                 ,"physical":       ({ "Physical" , NORM }) \
                 ,"other|sonic":    ({ "Sonic" , HIM }) ])