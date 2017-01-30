The items in this directory are responsible for realm-wide functions and are
not meant to be cloned, but are accessed by other objects via macros in the
definitions.h file.

[gridDM.c]
This object provides the basic framework for the 2-dimensional grid system
from which the map view works. Each block item on the map represents an
individual room, which is defined from /mines/core/cell.c

[mamasnapsDM.c]
This object generates random "Yo Mama" insults of various types.

[mobstatsDM.c]
This object governs the generation of statistics for monsters.

[shakespeareDM.c]
This object generates random psuedo-Shakespeare style olde English insults.

[templateDM.c]
This is a blank file which serves as a framework of sorts for these daemons.

[terrainDM.c]
This object contains a database of all the different terrain types used by
cellDM.c and ultimately individual cells. All of the different properties
relevant to each terrain type are queried against by this object.

[tripodcardDM.c]
This object governs activities supported by the Tripod Card, such as board
posting, stats, and other stuff TBD.
