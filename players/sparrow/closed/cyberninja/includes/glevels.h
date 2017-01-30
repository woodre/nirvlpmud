/* Quality Levels */
#ifndef  _GLEVELS_H_
#define  _GLEVELS_H_


/* General settings */
#define MIN_JOIN_LEVEL      8
#define MAX_QUALITY_LEVEL  10  /* maximum quality level          */

#define MAX_COMBO_LEVEL    27  /* real lv = belt lv + quality lv */
#define SENIOR             21  /* level of a senior guild member */
#define MIDLEVEL           15  /* a mid-range level in the guild */

#define MAX_COMBO_LEVEL_PRETITLE  "GrandLord";
#define SENIOR_PRETITLE           "MasterLord";
#define MIDLEVEL_PRETITLE         "Lord";
#define LOWLEVEL_PRETITLE         "Warrior";

/* Guild titles, correspond to belt lv + quality lv */
#define TITLE_MAX   "Annihilis"
#define TITLE_MD4   "Daemoniac"
#define TITLE_MD3   "Strider"
#define TITLE_MD2   "Blade"
#define TITLE_MD1   "Punk"
#define TITLE_MIN   "NetRunner"
#define TITLE_BAD   "defective"


/* Quality level experience requirements */
#define XP_LEVEL1       5000
#define XP_LEVEL2      20000
#define XP_LEVEL3      50000
#define XP_LEVEL4      90000
#define XP_LEVEL5     140000
#define XP_LEVEL6     230000
#define XP_LEVEL7     330000
#define XP_LEVEL8     450000
#define XP_LEVEL9     600000
#define XP_LEVEL10    800000
#define MAXEXP        800000


/* Quality level monetary requirements */
#define COST_LEVEL1     1000
#define COST_LEVEL2     5000
#define COST_LEVEL3    10000
#define COST_LEVEL4    20000
#define COST_LEVEL5    30000
#define COST_LEVEL6    40000
#define COST_LEVEL7    50000
#define COST_LEVEL8    60000
#define COST_LEVEL9    70000
#define COST_LEVEL10  100000


/* Quality level neuro chip brand names */
#define BRAND0  "acme"
#define BRAND1  ({"brainbit", "bitwagon"})
#define BRAND2  ({"brainbyte", "bytewagon", "macbox"})
#define BRAND3  ({"bitford", "neurospeed", "chipset"})
#define BRAND4  ({"thoughtloop", "286", "borgprobe"})
#define BRAND5  ({"picojiva", "386", "firecache", "dreadlock"})
#define BRAND6  ({"bitblaster", "486", "mindlogic", "borgcube"})
#define BRAND7  ({"psychogen", "amulet", "586", "sparc"})
#define BRAND8  ({"neurona", "686", "cyrex", "pentiam"})
#define BRAND9  ({"ultrasparc", "psipath", "alpha", "ultrajiva"})
#define BRAND10 ({"quantum", "tron", "darwin", "hal9000"})

#define BRAND1_DESC  "Simple-scalar non-pipelined CISC architectures"
#define BRAND2_DESC  "Simple-scalar pipelined CISC architectures"
#define BRAND3_DESC  "Simple-scalar deeper pipelined CISC architectures"
#define BRAND4_DESC  "Simple-scalar pipelined RISC architectures"
#define BRAND5_DESC  "Simple-scalar deeper pipelined RISC architectures"
#define BRAND6_DESC  "Megahertz superscalar RISC architectures"
#define BRAND7_DESC  "Gigahertz superscalar RISC architectures"
#define BRAND8_DESC  "Terahertz asynchronous superscalar architectures"
#define BRAND9_DESC  "TeraHertz asynchronous ultrascalar architectures"
#define BRAND10_DESC "Atomic bio-quantum architectures"

#endif
