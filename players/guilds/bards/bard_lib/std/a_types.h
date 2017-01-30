
#define A_ARMOR		1
#define A_BODY_ARMOUR	1
#define A_HELMET	2
#define A_BOOTS		4
#define A_RING		8
#define A_AMULET	16
#define A_SHIELD	32
#define A_MISC		64

#define stringtoa(s) (\
s == "armor"  ? A_ARMOR :\
s == "helmet" ? A_HELMET :\
s == "boots"  ? A_BOOTS :\
s == "ring"   ? A_RING :\
s == "amulet" ? A_AMULET :\
s == "shield" ? A_SHIELD :\
s == "misc"   ? A_MISC)
