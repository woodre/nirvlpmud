void reset(status arg) { return; }
status id(string arg) { return (arg == "tool" || arg == "stocks_tool"); }
string short() { return "Stocks Testing Tool"; }
string long() { write("Stocks: list, release, resentence, sentence, help\n"); }
status get() { return 1; }
status drop() { return 1; }

int stocks_cmd(string arg) { return (int)"/players/earwax/stocks/_stocks.c"->cmd_stocks(arg); }
void init() { add_action("stocks_cmd", "stocks"); }
