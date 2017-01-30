string remove_color(string text) {
  int i, siz;
  string *temp;
  string junk;

  if (!instr(text,ESC))
    return text;
  temp = explode(text,ESC);
  siz = sizeof(temp);

  for (i = 0; i < siz; i++)
    sscanf(temp[i], "[%sm%s", junk, temp[i]);

  text = implode(temp,"");
  return text;
}
