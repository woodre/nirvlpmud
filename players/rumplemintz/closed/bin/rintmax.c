int rintmax() {
#ifdef __LDMUD__
  write(__INT_MAX__ + "\n");
#else
  write(__MAX_INT__ + "\n");
#endif
  return 1;
}

