/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
All of the monsters grouped into arrays for randomization and presence checks.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
GHOSTS are the remnants of long-dead living attendees of the amusement park.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define GHOST_ACROBAT PATH_GHOST + "acrobat"
#define GHOST_CARNY PATH_GHOST + "carny"
#define GHOST_CLOWN PATH_GHOST + "clown"
#define GHOST_LION PATH_GHOST + "lion"
#define GHOST_PANTHER PATH_GHOST + "panther"
#define GHOST_TOURIST PATH_GHOST + "tourist"

#define GHOSTS ({GHOST_CARNY, GHOST_TOURIST})

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
GHOULS are the victims of the Necromancer in the graveyard.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define GHOUL_CLOWN PATH_GHOUL + "clown"

#define GHOULS ({GHOUL_CLOWN})

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
GOLEMS are the animated/haunted pieces of amusement park paraphernelia.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define GOLEM_HORSE PATH_GOLEM + "horse"
#define GOLEM_CLOWN PATH_GOLEM + "clown"
#define GOLEM_GNOME PATH_GOLEM + "gnome"
#define GOLEM_WOOD PATH_GOLEM + "wood"

#define GOLEMS ({GOLEM_HORSE, GOLEM_CLOWN, GOLEM_GNOME, GOLEM_WOOD})

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
MUTANTS have been affected by the illegal toxic waste dump under the park.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define MUTANT_CLOWN PATH_MUTANT + "clown"

#define MUTANTS ({MUTANT_CLOWN})

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
SCAVENGERS hunt through the park for scraps to live on.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define SCAVENGER_CAT PATH_SCAVENGER + "cat"
#define SCAVENGER_DOG PATH_SCAVENGER + "dog"
#define SCAVENGER_POSSUM PATH_SCAVENGER + "possum"
#define SCAVENGER_RACCOON PATH_SCAVENGER + "raccoon"
#define SCAVENGER_RAT PATH_SCAVENGER + "rat"

#define SCAVENGERS ({SCAVENGER_CAT, SCAVENGER_DOG, SCAVENGER_POSSUM, SCAVENGER_RACCOON, SCAVENGER_RAT})

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
TOYS are the animated/haunted midway prizes.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define TOY_BEAR PATH_TOY + "bear"
#define TOY_FISH PATH_TOY + "fish"
#define TOY_KITTY PATH_TOY + "kitty"
#define TOY_PUPPY PATH_TOY + "puppy"
#define TOY_RABBIT PATH_TOY + "rabbit"
#define TOY_SNAKE PATH_TOY + "snake"
#define TOY_UNICORN PATH_TOY + "unicorn"

#define TOYS ({TOY_BEAR, TOY_FISH, TOY_KITTY, TOY_PUPPY, TOY_RABBIT, TOY_SNAKE, TOY_UNICORN})

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Then there are a set of unique monsters.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define NECROMANCER PATH_UNIQUE + "necromancer"
