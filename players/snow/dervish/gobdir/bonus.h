/* 07/19/07 Earwax: beefing offense slightly to dictate guild balance */
/* Bonus of xlevel / 10 plus random chance of their sp vs 100k for 5 more */

gen_wc_bonus(){
  int xl, sandp;

  xl = (int)this_player()->query_extra_level();
  sandp = (int)this_object()->query_sand_points();
  return (xl / 10 + (sandp > random(100000) ? 5 : 0));
}
