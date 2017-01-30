inherit "room/room";
object vend;

reset(arg)
{
if (!vend){
        vend = clone_object("/players/catwoman/obj/vend");
        move_object(vend, this_object());
        }
  if (arg) return;
  set_light(1);
  short_desc = "A dark room";
  no_castle_flag = 0;

  long_desc = "An exotic pleasure Palace.\n"+"only exit is lounge.\n";

}

realm() 
{
}

init ()
   {
    add_action ("lounge","lounge");
    return;
  }
lounge(){
call_other(this_player(), "move_player", "lounge#players/catwoman/lounge");
return 1;
}

query_light(){
return 1;
}

