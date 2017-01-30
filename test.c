void reset(status arg) {
  int i;
  string *blah;
  string *admin;

  admin = ({ });
  if (arg) return;
  // admin = get_dir("/bin/wiz/_*.c");
  // admin = allocate(sizeof(blah));
  foreach(string f : (admin = get_dir("/bin/wiz/_*.c"))) { admin[i] = f[1..<3]; i++; }
  i = sizeof(admin); while(i--) printf("%s\n", admin[i]);
}
