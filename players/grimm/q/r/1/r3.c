inherit "/room/room";

reset(arg) {
  if(arg) return;
  short_desc="Path to Omar's Novelty Shop!";
  long_desc="You are on the path to Omar's Novelty Shop!\nAlong the way there"+
            " are numerous signs in brite\nneon pointing the way.\n";
  items=({
    "signs",
    "\nThe sign reads:\n\nOMAR'S NOVELTY SHOP! DEAD AHEAD!\n"+
    "HURRY OR YOU'LL MISS ALL THE GREAT BARGAINS!\n\nOmar",
    "sign",
    "\nThe sign reads:\n\nOMAR'S NOVELTY SHOP! DEAD AHEAD!\n"+
    "HURRY OR YOU'LL MISS ALL THE GREAT BARGAINS!\n\nOmar",
    });
  dest_dir=({
    "/players/grimm/q/r/1/r2", "west",
    "/players/grimm/q/r/1/r10", "south",
    });
}
