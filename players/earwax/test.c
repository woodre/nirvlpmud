void reset(status arg) {
if (arg) return;
#ifdef __VERSION__
write("It's ldmud\n");
#else
write("It's DR\n");
#endif
write("after check\n");
}
