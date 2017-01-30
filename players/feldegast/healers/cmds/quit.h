do_quit() {
  write("Leaving channel...\n");
  MYOB->guild_save();
  MYOB->set_muffle(1);
  MASTER->rebuild_channel();
  return 0;
}
