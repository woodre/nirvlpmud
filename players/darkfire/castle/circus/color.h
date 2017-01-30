/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Color codes grouped together in arrays to make random selection and mixing
a lot easier. Some are specific color schemes (like Galaga's blue/green) or
themed (like the blue, cyan, and white of the Freeze theme) and others are
just nice and circus-like, to be used for area titles, descriptions, etc.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#define C_NORMAL ({GRY, RED, GRN, YEL, BLU, MAG, CYN})
#define C_INTENSE ({HIBLK, HIR, HIG, HIY, HIB, HIM, HIC, HIW})
#define C_ALL C_NORMAL + C_INTENSE

/* Some amusement-park two-color combos. */
#define C_BR ({BLU, RED})
#define C_BG ({BLU, GRN})
#define C_RY ({RED, YEL})
#define C_BW ({BLU, WHT})
#define C_GW ({GRN, WHT})
#define C_YW ({YEL, WHT})
#define C_CW ({CYN, WHT})
#define C_RW ({RED, WHT})
#define C_BY ({BLU, YEL})
#define C_WBK ({NORM, GRY})

#define CH_RY ({HIR, HIY})
#define CH_BR ({HIB, HIR})
#define CH_BG ({HIB, HIG})
#define CH_BY ({HIB, HIY})
#define CH_RW ({HIR, HIW})
#define CH_GW ({HIG, HIW})
#define CH_BW ({HIK, HIW})
#define CH_WB ({HIW, HIK})
#define CH_YW ({HIY, HIW})

#define C_PUB ({BLU, MAG})
#define C_DESI ({HIM, CYN})

/* Some amusement-park three-color combos. */
#define C_BRY ({BLU, RED, YEL})
#define C_BGY ({BLU, GRN, YEL})
#define C_RYW ({RED, YEL, WHT})
#define C_BWG ({BLU, WHT, GRN})
#define C_BBG ({BLU, GRY, GRN})

#define CH_CWM ({HIC, HIW, HIM})
#define CH_BBG ({HIB, GRY, HIG})
#define CH_BRY ({HIB, HIR, HIY})
#define CH_RYW ({HIR, HIY, HIW})
#define CH_BRYG ({HIB, HIR, HIY, HIG})

#define C_GALAGA ({GRN, BLU, HIG})
#define CH_RAINBOW C_INTENSE - ({HIBLK})
#define C_RAINBOW C_NORMAL - ({BLK})

/* Some themed color combos. */
#define C_COLD ({HIB, HIW, HIC, BLU, CYN, GRY})
#define C_FIRE ({HIR, HIW, HIY, RED, YEL, GRY})
#define C_DEATH ({HIW, GRY})
#define C_TOXIC ({HIR, HIY, HIG, GRN, GRY})
