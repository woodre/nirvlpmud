#include "/players/fred/closed/templar/defs.h"

string *hints;
string *paths;
string *items;
string *questers;


void reset(mixed arg)
{
  if(arg) return;

  paths = ({
    "/players/coldwind/desert/armor/witch_hat.c",         /* 1 */ 
    "/players/arrina/weapons/punchknife.c",               /* 2 */   
    "/players/snow/WEAPONS/greydeath.c",                  /* 3 */
    "/players/snow/WEAPONS/balance.c",                    /* 4 */
    "/players/hurtbrain/castello/dag/gaul/amulet.c",      /* 5 */
    "/players/feldegast/equip/wandereye.c",               /* 6 */
    "/players/snow/heals/ice_sphere.c",                   /* 7 */
    "/players/fred/forest/Obj/cwep.c",                    /* 8 */
    "/players/maledicta/town/armor/wshield.c",            /* 9 */
    "/players/jareel/armor/orlanthi_wind_lord_shield.c",  /* 10 */
    "/players/jareel/heals/stone.c",                      /* 11 */
    "/players/hawkeye/weapons/weapon.c",                  /* 12 */
    "/players/maledicta/cont/rdragon/dragonscale.c",      /* 13 */
    "/players/dragnar/weapons/sword.c",                   /* 14 */
    "/players/saber/weapons/stormstaff.c",                /* 15 */
    "/players/saber/weapons/spiritsword.c",               /* 16 */
    "/players/saber/weapons/lightning.c",                 /* 17 */
    "/players/fakir/inn/ARM/patchcloak.c",                /* 18 */
    "/players/mythos/awep/forest/nodachi.c",              /* 19 */
    "/players/mythos/awep/forest/air.c",                  /* 20 */  
    "/players/mythos/amisc/forest/essence.c",             /* 21 */
    "/players/mythos/awep/forest/snake.c",                /* 22 */
    "/players/mythos/awep/forest/shurato.c",              /* 23 */
    "/players/wocket/graveyard/dcrown.c",                 /* 24 */
    "/players/snow/WEAPONS/tsunami.c",                    /* 25 */
    "/players/maledicta/ares/weapons/daggers.c",          /* 26 */
    "/players/fakir/ways/ARM/tshield.c",                  /* 27 */
    "/players/feldegast/weapons/summer.c",                /* 28 */
    "/players/eurale/Keep/OBJ/death_mace.c",              /* 29 */
    "/players/feldegast/wep/soulthief.c",                 /* 30 */
    "/players/forbin/realms/flame_forest/OBJ/juju.c",     /* 31 */
    "/players/eurale/Keep/OBJ/dragon_shell.c",            /* 32 */
    "/players/eurale/Keep/OBJ/dragon_ring.c",             /* 33 */
    "/players/zeus/realm/OBJ/siphon_stone.c",             /* 34 */
    "/players/zeus/heals/demon_heart.c",                  /* 35 */
    "/players/nightshade/weap/drow_cleaver.c",            /* 36 */
    "/players/eurale/Park/OBJ/rex_plate.c",               /* 37 */
    "/players/eurale/Abyss/OBJ/mace.c",                   /* 38 */
    "/players/snow/WEAPONS/temblor.c",                    /* 39 */
    "/players/scathe/armor/mgarb.c",                      /* 40 */
  });

  hints = ({
    "Search the desert for the evil witch and retrieve her hat.",

    "Search through the tunnels of old to find the knife forged\n"+
    "from black volcanic glass.",

    "Retrieve the sword from the brute's leader high on the mountain pass.",

    "Retrieve a sword of equalization if you're brave enough to face the demon.",
 
    "Travel through time in search of the King's amulet",
  
    "Search the desert for the Wanderer and retrieve his eye.",

    "Find an arctic sphere of healing from the demons atop the mountains.",

    "Locate the remains of the leader of these normally small furry creatures.",

    "Battle the hired hunter for his unique shield.",
  
    "Defeat the Princess for her enchanted armor of air.",

    "Retrieve a stone forged in the dark pits of hell.",
  
    "Search through the army encampment for a surgical tool.",
 
    "Find the scale of a firey dragon in a land far away.",

    "Retrieve the weapon that legends have claimed is so powerful\n"+
    "that it can vanish from sight.",

    "Travel to the center of the storm and battle the skeletal\n"+
    "warrior for it's weapon of power.",

    "Find the weapon infused with spirits held by the Guardian.",

    "Search the mountains for the weapon that lets you control the\n"+
    "power of Lightning.",

    "Search through time and defeat the retired Captain of the\n"+
    "Kings Guard for his unique cloak.",

    "Locate the great katana by searching the ancient forest.",
 
    "Defeat the sorcerer that is said to be able to control the\n"+
    "winds and retrieve his weapon.",

    "Search the ancient forest for the fabled spirit essence.",

    "Retrieve the weapon from the enforcer of justice who presides\n"+
    "within the tower.",

    "Destroy the avatar of destruction and war and retrieve the\n"+
    "dark sword.",

    "Search the graveyard for a crown made of the most precious\n"+
    "of jewels.",

    "Retrieve the trident that is in control over the water.",

    "Search a far away land for daggers of poison and wraith.",
 
    "Defeat the black wind and retrieve his coveted shield.",

    "Retrieve the seasonal sword if you are able to solve\n"+
    "the riddle.",

    "Find the weapon of the banneret who has visited the reaper.",

    "Search the desert to find a sword that is capable of stealing\n"+
    "one's very essence.",

    "Search the burning forest for the witch doctor and retrieve his\n"+
    "magical charm.",

    "Search the warp of time for the shell of a dragon.",

    "Retrieve the ring from the enchanter of the Keep.",
   
    "Defeat the evil wizard of the shadow lands and retrieve\n"+
    "the fabled stone.",

    "Search the land of shadows for the heart of the cursed.",

    "Locate the captain of the watch and retrieve her mighty cleaver.",

    "Go back through time and retrieve the tough skin of the\n"+
    "mightiest of reptiles.",

    "Seek out the diva for she has a mace of the most unholy nature.",

    "Retrieve the warhammer that is forged from the most precious gem\n"+
    "that is dark as night.",
  
    "Locate the robes of the Grandmaster deep within the caverns.",
  
  });

  items = ({
    "witch hat",
    "punchknife",
    "greydeath",
    "broadsword of balance",
    "lucky amulet",
    "wandering eye",
    "ice sphere",
    "remains of overlord",
    "wrist shield",
    "wind shield",
    "hell stone",
    "hawkeye scalpel",
    "shardak_dragon_scale",
    "ninja katana",
    "staff of power",
    "spirit sword",
    "bolt of lightning",
    "patchwork cloak",
    "nodachi",
    "element of air",
    "essence",
    "green snake",
    "shurato",
    "diamond crown",
    "tsunami",
    "stiletto daggers",
    "shield tears",
    "summersword",
    "deathmace",
    "soulthief",
    "juju trinket",
    "dragon shell",
    "shaman ring",
    "siphon stone",
    "demons heart", 
    "drow cleaver",
    "tyrannosaurus plate",
    "fist mace",
    "temblor",
    "black monk robes",
  }); 

}


get_task(int x){ return hints[x]; }

get_path(int x){ return paths[x]; }

get_item(int x){ return items[x]; }


/* Actual Item Names
1.   Witch hat
2.   Obsidian Punchknife
3.   Greydeath
4.   Broadsword of Balance
5.   Lucky Amulet
6.   The Wandering Eye
7.   Ice Sphere
8.   Remains of Overlord
9.   Wrist Shield
10.  Wind Shield
11.  Hell Stone
12.  Scalpel
13.  Red Dragonscale
14.  Ancient Ninja Katana
15.  Staff of Power
16.  Sword of the Spirits
17.  A Bolt of Lightning
18.  Patchwork Cloak
19.  Nodachi
20.  The Element of Air
21.  A White Sheet of Essence
22.  Green Snake
23.  Shurato
24.  Diamond Crown
25.  Tsunami
26.  Stiletto Daggers
27.  Shield of Tears
28.  Summersword
29.  Death Mace
30.  Soulthief
31.  Juju Trinket
32.  Sea Dragon Shell
33.  Shaman Ring
34.  Siphon Stone
35.  Demon Heart
36.  Drow Cleaver
37.  Tyrannosaurus Plate
38.  Unholy Fist Mace
39.  Temblor
40.  Black Robes
*/  

add_questers(string str)
{
  if(!query_questers(str))
    return questers += ({ str, });
  return 0;
}

query_questers(string str)
{
  if(!questers || !sizeof(questers)) return 0;
  if(index(questers, str) > -1) return str;
  return 0;
}
