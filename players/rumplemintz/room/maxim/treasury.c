/* ========================================================================== */
/*                                                                            */
/*   treasury.c                                                               */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Secret room where the cell keys are located in King Maxim's castle       */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";
object chest, key;

void reset(status arg){
  if(present("door", this_object())){
    object obj;
    obj = present("door", this_object());
    destruct(obj);
  }
  if(!present("chest")){
    chest = clone_object("/players/rumplemintz/room/maxim/obj/maxim_chest");
    key = clone_object("/obj/key");
    key->set_type("silver");
    key->set_code("m_prison");
    move_object(key, chest);
    move_object(chest, this_object());
  }
  if(arg) return;
  set_light(1);
  short_desc = "Treasure room in King Maxim's castle";
  long_desc =
"     You are in the treasury of the castle. There are various chests\n"+
"placed in this safe area. The walls are covered in silk and other fine\n"+
"fabrics from places where Maxim has traveled. There are some decorative\n"+
"weapons and suits of armor on one wall.\n";
  items = ({
    "treasury", "This is where all the treasure is kept",
    "chests", "Treasure chests overflowing with magnificent goods",
    "walls", "They are covered in silk and other fabrics",
    "weapons", "They are for decoration only",
    "armor", "They are for decoration only",
    "suits of armor", "They are for decoration only"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/upeast2", "east"
  });
}
