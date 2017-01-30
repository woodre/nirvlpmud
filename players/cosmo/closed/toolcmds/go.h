/*
 * go.h
 */

go(string where) {
  switch (where) {
  case "church": TPMP("church#room/church.c"); break;
  case "post": TPMP("post#room/post.c"); break;
  case "advance": TPMP("advance#room/adv_guild.c"); break;
  case "pub": TPMP("pub#room/pub2.c"); break;
  case "inner": TPMP("inner#room/adv_inner.c"); break;
  case "lockers": TPMP("lockers#players/catwoman/tl.c"); break;
  case "portal": TPMP("portal#players/saber/ryllian/portal.c"); break;
  case "apartment": TPMP("apartment#room/plane1.c"); break;
  case "rats": TPMP("rats#players/cosmo/apt/rooms/NEWBIE/h1.c"); break;
  case "beyond": TPMP("beyond#players/cosmo/closed/workroom2.c"); break;
  case "dc": TPMP("dc#players/cosmo/dc/rooms/entrance.c"); break;
  case "?": write("You may go:\nchurch  post  advance  inner  pub\n");
            write("beyond  apartment  rats  dc\nlockers portal\n");
            break;
  default: write("Unknown destination.  Use 'go ?'\n"); break;
  }
  return 1; 
}

/* END */

