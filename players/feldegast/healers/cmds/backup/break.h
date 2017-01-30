do_sever(str) {
  notify_fail("Sever what?\n");
  if(!str) return 0;
  if(str=="link") {
    if(remove_call_out("link_cycle")) {
      write("You sever the order link.\n");
      return 1;
    }
  }
}

