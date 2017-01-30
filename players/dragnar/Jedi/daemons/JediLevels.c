mapping Levels;

void CreateMapping() {
    Levels = ([ 1: 0,
                2: 50000,
                3: 130000,
                4: 280000, 
                5: 480000,
                6: 680000,
                7: 880000,
                8: 1080000,
                9: 1480000,
               10: 1880000,
               11: 2280000,
               12: 2680000,
               13: 3680000 ]);
}

int QLevel(int level, int gexp) {
  int needed;

  if(level > 12) return 0;
  if(level < 0) level = 0;
  level++;                         /* adj. level to next level */
  if(!Levels) CreateMapping();     /* make mapping if needed */
  needed = Levels[level];          /* Get the exps needed for the level */
  if(needed > gexp) return 0;      /* Not enough to advance */
  else return 1;                   /* Player can advance */
}

/***** See if player has enough exp for current level *****/
status CheckLevel(int level, int gexp) {
  int needed;

  if(!Levels) CreateMapping();
  needed = Levels[level];
  if(needed > gexp) return 0;
  return 1;
}

Advance(object who) {
  object Jedi;
  int rank;

  if(!who) return 0;
  Jedi = present("jedi_object", who);
  if(!Jedi) return 0;
  rank = who->query_guild_rank();
  if(rank > 12) return 0;
  who->add_guild_rank(1);
  rank++;

  /* Bonus for gaining a new rank */
  if(rank == 5) Jedi->adj_skill_points(1);
  if(rank == 9) Jedi->adj_skill_points(2);

  switch(rank) {
  case 2..4:
    Jedi->adj_skill_points(1);
    break;
  case 5..8:
    Jedi->adj_skill_points(2);
    break;
  case 9..12:
    Jedi->adj_skill_points(5);
    break;
  case 13:
    Jedi->adj_skill_points(10);
    Jedi->set_my_master("none");
    break;
  default:
    break;
  }
  return 1;
}
