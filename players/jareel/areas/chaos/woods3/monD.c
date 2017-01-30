/*
 * Daemon to populate monsters in area
 * -- Rumplemintz
 */

#define MON "/players/jareel/monsters/chaos/woods2/"

void populate_monsters(object ob) {
  int i, j, k;

  i = random(100);

  switch(i) {
  case 0..5:
    move_object(clone_object(MON + "dark_demon"), ob);
    if (random(2) == 1)
      move_object(clone_object(MON + "dark_demon"), ob);
    break;
  case 6..20:
    move_object(clone_object(MON + "skeleton"), ob);
    if (random(15) == 1) {
      move_object(clone_object(MON + "rhino_broo"), ob);
      if (random(5) == 1) {
        j = 5;
        for (k=0;k<j;k++)
          move_object(clone_object(MON + "broo"), ob);
      }
    }
    break;
  case 21..75:
    if (random(3) == 1)
      move_object(clone_object(MON + "skeleton"), ob);
    if (random(2) == 1)
      move_object(clone_object(MON + "broo"), ob);
    if (random(4) == 1)
      move_object(clone_object(MON + "broo"), ob);
    if (random(4) == 1)
      move_object(clone_object(MON + "skeleton"), ob);
    if (random(5) == 1) 
      move_object(clone_object(MON + "broo"), ob);
      if (random(13) == 1) 
        move_object(clone_object(MON + "rhino_broo"), ob);
    break;
  case 76..90:
    break;
  default:
    if (random(5) == 1)
      move_object(clone_object(MON + "skeleton"), ob);
    if (random(20) == 1)
      move_object(clone_object(MON + "rhino_broo"), ob);
    if (random(2) == 1)
      move_object(clone_object(MON + "broo"), ob);
    if (random(2) == 1)
      move_object(clone_object(MON + "skeleton"), ob);
    if (random(15) == 1)
      move_object(clone_object(MON + "skeleton"), ob);
    if (random(20) == 1)
      move_object(clone_object(MON + "rhino_broo"), ob);
    if (random(3) == 1)
      move_object(clone_object(MON + "broo"), ob);
    if (random(5) == 1)
      move_object(clone_object(MON + "skeleton"), ob);
    if (random(15) == 1)
      move_object(clone_object(MON + "rhino_broo"), ob);
    if (random(2) == 1)
      move_object(clone_object(MON + "broo"), ob);
    break;
  }
}
