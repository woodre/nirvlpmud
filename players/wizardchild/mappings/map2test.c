inherit "/players/wizardchild/mapping2.c";
mixed *save;
mapping map;
reset(arg) {
  map = (["obj/player":find_object("/obj/player.c"),"hello":5]);
  save = mapping_to_mixed(map);
  save_object("players/wizardchild/map2");
  destruct(this_object());
}
