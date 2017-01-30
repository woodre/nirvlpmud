inherit "obj/clean";


id(str) { return str == "map"; }

get() { return 1; }
drop() { return 0; }
query_weight() { return 1; }
query_value() { return 10; }

reset() {}


short() { return "A map of Lothlorien"; }


long()
{
  write(
"                   THE WORLD OF LOTHLORIEN                  \n"+
"                                                    N       \n"+
"                          FARM    r                 |       \n"+
"              FOREST       LAND   r   SWAMPS      W---E     \n"+
"                          ppppppp r                 |       \n"+
"          fffffppppppppppppppppppp r                S       \n"+
"MOUNTAINS  fffffppppppppppppppppp  r  o   o   o             \n"+
"       MOUNTAINS ffppppppppppppppppp o                      \n"+
"                fffpppppppppppppp o                         \n"+
"            MOUNTAIN fffppppppppppp o                       \n"+
"                     ffffffppppppp o            K E Y       \n"+
"                  MOUN  ffffppppp o            --------     \n"+
"                    TAINS ffpp o               r - river    \n"+
"                            o                  o - coastline\n"+
"                          o                    p - plains   \n"+
"                                               f - foothills\n");
}
