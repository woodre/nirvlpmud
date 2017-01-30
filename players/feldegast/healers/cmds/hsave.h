int do_hsave() {
  MYOB->guild_save();
  write(CYN+"Saving guild stats...\n"+NORM);
  return 1;
}
