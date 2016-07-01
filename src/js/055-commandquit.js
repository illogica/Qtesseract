commands.add(new Command("quit", commandQuit, "#quit: tries to shut down the server gracefully"));
function commandQuit(ci, args){
    if(ci.privilege < Privilege.PRIV_ADMIN)
        server.sendplayermsg(ci.clientnum, "Insufficient privilege.");
    else{
        server.sendplayermsg(ci.clientnum, "Server shutting down...");
        server.quit();
    }
}
