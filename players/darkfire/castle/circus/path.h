
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Various paths within the directory structure of the abandoned amusement park.
This makes changing the locations of files much easier.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#define PATH_CIRCUS ("/players/darkfire/castle/circus/")

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
ROOMS
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define PATH_ROOMS (PATH_CIRCUS + "rooms/")

#define PATH_AREA (PATH_ROOMS + "area/")
#define PATH_ENTRANCE (PATH_ROOMS + "entrance/")
#define PATH_GRAVEYARD (PATH_ROOMS + "graveyard/")
#define PATH_MIDWAY (PATH_ROOMS + "midway/")
#define PATH_RIDES (PATH_ROOMS + "rides/")
#define PATH_SQUARE (PATH_ROOMS + "square/")
#define PATH_TENTS (PATH_ROOMS + "tents/")
#define PATH_TRAIN (PATH_ROOMS + "train/")
#define PATH_TUNNELS (PATH_ROOMS + "tunnels/")

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
MONSTERS
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define PATH_MONSTERS (PATH_CIRCUS + "monsters/")

#define PATH_GHOST PATH_MONSTERS + "ghost/"
#define PATH_GHOUL PATH_MONSTERS + "ghoul/"
#define PATH_GOLEM PATH_MONSTERS + "golem/"
#define PATH_MUTANT PATH_MONSTERS + "mutant/"
#define PATH_SCAVENGER PATH_MONSTERS + "scavenger/"
#define PATH_TOY PATH_MONSTERS + "toy/"
#define PATH_UNIQUE PATH_MONSTERS + "unique/"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
ITEMS
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define PATH_ITEMS PATH_CIRCUS + "items/"
#define PATH_ITEMS_MISC PATH_ITEMS + "misc/"
#define PATH_ITEMS_HEAL PATH_ITEMS + "heal/"
