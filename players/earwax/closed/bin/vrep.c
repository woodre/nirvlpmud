int main(string arg) {
  if (!arg) {
    command("ls /log/WR", this_player());
    return 1;
  }

  command("more /log/WR/"+arg+"_workreport", this_player());
  return 1;
}
