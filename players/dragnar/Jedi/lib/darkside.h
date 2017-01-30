DarksideFall() {
  tell_object(USER,
    ""+BOLD+""+BLK+"\n\n\n"+
    "       -=[YOUR ACTIONS HAVE DRIVEN YOU TO THE DARKSIDE OF THE FORCE]=-\n\n\n"+
    "You feel the "+HIR+"Anger"+NORM+""+BOLD+""+BLK+""+
    " within you take control and dominate your destiny...."+NORM+"\n");
  command("wimpy off",USER);
  darkside = 1;
  if(council) council = 0;
}
