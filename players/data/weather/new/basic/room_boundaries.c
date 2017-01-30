/* Room baundaries. This was written in LPC for TUBMUD by Frazor on
   1995/JUN/28.
*/

virtual inherit "/basic/timedepitem";

private void set_corners(string *wall_ids, string wall1, string wall2);

varargs void
set_walls (mixed wall_ids, status omit_corners) {
  int i;	/* counter */

  if (stringp (wall_ids))  wall_ids = ({ wall_ids });
  for (i=0; i < sizeof (wall_ids); i++)
    set_one_item_description (
      ({ wall_ids[i]+"ern wall", wall_ids[i]+" wall",
      wall_ids[i][0..0]+" wall" }),
      "You see nothing special about the "+wall_ids[i]+"ern wall.\n"
    );
  set_one_item_description (
    ({ "wall", "walls" }),
    "Please specify the wall you mean more exactly.\n"
  );
  if (!omit_corners) {
    set_corners (wall_ids, "north", "east");
    set_corners (wall_ids, "north", "west");
    set_corners (wall_ids, "south", "east");
    set_corners (wall_ids, "south", "west");
    set_one_item_description (
      ({ "corner", "corners" }),
      "Please specify the corner you mean more exactly.\n"
    );
  }
}

private void
set_corners(string *wall_ids, string wall1, string wall2) {
  int i;	/* counter */
  int b;	/* measuring if both walls are there */

  b = 0;
  for (i=0; i < sizeof (wall_ids); i++)
    if (wall_ids[i] == wall1 || wall_ids[i] == wall2)
      b++;
  if (b = 2) {
    set_one_item_description (
      ({ wall1+wall2+"ern corner", wall1+wall2+" corner",
        wall1[0..0]+wall2[0..0]+" corner" }),
      "You see nothing special about the "+wall1+wall2+"ern corner.\n"
    );
  }
}

void
set_ceiling() {
  set_one_item_description (
    "ceiling", "You see nothing special about the ceiling.\n"
  );
}

void
set_floor() {
  set_one_item_description (
    "floor", "You see nothing special about the floor.\n"
  );
}

void
set_ground() {
  set_one_item_description (
    "ground", "You see nothing special about the ground.\n"
  );
}
