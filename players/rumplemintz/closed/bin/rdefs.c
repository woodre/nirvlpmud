int rdefs() {
#ifdef __LDMUD__
  write("__LDMUD__\n");
#else
  write("No __LDMUD__\n");
#endif
#ifdef NOWRITE
  write("NOWRITE\n");
#else
  write("No NOWRITE\n");
#endif
#ifdef __COMPAT_MODE__
  write("__COMPAT_MODE__\n");
#else
  write("No __COMPAT_MODE__\n");
#endif
#ifdef __NEW_LIGHT__
  write("__NEW_LIGHT__\n");
#else
  write("No __NEW_LIGHT__\n");
#endif
#ifdef __NEW_SKILLS__
  write("__NEW_SKILLS__\n");
#else
  write("No __NEW_SKILLS__\n");
#endif
#ifdef __NEW_LEVELS__
  write("__NEW_LEVELS__\n");
#else
  write("No __NEW_LEVELS__\n");
#endif
#ifdef __VERSION__
  write("__VERSION__ : " + __VERSION__ + "\n");
#else
  write("No __VERSION__\n");
#endif
  return 1;
}
