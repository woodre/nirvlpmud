/* SILENT ZAP */

main(str) {
  object ob;
  if(str && (ob = present(str, environment(this_player()))))
    ob->hit_player(1000000, "other|vertebraker");
}
