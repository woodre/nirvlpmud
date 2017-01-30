#define FILENAME "KhrellApproval"
status main(string arg) {
  if(!arg) write_file("/players/forbin/closed/"+FILENAME, "\n");
else write_file("/players/forbin/closed/"+FILENAME, "* "+arg+"\n");
    return (write("Note made.\n"), 1);
}
