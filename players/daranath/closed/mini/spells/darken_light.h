/*
 *  The Larn ability to dismiss their light.  (v. 2.0)
 *
 */

darken_light()  {

  if(is_lit)  {

  set_light(0);
  is_lit = 1 + is_lit;
    write("You end the prayer, and the holy light dims.\n");
    say("The light in the room dims.\n");
  return 1;
        }

  write("You have not yet prayed for light.\n");
  return 1;
        }
