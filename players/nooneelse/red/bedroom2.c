/*
 bedroom2.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "ladys' bedroom";
  no_castle_flag=1;
  long_desc =
    "This room was luxuriously furnished with a woman's touch, with a\n"
    + "large four poster bed, lush carpeting, and several soft couches\n"
    + "and chairs.  Several flickering lanterns provide dim illumination.\n"
    + "There are some large, beautiful paintings hanging on each of\n"
    + "the walls.\n";
  items =
    ({
      "bed", "A large comfortable feather bed with ornately carved posts.",
      "carpeting", "Thick, comfortable carpeting.",
      "carpet", "Thick, comfortable carpeting.",
      "chairs", "You see several large comfortable chairs.",
      "chair", "You see a large comfortable chair.",
      "couches", "It is a large comfortable couches.",
      "couch", "It is a large comfortable couch.",
      "paintings", "Each is of a different sundrenched landscape.",
      "painting", "It is of a peaceful sundrenched landscape.",
      "lanterns", "They are large crystal oil lanterns.",
      "lantern", "It is a large crystal oil lantern.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/dressing", "south",
    });
}
