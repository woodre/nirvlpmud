/*
 *  The goth ability to paint a players face white. (v2.0)
 *
 */

paint_face(str)  {
object ob, ob2;

  if(!str && present("white_face", this_player()))  {
    write("Your face ihas already been painted.\n");
    return 1;
        }

  if(!str && !present("white_face", this_player()))  {
    ob = clone_object("/players/saber/closed/new_mini/white_face.c");
    move_object(ob, this_player());
    write("You paint your face white.\n");
    say(tp+" paints "+GENDER+" face white.\n");
    return 1;
        }

  ob = present(str, environment(this_player()));
  if(!ob)  {
    write(CAP+" is not here to paint...\n");
    return 1;
        }

  if(!living(ob))  {
    write("Your paint doesn't really stick to the "+CAP+".\n");
    return 1;
        }

  if(present("white_face",ob))  {
    write(CAP+"'s face has already been painted white.\n");
    return 1;
        }

  write("You offer to paint "+CAP+"'s face white.\n");
  say(tp+" offers to paint "+CAP+"'s face white.\n",ob);
  tell_object(ob,
    "\n"+tp+" offers to paint your face white.\n"+
    "To accept, type paint_me.\n");
  ob2 = clone_object("/players/saber/closed/new_mini/face_yes.c");
  ob2->set_paint(tp);
  move_object(ob2, ob);
  return 1;
        }
