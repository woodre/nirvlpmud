inherit"obj/treasure";

string paint;

reset(arg){
   set_id("face_yes");
   set_short();
   set_long();
   set_weight(0);
   set_value(0);
  call_out("paint_face",100);
}
drop() {return 1;}
get() {return 1;}

init()  {
  ::init();
  add_action("face_me","paint_me");
        }

paint_face()  {
  destruct(this_object());
  return 1;
        }
face_me()  {
object ob;
  ob = environment(this_object());

  tell_room(environment(ob),
  this_object()->query_paint()+" paints "+ob->query_name()+"'s face white.\n");
  move_object(clone_object("/players/saber/closed/new_mini/white_face.c"),ob);
  destruct(this_object());
  return 1;
        }

set_paint(str)  { paint = str; }
query_paint()   { return paint; }
