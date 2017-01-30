/*
 * Ascension, by Dune and Snow
 * level daemon
 */
#include "../def.h"

#define LEVEL1  "Deva, Silver"
#define LEVEL2  "Deva, Gold"
#define LEVEL3  "Deva, Platinum"
#define LEVEL4  "Planetar, Silver"
#define LEVEL5  "Planetar, Gold"
#define LEVEL6  "Planetar, Platinum"
#define LEVEL7  "Solar, Silver"
#define LEVEL8  "Solar, Gold"
#define LEVEL9  "Solar, Platinum"
#define LEVEL10 "Solar, Greater"
#define LEVEL11 "Deity"


status display_levels() {
  write(
    LEVEL1+"\n"+
    LEVEL2+"\n"+
    LEVEL3+"\n"+
    LEVEL4+"\n"+
    LEVEL5+"\n"+
    LEVEL6+"\n"+
    LEVEL7+"\n"+
    LEVEL8+"\n"+
    LEVEL9+"\n");
  return 1;
}


string get_title(int class) {
  string title;
  switch(class) {
    case 1: title = LEVEL1; break;
    case 2: title = LEVEL2; break;
    case 3: title = LEVEL3; break;
    case 4: title = LEVEL4; break;
    case 5: title = LEVEL5; break;
    case 6: title = LEVEL6; break;
    case 7: title = LEVEL7; break;
    case 8: title = LEVEL8; break;
    case 9: title = LEVEL9; break;
    case 10: title = LEVEL10; break;
    case 11: title = LEVEL11; break;
    default: title = "Defect"; break;
    }
  return title;
}


string get_being(int class) {
  string title;
  switch(class) {
    case 0..3:   title = "Deva";     break;
    case 4..6:   title = "Planetar"; break;
    case 7..10:  title = "Solar";    break;
    case 11:     title = "Demigod";  break;
    default:     title = "Defect";   break;
    }
  return title;
}


string get_skin(int class) {
  string skin;
  switch(class) {
    case 1:
    case 4:
    case 7:   skin = "silver"; break;
    case 2:
    case 5:
    case 8:   skin = "gold"; break;
    case 3:
    case 6:
    case 9:   skin = "platinum"; break;
    default:  skin = "platinum"; break;
    }
  return skin;
}


int get_lev_percent(int lev, int xlev) {
  /* convert lev and xlev into lev_percent */
  /* returns a number from 0 to 100 */
  int lev_sum, percent, max;
  lev_sum = xlev + (lev - MIN_LEV);
  percent = lev_sum * 100;

  /* range of levels that guild covers */
  max = 22;

  percent = percent / max;
  if(percent > 100) percent = 100;
  return percent;
}


int get_qp_percent(int qp) {
  /* convert qp into qp_percent */
  /* returns a number from 0 to 100 */
  int percent, max;
  percent *= 100;

  /* quest points needed to wiz */
  max = 284;

  percent = percent / max;
  if(percent > 100) percent = 100;
  return percent;
}


int get_class(int percent) {
  /* returns class number from 1 to 9, given 0 to 200% */
  int class;
  class = 1;
  switch(percent) {
    case 0..39:     class = 1; break;
    case 40..59:    class = 2; break;
    case 60..79:    class = 3; break;
    case 80..99:    class = 4; break;
    case 100..119:  class = 5; break;
    case 120..139:  class = 6; break;
    case 140..159:  class = 7; break;
    case 160..179:  class = 8; break;
    case 180..200:  class = 9; break;
    }
  if(percent > 200) class = 9;
  return class;
}


int determine_level(int lev, int xlev, int qp) {
  int level_sum, lev_percent, qp_percent, halo_class;

  lev_percent = get_lev_percent(lev, xlev);
  qp_percent = get_qp_percent(qp);

  /* get class level from percentages */
  halo_class = get_class(lev_percent + qp_percent);
  return halo_class;
}


status renew_class(object ob) {
  int lev, xlev, qp, glev, new_class, grank;
  string title, name;
  lev   = ((int)ob->query_level());
  xlev  = ((int)ob->query_extra_level());
  qp    = ((int)ob->query_quest_point());
  glev  = ( (int) (present(GUILDID, ob)->query_setting(CLASS)) );
  if(lev < MIN_LEV) {
    tell_object(ob, "You are too weak to be immortal.\n");
    destruct(IPOB);
    return 1; }
  new_class = determine_level(lev, xlev, qp);
  if(lev >= 20) new_class = 10;
  name = CAP((string)ob->query_real_name());
  if((name == OWNER1) || (name == OWNER2)) new_class = 11;
  grank = ((int)ob->query_guild_rank());
  ob->add_guild_rank(-grank);
  ob->add_guild_rank(new_class);
  if(glev == new_class) {}
  else {
    write("The heavens change your spiritual being.\n");
    title = get_title(new_class);
    write("You are now a "+CAP(title)+".\n");
    IPOB->set_setting(CLASS, new_class);
    IPOB->save_me();
    move_object(IPOB, ob); /* force init */
    }
  ob->save_me();
  return 1;
}
