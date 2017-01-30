#define CHAND "/bin/channel_daemon.c"

int cmd_chandebug( string str ) {
  CHAND->debug();
  return 1;
}
