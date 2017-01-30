/*
 * /basic/confirm.c written by Alfe for Tubmud 1996-Jun-04
 * 
 * Inherit this file and call confirm() to implement a simple confirmation
 * before something should happen.
 */

private void work(mixed m,string s) {
  if (closurep(m))
    funcall(m,s);
  else if (stringp(m) || pointerp(m))
    message(m);
}

static varargs void receive_confirm(string s,mixed yes,mixed no) {
  if (stringp(s) && strlen(s) && (s[0]=='y' || s[0]=='Y'))
    work(yes,s);
  else
    work(no,s);
}

varargs void confirm(mixed yes,mixed no) {
  input_to("receive_confirm",0,yes,no);
}
