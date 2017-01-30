do_cmd(str) {
  write("You lay a trail of cookies from the church to your castle.\n");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "/room/church");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/vill_green");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/hump");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/wild1");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/forest1");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/clearing");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/plane1");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/plane2");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/plane3");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/plane6");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/plane10");
  move_object(clone_object("/players/feldegast/heals/cookie.c"), "room/plane12");
  return 1;
}
