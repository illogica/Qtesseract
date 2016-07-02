/**

  Handler for the #help command

  #help <command> will show help for the single commands

  */

commands.add(new Command("help", commandHelp, "Did you really ask for #help on #help?"));
function commandHelp(ci, args){
    if(args === "")
        server.sendplayermsg(ci.clientnum, "Available commands: " + commands.getPrefixes());
    else {
        var tkz = args.split(" ");
        server.sendplayermsg(ci.clientnum, commands.getHelp(tkz[0]));
    }
}
