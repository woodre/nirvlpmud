inherit"obj/treasure";

reset(arg){
   set_id("white_face");
   set_short();
   set_long();
   set_weight(0);
   set_value(0);
}
drop() {return 1;}
get() {return 1;}

extra_look()  {
object ex_look;
  ex_look = environment(this_object())->query_name();
    write(ex_look+"'s face has been painted white.\n");
        }
